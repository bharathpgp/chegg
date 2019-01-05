#include <cassert>
#include "guarded_array.h"

GuardedArray::GuardedArray() {
  for (unsigned i = 0; i < MAX_LENGTH; i++)
    array[i] = 0;
}

GuardedArray::GuardedArray(ItemType x) {
  for (unsigned i = 0; i < MAX_LENGTH; i++)
    array[i] = x;
}

ItemType GuardedArray::read(unsigned i) const {
  assert(i < MAX_LENGTH);
  return array[i];
}

void GuardedArray::write(unsigned i, ItemType x) {
  assert(i < MAX_LENGTH);
  array[i] = x;
}