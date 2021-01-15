//
// Created by Yusuf Pisan on 3/26/18.
//

#ifndef ASS1_LIBRARY_H
#define ASS1_LIBRARY_H

#include <string>

// Only for class code, OK to use namespace
using namespace std;

// Library holds books - can add, remove and list books
class Library {
  // display all books in library
  friend ostream &operator<<(ostream &Out, const Library &Lib);
  // friend Library Library::operator+=(const Library &Other) const;

public:
  // constructor with default name
  explicit Library(const string &Name);

  // destructor
  virtual ~Library();

  // add a new book
  // return true if successful, false if
  // book already in library
  bool addBook(const string &BookName);

  // remove a book
  // return true if successfully removed
  // false if book not in library
  bool removeBook(const string &BookName);

  int findBook(const string &BookName);

  // list all books
  void listAllBooks() const;

  // true if book found in library
  bool isInLibrary(const string &BookName) const;

  Library& operator+=(const Library &Other);

private:
  // max number of books
  static const int MAX = 100;

  // name of library
  string libraryName;

  // string array to store book names
  string libraryCatalog[MAX];

  // number of books in the catalog
  int numberOfBooks;
};

#endif // ASS1_LIBRARY_H
