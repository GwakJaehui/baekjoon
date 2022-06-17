#include <iostream>
using namespace std;

bool Check(int n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int cnt = 0;

	while (n--)
	{
		int num;
		cin >> num;

		if (Check(num)&&num!=1)
			cnt++;
	}

	cout << cnt << '\n';

	return 0;
}

bool Check(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}