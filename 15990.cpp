#include <iostream>
using namespace std;

long long d[100001][4];

long long getResult(int n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	d[1][1] = 1;
	d[2][2] = 1;
	d[3][1] = 1;
	d[3][2] = 1;
	d[3][3] = 1;

	while (t--)
	{
		int n;
		cin >> n;

		cout << getResult(n) << '\n';
	}

	return 0;
}

long long getResult(int n)
{
	long long result = 0;
	
	for (int i = 4; i <= n; i++)
	{
		d[i][1] = (d[i - 1][2] + d[i - 1][3]) % 1000000009;
		d[i][2] = (d[i - 2][1] + d[i - 2][3]) % 1000000009;
		d[i][3] = (d[i - 3][1] + d[i - 3][2]) % 1000000009;
	}

	result = (d[n][1] + d[n][2] + d[n][3])% 1000000009;

	return result;
}