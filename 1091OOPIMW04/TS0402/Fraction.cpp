#include "Fraction.h"
#include <vector>


int Gcd(int a, int b)
{
	while (b) b ^= a ^= b ^= a %= b;
	return a;
}

void Fraction::setNumerator(int nu)
{
	numerator = nu;
}

void Fraction::setDenominator(int de)
{
	denominator = de;
}

//numerator = a, denominator = b
void Fraction::getDouble()
{
    int tempn = numerator, tempd = denominator;
    int n = 7;
    if (tempd == 0)
    {
        cout << "Infinite" << endl;
        return;
    }
    if (tempn == 0)
    {
        cout << 0 << endl;
        return;
    }
    if (n <= 0)
    {
        cout << tempn / tempd << endl;
        return;
    }

    if (((tempn > 0) && (tempd < 0)) || ((tempn < 0) && (tempd > 0))) {
        cout << "-";
        tempn = tempn > 0 ? tempn : -tempn;
        tempd = tempd > 0 ? tempd : -tempd;
    }

    //out << tempn << " " << tempd << endl;
    int res = tempn / tempd;
    //cout << res << "this is res" << endl;
    vector<int> dec;
    dec.push_back(res);

    bool noRem = false;

    for (int i = 0; i <= n; i++)
    {
        //cout << tempn << " " << tempd << endl;
        dec.push_back(res);

        tempn = tempn - (tempd * res);
        if (tempn == 0)
        {
            noRem = true;
            break;

        }
        tempn = tempn * 10;
        res = tempn / tempd;
    }

    //cout << "dec size = " << dec.size() << noRem << endl;
    for (int i = 1; i < dec.size(); i++)
    {
        //cout << "i = " << i << endl;
        if (!noRem && i == dec.size() - 2)
            if (dec[i + 1] >= 5 && dec[i + 1] != NULL)
            {
                cout << dec[i] + 1;
                break;
            }
            else
            {
                cout << dec[i];
                break;
            }
        else
            cout << dec[i];

        if (i == 1 && !noRem)
            cout << ".";
    }

    //cout << endl;
    //cout << tempn << " " << tempd << endl;
    cout << endl;
}

void Fraction::outputReducedFraction()
{
	int gcd = Gcd(numerator, denominator);
    //cout << "gcd is " << gcd << endl;
	cout << numerator / gcd;

	if (denominator / gcd != 0 && denominator / gcd != 1)
	{
		cout << "/" << denominator / gcd;
	}

	cout << endl;
}



