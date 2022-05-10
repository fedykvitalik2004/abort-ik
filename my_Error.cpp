#include "my_Error.h"

my_Error::my_Error(const string& s)
	:message(s)
{}

string my_Error::What() const
{
	return message;
}
