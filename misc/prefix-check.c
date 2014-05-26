#include <stdio.h>
#include <stdint.h>

enum prefix { ONE_BYTE, TWO_BYTE, THREE_BYTE, CONT_BYTE };

/*
 * 0xxxxxxx - 1 byte
 * 10xxxxxx - cont byte
 * 110xxxxx - 2 byte
 * 1110xxxx - 3 byte
 */
enum prefix get_prefix(uint8_t byte)
{
	if (byte < 128)
		return ONE_BYTE;
	if (byte < 192)
		return CONT_BYTE;
	if (byte < 224)
		return TWO_BYTE;
	return THREE_BYTE;
}

int check_stream(char *str, int n)
{
	int nbytes = 0, i;
	enum prefix pref;

	for(i = 0; i < n; i++) {
		pref = get_prefix(str[i]);

		if (nbytes == 0 && pref == CONT_BYTE)
			return -1;
		if (nbytes != 0 && pref != CONT_BYTE)
			return -1;

		switch(pref)
		{
			case ONE_BYTE:
				nbytes = 1;
				break;
			case TWO_BYTE:
				nbytes = 2;
				break;
			case THREE_BYTE:
				nbytes = 3;
				break;
			default:
				break;
		}

		nbytes--;
	}

	/* Incomplete stream */
	if (nbytes)
		return -1;

	return 0;
}

void main() {
	char buff[100] = { 64, 250, 130, 152 };

	printf("check = %d\n", check_stream(buff, 4));
}




