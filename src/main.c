#include <kv.h>
#include <stdatomic.h>
#include <stdio.h>

int main() {
  kv_t *table = kv_init(3);
  printf("%p\n", table);

  printf("%ld\n", table->capacity);
}
