/*
This program simulates an inventory control system for a small library.
It tracks the books, authors, and patrons in the library's system.
It offers the user a command line interface, which sports a menu
that looks like this and provides these options:
********************************************************************************
    Enter one of the following options:
	1. Include a book in the catalog
	2. Check out a book
	3. Return a book
	4. Status
	5. Exit
	Your option?
********************************************************************************

Most of the source code comes from a text book:
Data Structures and Algorithms in C++, by Adam Drozdek, section 3.9
*/
#include <algorithm>
#include <cstring> // added to fix warnings
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Patron;        // forward declaration;

/******************************************************************************
The class below, Book, represents a book in the library.
It has title, patron, quantity, and copiesOut member variables.
It has a member function for printing book data.
It gives some non-class functions and classes access to it's
private member variables.
It defines a constructor and a comparison operator.
******************************************************************************/
class Book {
public:
	Book() {
        quantity = 1;
        copiesOut = 0;
	}
	bool operator== (const Book& bk) const {
		return strcmp(title, bk.title) == 0;
	}
private:
	char *title;
    list<Patron> patrons; // multiple patrons are possible.
    int quantity, copiesOut;
	ostream& printBook(ostream&) const;
	friend ostream& operator<< (ostream& out, const Book& bk) {
		return bk.printBook(out);
	}
	friend class CheckedOutBook;
	friend Patron;
	friend void includeBook();
	friend void checkOutBook();
	friend void returnBook();
};

/******************************************************************************
The class below, Author, represents an author of book(s) in the library.
It has name and books member variables.
It has a member function for printing author data.
It gives some non-class functions and classes access to it's
private member variables.
It defines a comparison operator.
******************************************************************************/
class Author {
public:
	Author() {
	}
	bool operator== (const Author& ar) const {
		return strcmp(name, ar.name) == 0;
	}
private:
	char *name;
	list<Book> books;
	ostream& printAuthor(ostream&) const;
	friend ostream& operator<< (ostream& out, const Author& ar) {
		return ar.printAuthor(out);
	}
	friend void includeBook();
	friend void checkOutBook();
	friend void returnBook();
	friend class CheckedOutBook;
	friend Patron;
};

/******************************************************************************
The class below, CheckedOutBook, represents a book in the library that's not
in the library.
It has author and book member variables.
It gives some non-class functions and a class access to it's
private member variables.
It defines a constructor and a comparison operator.
******************************************************************************/
class CheckedOutBook {
public:
	CheckedOutBook(list<Author>::iterator ar,
		list<Book>::iterator bk) {
		author = ar;
		book = bk;
	}
	bool operator== (const CheckedOutBook& bk) const {
		return strcmp(author->name, bk.author->name) == 0 &&
			strcmp(book->title, bk.book->title) == 0;
	}
private:
	list<Author>::iterator author;
	list<Book>::iterator book;
	friend void checkOutBook();
	friend void returnBook();
	friend Patron;
};

/******************************************************************************
The class below, Patron, represents a library user.
It has name and books member variables.
It gives some non-class functions and a class access to it's
private member variables.
It defines a comparison operator.
******************************************************************************/
class Patron {
public:
	Patron() {
	}
	bool operator== (const Patron& pn) const {
		return strcmp(name, pn.name) == 0;
	}
private:
	char *name;
	list<CheckedOutBook> books;
	ostream& printPatron(ostream&) const;
	friend ostream& operator<< (ostream& out, const Patron& pn) {
		return pn.printPatron(out);
	}
	friend void checkOutBook();
	friend void returnBook();
	friend Book;
};

/******************************************************************************
These globally scoped variables are arrays of lists of Authors and
Patrons in the library system. They're big enough to hold as many pointers as
there are letters in the alphabet, plus whatever comes before the alphabet
on an ASCII table, and a null terminator.
******************************************************************************/
list<Author> catalog['Z' + 1];
list<Patron> people['Z' + 1];

/******************************************************************************
The function below, Author::printAuthor(ostream& out), prints, to the console,
an author's name and their books in the library.
input: a reference to an ostream object: out.
output: a reference to the same ostream object, post modification: out.
******************************************************************************/
ostream& Author::printAuthor(ostream& out) const {
	out << name << endl;
	list<Book>::const_iterator ref = books.begin();
	for (; ref != books.end(); ref++)
		out << *ref; // overloaded <<
	return out;
}

/******************************************************************************
The function below, Book::printBook(ostream& out), prints book data to the
console, including the patron(s) who has it checked out, if its checked out.
input: a reference to an ostream object: out.
output: a reference to a modified version of that ostream object: out.
******************************************************************************/
ostream& Book::printBook(ostream& out) const {
	out << "    * " << title << endl;
    out << "    total copies in circulation: " << quantity << endl;
    out << "    total copies rented out now: " << copiesOut << endl;
    if (!patrons.empty()) {
        list<Patron>::const_iterator pats = patrons.begin();
        for(; pats != patrons.end(); pats++)
            out << " - checked out to " << (*pats).name << endl;
    }
	out << endl;
	return out;
}

