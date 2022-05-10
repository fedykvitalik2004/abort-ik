#include <iostream>
#include "Time.h"
#include "my_Error.h"

using namespace std;

int main()
{
	bool result;
	int a, b;
	Time h;

	do {
		try {
			result = true;
			cin >> h;
		}
		catch (bad_exception a) {
			result = false;
			cerr << a.what() << endl;
		}
		catch (invalid_argument& b)
		{
			result = false;
			cerr << b.what()<<endl;
		}
		catch (Error* c)
		{
			result = false;
			cerr << c->What() << endl;
			delete c;
		}
		catch (my_Error& a) {
			result = false;
			cerr << a.What() << endl;
		}
	} while (!result);

	cout << "In minutes: " << h.minutes() << endl;
	cout << "\n" << h << "\n";

	try {
		cout << "--h\n" << --h;
		cout << "++h\n" << ++h;
		cout << "h++\n" << h++;
		cout << "h--\n" << h--;
	}
	catch (const char* a) {
		cerr << a << endl;
	}

	return 0;
}