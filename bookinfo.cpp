#include"bookinfo.h"

#include<fstream>
#include<iomanip>
#include<iostream>
using namespace std;

void bookinfo(string* bookTitle, string* isbn, string* author, string* publisher, string* dateAdded, int* qtyOnHand, double* wholesale, double* retail,int i)
{
		cout << "  " << left << setw(14) << dateAdded[i] << setw(6) << qtyOnHand[i] << setw(16) << isbn[i] << setw(30) << bookTitle[i];
		cout << setprecision(2) << fixed << showpoint;
		cout << "\t\t" << left << "$" << setw(6) << retail[i] << right << setw(10) << "$" << left << setw(6) << wholesale[i] << endl;
		


}