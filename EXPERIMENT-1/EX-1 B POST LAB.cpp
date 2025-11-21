#include <iostream>
#include <string>
using namespace std;


// ===== Task 4: Exceptions =====
class BookNotFoundException {};
class MemberNotFoundException {};
class BookNotAvailableException {};


// ===== Task 1: Book class =====
class Book {
    string title, author, ISBN;
    bool available;
public:
    Book() { available = true; }
    Book(string t, string a, string i) {
        title = t; author = a; ISBN = i; available = true;
    }


    string getISBN() { return ISBN; }


    // Task 2: get/set status
    bool getStatus() { return available; }
    void setStatus(bool s) { available = s; }


    void print() {
        cout << title << " (" << ISBN << ") - "
             << (available ? "Available" : "Issued") << endl;
    }
};


// ===== Task 5: Base class User =====
class User {
protected:
    int userID;
    string name;
public:
    User() {}
    User(int id, string n) { userID = id; name = n; }
    virtual void performAction() {
        cout << "User " << name << " performs a generic action\n";
    }
    int getID() { return userID; }
    string getName() { return name; }
};


// ===== Task 1 + 5: Member (inherits User) =====
class Member : public User {
public:
    string borrowedBooks[3];
    int count;
    Member() { count = 0; }
    Member(int id, string n) : User(id, n) { count = 0; }


    // Task 2: add/remove borrowed books
    void addBook(string isbn) {
        if (count < 3) borrowedBooks[count++] = isbn;
    }
    void removeBook(string isbn) {
        for (int i = 0; i < count; i++)
            if (borrowedBooks[i] == isbn) {
                borrowedBooks[i] = borrowedBooks[count - 1];
                count--;
                break;
            }
    }


    void performAction() override {
        cout << "Member " << name << " borrows/returns books\n";
    }
};


// ===== Task 5: Librarian (inherits User) =====
class Librarian : public User {
public:
    Librarian() {}
    Librarian(int id, string n) : User(id, n) {}
    void performAction() override {
        cout << "Librarian " << name << " manages books and members\n";
    }
};


// ===== Task 1 + 2 + 3 + 4 + 5: Library =====
class Library {
public:
    Book books[10];
    int bcount;
    Member members[10];
    int mcount;


    Library() { bcount = mcount = 0; }


    // Task 2: add new books
    void addBook(string t, string a, string isbn) {
        books[bcount++] = Book(t, a, isbn);
    }


    // Task 2: register new members
    void addMember(int id, string n) {
        members[mcount++] = Member(id, n);
    }


    // Task 3: find book by ISBN
    int findBook(string isbn) {
        for (int i = 0; i < bcount; i++)
            if (books[i].getISBN() == isbn) return i;
        throw BookNotFoundException();
    }


    // Task 3: find member by ID
    int findMember(int id) {
        for (int i = 0; i < mcount; i++)
            if (members[i].getID() == id) return i;
        throw MemberNotFoundException();
    }


    // Task 3 + 4: issue book
    void issueBook(string isbn, int id) {
        int bi = findBook(isbn);
        int mi = findMember(id);
        if (!books[bi].getStatus())
            throw BookNotAvailableException();
        books[bi].setStatus(false);
        members[mi].addBook(isbn);
        cout << "Issued " << isbn << " to member " << id << endl;
    }


    // Task 3 + 4: return book
    void returnBook(string isbn, int id) {
        int bi = findBook(isbn);
        int mi = findMember(id);
        books[bi].setStatus(true);
        members[mi].removeBook(isbn);
        cout << "Returned " << isbn << " from member " << id << endl;
    }


    // Task 5: polymorphism example
    void performUserAction(User *u) {
        u->performAction();   // virtual call
    }


    void showBooks() {
        for (int i = 0; i < bcount; i++)
            books[i].print();
    }
};


int main() {
    Library L;


    // add books and members
    L.addBook("C++ Basics", "ABC", "B1");
    L.addBook("OOP", "XYZ", "B2");
    L.addMember(1, "Ram");
    L.addMember(2, "Sita");


    // Users
    Member m(3, "Shyam");
    Librarian lib(100, "Admin");


    // Task 5: polymorphism
    L.performUserAction(&m);
    L.performUserAction(&lib);


    try {
        L.issueBook("B1", 1);   // OK
        L.issueBook("B1", 2);   // will throw BookNotAvailableException
    }
    catch (BookNotFoundException &) {
        cout << "Error: Book not found\n";
    }
    catch (MemberNotFoundException &) {
        cout << "Error: Member not found\n";
    }
    catch (BookNotAvailableException &) {
        cout << "Error: Book not available\n";
    }


    cout << "\nCurrent books:\n";
    L.showBooks();


    try {
        L.returnBook("B1", 1);   // OK
    }
    catch (...) {
        cout << "Error while returning book\n";
    }


    cout << "\nAfter return:\n";
    L.showBooks();


    return 0;
}
