/*
 * Find all coin combinations that add up to a specific total
 * eg, total=5, coins are 1 2 3, then one possible is 1 1 1 1 1
 * or 1 2 2 etc.
 */

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

void print_path(vector<int> &path)
{
	int i;
	int size;

	size = path.size();

	for (i = 0; i < size; i++) {
		printf("%d ", path[i]);
	}

	printf("\n");
}

void print_all(vector<int> &coins, vector<int> &path, int price, int choice_idx)
{
	int i, choice;

	choice = coins[choice_idx];

	if (price <= 0 || choice > price)
		return;

	path.push_back(coins[choice_idx]);

	if (choice == price) {
		print_path(path);
		path.pop_back();
		return;
	}

	for (i = choice_idx; i < coins.size(); i++)
		print_all(coins, path, price - choice, i);

	path.pop_back();
}

int main() {
	int _coins[3] = { 1, 2, 3 };
	vector<int> coins (_coins, _coins + 3);
	vector<int> path;
	int i;

	for (i = 0; i < 3; i++) {
		print_all(coins, path, 5, i);
	}

	return 0;
}
