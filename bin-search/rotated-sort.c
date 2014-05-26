#include <stdio.h>
#include <stdlib.h>

/* Function to print pair of elements having minimum sum */
int findMin(int *a, int start, int end){
	int mid;

	mid = (start + end) / 2;

	// check for inflection
	if(a[mid] > a[mid+1])
		return a[mid+1];

	// go left
	if(a[start] > a[mid])
		return findMin(a, start, mid-1);

	// go right
	if(a[end] < a[mid])
		return findMin(a, mid+1, end);

	// The sorted array we're searching an inflection for is not rotated
	// This should get caught in the first attempt.
	// If there is rotation, we catch it right in the beginning 
	return a[0];
	
}
  
/* Main program to test above function */
int main()
{
    int arr[] = { 9, 10, 2, 3, 4, 5, 6};

    printf("%d",findMin(arr, 0, 6));
    getchar();
    return 0;
}
