#include<stdio.h>
#include<stdlib.h>

#define RANGE 20 /* numbers from 0 to 19 */
#define BSIZE 5  /* Each bucket range is 5 for ex 0..4, 5..9, 10..14 etc */
#define MAX_PER_B 10

typedef struct buck {
	int *a;
	int size;
} buck;

void sort(int *a, int n)
{
	int i, nb, bucket, j, k, min, tmp;
	buck *b;
	nb = RANGE/BSIZE;

	b = malloc(sizeof(buck) * nb);

	for(i = 0; i < nb; i++) {
		b[i].a = malloc(sizeof(int)*MAX_PER_B);
		b[i].size = 0;
	}
	for(i = 0; i < n; i++) {
		if(a[i] >= RANGE)
			return;
		bucket = a[i] / BSIZE;
	
		if(b[bucket].size == MAX_PER_B)
			return;
		
		if(b[bucket].a[b[bucket].size])
			printf("11\n");

		b[bucket].a[b[bucket].size++] = a[i];

	}

	// sort each bucket
	for(i = 0; i < nb; i++) {
		for(j = 0; j < b[i].size; j++) {
			min = b[i].a[j];
			for(k = j+1; k < b[i].size; k++) {
				if(b[i].a[k] < min) {
					min = b[i].a[k];
					tmp = min;
					b[i].a[k] = b[i].a[j];
					b[i].a[j] = tmp;
				}
			}
		}
	}

	n = 0;
	for(i = 0; i < nb; i++) {
		for(j = 0; j < b[i].size; j++) {
			a[n++] = b[i].a[j];
		}
	}
	return;
}

#include "run-sort.h"
