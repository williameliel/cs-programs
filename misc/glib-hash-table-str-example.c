#include <glib.h>
#include <stdint.h>
#include <stdio.h>

/*
 * glib hashtable example.
 * note that value can really be anything as long as its an integer or pointer.
 * key changes. if g_direct_hash is used, key is directly hashed, instead of deref'd and then hashed.
		if g_int_hash is used, key is deref'd to an int and then hashed.
		if g_str_hash is used, string pointer is deref'd and hashed.
	Check glib-pair-sum-hash-table.c example for g_direct_hash example.
 */

int main() {
        intptr_t x = 10;
        intptr_t y;
        GHashTable *gstr;

        gstr = g_hash_table_new(g_str_hash, g_str_equal);
        g_hash_table_insert(gstr, (gpointer)"hello world", (gpointer)x);
        y = (intptr_t)g_hash_table_lookup(gstr, (gpointer)"hello world");

        printf("y = %ld\n", y);
}
