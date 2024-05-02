// Anvesh Khode
// 6a - Create a parametrized constructor for the class 'Book' having
// initialized the book details such as 'book title', 'author name' and
// 'publication year'. Display the details of 5 such books.

#include <iostream>
#include <string>

class Book {
   private:
    std::string title;
    std::string author;
    int publicationYear;

   public:
    Book(std::string t, std::string a, int year)
        : title(t), author(a), publicationYear(year) {}

    void displayDetails() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Publication Year: " << publicationYear << std::endl
                  << std::endl;
    }
};

int main() {
    Book books[5] = {Book("The Great Gatsby", "F. Scott Fitzgerald", 1925),
                     Book("To Kill a Mockingbird", "Harper Lee", 1960),
                     Book("1984", "George Orwell", 1949),
                     Book("Pride and Prejudice", "Jane Austen", 1813),
                     Book("The Catcher in the Rye", "J.D. Salinger", 1951)};

    std::cout << "Details of 5 Books:\n";
    for(int i = 0; i < 5; ++i) {
        books[i].displayDetails();
    }

    return 0;
}
