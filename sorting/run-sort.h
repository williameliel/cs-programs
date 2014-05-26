int main() {
	int nums[5] = { 4, 7, 11, 1, 3 };

	sort(nums, 5);

	for(int i = 0; i < 5; i++) {
		printf("%d\n", nums[i]);
	}
}
