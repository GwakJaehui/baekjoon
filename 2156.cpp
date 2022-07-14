#include <iostream>
using namespace std;

int p[10001];
int d[10001][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> p[i];

	d[1][1] = p[1];

	for (int i = 2; i <= n; i++)
	{
		d[i][0] = d[i - 1][1];
		if (d[i][0] < d[i - 1][0])
			d[i][0] = d[i - 1][0];

		d[i][1] = p[i-1] + d[i - 2][0] + p[i];
		if (d[i][1] < d[i - 1][0] + p[i])
			d[i][1] = d[i - 1][0] + p[i];
	}

	int max = d[n][0];
	if (max < d[n][1])
		max = d[n][1];

	cout << max << '\n';

	return 0;
}

// d[n][0] : n번째가 포함되지 않은 최대값
// d[n][1] : n번째가 포함된 최대값

// d[n][0] = max(d[n-1][1], d[n-1][0])
// d[n][1] = max(d[n-1][0]+p[n], d[n-2][0]+p[n]+p[n-1])