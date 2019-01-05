#ifndef __GUARDED_ARRAY_H__
#define __GUARDED_ARRAY_H__

typedef int ItemType;

const unsigned MAX_LENGTH = 500;

//
// GuardedArray
// - A wrapper class for C++ arrays to make array access safe.
//   Specifically, initialization is guaranteed, and assertions are
//   in place to detect array index out of bound errors in array member
//   accesses.
//

class GuardedArray {
public:
  //
  // Constructor
  //
  // Purpose: Initializes array elements to zeros
  // Argument(s): N/A
  // Side Effect: All array elements are initialized to zero.
  // Return: N/A
  //

  GuardedArray();

  //
  // Constructor
  //
  // Purpose: Initializes all array elements to a given value.
  // Argument(s):
  //  x : value to which array elements should be initialized.
  // Side Effect: All array elements are initialized to x.
  // Return: N/A
  //

  GuardedArray(ItemType x);

  //
  // read
  //
  // Purpose: Read array element at index i.
  // Argument(s):
  //  i : index of element to be read.
  // Precondition(s): i < MAX_LENGTH
  // Return: Value of array element at index i
  // 

  ItemType read(unsigned i) const;

  //
  // write
  //
  // Purpose: Write x into array element at index i.
  // Argument(s):
  //  i : index of array element to be overwritten.
  //  x : value to be stored into array.
  // Precondition(s): i < MAX_LENGTH.
  // Side Effect: The array element at index i will be 
  //              overwritten by x.
  // Return: N/A
  //

  void write(unsigned i, ItemType x);

private:

  ItemType array[MAX_LENGTH];

};

#endif