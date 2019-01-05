#include <iostream>

using namespace std;

#include "process.h"

void process_sequence(Container& c) {
  int x;

  // Read input sequence
  
  cin >> x;
  while (cin) {
    c.insert(x);
    cin >> x;
  }
  
  // Write output sequence

  while (! c.empty()) {
    cout << c.remove() << endl;
  }
}