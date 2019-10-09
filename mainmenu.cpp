#include<iostream>
#include<string>
#include<fstream>
#include"invmenu.h"
#include"bookinfo.h"
#include"report.h"
#include"read.h"
#include"mainmenu.h"
#include"cashier.h"
using namespace std;


int main()
{
	
	int choice; // choice user inputs 
	
	read(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail);
	//Displays the menu
	do {
		cout << "\n\t\t  Serendipity Booksellers\n\t\t\t Main Menu\n\n\t\t1.Cashier Module\n\t\t2.";
		cout << "Inventory Database Module\n\t\t3.Report Module\n\t\t4.Exit\n\n\t\tEnter your choice:";
		cin >> choice;
		
		
		//validation loop
		while ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4))
		{
			cout << "\n\t\tError! Please enter from the given choice!\n\n";
			cout << "\n\t\t  Serendipity Booksellers\n\t\t\t Main Menu\n\n\t\t1.Cashier Module\n\t\t2.";
			cout << "Inventory Database Module\n\t\t3.Report Module\n\t\t4.Exit\n\n\t\tEnter your choice:";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:cashier(bookTitle,isbn,author,publisher,dateAdded,qtyOnHand,wholesale,retail);
			break;
		case 2:invmenu(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail,20);
			break;
		case 3:report(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail,20);
			break;
		case 4:exit(0);
			break;
		}

	} while (choice != 4);



	return 0;
}