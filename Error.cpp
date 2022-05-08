#include "Error.h"

Error::Error(const string& s)
	:message(s)
{}

string Error::What() const
{
	return message;
}
