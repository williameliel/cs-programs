/*
 * From Cormen:
 *  Find the maximum-size subset of intervals which are  mutually-compatible non-overlapping intervals
 *  in a set of intervals in O(n).
 *	Intervals are assumed to be sorted by finish time.
 */

#include "intervals-priv.h"

struct interval_list *max_subset(struct interval intervals[], int n)
{
	int i = 0;
	struct interval_list *result = NULL, *new_res;


	while(i < n) {
		int compat = 0;
		if(!result || intervals[i].start > result->i->end)
			compat = 1;

		if(compat) {
			new_res = malloc(sizeof(struct interval_list));
			new_res->next = result;
			new_res->i = &intervals[i];
			result = new_res;
		}
		i++;
	}

	return result;
}

int main()
{
	struct interval intervals[] = { {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 9}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 14}, {12, 16}};
	struct interval_list *result, *stale;

	result = max_subset(intervals, sizeof(intervals)/sizeof(intervals[0]));

	printf("Max subset:\n");
	while(result) {
		print_interval(*result->i);
		stale = result;
		result = result->next;
		free(stale);
	}
}

