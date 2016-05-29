#include<stdio.h>

#define MAX_HEAP_SIZE 1024

struct hdr {
	int size;
	int valid;
};

char mem[MAX_HEAP_SIZE];

void *my_malloc(int size)
{
	struct hdr *cur, *frag;
	int alloc_size;

	cur = (struct hdr *)mem;

	// Find first block that's invalid and big enough
	while (cur->valid || cur->size < size) {
		cur = (struct hdr *)((char *)cur + sizeof(struct hdr) + cur->size);
		if ((char *)cur - mem >= MAX_HEAP_SIZE)
			return NULL;
	}

	// do we fragment?
	if (cur->size - sizeof(struct hdr) - size > 0)
		alloc_size = size;
	else
		alloc_size = cur->size;

	if (alloc_size != cur->size) {
		// fragment
		frag = (struct hdr *)((char *)cur + alloc_size + sizeof(struct hdr));
		frag->valid = 0;
		frag->size = cur->size - alloc_size - sizeof(struct hdr);
	}
	cur->valid = 1;
	cur->size = alloc_size;
	return (void *)((char *)cur + sizeof(struct hdr));
}

void my_free(void *ptr)
{
	struct hdr *cur, *prev;
	struct hdr *hdr = (struct hdr *)((char *)ptr - sizeof(struct hdr));
	hdr->valid = 0;

	cur = (struct hdr *)((char *)hdr + sizeof(struct hdr) + hdr->size);
	prev = hdr;
	while (1) {
		if ((char *)cur - mem >= MAX_HEAP_SIZE)
			break;

		if (cur->valid) {
			break;
		} else {
			/*
			 * Merge consecutive blocks that are free
			 */
			prev->size = prev->size + sizeof(struct hdr) + cur->size;
			cur = (struct hdr *)((char *)cur + sizeof(struct hdr) + cur->size);
		}
	}
}

int main(void)
{
	struct hdr *hdr = (struct hdr *)mem;
	void *ptr;

	hdr->size = MAX_HEAP_SIZE - sizeof(struct hdr);

	printf("1: %p\n", my_malloc(50));
	ptr = my_malloc(60);
	printf("2: %p\n", ptr);
	printf("3: %p\n", my_malloc(10));
	my_free(ptr);
	printf("3: %p\n", my_malloc(1));
	printf("3: %p\n", my_malloc(50));
}
