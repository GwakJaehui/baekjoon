#include <iostream>
#include <string>
using namespace std;

int result[3];
int cnt = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string o;
	getline(cin, o);

	int tmp = o[0] - '0';
	while (tmp / 2 != 0)
	{
		result[cnt++] = tmp % 2;
		tmp /= 2;
	}
	result[cnt++] = tmp % 2;
	
	for (int i = cnt - 1; i >= 0; i--)
	{
		cout << result[i];
	}


	for (int i = 1; i < (int)o.size(); i++)
	{
		cnt = 0;
		for (int j = 0; j < 3; j++)
			result[j] = 0;

		tmp = o[i] - '0';

		while (tmp / 2 != 0)
		{
			result[cnt++] = tmp % 2;
			tmp /= 2;
		}
		result[cnt++] = tmp % 2;

		for (int j = 2; j >= 0; j--)
			cout << result[j];

	}
		

	return 0;
}