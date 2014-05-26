#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// current char not same, next char same

int search_mismatch(char a[], char b[], int s, int e)
{
    int mid;
  
    mid = (s + e) / 2;
    
    if (a[mid] == b[mid] && a[mid+1] != b[mid+1])
        return mid+1;

    if (a[mid] != b[mid]) {
        if (s == e) {
            return mid;
        }
        return search_mismatch(a, b, s, mid-1);
    } else {
        return search_mismatch(a, b, mid+1, e);
    }    
}

void main()
{
    char s1[] = "axabya";
    char s2[] = "joelaxabya";
    
    int s1len, s2len;
    s1len = strlen(s1);
    s2len = strlen(s2);
    
    if(s1len == s2len) {
        printf("Strings are identical\n");
        exit(0);
    }
    
    printf("mismatch is at location: %d\n", search_mismatch(s1, s2, 0, s1len));
}
