#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max_n(a,b) a > b ? a : b

void reverse(char *str) {
	int i, j;
	char tmp;
	i = 0;
	j = strlen(str) - 1;

	while(i < j) {
		tmp = str[i];
		str[i]=str[j];
		str[j]=tmp;
		i++;
		j--;
	}
}

int str2int(char c)
{
	return c - '0';
}

int int2str(int i)
{
	return i + '0';
}

void mult1(char a[], char b[], char pp[], int n, int level) {
	int mplier;
	int res, car;
	if(level == strlen(b))
		return;
	else {
		mplier = str2int(b[level]);
		for(int i = 0; i < n; i++) {
			res = (str2int(a[i]) * mplier) + str2int(pp[level+i]);
			car = res / 10;
			res = res % 10;
			pp[level+i] = int2str(res);
			pp[level+i+1] = int2str(str2int(pp[level+i+1]) + car);
		}
		return mult1(a, b, pp, n, level+1);
	}
}

char *mult(char *a, char *b)
{
	char *pp;
	int lena, lenb, n;
	char *tmp;

	lena = strlen(a);
	lenb = strlen(b);
	n = max_n(lena, lenb);

	reverse(a);
	reverse(b);

	if(n == lenb) {
		tmp = a;
		a = b;
		b = tmp;
	}

	/* 1 extra for null char */
	pp = malloc(n*2 + 1);
	pp[n*2] = 0;
	for(int i = 0; i < n*2; i++)
		pp[i] = '0';

	mult1(a, b, pp, n, 0);

	reverse(pp);
	reverse(a);
	reverse(b);
	return pp;
}

int main() {
	char a[100], b[100], *prod;

	printf("Enter 1st num:");
	fgets(a, 100, stdin);

	printf("Enter 2nd num:");
	fgets(b, 100, stdin);

	/* Strip off newline chars */
	a[strlen(a)-1] = 0;
	b[strlen(b)-1] = 0;

	prod = mult(a, b);
	printf("Product = %s\n", prod);

	free(prod);
}





























