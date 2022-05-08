#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include "Error.h"
#include <stdexcept>

using namespace std;

class Time
{
private:
	int first, second;   
public:
	Time();                            
	Time(int, int);           
	Time(const Time&);     

	friend ostream& operator << (ostream&, const Time&);                   //usedall
	friend istream& operator >> (istream&, Time&);                  
	Time& operator = (const Time&);                                           
	operator string() const;                                                 

	Time& operator ++();            //used all
	Time& operator --();
	Time operator ++(int);
	Time operator --(int);

	void SetFirst(int value) { first = (value >= 0) ? value : 0; };                        //used all      
	void SetSecond(int value) { second = (value >= 0 && value < 60) ? value : 0; }                  
	int GetFirst() const { return first; };                                             
	int GetSecond() const { return second; };                                           

	int minutes() const;                                          //used              
};

