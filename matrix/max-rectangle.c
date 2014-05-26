#include<stdio.h>
#include<string.h>

#define R 4
#define C 5

struct res {
        int i;
        int j;
        int sum;
};

struct res max_sub(int a[], int i, int j)
{
        int mid, left_sum = 0, right_sum = 0, sum, left_ind, right_ind, p;
        struct res r, left, right, center;

        // printf("max_sub(a, %d, %d) ", i, j);
        mid = (i+j)/2;

        if (i == j) {
                r.i = r.j = i;
                r.sum = a[i];
                goto ret;
        }

        right = max_sub(a, mid + 1, j);
        left = max_sub(a, i, mid);

        /* Find max left and right sum and track indices */
        sum = 0;
        left_ind = mid;

        for(p = mid; p >= i; p--) {
                sum += a[p];
                if(sum > left_sum) {
                        left_sum = sum;
                        left_ind = p;
                }
        }

        sum = 0;
        right_ind = mid + 1;

        for(p = mid + 1; p <= j; p++) {
                sum += a[p];
                if(sum > right_sum) {
                        right_sum = sum;
                        right_ind = p;
                }
        }

        center.sum = right_sum + left_sum;
        center.i = left_ind;
        center.j = right_ind;

        if(left.sum > right.sum)
                r = left;
        else
                r = right;

        if(r.sum < center.sum)
                r = center;

ret:
        // printf(" --> (%d, %d). sum = %d\n", r.i, r.j, r.sum);
        return r;
}

void max_rect(int a[R][C])
{
	int i, j, sum[R], max_sum, t;
	int p, q, r, s;
	struct res res;

	max_sum = a[0][0];
	p = 0;
	q = 0;

	for(i = 0; i < C; i++) {
		memset(sum, 0, R*sizeof(int));
		for(j = i; j < C; j++) {
			for(t = 0; t < R; t++)
				sum[t] += a[t][j];
			res = max_sub(sum, 0, R-1);
			if(res.sum > max_sum) {
				max_sum = res.sum;
				p = res.i;
				q = res.j;
				r = i;
				s = j;
			}
		}
	}

	printf("max rectangle (%d,%d) (%d,%d) (%d,%d) (%d,%d)\n", p,r,p,s,q,r,q,s);
}

int main()
{
    int M[R][C] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}
                      };
 
    max_rect(M);
 
    return 0;
}
