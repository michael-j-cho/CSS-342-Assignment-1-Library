//
// Created by Michael Cho on 01/06/2021.
//
// Library Class
//
// This library class can check for books in the library,
// add books to the libraryCatalog, remove books from the
// libraryCatalog, and list the library name and libraryCatalog
// contents. Overloaded operator will cout << the name and
// contents of the library.

#include "library.h"
#include <iostream>

// Constructor that sets the libraryName and
// sets numberOfBooks to 0.
Library::Library(const string &Name) {
  libraryName = Name;
  numberOfBooks = 0;
}

// destructor
// nothing on heap
Library::~Library() {
  // destructor
}

// A for loop that iterates through each
// index of the libraryCatalog array.
// Returns true if book is found in library.
// If no book is, found returns false.
bool Library::isInLibrary(const string &BookName) const {
  for (string book : libraryCatalog) {
    if (book == BookName)
    return true;
  }
  return false;
}

// Function to add a book to libraryCatalog array.
// Checks to make sure array is not full.
// Calls function to see if book is already in library.
// Adds BookName to the end of the array and
// increases numberOfBooks by 1.
bool Library::addBook(const string &BookName) {
  if (numberOfBooks < MAX) {
    if (isInLibrary(BookName))
      return false;
    libraryCatalog[numberOfBooks] = BookName;
    numberOfBooks++;
    return true;
  }
  return false;
}

// Function that removes book from libraryCatalog.
// The for loop iterates through the libraryCatalog array.
// If BookName matches a string from libraryCatalog,
// changes that index to the last book in the array.
// Then, clears the last index and decrements the numberOfBooks.
bool Library::removeBook(const string &BookName) {
  for (int I = 0; I < numberOfBooks; I++) {
    if (libraryCatalog[I] == BookName) {
      libraryCatalog[I] = numberOfBooks;
      libraryCatalog[numberOfBooks].clear();
      numberOfBooks--;
      return true;
    }
  }
  return false;
}

// Calls the overloaded opeator to list the books.
void Library::listAllBooks() const { cout << *this; }

// Overloaded operator that displays the libaray name and
// the contents of the libraryCatalog array.
ostream &operator<<(ostream &Out, const Library &Lib) {
  Out << Lib.libraryName << " Library Catalog:" << endl;
  for (int I = 0; I < Lib.numberOfBooks; I++) {
    Out << Lib.libraryCatalog[I] << endl;
  }
  return Out;
}

Library &Library::operator+=(const Library &Other) {
  for(int i = 0; i < Other.numberOfBooks; i++) {
    libraryCatalog[numberOfBooks] = Other.libraryCatalog[i];
    numberOfBooks++;
  }
  return *this;
}