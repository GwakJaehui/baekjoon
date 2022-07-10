#include <iostream>
using namespace std;

long long d[1000001][4];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long mod = 1000000009;

	int t;
	cin >> t;

	d[1][1] = 1;
	d[2][2] = 1;
	d[3][3] = 1;

	while (t--)
	{
		int n;
		cin >> n;

		for (int i = 2; i <= n; i++)
		{
			if (i - 1 > 0)
			{
				d[i][1] = d[i - 1][1] + d[i - 1][2] + d[i - 1][3];
				d[i][1] %= mod;
			}
			if (i - 2 > 0)
			{
				d[i][2] = d[i - 2][1] + d[i - 2][2] + d[i - 2][3];
				d[i][2] %= mod;
			}
			if (i - 3 > 0)
			{
				d[i][3] = d[i - 3][1] + d[i - 3][2] + d[i - 3][3];
				d[i][3] %= mod;
			}
		}
		
		cout << (d[n][1] + d[n][2] + d[n][3]) % mod << '\n';
	}

	return 0;
}

//...+1=n -> d[n][1]=d[n-1][1]+d[n-1][2]+d[n-1][3]
//...+2=n -> d[n][2]=d[n-2][1]+d[n-2][2]+d[n-2][3]
//...+3=n -> d[n][3]=d[n-3][1]+d[n-3][2]+d[n-3][3]