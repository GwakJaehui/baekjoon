#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	getline(cin, str);

	int i = 0;

	if ((int)str.size() % 3 == 1)
	{
		cout << str[i] - '0' * 1;
		i++;
	}
	else if ((int)str.size() % 3 == 2)
	{
		cout << (str[i] - '0') * 2 + (str[i + 1] - '0') * 1;
		i += 2;
	}


	for (; i <(int)str.size(); i += 3)
	{
		cout << (str[i] - '0') * 4 + (str[i + 1] - '0') * 2 + (str[i + 2] - '0') * 1;
	}
	cout << '\n';


	return 0;
}

