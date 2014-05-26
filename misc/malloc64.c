/*
 * Write a malloc64 and free64 function that can alloc
 * 8 byte (64 bit) aligned addresses
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void *malloc64(int size)
{
	char *ma, *na;
	ma = malloc(size + 8);

	if (!ma) return ma;

	na = (char *)(((intptr_t)ma + 8) & (~7));

	*(na - 1) = na - ma;

	printf("ma = %p\n", ma);
	printf("na = %p\n", na);

	return ((void *) na);
}

void free64(void *a)
{
	char *na, *ma;

	if (!a)	return;

	na = a;

	ma = na - (*(na - 1));

	printf("ma = %p\n", ma);
	printf("na = %p\n", na);

	free(ma);
}

int main()
{
	void *p;
	malloc(33);

	p = malloc64(20);
	free64(p);
}

