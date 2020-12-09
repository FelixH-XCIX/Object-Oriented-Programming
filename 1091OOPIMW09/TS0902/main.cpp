#include <iostream>
#include "Password.h"
#include "User.h"

using namespace std;
using namespace Authenticate;

int main()
{
	//let user input username
	inputUserName();

	//let user input password
	inputPassword();

	//output user's username and password
	cout << "Your username is " << getUserName() <<
		" and your password is: " <<
		getPassword() << endl;

	return 0;
}
