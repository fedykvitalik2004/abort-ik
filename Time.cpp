#include "Time.h"
#include <iostream>
#include <sstream>

using namespace std;

Time::Time()
{
	first = 0;
	second = 0;
}

Time::Time(int a, int b)
{
	if (a < 0 && (b < 0 || b >= 60))
		throw bad_exception();
	else if (a < 0)
		throw new Error("Quantity of hours cannot be below 0");
	else if (b < 0 || b>=60)
		throw invalid_argument("Quantity of minutes cannot be below 0 or under 60");
	first = a;
	second = b;
}

Time::Time(const Time& r)
{
	first = r.first;
	second = r.second;
}

Time& Time::operator=(const Time& r)
{
	first = r.first;
	second = r.second;

	return *this;
}

Time::operator string() const
{
	stringstream sout;
	sout << "Hours=" << GetFirst() << " and minutes=" << GetSecond() << endl;

	return sout.str();
}

Time& Time::operator++()
{
	++first;
	return*this;
}

Time& Time::operator--()
{
	if (first == 0)
		throw "impossible_action";
	--first;
	return*this;

}

Time Time::operator++(int)
{
	Time a(*this);
	second++;
	if (second == 60)
	{
		first += 1;
		second = 0;
	}

	return a;
}

Time Time::operator--(int)
{
	Time a(*this);
	if (second == 0 && first == 0)
		throw "impossible_action";
	else
	{
		if (second == 0 )
		{
			second--;
			if (second==-1)
			{ 
				first-=1;
				second = 59;
			}
		}
		else second--;
	}
	return a;
}

int Time::minutes() const
{
	return first * 60 + second;
}

ostream& operator<<(ostream& out, const Time& r)
{
	out << string(r);
	return out;
}

istream& operator>>(istream& in, Time& r)
{
	cout << "Input values" << endl;
	cout << "Hours="; in >> r.first;
	cout << "Minutes="; in >> r.second;
	
	if (r.first < 0 && (r.second < 0 || r.second >= 60))
		throw bad_exception();
	else if (r.first < 0)
		throw new Error("Quantity of hours cannot be below 0");
	else if (r.second < 0 || r.second >= 60)
		throw invalid_argument("Quantity of minutes cannot be below 0 or under 60");

	return in;
}

