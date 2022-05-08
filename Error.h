#pragma once
#include <exception>
#include <string>

using namespace std;

class Error: 
	public exception
{
private:
	string message;
public:
	Error(const string& s);
	string What() const;
};

