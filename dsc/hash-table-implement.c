#include<stdlib.h>
#include<stdio.h>

struct Bucket {
	int k;
	int v;
	struct Bucket *next;
};

struct Hashtable {
	/* An array of pointers to struct Bucket */
	struct Bucket **b;
	/* Number of buckets in above array of Buckets, needed for hashing */
	int n;
};

struct Hashtable *hashtable_create(int n)
{
	struct Hashtable *h;

	if(!n)
		return NULL;

	h = malloc(sizeof(struct Hashtable));
	if(!h)
		return NULL;
	h->n = n;

	h->b = calloc(sizeof(struct Bucket *), n);
	return h;
}

void hashtable_insert(struct Hashtable *h, int k, int v)
{
	int hash;
	struct Bucket *b, *new;

	hash = k % h->n;

	b = h->b[hash];

	new = calloc(sizeof(struct Bucket), 1);
	new->k = k;
	new->v = v;
	new->next = b;
	h->b[hash] = new;
}

int hashtable_lookup(struct Hashtable *h, int k)
{
	int hash;
	struct Bucket *b;

	hash = k % h->n;

	b = h->b[hash];

	while(b) {
		if(b->k == k)
			return b->v;
		b = b->next;
	}
	return -1;
}

void main()
{
	struct Hashtable *h;
	h = hashtable_create(100);


	hashtable_insert(h, 2, 1);
	hashtable_insert(h, 10, 21);
	hashtable_insert(h, 5, 15);
	hashtable_insert(h, 15, 4);
	hashtable_insert(h, 1111, 15);


	printf("hash[%d] = %d\n", 5,  hashtable_lookup(h,5));
	printf("hash[%d] = %d\n", 15, hashtable_lookup(h,15));
	printf("hash[%d] = %d\n", 10, hashtable_lookup(h,10));
	printf("hash[%d] = %d\n", 1111, hashtable_lookup(h,1111));
}
