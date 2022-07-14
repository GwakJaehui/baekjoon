#include <iostream>
using namespace std;

long long d[1001][10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int mod = 10007;

	for (int i = 0; i <= 9; i++)
		d[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				d[i][j] += d[i - 1][k];
			}
			d[i][j] %= mod;
		}
	}

	long long result = d[n][0];
	for (int i = 1; i <= 9; i++)
	{
		result += d[n][i];
	}

	result %= mod;
	cout << result << '\n';

	return 0;
}

//.... i -> i, i+1,... 
//d[n][i]=d[n-1][i]+d[n-1][i-1]+....d[n-1][0] 
//n자리수에서 n번째 자리수가 i인 경우 