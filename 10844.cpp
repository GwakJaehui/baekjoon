#include <iostream>
using namespace std;

long long d[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int mod = 1000000000;

	for (int i = 1; i <= 9; i++)
		d[1][i] = 1;
	
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j - 1 < 0)
			{
				d[i][j] = d[i - 1][j + 1];
			}
			else if (j + 1 > 9)
			{
				d[i][j] = d[i - 1][j - 1];
			}
			else
			{
				d[i][j] = (d[i - 1][j + 1] + d[i - 1][j - 1])%mod;
			}

		}
	}

	long long result = 0;

	for (int i = 0; i <= 9; i++)
	{
		result += d[n][i];
	}
	cout << result % mod << '\n';

	return 0;
}