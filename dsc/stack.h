#include<stdlib.h>

struct Stack {
        int *a;
        int n;
        int top;
};

typedef struct Stack stack;

struct Stack *create_stack(int n) {
        struct Stack *ret = NULL;

        ret = malloc(sizeof(*ret));

        if(ret) {
                ret->n = n;
                ret->top = -1;
                ret->a = malloc(sizeof(*ret->a) * n);
                if(!ret->a) {
                        free(ret);
                        return NULL;
                }
        }

        return ret;
}

int push(struct Stack *s, int a) {
        if(!s || s->top == s->n-1)
                return -1;

        s->a[++s->top] = a;
        return 0;
}

int pop(struct Stack *s, int *ret) {
        if(!s || s->top == -1)
                return -1;

        *ret = s->a[s->top--];
        return 0;
}
