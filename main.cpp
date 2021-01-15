#include "library.h"

#include <cassert>
#include <iostream>

using namespace std;

void test1() {
  Library Libs("Libs1");
  Libs.addBook("Don Quixote");
  Libs.addBook("In Search of Lost Time");
  Libs.addBook("Ulysses");
  Libs.addBook("The Odyssey");
  Libs.listAllBooks();

  Library Libs2("Libs2");
  Libs2.addBook("Kite Runner");
  Libs2.addBook("Name of the Wind");
  Libs2.addBook("The Three Body Problem");
  Libs2.listAllBooks();

  // should generate already in library message and return true
  bool Result = Libs.isInLibrary("The Odyssey");
  assert(Result);

  // cannot add book twice, result should be false
  Result = Libs.addBook("The Odyssey");
  assert(!Result);

  // test remove, result should be true
  Result = Libs.removeBook("The Odyssey");
  assert(Result);

  // not in library, result should be false
  Result = Libs.isInLibrary("The Odyssey");
  assert(!Result);

  // cannot remove twice, result should be false
  Result = Libs.removeBook("The Odyssey");
  assert(!Result);

  // testing overloaded << operator<<
  cout << endl << Libs << endl << Libs2 << endl << "Libs += Libs2;" << endl;

  Libs += Libs2;
  Libs.listAllBooks();
}

void testAll() {
  test1();
  cout << "Successfully completed all tests." << endl;
}

int main() {
  testAll();
  return 0;
}