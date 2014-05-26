#include<stdio.h>

int naive_fib(int n) {
	if(n <= 2)
		return 1;
	else
		return naive_fib(n-1) + naive_fib(n-2);
}


/*
 * Now using dynamic programming and recursion
 */
int mem[1000];

int fib(int n) {
	int fib1, fib2;

	if(n <= 2) {
		mem[n] = 1;
		return 1;
	} else {
		if(mem[n-1])
			fib1 = mem[n-1];
		else
			fib1 = fib(n-1);

		if(mem[n-2])
			fib2 = mem[n-2];
		else
			fib2 = fib(n-2);

		return fib1 + fib2;
	}
}

/*
 * Using dynamic programming and iteration
 */
int fib_dynamic_2(int n)
{
	/* Declare an array to store fibonacci numbers. */
	int f[n+1];
	int i;

	/* 0th and 1st number of the series are 0 and 1*/
	f[0] = 0;
	f[1] = 1;

	for (i = 2; i <= n; i++)
	{
		/* Add the previous 2 numbers in the series
		   and store it */
		f[i] = f[i-1] + f[i-2];
	}

	return f[n];
}

/*
 * Space optimized  and iterative. As a result - fasted.
 */
int fib_fast(int n) {
	int a, b, c;
	a = 1;
	b = 1;
	n -= 2;
	while(n--) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}
 
int main() {
	printf("Fib = %d\n", fib_fast(10));

	return 0;
}
