#include <iostream>
#include "HashTable.h"



int main() {
	setlocale(LC_ALL, "Russian");
	HashTable ht(21);

	Employee emp1("09nager", 1);
	Employee emp2("Administrator", 5);
	Employee emp3("0nag9er", 1);
	Employee emp4("18nager", 1);
	cout << endl << ht;
	for (int i = 0; i <= 5; i++) {
		
		ht.AddRecord(emp1);
		emp1.prof[0] += 1;
		emp1.prof[1] -= 1;
		ht.AddRecord(emp3);
		emp3.prof[0] += 1;
		emp3.prof[4] -= 1;

	}

	cout << endl << ht;

	for (int i = 0; i <= 5; i++) {

		ht.DelRecord(emp1);
		emp1.prof[0] -= 2;
		emp1.prof[1] += 2;
		ht.DelRecord(emp3);
		emp3.prof[0] -= 2;
		emp3.prof[4] += 2;

	}

	cout << endl << ht;

	ht.AddRecord(emp4);

	cout << endl << ht;

	if (ht.SearchRec(emp4)) cout << "Yes";
	else cout << "No";

	return 0;

}