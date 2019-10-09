#include"read.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;


void read(string* bookTitle, string* isbn, string* author, string* publisher, string* dateAdded, int* qtyOnHand, double* wholesale, double* retail)
{

	ifstream infile("OG Catalog.txt");
	int num = 0;
	string line,ws,ret,qty;
	if (infile)
	{
		/*This is an alternative method to read in strings
		while(getline(infile,line))
		{	
				split_1st_line(line1);
				int c = line.length();
				dateAdded[num] = line.substr(0, 20);
				cout << dateAdded[num] << endl;
				publisher[num] = line.substr(21, 16);
				cout << publisher[num] << endl;
				author[num] = line.substr(41, 41);
				cout << author[num] << endl;
				num++;
				if (num == 4)
				break;
		}*/
			
		while (getline(infile, line) &&(num<4))
		{
			dateAdded[num] = line;
		//	cout << dateAdded[num] << endl;
			getline(infile, publisher[num]);
		//	cout << publisher[num] << endl;
			getline(infile, author[num]);
		//	cout << author[num] << endl;
			getline(infile, bookTitle[num]);
		//	cout << bookTitle[num] << endl;
			getline(infile, isbn[num]);
		//	cout << isbn[num] << endl;
			//getline(infile, dateAdded[num]);
			
			getline(infile, ws);
			*(wholesale + num) = atof(ws.c_str());
			//infile >> *(wholesale + num);
		//	cout << *(wholesale + num) << endl;
			//infile >> *(retail + num);
			getline(infile, ret);
			*(retail + num) = atof(ret.c_str());
		//	cout << *(retail + num) << endl;
			//infile >> *(qtyOnHand + num);
			getline(infile, qty);
			*(qtyOnHand + num) = atoi(qty.c_str());
		//	cout << *(qtyOnHand + num) << endl;

			num++;
	
		}
	}
	else
		cout << "File not found" << endl;

	infile.close();

}
