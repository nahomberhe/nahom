#include"invmenu.h"
#include"bookinfo.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<cstring>
using namespace std;


void invmenu(string *bookTitle, string* isbn, string* author, string* publisher, string* dateAdded, int* qtyOnHand, double* wholesale, double* retail, int size)
{
	int choice;
	do
	{
		cout << "\n\t\t  Serendipity Booksellers\n\t\t    Inventory Database\n\n\t\t1.Look Up a Book\n\t\t2.";
		cout << "Add a Book\n\t\t3.Edit a Book's Record\n\t\t4.Delete a Book\n\t\t5.Return to the Main Menu\n\n\t\tEnter your choice:";

		cin >> choice;
		while ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4) && (choice != 5))
		{
			cout << "\n\t\tError! Please enter from the given choice!\n\n";
			cout << "\n\t\t  Serendipity Booksellers\n\t\t    Inventory Database\n\n\t\t1.Look Up a Book\n\t\t2.";
			cout << "Add a Book\n\t\t3.Edit a Book's Record\n\t\t4.Delete a Book\n\t\t5.Return to the Main Menu\n\n\t\tEnter your choice:";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:lookUpBook(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, 20);
			break;
		case 2:addBook(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, 20);
			break;
		case 3:editBook(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, 20);
			break;
		case 4:deleteBook(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, 20);
			break;
		}


	} while (choice != 5);
}
void lookUpBook(string* bookTitle, string* isbn, string* author, string* publisher, string* dateAdded, int* qtyOnHand, double* wholesale, double* retail, int size)
{
	string book_being_looked_for, temp_title = "", temp_isbn = "", temp_auth = "", temp_pub = "", temp_date = "";
	double  temp_whole = 0, temp_retail = 0;
	int temp_qty = 0;
	cout << "\n\t\tWhat book are you looking for?";
	cin.ignore();
	getline(cin, book_being_looked_for);



	for (int k = 0; k < 19; k++)
	{
		for (int i = 0; i < 19; i++)
		{
			if (bookTitle[i] > bookTitle[i + 1])
			{
				temp_title = bookTitle[i];
				temp_isbn = isbn[i];
				temp_auth = author[i];
				temp_pub = publisher[i];
				temp_date = dateAdded[i];
				temp_qty = qtyOnHand[i];
				temp_whole = wholesale[i];
				temp_retail = retail[i];
				bookTitle[i] = bookTitle[i + 1];
				publisher[i] = publisher[i + 1];
				author[i] = author[i + 1];
				isbn[i] = isbn[i + 1];
				dateAdded[i] = dateAdded[i + 1];
				qtyOnHand[i] = qtyOnHand[i + 1];
				wholesale[i] = wholesale[i + 1];
				retail[i] = retail[i + 1];
				bookTitle[i + 1] = temp_title;
				publisher[i + 1] = temp_pub;
				author[i + 1] = temp_auth;
				isbn[i + 1] = temp_isbn;
				dateAdded[i + 1] = temp_date;
				qtyOnHand[i + 1] = temp_qty;
				wholesale[i + 1] = temp_whole;
				retail[i + 1] = temp_retail;
			}
		}
	}

	for (int i = 0; i < 20; i++)
	{
		cout << i << "=> " << bookTitle[i] << endl;
		cout << "booktitle=> " << bookTitle[i] << endl;
		cout << "publishers=> " << publisher[i] << endl;
		cout << "authors=> " << author[i] << endl;
		cout << "isbn=> " << isbn[i] << endl;
		cout << "dateadded=> " << dateAdded[i] << endl;
		cout << "qtyonhand=> " << qtyOnHand[i] << endl;
		cout << "wholesale=> " << wholesale[i] << endl;
		cout << "retail=> " << retail[i] << endl;
	}


	for (int first = 0, middle, last = 20; first <= (last - 1); first++)
	{
		middle = (last + first) / 2;
		if (bookTitle[middle] == book_being_looked_for)
			return bookinfo(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, retail, wholesale, middle);
		else if (bookTitle[middle] > book_being_looked_for)
			last = middle - 1;
		else if (bookTitle[middle] < book_being_looked_for)
			first = middle + 1;
	}

}
void addBook(string* bookTitle, string* isbn, string* author, string* publisher, string* dateAdded, int* qtyOnHand, double* wholesale, double* retail, int size)
{
	string book_being_looked_for, temp_title = "", temp_isbn = "", temp_auth = "", temp_pub = "", temp_date = "";
	double  temp_whole = 0, temp_retail = 0;
	int temp_qty = 0;
	int qty;
	double price, subtotal, total, tax;
	string date, isbn_var, title, auth, pub;
	char choice = 'Y';
	//bool stub = false; //lets me know if there were any books enter or if the array was full
	bool found = false;
	//cout << "This function should display the message,“You selected Add Book." << endl;


	do
	{

		for (int i = 0; ((i < 20) && (found == false)); i++)
		{
			if (bookTitle[i].empty())
			{
				cout << "In the if loop!" << i << " element was found to be empty" << endl;
				cout << " \t\tDate the book was added to Inventory(Format MM/DD/YY):";
				cin.ignore();
				getline(cin, date);
				cout << " \t\tQuantity of Books: ";
				cin >> qty;
				cin.ignore();		// The cin.ignore function tells the cin object to skip one or more characters in the keyboard buffer.
				cout << " \t\tISBN: ";
				getline(cin, isbn_var);
				cout << " \t\tAuthor Name: ";
				getline(cin, auth);
				cout << " \t\tPublisher Name: ";
				getline(cin, pub);
				cout << " \t\tBook Title: ";
				getline(cin, title);
				cout << " \t\tRetail Price: ";
				cin >> price;

				subtotal = qty * price;
				tax = 0.06 * subtotal;
				total = subtotal + tax;


				/*cout << "\n\n\t\t\t\t Serendipity Book Sellers\n\n \t\tDate:" << date << "\n\n\t\tQty  ISBN\t  Title  \t\t\t\t\t Price\t\t Total\n";
				cout << " \t\t______________________________________________________________________________________\n ";
				cout << "\t\t" << left << setw(4) << qty << setw(14) << isbn_var << setw(30) << title;
				cout << setprecision(2) << fixed << showpoint;
				cout << "\t\t" << left << "$" << setw(6) << price << right << setw(10) << "$" << left << setw(6) << subtotal << endl;
				cout << "\n\n\t\t  " << left << setw(52) << "\t\tSubtotal" << "$" << right << setw(6) << subtotal << endl;
				cout << "\t\t" << left << setw(50) << "\t\tTax" << "$" << right << setw(6) << tax << endl;
				cout << "\t\t" << left << setw(50) << "\t\tTotal" << "$" << right << setw(6) << total << "\n\n\t\t Thank You for Shopping at Serendipity!\n";

				cout << "\t\tDo you want to proceed with another transaction?(Y/N)";
				cin >> choice;
				while ((choice != 'Y') && (choice != 'y') && (choice != 'N') && (choice != 'n'))
				{
					cout << "\t\tError! Enter(Y/N). Do you want to proceed with another transaction?(Y/N)";
					cin >> choice;
				}*/

				publisher[i] = pub;
				author[i] = auth;
				bookTitle[i] = title;
				isbn[i] = isbn_var;
				dateAdded[i] = date;
				qtyOnHand[i] = qty;
				wholesale[i] = price;
				retail[i] = total;
				//stub++;
				bookTitle[i] = title;
				found = true;
			}

			// cout << "Out of the if loop at element " << i << endl;
			// if (stub>0)
			//	break;
		}
		//if (stub == 0)
		//cout << "\n\t\tArray is full.More books cannot be added to the inventory." << endl;

		//cout << "\t\tDo you want to add another book?(Y/N)";
		//cin >> choice;

		cout << "\t\tDo you want to add another book?(Y/N)";
		cin >> choice;
		while ((choice != 'Y') && (choice != 'y') && (choice != 'N') && (choice != 'n'))
		{
			cout << "\t\tError! Enter(Y/N). Do you want to add another book?(Y/N)";
			cin >> choice;
		}

		for (int i = 0; i < 20; i++)
			cout << i << "=> " << bookTitle[i] << endl;
		found = false;

	} while ((choice == 'Y') || (choice == 'y'));

	for (int k = 0; k < 19; k++)
	{
		for (int i = 0; i < 19; i++)
		{
			if (bookTitle[i] > bookTitle[i + 1])
			{
				temp_title = bookTitle[i];
				temp_isbn = isbn[i];
				temp_auth = author[i];
				temp_pub = publisher[i];
				temp_date = dateAdded[i];
				temp_qty = qtyOnHand[i];
				temp_whole = wholesale[i];
				temp_retail = retail[i];
				bookTitle[i] = bookTitle[i + 1];
				publisher[i] = publisher[i + 1];
				author[i] = author[i + 1];
				isbn[i] = isbn[i + 1];
				dateAdded[i] = dateAdded[i + 1];
				qtyOnHand[i] = qtyOnHand[i + 1];
				wholesale[i] = wholesale[i + 1];
				retail[i] = retail[i + 1];
				bookTitle[i + 1] = temp_title;
				publisher[i + 1] = temp_pub;
				author[i + 1] = temp_auth;
				isbn[i + 1] = temp_isbn;
				dateAdded[i + 1] = temp_date;
				qtyOnHand[i + 1] = temp_qty;
				wholesale[i + 1] = temp_whole;
				retail[i + 1] = temp_retail;
			}
		}
	}


}
void editBook(string* bookTitle, string* isbn, string* author, string* publisher, string* dateAdded, int* qtyOnHand, double* wholesale, double* retail, int size)
{
	cout << "This function should display the message “You selected Edit Book.”" << endl;


	int qty;
	double price, subtotal, total, tax;
	string date, isbn_var, title, auth, pub;
	char choice;
	string book_being_looked_for;
	cout << "\n\t\tWhat is the book you are looking to edit?";
	cin.ignore();
	getline(cin, book_being_looked_for);


	cout << "Book being edited : " << book_being_looked_for << endl;
	bool stub = false;//checks if the book is found in inventory

	for (int i = 0; i < 20; i++)
		cout << i << "=> " << bookTitle[i] << endl;


	for (int i = 0; (i < 20); i++)
	{

		if (book_being_looked_for == bookTitle[i])
		{
			bookinfo(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, retail, wholesale, i);
			cout << "\n\n\t\tAlter the fields you would like to change\n";

			cout << " \t\tDate the book was added to Inventory(Format MM/DD/YY):";
			cin.ignore();
			getline(cin, date);
			cout << " \t\tQuantity of Books: ";
			cin >> qty;
			cin.ignore();		// The cin.ignore function tells the cin object to skip one or more characters in the keyboard buffer.
			cout << " \t\tISBN: ";
			getline(cin, isbn_var);
			cout << " \t\tAuthor Name: ";
			getline(cin, auth);
			cout << " \t\tPublisher Name: ";
			getline(cin, pub);
			cout << " \t\tBook Title: ";
			getline(cin, title);
			cout << " \t\tRetail Price: ";
			cin >> price;

			subtotal = qty * price;
			tax = 0.06 * subtotal;
			total = subtotal + tax;

			publisher[i] = pub;
			author[i] = auth;
			bookTitle[i] = title;
			isbn[i] = isbn_var;
			dateAdded[i] = date;
			qtyOnHand[i] = qty;
			wholesale[i] = price;
			retail[i] = total;
			stub = true;
			bookTitle[i] = title;

		}
		if ((i == 19) && (stub == false))
			cout << "\n\t\t The book isnt present in the inventory. Try looking for another book." << endl;

	}
	stub = false;

	cout << "\t\tDo you want to edit another book?(Y/N)";
	cin >> choice;
	if ((choice == 'Y') || (choice == 'y'))
		editBook(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, 20);

	while ((choice != 'Y') && (choice != 'y') && (choice != 'N') && (choice != 'n'))
	{
		cout << "\t\tError! Enter(Y/N). Do you want to add another book?(Y/N)";
		cin >> choice;
		if ((choice == 'Y') || (choice == 'y'))
			editBook(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, 20);
	}
}
void deleteBook(string* bookTitle, string* isbn, string* author, string* publisher, string* dateAdded, int* qtyOnHand, double* wholesale, double* retail, int size)
{
	cout << "This function should display the message “You selected Delete Book.”" << endl;

	//string book_being_looked_for, temp_title = "", temp_isbn = "", temp_auth = "", temp_pub = "", temp_date = "";
	//double  temp_whole = 0, temp_retail = 0;
	//int temp_qty = 0;

	char choice;
	string book_being_looked_for;
	cout << "\n\t\tEnter the book title you are looking to delete?";
	cin.ignore();
	getline(cin, book_being_looked_for);


	cout << "Book being deleted : " << book_being_looked_for << endl;
	bool stub = false;//checks if the book is found in inventory

	for (int i = 0; i < size; i++)
		cout << i << "=> " << bookTitle[i] << endl;


	for (int i = 0; (i < size); i++)
	{

		if (book_being_looked_for == bookTitle[i])
		{
			//bookinfo(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, retail, wholesale, i);

			/*temp_title = bookTitle[size - 1];
			temp_isbn = isbn[size - 1];
			temp_auth = author[size - 1];
			temp_pub = publisher[size - 1];
			temp_date = dateAdded[size - 1];
			temp_qty = qtyOnHand[size - 1];
			temp_whole = wholesale[size - 1];
			temp_retail = retail[size - 1];
			bookTitle[size - 1] = bookTitle[i];
			publisher[size - 1] = publisher[i];
			author[size - 1] = author[i];
			isbn[size - 1] = isbn[i];
			dateAdded[size - 1] = dateAdded[i];
			qtyOnHand[size - 1] = qtyOnHand[i];
			wholesale[size - 1] = wholesale[i];
			retail[size - 1] = retail[i];
			bookTitle[i] = temp_title;
			publisher[i] = temp_pub;
			author[i] = temp_auth;
			isbn[i] = temp_isbn;
			dateAdded[i] = temp_date;
			qtyOnHand[i] = temp_qty;
			wholesale[i] = temp_whole;
			retail[i] = temp_retail;*/


			bookTitle[i] = bookTitle[i].empty();
			publisher[i] = publisher[i].empty();
			author[i] = author[i].empty();
			bookTitle[i] = bookTitle[i].empty();
			isbn[i] = isbn[i].empty();
			dateAdded[i] = dateAdded[i].empty();
			
			qtyOnHand[i] = to_string(qtyOnHand[i]).empty();
			wholesale[i] = to_string(wholesale[i]).empty();
			retail[i] = to_string(retail[i]).empty();
			stub = true;


		}
		if ((i == 19) && (stub == false))
			cout << "\n\t\t The book isnt present in the inventory. Try looking for another book." << endl;

	}
	//if (stub == 0)
	stub = false;
	cout << "\t\tDo you want to delete another book?(Y/N)";
	cin >> choice;
	if ((choice == 'Y') || (choice == 'y'))
		deleteBook(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, 20);

	while ((choice != 'Y') && (choice != 'y') && (choice != 'N') && (choice != 'n'))
	{
		cout << "\t\tError! Enter(Y/N).Do you want to delete another book?(Y/N)";
		cin >> choice;
		if ((choice == 'Y') || (choice == 'y'))
			deleteBook(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, 20);
	}
}