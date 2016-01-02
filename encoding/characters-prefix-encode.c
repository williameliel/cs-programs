/*
Snap chat int: Dumb encoder
hhhhffee

hfe 11110101 00100100

h -> 1
f -> 01
e -> 001
4th -> 0001
0000 at end are padding

Untested.
*/


/* Map storing priority number of characters */
int map[256];
int current_bit;
char *out;

void setbit(int bit)
{
    int byte, bit_in_byte;
    void *mem;
    
    // find the byte
    byte = bit / 8;
    bit_in_byte = bit % 8;
    mem = out + byte;
    mem |= (1 << (7 - bit_in_byte));
}

void main()
{
    char ch;
    char str[100];
    int num = 1;
    char *cur;
    
    while((ch = getchar()) != EOF)
        map[ch] = num++;
    }
    
    printf("Enter string: ");
    fgets(str, 100, stdin);
    
    cur = str;
    while(*cur) {
        num = map[*cur];
        setbit(current_bit + (num-1));
        current_bit =+ num;
        cur++;
    }
}
