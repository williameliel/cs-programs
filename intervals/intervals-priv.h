#include<stdio.h>
#include<stdlib.h>

struct interval {
	int start;
	int end;
 /* The counts field is passed in blank, and is updated by the program
    and used in the end to find the final answer */
	int counts;
};

/* For active interval list */
struct interval_list {
	struct interval *i;
	struct interval_list *next;
};

/* start or end points of the interval mapped to the interval */
struct int_map {
	struct interval *interval;
	int num;
};

void print_interval(struct interval i)
{
	printf("(%d,%d)\n", i.start, i.end);
}
