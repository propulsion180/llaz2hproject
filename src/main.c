#include "../inc/kv.h"
#include <stdio.h>

int main() {
  kv_t *table = kv_init(1024);
  printf("%p\n", table);

  printf("%ld\n", table->capacity);

  int one = kv_put(table, "hi", "ha");
  int two = kv_put(table, "hi", "hra");
  int three = kv_put(table, "hd", "ha");

  printf("%d, %d, %d", one, two, three);

  for (int i = 0; i < table->capacity; i++) {
    if (table->entries[i].key) {
      printf("[%d] %s: %s\n", i, table->entries[i].key,
             table->entries[i].value);
    }
  }

  char *value = kv_get(table, "hi");
  char *val2 = kv_get(table, "hd");
  char *val3 = kv_get(table, "asrtarstarst");
  printf("%s, %s, %s\n", value, val2, val3);

  kv_delete(table, "hi");
  value = NULL;
  value = kv_get(table, "hi");
  printf("%s, %s, %s\n", value, val2, val3);

  kv_free(table);
  table = NULL;
  value = kv_get(table, "hd");
  printf("%d\n", value);
}
