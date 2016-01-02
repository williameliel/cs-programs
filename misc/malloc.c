/*
 * My malloc implementation, untested
 */

// Write your own malloc

typedef struct {
	uint32_t size;
	int valid;
} hdr;

#define HEAP_SIZE 4096

uint8_t heap[HEAP_SIZE];

void *malloc(int size)
{
	void *tmp, *prev, *tmp1;

	if (size % 8)
		size = ((size / 8) * 8) + 8;

	tmp = heap;
	prev = NULL;

	/* Find a block that's big enough and invalid */
	while(1) {
		if (!tmp)
			break;

		if (!tmp->valid && tmp->size <= size)) {
			break;
		}

		prev = tmp;
		tmp = tmp + sizeof(hdr) + tmp->size;
	}

	// Found a block that's empty
	if (tmp) {
		tmp->valid = 1;
		// We have more space in the empty block
		if (tmp->size != size) {
			// Create a new empty block
			tmp1 = tmp + sizeof(hdr) + size;
			tmp1->valid = 0;
			tmp1->size = tmp->size - size - sizeof(hdr);
		}
		tmp->size = size;
		return ((void *)(tmp + sizeof(hdr));
	}

	// No block found, allocate a new block
	tmp = prev + sizeof(hdr) + prev->size;

	if ((tmp + sizeof(hdr) + size) - heap > HEAP_SIZE)
		// out of memory
		return NULL;

	tmp->size = size;
	tmp->valid = 1;
	return tmp + sizeof(hdr);
}
