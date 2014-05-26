#include "intervals-priv.h"

/* Find the interval that intersects the most or overlaps the most
   in a given set of intervals */

static void sort_array(struct int_map *map_arr, int n)
{
	struct int_map tmp;

	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			if(map_arr[j].num < map_arr[i].num) {
				tmp = map_arr[j];
				map_arr[j] = map_arr[i];
				map_arr[i] = tmp;
			}
		}
	}
}

struct interval_list *add_to_list(struct interval_list *ilist, struct interval *i)
{
	struct interval_list *tmp, *tmp1;

	tmp = calloc(1, sizeof(struct interval_list));
	if(!tmp) {
		perror("failed to alloc memory\n");
		exit(1);
	}
	tmp->i = i;
	tmp->next = ilist;

	tmp1 = tmp;

	if(ilist != NULL) { /* We don't overlap with anyone if we were the first one to add to list */
		while(tmp) {
			tmp->i->counts++;
			tmp = tmp->next;
		}
	}

	return tmp1;
}

struct interval_list *remove_from_list(struct interval_list *ilist, struct interval *i)
{
	struct interval_list *ret;
	while(ilist) {
		if(ilist->i == i) {
			ret = ilist->next;
			free(ilist);
			return ret;
		}
		ilist = ilist->next;
	}
	return NULL;
}


struct interval find_max_overlap(struct interval ints[], int n)
{
	/* Active list that maintains the current set of active intervals,
	   used during the sweep */
	struct interval_list *active = NULL;
	struct interval result;

	/* Linear arrays containing startpoints and endpoints, with pointers*/
	struct int_map *start, *end;
	int p = 0, q = 0;

	start = malloc(n*sizeof(struct int_map));
	end = malloc(n*sizeof(struct int_map));

	/* copy over start/end -> interval map into arrays */
	for(int i = 0; i < n; i++) {
		start[i].interval = &ints[i];
		start[i].num = ints[i].start;
		end[i].interval = &ints[i];
		end[i].num = ints[i].end;
	}

	/* Sorting - O(nlogn) */
	sort_array(start, n);
	sort_array(end, n);

	/* Sequential sweep - O(m*n), where m is the number of active overlapping intervals */

	while(p < n && q < n) {
		if(start[p].num <= end[q].num)
			active = add_to_list(active, start[p++].interval);
		if(end[q].num <= start[p].num)
			active = remove_from_list (active, end[q++].interval);
	}
	while(q < n)
		active = remove_from_list (active, end[q++].interval);

	result = ints[0];
	for(int i = 1; i < n; i++)
		if(ints[i].counts > result.counts)
			result = ints[i];

	return result;
}

int main()
{
	struct interval i[3] = {
					{  1,  6 },
					{  2,  3 },
					{  4,  11 }
				};
	struct interval result;

	result = find_max_overlap(i, 3);

	printf("result: ");
	print_interval(result);
}
