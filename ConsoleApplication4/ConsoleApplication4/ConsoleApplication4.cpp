// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "conio.h"
#include "math.h"

using namespace std;
int check(char *s)
{
	ifstream f;
	f.open(s);
	int res = 0;
	if (!f) cout << "Fail ne nayden";
	else
	{
		f.seekg(0, ios::end);
		int n = f.tellg();
		char *str = new char[n + 3];
		f.clear();
		f.seekg(0, ios::beg);
		f.getline(str, n + 1);
		cout << "Ishodniy fail:" << endl;
		cout << str << endl;
		bool tochka = false;
		int n1 = 0;
		int n2 = 0;
		int k = -1;
		for (int i = 0; i <= n; i++)
		{
			if (isdigit(str[i]))
			{
				if (tochka) n2 += str[i] - '0';
				else n1 += str[i] - '0';
				if (k == -1) k = i;
			}
			else
				if (str[i] == '.' || str[i] == ',')
					tochka = true;
				else
				{
					if (k != -1)
						if (n1 != n2)
						{
							if (res == 0) cout << "\nChisla s drobnoy chastyu ne ravnoy celoy:\n";
							res = 1;
							for (int j = k; j<i; j++)
								cout << str[j];
							cout << endl;
						}
					tochka = false;
					k = -1;
					n1 = 0;
					n2 = 0;
				}
		}
		f.close();
	}
	return res;
}


int main()
{
	char s[30];
	cout << "Vvedite imya faila:";
	cin >> s;
	check(s);

	getch();
	return 0;
}
