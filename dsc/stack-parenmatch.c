#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "stack.h"

int main() {
	char s[100];
	char *sr;
	char c;
	struct Stack *st;
	int valid = 1;

	st = create_stack(100);

	fgets(s, 100, stdin);
	s[strlen(s)-1] = 0;

	sr = s;
	while(*sr && valid) {
		switch(*sr) {
			case '(':
			case '[':
			case '{':
				push(st, *sr);
				break;

			case ')':
			case ']':
			case '}':
				pop(st, &c);
				if(*sr == ')' && c != '(')
					valid = 0;
				if(*sr == ']' && c != '[')
					valid = 0;
				if(*sr == '}' && c != '{')
					valid = 0;
		}			
		sr++;
	}

	if(valid && pop(st, &c) != -1)
		valid = 0;

	if(!valid)
		printf("Parens not matched!\n");
	else
		printf("Parens matched!\n");

	return 0;
}
