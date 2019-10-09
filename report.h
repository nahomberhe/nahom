#ifndef REPORT_H
#define REPORT_H
#include<string>
using namespace std;

void repListing(string* bookTitle, string* isbn, string* author, string* publisher, string* dateAdded, int* qtyOnHand, double* wholesale, double* retail, int size);
void repWholesale(string* bookTitle, string* isbn, string* author, string* publisher, string* dateAdded, int* qtyOnHand, double* wholesale, double* retail, int size);
void repRetail(string* bookTitle, string* isbn, string* author, string* publisher, string* dateAdded, int* qtyOnHand, double* wholesale, double* retail, int size);
void repQty(string* bookTitle, string* isbn, string* author, string* publisher, string* dateAdded, int* qtyOnHand, double* wholesale, double* retail, int size);
void repCost(string* bookTitle, string* isbn, string* author, string* publisher, string* dateAdded, int* qtyOnHand, double* wholesale, double* retail, int size);
void repAge(string* bookTitle, string* isbn, string* author, string* publisher, string* dateAdded, int* qtyOnHand, double* wholesale, double* retail, int size);
void report(string* bookTitle, string* isbn, string* author, string* publisher, string* dateAdded, int* qtyOnHand, double* wholesale, double* retail, int size);

#endif