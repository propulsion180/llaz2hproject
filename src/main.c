#include <kv.h>
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
}