/******************************************************************************
The function below, Patron::printPatron(ostream& out), prints patron data to the
console, including the books they have checked out.
input: a reference to an ostream object: out.
output: a reference to a modified version of that ostream object: out.
******************************************************************************/
ostream& Patron::printPatron(ostream& out) const {
	out << name;
	if (!books.empty()) {
		out << " has the following books:\n";
		list<CheckedOutBook>::const_iterator bk = books.begin();
		for (; bk != books.end(); bk++)
			out << "    * " << bk->author->name << ", "
			<< bk->book->title << endl;
	}
	else out << " has no books\n";
	return out;
}

/******************************************************************************
The function below, the overloaded stream insertion operator, prints lists
to the console.
input: a reference to an ostream object: out, and a reference to a list of
objects of the template class.
output: a reference to the modified ostream object: out.
******************************************************************************/
template<class T>
ostream& operator<< (ostream& out, const list<T>& lst) {
	for (
		typename list<T>::const_iterator ref = lst.begin();
		ref != lst.end();
		ref++
	)
		out << *ref; // overloaded <<
	return out;
}

/******************************************************************************
The function below, getString(string msg), receives, formats, and return input
from the console.
input: a string.
output: a char pointer.
******************************************************************************/
char* getString(string msg) {
	char s[82], i, *destin;
	cout << msg;
	cin.get(s, 80);
	while (cin.get(s[81]) && s[81] != '\n');  // discard overflowing
	destin = new char[strlen(s) + 1];           // characters;
	for (i = 0; (destin[i] = toupper(s[i])); i++);
	return destin;
}

/******************************************************************************
The function below, status(), prints all the info library info to the console,
including all the book info and all the patron info.
input: none.
output: none.
******************************************************************************/
void status() {
	int i;
	cout << "Library has the following books:\n\n";
	for (i = 'A'; i <= 'Z'; i++)
		if (!catalog[i].empty())
			cout << catalog[i];
	cout << "\nThe following people are using the library:\n\n";
	for (i = 'A'; i <= 'Z'; i++)
		if (!people[i].empty())
			cout << people[i];
}

/******************************************************************************
The function below, includeBook(), prompts the user for info on a new book,
receives that info, then adds that book to the library's inventory.
input: none.
output: none.
******************************************************************************/
void includeBook() {
	Author newAuthor;
	Book newBook;
	newAuthor.name = getString("Enter author's name: ");
	newBook.title = getString("Enter the title of the book: ");
	list<Author>::iterator oldAuthor =
		find(catalog[newAuthor.name[0]].begin(),
			catalog[newAuthor.name[0]].end(), newAuthor);
	if (oldAuthor == catalog[newAuthor.name[0]].end()) {
		newAuthor.books.push_front(newBook);
		catalog[newAuthor.name[0]].push_front(newAuthor);
	}
	else {
	    list<Book>::iterator bookRef;
	    bookRef = find(
	        (*oldAuthor).books.begin(),
	        (*oldAuthor).books.end(),
	        newBook
	    );
	    // condition checks whether the library already has a copy of that book.
        // if so, the total number of copies is incremented.
	    if (!(bookRef == (*oldAuthor).books.end())) {
          (*bookRef).quantity++;
	    }
	    else {
	        (*oldAuthor).books.push_front(newBook);
	    }
	}
}

/******************************************************************************
The function below, checkOutBook(), receives patron and book info.
Then, it adds the patron to the system, if they weren't there already.
Then, it modifies the book object to point to the patron, and it modifies
the patron object to point to the book.
input: none.
output: none.
******************************************************************************/
void checkOutBook() {
	Patron patron;
	Author author;
	Book book;
	list<Author>::iterator authorRef;
	list<Book>::iterator bookRef;
	bool noWhammies = true; // flag, in case anything goes wrong
	patron.name = getString("Enter patron's name: ");
	author.name = getString("Enter author's name: ");
	authorRef = find(catalog[author.name[0]].begin(),
		catalog[author.name[0]].end(), author);
    // check whether any such author exists in the system
	if (authorRef == catalog[author.name[0]].end()) {
		cout << "We have no books written by " << author.name << endl;
	    noWhammies = false;
	}
	if (noWhammies) { // assuming the author exists
		book.title = getString("Enter the title of the book: ");
		bookRef = find((*authorRef).books.begin(),
			(*authorRef).books.end(), book);
        // checks whether that title exists (for that author)
		if (bookRef == (*authorRef).books.end()) {
			cout << "Misspelled title.\n"
			     << "We have these books by that author: \n"
			     << *authorRef;
		    noWhammies = false;
		}
        // checks whether any copies are left in the library
		else if ((*bookRef).quantity <= (*bookRef).copiesOut) {
		    cout << "All copies of that book are already checked out.\n";
		    cout << (*bookRef);
            noWhammies = false;
		}
	}
	if (noWhammies) { // author, title, and available copies checked out
    	list<Patron>::iterator patronRef;
    	patronRef = find(people[patron.name[0]].begin(),
    		people[patron.name[0]].end(), patron);
    	CheckedOutBook checkedOutBook(authorRef, bookRef);
    	if (patronRef == people[patron.name[0]].end()) { // a new patron
    		patron.books.push_front(checkedOutBook);    // in the library;
    		people[patron.name[0]].push_front(patron);
    		(*bookRef).patrons.push_front(patron);
            (*bookRef).copiesOut++;
    	}
    	else { // must be a pre-existing patron
            CheckedOutBook checkedOutBook(authorRef, bookRef);
            list<CheckedOutBook>::iterator checkedOutChecker;
            checkedOutChecker = find(
                (*patronRef).books.begin(),
                (*patronRef).books.end(),
                checkedOutBook
            );
            // condition ensures patron does not have a copy already
            if (!(checkedOutChecker == (*patronRef).books.end())) {
                cout << "That patron has already checked out a copy of "
                     << "that book.\n";
            }
            else {
                // add that book to the patron's books
        		(*patronRef).books.push_front(checkedOutBook);
                // add that patron to the book's patrons
        		(*bookRef).patrons.push_front(patron);
                // increment the number of copies rented out at the moment
                (*bookRef).copiesOut++;
            }
    	}
	}
}

