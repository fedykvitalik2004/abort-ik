#pragma once
#include <string>

using namespace std;

class my_Error
{
private:
	string message;
public:
	my_Error(const string& s);
	string What() const;
};

