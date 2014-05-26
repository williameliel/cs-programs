#include<stdio.h>
#include<stdlib.h>

typedef struct res {
	// Cut for a particluar length
	int l;
	// Total value after cut
	int v;
} res;

// m and v should be n+1 in size
void maxval(int v[], res m[], int n)
{
	int i, l, max_l, max;
	m[0].l = 0;
	m[0].v = 0;

	for(i = 1; i <= n; i++) {
		// Initially set the value to no cut
		max = v[i];
		max_l = 0;

		// find a better cut
		// l is the cut, cut from 1 to half of current length
		for(l = 1; l <= i/2; l++) {
			if(m[l].v + m[i-l].v > max) {
				max = m[l].v + m[i-l].v;
				max_l = l;
			}
		}

		m[i].l = max_l;
		m[i].v = max;
	}
}

int main() {
	// 8 elements but v[0] makes it 9
	int v[9] = { 0, 1, 5, 8, 9, 10, 17, 17, 20 };

	/* Try :)
		int v[9] = { 0, 3, 5, 8, 9, 10, 17, 17, 20 };
	*/
	res m[9];
	int i;

	maxval(v, m, 8);

	for(i = 0; i <= 8; i++) {
		printf("length=%d maxval=%d cut=%d\n", i, m[i].v, m[i].l);
	}
}
