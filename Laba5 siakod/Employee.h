#pragma once
#include <string>
using namespace std;

struct Date {

	unsigned dd;
	unsigned mm;
	unsigned yy;

	bool operator == (const Date& date) const {
		return (dd == date.dd) && (mm == date.mm) && (yy == date.yy);
	};

	Date() {
		dd = 0;
		mm = 0;
		yy = 0;
	}

	Date(unsigned dd, unsigned mm, unsigned yy)
		: dd(dd), mm(mm), yy(yy)
	{
	}
};

struct Employee {
	string prof;
	unsigned period;

	bool operator == (const Employee& emp) const {
		return (prof == emp.prof) && (period == emp.period);
	};

	Employee(){
		prof = "";
		period = 0;
	};

	Employee(const  const string& prof, unsigned period)
		: prof(prof), period(period)
	{
	}	
};