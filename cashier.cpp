#include"cashier.h"
#include"bookinfo.h"
#include<iostream>
#include<string>
#include <chrono> 
#include <ctime> 
#include<iomanip>
#include<fstream>
using namespace std;


void cashier(string* bookTitle, string* isbn, string* author, string* publisher, string* dateAdded, int* qtyOnHand, double* wholesale, double* retail)
{


	/*for (int i = 0; i < 4; i++)
	{
		cout << "publisher["<<i<<"] =>"<<publisher[i] <<"  "<< publisher[i].size()<< endl;
		cout << "author[" << i << "]=>" << author[i] << "  " << author[i].size()<<endl;
		cout << "booktitle" << i << "]=>" << bookTitle[i] << "  " << bookTitle[i].size()<< endl;
		cout << "isbn[" << i << "]=>" << isbn[i] << "  " << isbn[i].size() <<endl;
		cout << "date[" << i << "]=>" << dateAdded[i] << "  " << dateAdded[i].size() <<endl;
		cout << "wholesale" << i << "]=>" << *(wholesale + i) << endl;
		cout << "retail[" << i << "]=>" << *(retail + i) << endl;
		cout << "QTY on Hand[" << i << "]=>" << *(qtyOnHand + i) << endl;
	}*/


	cout << "I am in the cashier function" << endl;

	//Vaibles that keep count of the number of items being checked out
	int num = 0, element = 0;
	//Varaible that help me conteol the availability for th equantity asked 
	bool found = false, qty_check = false;;
	//char variable to ask th euser of he want to proceed with another transaction
	char choice;
	//

	int qty[20], qty_asked;
	//why is there a copy of each array. Because the book selected migh be in an unorderly fashion. There fore this copy arrays store the book
	//and other info in a chronological order which is convienet for the for-loop
	double price[20],ws_copy[20], price_4_dispay[20];	
	string date[20], isbn_var[20], title[20], auth[20], pub[20], isbn_search,today_date;
	double  retail_total = 0, tax, total_cost_plus_tax, wholesale_sum = 0;


	cout << "\n\t\t Serendipity Book Sellers\n  \t\t  Cashier Module\n\n";

	do {
	
		cout << " \t\tISBN: ";
		cin.ignore();
		getline(cin, isbn_search);
		//cout << " \t\tTodays Date: ";
		//cin.ignore();
		//getline(cin,today_date);
		cout << " \t\tQuantity needed: ";
		cin >> qty_asked;

		

		for (int i = 0; ((i < 20) && (found != true)); i++)
		{
			if (isbn_search == isbn[i])
			{
				found = true;
				if (qty_asked <= qtyOnHand[i])
				{
					qty_check = true;
					num = i; // helps calculate the retail and total price every iteration
					isbn_var[element] = isbn[i];
					pub[element] = publisher[i];
					auth[element] = author[i];
					title[element] = bookTitle[i];
					date[element] = dateAdded[i];
					ws_copy[element] = wholesale[i];
					qty[element] = qty_asked;
					qtyOnHand[i] -= qty_asked;
					price[element] = retail[i];
					price_4_dispay[element] = (qty_asked * retail[i]);
					element++;
				}
			}
		}
		if (found == false)
			cout << "\n\n\t\tThe item being looked for cannot be found.\n";
		else if (qty_check == false)
			cout << "\n\n\t\tThe demand for the quantity of the item being looked for isnt avaliable.\n";

	
		retail_total += qty_asked * retail[num];
		wholesale_sum += qty_asked * wholesale[num];

		cout << "\n\t\tDo you want to proceed with another transaction?(Y/N)";
		cin >> choice;
		while ((choice != 'Y') && (choice != 'y') && (choice != 'N') && (choice != 'n'))
		{
			cout << "\t\tError! Enter(Y/N). Do you want to proceed with another transaction?(Y/N)";
			cin >> choice;
		}

		found = false;
		qty_check = false;
	} while ((choice == 'Y') || (choice == 'y'));

	tax = 0.06 * retail_total;
	total_cost_plus_tax = retail_total + tax;
	
	auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
	cout << strlen((ctime(&timenow))) << endl;
	string time;
	//for (int i = 0; i < (int)strlen((ctime(&timenow))); i++)
	{
		//xx = *(ctime(&timenow) + i);
		//cout << xx << endl;
		
		//x[i] = xx.c_str();
		//strcat(x, xx.c_str());
		//cout << x << endl;
		//time.at(i) = x;

	}
	

	std::string filename(ctime(&timenow));
	time = filename.substr(0, 3)+" "+ filename.substr(4, 3)+ filename.substr(8, 11)+" "+ filename.substr(20, 4);
//	cout << "time=>"<< time << endl;
//	cout << time.size()<< endl;
	std::cout << "'" << filename << "'\n";
	//filename.pop_back();
	//time.pop_back();
	ofstream outfile(time.substr(0,15).c_str());//ctime(&timenow));
	if (!outfile) {
		std::cerr << "Problem with: " << time.c_str() << '\n';
		return;
	}


	
	cout << "\n\n\t\t\t\t\t Serendipity Book Sellers\n\t\t\t\t\t    Cashier Module" << endl;
	cout << "\n\n\tTime recorded is " << ctime(&timenow) << endl;
	//cout << typeid(time).name() << endl;
	cout << "  _____________________________________________________________________________________________________";

	cout<<"\n\n  Date Added\tQty   ISBN\t      Title  \t\t\t\t\tPrice\t\t Total\n";
	cout << "  _____________________________________________________________________________________________________\n";

	outfile << "Time recorded is " << ctime(&timenow) << endl;
	outfile << "\n\n\t\t\t\t\t Serendipity Book Sellers\n\t\t\t\t\t Cashier Module\n\n  Date Added\tQty   ISBN\t      Title  \t\t\t\t\tPrice\t\t Total\n";
	outfile << "  _____________________________________________________________________________________________________\n";
	
	//calls book info when its over and displays the info of books

	for (int i=0; i < element; i++)
	{
		bookinfo(title, isbn_var, auth, pub, date, qty, price_4_dispay, price, i);
		outfile << "  " << left << setw(14) << dateAdded[i] << setw(6) << qtyOnHand[i] << setw(16) << isbn[i] << setw(30) << bookTitle[i];
		outfile << setprecision(2) << fixed << showpoint;
		outfile << "\t\t" << left << "$" << setw(6) << retail[i] << right << setw(10) << "$" << left << setw(6) << retail_total	<< endl;

	}
	

	cout << "\n\n\t\t  " << left << setw(49) << "\t\tRetail total" << "$" << right << setw(6) << retail_total << endl;
	cout << "\t\t  " << left << setw(49) << "\t\tWholesale total" << "$" << right << setw(6) << wholesale_sum << endl;
	cout << "\t\t" << left << setw(49) << "\t\tTax" << "$" << right << setw(6) << tax << endl;
	cout << "\t\t" << left << setw(49) << "\t\tTotal" << "$" << right << setw(6) << total_cost_plus_tax<< endl;
	cout << "\t\t" << left << setw(49) << "\t\tProfit" << "$" << right << setw(6) << (total_cost_plus_tax)-((wholesale_sum)+(wholesale_sum * 0.06));
	cout<< "\n\n\t\t Thank You for Shopping at Serendipity!\n";

	outfile << "\t\t  " << left << setw(49) << "\t\tWholesale total" << "$" << right << setw(6) << wholesale_sum << endl;
	outfile << "\n\n\t\t  " << left << setw(49) << "\t\tRetail total" << "$" << right << setw(6) << retail_total << endl;
	outfile << "\t\t" << left << setw(49) << "\t\tTax" << "$" << right << setw(6) << tax << endl;
	outfile << "\t\t" << left << setw(49) << "\t\tTotal" << "$" << right << setw(6) << total_cost_plus_tax << endl;
	outfile << "\t\t" << left << setw(49) << "\t\tProfit" << "$" << right << setw(6) << (total_cost_plus_tax)-((wholesale_sum)+(wholesale_sum * 0.06));
	outfile << "\n\n\t\t Thank You for Shopping at Serendipity!\n";

	
	
	outfile.close();
}
