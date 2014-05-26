#include<stdio.h>

void sort(int *nums, int n) {
	int i, j, tmp;
	for(i = 0; i < n-1; i++) {	/* n-1 passes */
		for(j = 0; j < n-1-i; j++) {
			if(nums[j] > nums[j+1]) {
				tmp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = tmp;
			}
		}
	}
}

#include "run-sort.h"
