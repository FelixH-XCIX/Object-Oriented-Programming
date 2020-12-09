#include <iostream>
#include <string>
#include <cctype>
using namespace std;

namespace

{

    string username;
    bool isValid()
    {
        if (username.length() == 8)
        {
            for (int i = 0; i < username.length(); i++)
                if (!isalpha(username[i]))
                    return false;
            return true;
       }
        else
            return false;
    }
}



namespace Authenticate
{
    void inputUserName()
    {
        do
        {
            cout << "Enter your username (8 letters only)" << endl;
            cin >> username;
        } while (!isValid());
    }
    string getUserName()
     {
        return username;
    }
}