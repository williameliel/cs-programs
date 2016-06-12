/*
 * print combinations of all characters in a string (Careercup book)
 */

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

void print_path(vector<char> &path)
{
	int i;
	int size;

	size = path.size();

	for (i = 0; i < size; i++) {
		printf("%c ", path[i]);
	}

	printf("\n");
}

void print_all(char *str, int size, vector<char> &stk, int visited[], int i, int n)
{
	int j;

	if (i >= size || i < 0 || n >= size || visited[i])
		return;

	visited[i] = 1;

	stk.push_back(str[i]);

	if (n == size - 1) {
		print_path(stk);
		visited[i] = 0;
		stk.pop_back();
		return;
	}

	for (j = 0; j < size; j++) {
		if (!visited[j] && i != j)
			print_all(str, size, stk, visited, j, n+1);
	}

	visited[i] = 0;
	stk.pop_back();
}

int main() {
	char *str = "abcdefg";
	int size = 7;
	int i;
	int visited[7] = {};
	vector<char> stk;

	for (i = 0; i < size; i++) {
		print_all(str, size, stk, visited, i, 0);
	}

	return 0;
}

