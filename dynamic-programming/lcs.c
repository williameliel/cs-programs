#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * Longest Common Subsequence
 */

struct pair {
	int start;	
	int end;
};

struct char_list {
	char c;
	struct char_list *next_char;
};

int find_len(struct char_list *list) {
	int n = 0;
	while(list) {
		n++;
		list = list->next_char;
	}
	return n;
}

struct char_list *lcs(char *str1, char *str2, struct pair p1, struct pair p2, struct char_list *clist)
{
	struct char_list *tmp;
	struct char_list *option1, *option2;

	if(p1.end < p1.start ||  p2.end < p2.start)
		return clist;

	if(str1[p1.end] == str2[p2.end]) {
		tmp = malloc(sizeof(struct char_list));
		tmp->c = str1[p1.end];
		tmp->next_char = clist;

		p1.end--;
		p2.end--;
		return lcs(str1, str2, p1, p2, tmp);
	} else {
		p2.end--;
		option1 = lcs(str1, str2, p1, p2, clist);
		p2.end++;

		p1.end--;
		option2 = lcs(str1, str2, p1, p2, clist);
		p1.end++;

		/* TODO: Fix memory leaks */
		if(find_len(option1) < find_len(option2))
			return option2;
		else
			return option1;
	}
}

void print_clist(struct char_list *clist) {
	printf("Clist:\n");
	while(clist) {
		printf("%c\n", clist->c);
		clist = clist->next_char;
	}
	return;
}

int main() {
	char *str1 = "thisisatest";
	char *str2 = "testing123testing";

	struct char_list\
	 *lcs_str = lcs(str1, str2, (struct pair){0, strlen(str1)-1}, (struct pair){0, strlen(str2)-1}, NULL);

	print_clist(lcs_str);
	return 0;
}


