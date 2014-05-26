#include<stdio.h>

// a is of size n+1

void swap(int *a, int *b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

// n is number of elements in the heap

void downheap(int a[], int n)
{
	int cur = 1, left, right, max, next;

	if(n < 1)
		return;

	left = (2 * cur);
	right = (2 * cur) + 1;


	while(left <= n && right <= n) {
		max = a[cur];
		next = -1;

		if(left <= n) {
			if(max < a[left]) {
				max = a[left];
				next = left;
			}				
		}

		if(right <= n) {
			if(max < a[right]) {
				max = a[right];
				next = right;
			}				
		}

		if(next == -1) {
			break;
		} else {
			swap(&a[cur], &a[next]);
		}

		cur = next;
		left = cur*2;
		right = (cur*2) + 1;
	}
}

void upheap(int a[], int n, int i)
{
	int parent;

	if(i > n || i < 1)
		return;

	parent = i / 2;

	while(parent >= 1) {
		if(a[i] <= a[parent])
			break;

		swap(&a[i], &a[parent]);

		i = parent;
		parent = i / 2;
	}
}

int insert_heap(int *a, int n, int used, int data)
{
	used++;

	if(used > n-1)
		return -1;	// full

	a[used] = data;
	upheap(a, used, used);

	return used;
}

void main() {
	int input[9] = { 3, 10, 5, 2, 1, 9, 6, 4, 7 };

	// ideally I'd make heap and n a function of the input size
	int heap[10] = {};
	int n = sizeof(heap) / sizeof(int);

	int used = 0;
	int i;

	while((used = insert_heap(heap, n, used, input[used])) != -1);
	used = n - 1;

	// heap sort
	while(used > 0) {
		swap(&heap[1], &heap[used]);
		used--;
		downheap(heap, used);
	}

	for(i = 0; i < n; i++)
		printf("%d\n", heap[i]); 

}















