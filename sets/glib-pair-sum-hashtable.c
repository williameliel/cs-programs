#include <glib.h>
#include <stdio.h>

void summing_pair_hash(long a[], int size, long sum, long pair[2]) {
	GHashTable *ght;

	ght = g_hash_table_new(g_direct_hash, g_direct_equal);

	for(long i = 0; i < size; i++) {
		long diff, lookup;
		g_hash_table_insert(ght, (gpointer)(a[i]), (gpointer)i);

		diff = sum - a[i];
		/* BUG: NULL which is failed look up, and lookup=0 are treated same */
		lookup = (long)g_hash_table_lookup(ght, (gpointer)diff);
		if (lookup && lookup != i) {
                        pair[0] = a[i];
                        pair[1] = sum - a[i];
			g_free(ght);
			return;
		}
        }
	g_free(ght);
        pair[0] = -1;
        pair[1] = -1;
        return;
}

int main() {
        long a[5] = {10, 1,-3000000,5,9};
        long pair[2] = {};

        summing_pair_hash(a, 5, -3000000 + 9, pair);

        printf("pair returned %ld, %ld\n", pair[0], pair[1]);

        return 0;
}

#if 0
/* Compile with:
 * gcc -o test hash-table.c `pkg-config --cflags --libs glib-2.0`
 */
 
typedef struct
{
        gint id;
        gchar *name;
} SomeObject;
 
int main(void)
{
        // For brevity's sake, I used the short form of creating a new
        // hash table. Normally, I would use g_hash_table_new_full()
        GHashTable *hashTable = g_hash_table_new(g_int_hash, g_int_equal);
 
        // Create a new SomeObject
        SomeObject *object1 = g_new0(SomeObject, 1);
        object1->id = 0;
        object1->name = g_strdup("name1");
 
        // Insert into hash table using the ptr as
        // both the key AND the value
        g_hash_table_insert(hashTable, object1, object1);
 
        // Create another
        SomeObject *object2 = g_new0(SomeObject, 1);
        object2->id = 1;
        object2->name = g_strdup("name2");
 
        g_hash_table_insert(hashTable, object2, object2);
 
        // Recall object1
        SomeObject *recalledObject = g_hash_table_lookup(hashTable, object1);
        g_print("[%d] %s\n", recalledObject->id, recalledObject->name);
 
        recalledObject = g_hash_table_lookup(hashTable, object2);
        g_print("[%d] %s\n", recalledObject->id, recalledObject->name);

	g_free(object1->name);
 
        return 0;
}
#endif
