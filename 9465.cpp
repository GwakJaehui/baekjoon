#include <iostream>
using namespace std;

int p[3][100001];
int d[100001][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		for (int i = 1; i <= 2; i++)
		{
			for (int j = 1; j <= n; j++)
				cin >> p[i][j];
		}

		d[1][1] = p[1][1];
		d[1][2] = p[2][1];

		for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j <= 2; j++)
			{
				if (j == 0)
				{
					d[i][j] = d[i - 1][j];

					if (d[i][j] < d[i - 1][1])
						d[i][j] = d[i - 1][1];
					
					if (d[i][j] < d[i - 1][2])
						d[i][j] = d[i - 1][2];
				}
				if (j == 1)
				{
					d[i][j] = d[i - 1][0] + p[1][i];

					if (d[i][j] < d[i - 1][2] + p[1][i])
						d[i][j] = d[i - 1][2] + p[1][i];
				}
				if (j == 2)
				{
					d[i][j] = d[i - 1][0] + p[2][i];

					if (d[i][j] < d[i - 1][1] + p[2][i])
						d[i][j] = d[i - 1][1] + p[2][i];
				}
			}
		}

		int max = d[n][0];
		for (int i = 1; i <= 2; i++)
		{
			if (max < d[n][i])
				max = d[n][i];
		}

		cout << max << '\n';
	}

	return 0;
}

// 동물원 문제와 유사하게 해결하면 될 것 같다.
// d[n][0] : n번쨰 열에서 선택하지 않은 경우, d[n][1] : 위쪽을 선택한 경우, d[n][2] : 아래쪽을 선택한 경우.
// d[n][0] = max(d[n-1][0], d[n-1][1], d[n-1][2]) 
// d[n][1] = max(d[n-1][0], d[n-1][2] + p[1][n])
// d[n][2] = max(d[n-1][0], d[n-1][1] + p[2][n])