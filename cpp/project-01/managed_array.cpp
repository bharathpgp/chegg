#include <cassert>
#include "managed_array.h"

ManagedArray::ManagedArray() : array() {
  count = 0;
}

ManagedArray::ManagedArray(unsigned N) : array() {
  assert(N <= MAX_LENGTH);
  count = N;
}

ManagedArray::ManagedArray(unsigned N, ItemType x) : array(x) {
  assert(N <= MAX_LENGTH);
  count = N;
}

unsigned ManagedArray::size() const {
  return count;
}

ItemType ManagedArray::read(unsigned i) const {
  assert(i < count);
  return array.read(i);
}

void ManagedArray::write(unsigned i, ItemType x) {
  assert(i < count);
  array.write(i, x);
}

void ManagedArray::insert(unsigned i, ItemType x) {
  assert(i <= count && count < MAX_LENGTH);
  for (unsigned j = count; j > i; j--)
    array.write(j, array.read(j-1));
  array.write(i, x);
  count++;
}

void ManagedArray::remove(unsigned i) {
  assert(i < count && count > 0);
  for (unsigned j = i; j < count - 1; j++)
    array.write(j, array.read(j+1));
  count--;
}