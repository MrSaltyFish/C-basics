// Anvesh Khode
// 6b - 6. b) Create a class Book with the following attributes
// title, author and year of publication

#include <iostream>

using namespace std;

class Book {
private:
  string title;
  string author;
  int yearOfPublication;

public:
  Book(string title, string author, int yearOfPublication) : title(title), author(author), yearOfPublication(yearOfPublication) {}

  void displayDetails() {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Year of publication: " << yearOfPublication << endl;
  }
};

int main() {
  Book books[5];

  books[0] = Book("The Lord of the Rings", "J. R. R. Tolkien", 1954);
  books[1] = Book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 1979);
  books[2] = Book("Harry Potter and the Sorcerer's Stone", "J. K. Rowling", 1997);
  books[3] = Book("To Kill a Mockingbird", "Harper Lee", 1960);
  books[4] = Book("Pride and Prejudice", "Jane Austen", 1813);

  for (int i = 0; i < 5; i++) {
    books[i].displayDetails();
  }

  return 0;
}