/******************************************************************************
The function below, returnBook(), gets patron, author, and
book data from the user.
Then, it ensures the patron indeed checked out the book they are returning.
Then, it modifies the book object to indicate that NULL is the patron.
Then, it modifies the patron object by removing the book from their list of
checked out books.
input: none.
output: none.
******************************************************************************/
void returnBook() {
	Patron patron;
	Book book;
	Author author;
	list<Patron>::iterator patronRef;
	list<Book>::iterator bookRef;
	list<Author>::iterator authorRef;
	bool patronExists = true; // flag in case something goes wrong

	patron.name = getString("Enter patron's name: ");
	patronRef = find(people[patron.name[0]].begin(),
		people[patron.name[0]].end(), patron);
    // check for the patron in the system
	if (patronRef == people[patron.name[0]].end()) {
		cout << "Patron's name misspelled.\n"
		     << "They are either a new patron, or you made a typo.\n"
		     << "The following people are using the library:\n";
	    for (int i = 'A'; i <= 'Z'; i++)
		    if (!people[i].empty())
			    cout << people[i];
		patronExists = false;
	}
	if (patronExists) { // the patron is in the system
		author.name = getString("Enter author's name: ");
		authorRef = find(catalog[author.name[0]].begin(),
			catalog[author.name[0]].end(), author);
        // check for the author in the system
		if (authorRef == catalog[author.name[0]].end()) {
			cout << "You either misspelled the author's name, \n"
			     << "or we don't have a book by that author.\n"
			     << "We have these authors: \n";
		    for (int i = 'A'; i <= 'Z'; i++)
		        if (!catalog[i].empty())
			        cout << catalog[i];
		    patronExists = false;
		}
	}
	if (patronExists) { // the patron and author are in the system
		book.title = getString("Enter the title of the book: ");
		bookRef = find((*authorRef).books.begin(),
			(*authorRef).books.end(), book);
        // check for that title under that author
		if (bookRef == (*authorRef).books.end()) {
			cout << "You may have misspelled the title.\n"
			     << "We have these books by that author:\n"
			     << *authorRef;
			patronExists = false;
		}
	}
	if (patronExists) { // patron, author, and title all check out
    	CheckedOutBook checkedOutBook(authorRef, bookRef);
    	list<CheckedOutBook>::iterator checkedOutChecker;
    	checkedOutChecker = find(
    	    (*patronRef).books.begin(),
    	    (*patronRef).books.end(),
    	    checkedOutBook
    	);
    	// condition ensures the patron indeed checked that book out.
    	if (!(checkedOutChecker == (*patronRef).books.end())) {
            // remove that patron from the book's patrons
            (*bookRef).patrons.remove((*patronRef));
            // remove that book from the patron's books
        	(*patronRef).books.remove(checkedOutBook);
            // decrement the number of copies rented out, at the moment
            (*bookRef).copiesOut--;
    	}
    	else {
    	    cout << "That patron does not have that book checked out.\n"
    	         << *patronRef;
    	}
	}
}

/******************************************************************************
The function below, menu(), prints the user's options to the console.
input: none.
output: an int: option, the user's choice, i.e., what they want to do.
******************************************************************************/
int menu() {
	int option;
	cout << "\nEnter one of the following options:\n"
		<< "1. Include a book in the catalog\n2. Check out a book\n"
		<< "3. Return a book\n4. Status\n5. Exit\n"
		<< "Your option? ";
	cin >> option;
	cin.get();         // discard '\n';
	return option;
}

/******************************************************************************
The function below, main(), is the driver program for this console application.
input: none. ARGC and ARGV[] are not used.
output: arbitrarily returns an integer, 0.
******************************************************************************/
int main() {
	while (true)
		switch (menu()) {
		case 1: includeBook();  break;
		case 2: checkOutBook(); break;
		case 3: returnBook();   break;
		case 4: status();       break;
		case 5: return 0;
		default: cout << "Wrong option, try again: ";
		}
	return 0;
}
