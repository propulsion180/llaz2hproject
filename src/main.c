#include <kv.h>
#include <stdatomic.h>
#include <stdio.h>

int main() {
  kv_t *table = kv_init(3);
  printf("%p\n", table);

  printf("%ld\n", table->capacity);

  kv_put(table, "hi", "ha");

  for (int i = 0; i < table->capacity; i++) {
    if (table->entries[i].key) {
      printf("%s: %s\n", table->entries[i].key, table->entries[i].value);
    }
  }
}
