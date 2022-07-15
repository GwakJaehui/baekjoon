#include <iostream>
using namespace std;

int a[501][501];
int d[501][501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
			cin >> a[i][j];
	}

	d[1][0] = a[1][0];

	for (int i = 2; i <= n; i++)
	{
		int max = -1;
		for (int j = 0; j < i; j++)
		{
			max = d[i - 1][j] + a[i][j];
			if (j - 1 >= 0)
			{
				if (max < d[i - 1][j - 1] + a[i][j])
					max = d[i - 1][j - 1] + a[i][j];
			}
			d[i][j] = max;
		}
	}

	int max = d[n][0];
	for (int i = 1; i < n; i++)
	{
		if (max < d[n][i])
			max = d[n][i];
	}

	cout << max << '\n';

	return 0;
}

//d[n][left] : n번째 행에서 왼쪽 수를 선택했을 때의 최대값.
//d[n][right] : n번째 행에서 오른쪽 수를 선택했을 때의 최대값.
//d[n][left] = max(d[n-1][left]+a[n][left], d[n-1][1]+a[n][left])
//d[n][right] = max(d[n-1][left]+a[n][right], d[n-1][right]+a[n][right])