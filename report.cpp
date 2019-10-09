#include"bookinfo.h"
#include"report.h"
#include<iomanip>
#include<iostream>
using namespace std;


void report(string* bookTitle, string* isbn, string* author, string* publisher, string* dateAdded, int* qtyOnHand, double* wholesale, double* retail, int size)

{
	cout << "I am in the reports function" << endl;

	int choice;
	do
	{
		cout << "\n\t\t  Serendipity Booksellers\n\t\t\t Reports\n\n\t\t1.Inventory Listing\n\t\t2.";
		cout << "Inventory Wholesale Value\n\t\t3.Inventory Retail Value \n\t\t4.Listing by Quantity\n\t\t5.";
		cout << "Listing by Cost\n\t\t6.Listing by Age\n\t\t7.Return to Main Menu\n\n\t\tEnter your choice:";
		cin >> choice;
		while ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4) && (choice != 5) && (choice != 6) && (choice != 7))
		{

			cout << "\n\t\tError! Please enter from the given choice!\n\n";
			cout << "\n\t\t  Serendipity Booksellers\n\t\t\t Reports\n\n\t\t1.Inventory Listing\n\t\t2.";
			cout << "Inventory Wholesale Value\n\t\t3.Inventory Retail Value \n\t\t4.Listing by Quantity\n\t\t5.";
			cout << "Listing by Cost\n\t\t6.Listing by Age\n\t\t7.Return to Main Menu\n\n\t\tEnter your choice:";
			cin >> choice;
		}

		switch (choice)
		{
		case 1:repListing(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, 20);
			break;
		case 2:repWholesale(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, 20);
			break;
		case 3:repRetail(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, 20);
			break;
		case 4:repQty(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, 20);
			break;
		case 5: repCost(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, 20);
			break;
		case 6:repAge(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, 20);
			break;
		}

	} while (choice != 7);

}
void repListing(string* bookTitle, string* isbn, string* author, string* publisher, string* dateAdded, int* qtyOnHand, double* wholesale, double* retail, int size)
{
	cout << "This function should display the message “You selected Inventory Listing.\n\n" << endl;
	string book_being_looked_for, temp_title, temp_isbn, temp_auth, temp_pub, temp_date;
	double temp_whole, temp_retail;
	int temp_qty;

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

	cout << "\t\t\t\t\t\t\tSerendipity Book Sellers \n\n\t\t\t\t\t\t\t   Inventory Listing\n";
	cout << "  ________________________________________________________________________________________________________________________________________________";

	cout << " \n\n  Date Added\tQty   ISBN\t      Title  \t\t\t    Author      \t\t  Publisher \t  Retail / Set      Wholesale / Set\n";
	cout << "  ________________________________________________________________________________________________________________________________________________\n";

	for (int i = 0; i < 20; i++)
	{
		if (bookTitle[i].empty())
			continue;
		else
		{
			cout << "  " << left << setw(14) << dateAdded[i] << setw(6) << qtyOnHand[i] << setw(16) << isbn[i] << setw(30) << bookTitle[i] << setw(30) << author[i] << setw(16) << publisher[i];
			cout << setprecision(2) << fixed << showpoint;
			cout << left << "$" << setw(6) << retail[i] << right << setw(10) << "$" << left << setw(6) << wholesale[i] << endl;

		}

	}
}
void repWholesale(string* bookTitle, string* isbn, string* author, string* publisher, string* dateAdded, int* qtyOnHand, double* wholesale, double* retail, int size)
{
	cout << "This function should display the message “You selected Inventory Wholesale Value.”" << endl;

	string book_being_looked_for, temp_title, temp_isbn, temp_auth, temp_pub, temp_date;
	double temp_whole, temp_retail;
	int temp_qty;


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



	cout << "\t\t\t\t\t\t\tSerendipity Book Sellers \n\n\t\t\t\t\t\t\t   Wholesale Value\n";
	cout << "  _________________________________________________________________________________________________________________________________________";

	cout << " \n\n  Date Added\tQty   ISBN\t      Title  \t\t\t     Author      \t\t  Publisher \t  WS / Each      WS / Total\n";
	cout << "  _________________________________________________________________________________________________________________________________________\n";


	double tot = 0;
	for (int i = 0; i < 20; i++)
	{
		if (bookTitle[i].empty())
			continue;
		else
		{
			cout << "  " << left << setw(14) << dateAdded[i] << setw(6) << qtyOnHand[i] << setw(16) << isbn[i] << setw(30) << bookTitle[i] << setw(30) << author[i] << setw(16) << publisher[i];
			cout << setprecision(2) << fixed << showpoint;
			cout << left << "$" << setw(12) << wholesale[i] << right << "$" << left << setw(12) << wholesale[i] * qtyOnHand[i] << endl;
			tot += wholesale[i] * qtyOnHand[i];
		}
	}

	cout << "\n\n\tThe total wholesale of the inventory (the sum of each book\'s wholesale cost multiplied by the quantity on hand) is $" << tot << endl;


}
void repRetail(string* bookTitle, string* isbn, string* author, string* publisher, string* dateAdded, int* qtyOnHand, double* wholesale, double* retail, int size)
{
	cout << "This function should display the message “You selected Inventory Retail Value.”" << endl;

	string book_being_looked_for, temp_title, temp_isbn, temp_auth, temp_pub, temp_date;
	double temp_whole, temp_retail;
	int temp_qty;



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



	cout << "\t\t\t\t\t\t\tSerendipity Book Sellers \n\n\t\t\t\t\t\t\t   Retail Value\n";
	cout << "  _________________________________________________________________________________________________________________________________________";

	cout << " \n\n  Date Added\tQty   ISBN\t      Title  \t\t\t     Author      \t\t  Publisher \t  RP / Each      RP / Total\n";
	cout << "  _________________________________________________________________________________________________________________________________________\n";

	double tot = 0;
	for (int i = 0; i < 20; i++)
	{
		if (bookTitle[i].empty())
			continue;
		else
		{
			cout << "  " << left << setw(14) << dateAdded[i] << setw(6) << qtyOnHand[i] << setw(16) << isbn[i] << setw(30) << bookTitle[i] << setw(30) << author[i] << setw(16) << publisher[i];
			cout << setprecision(2) << fixed << showpoint;
			cout << left << "$" << setw(12) << retail[i] << right << "$" << left << setw(12) << retail[i] * qtyOnHand[i] << endl;
			tot += retail[i] * qtyOnHand[i];
		}
	}

	cout << "\n\n\tThe total retail cost of the inventory (the sum of each book\'s retail cost multiplied by the quantity on hand) is $" << tot << endl;

}
void repQty(string* bookTitle, string* isbn, string* author, string* publisher, string* dateAdded, int* qtyOnHand, double* wholesale, double* retail, int size)
{
	cout << "This function should display the message “You selected Listing By Quantity.”" << endl;

	string book_being_looked_for, temp_title, temp_isbn, temp_auth, temp_pub, temp_date;
	double temp_whole, temp_retail;
	int temp_qty;



	for (int k = 0; k < 19; k++)
	{
		for (int i = 0; i < 19; i++)
		{
			if (qtyOnHand[i] < qtyOnHand[i + 1])
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





	cout << "\t\t\t\t\t\t\t     Serendipity Book Sellers \n\n\t\t\t\t\t\t\t   Desending Order of Quantity on Hand\n";
	cout << "  ________________________________________________________________________________________________________________________________________________";

	cout << " \n\n  Date Added\tQty   ISBN\t      Title  \t\t\t    Author      \t\t  Publisher \t  Retail / Set      Wholesale / Set\n";
	cout << "  ________________________________________________________________________________________________________________________________________________\n";

	for (int i = 0; i < 20; i++)
	{
		if (bookTitle[i].empty())
			continue;
		else
		{
			cout << "  " << left << setw(14) << dateAdded[i] << setw(6) << qtyOnHand[i] << setw(16) << isbn[i] << setw(30) << bookTitle[i] << setw(30) << author[i] << setw(16) << publisher[i];
			cout << setprecision(2) << fixed << showpoint;
			cout << left << "$" << setw(6) << retail[i] << right << setw(10) << "$" << left << setw(6) << wholesale[i] << endl;

		}

	}
}
void repCost(string* bookTitle, string* isbn, string* author, string* publisher, string* dateAdded, int* qtyOnHand, double* wholesale, double* retail, int size)
{
	cout << "This function should display the message “You selected Listing By Cost.”" << endl;



	string book_being_looked_for, temp_title, temp_isbn, temp_auth, temp_pub, temp_date;
	double temp_whole, temp_retail;
	int temp_qty;



	for (int k = 0; k < 19; k++)
	{
		for (int i = 0; i < 19; i++)
		{
			if (wholesale[i] < wholesale[i + 1])
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





	cout << "\t\t\t\t\t\t\t     Serendipity Book Sellers \n\n\t\t\t\t\t\t\t   Desending Order of Wholesale Cost\n";
	cout << "  ________________________________________________________________________________________________________________________________________________";

	cout << " \n\n  Date Added\tQty   ISBN\t      Title  \t\t\t    Author      \t\t  Publisher \t  Retail / Set      Wholesale / Set\n";
	cout << "  ________________________________________________________________________________________________________________________________________________\n";

	for (int i = 0; i < 20; i++)
	{
		if (bookTitle[i].empty())
			continue;
		else
		{
			cout << "  " << left << setw(14) << dateAdded[i] << setw(6) << qtyOnHand[i] << setw(16) << isbn[i] << setw(30) << bookTitle[i] << setw(30) << author[i] << setw(16) << publisher[i];
			cout << setprecision(2) << fixed << showpoint;
			cout << left << "$" << setw(6) << retail[i] << right << setw(10) << "$" << left << setw(6) << wholesale[i] << endl;

		}

	}
}
void repAge(string* bookTitle, string* isbn, string* author, string* publisher, string* dateAdded, int* qtyOnHand, double* wholesale, double* retail, int size)
{
	cout << "This function should display the message “You selected Listing By Age.”" << endl;

	string book_being_looked_for, temp_title, temp_isbn, temp_auth, temp_pub, temp_date;
	double temp_whole, temp_retail;
	int temp_qty;



	for (int k = 0; k < 19; k++)
	{
		for (int i = 0; i < 19; i++)
		{
			if (dateAdded[i] < dateAdded[i + 1])
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





	cout << "\t\t\t\t\t\t\t     Serendipity Book Sellers \n\n\t\t\t\t\t\t\t   Sorted According to the Date Added\n";
	cout << "  ________________________________________________________________________________________________________________________________________________";

	cout << " \n\n  Date Added\tQty   ISBN\t      Title  \t\t\t    Author      \t\t  Publisher \t  Retail / Set      Wholesale / Set\n";
	cout << "  ________________________________________________________________________________________________________________________________________________\n";

	for (int i = 0; i < 20; i++)
	{
		if (bookTitle[i].empty())
			continue;
		else
		{
			cout << "  " << left << setw(14) << dateAdded[i] << setw(6) << qtyOnHand[i] << setw(16) << isbn[i] << setw(30) << bookTitle[i] << setw(30) << author[i] << setw(16) << publisher[i];
			cout << setprecision(2) << fixed << showpoint;
			cout << left << "$" << setw(6) << retail[i] << right << setw(10) << "$" << left << setw(6) << wholesale[i] << endl;

		}

	}
}
