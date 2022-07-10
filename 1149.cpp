#include <iostream>
using namespace std;

int p[1001][4];
int d[1001][4];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 3; j++)
			cin >> p[i][j];
	}

	for (int i = 1; i <= 3; i++)
	{
		d[1][i] = p[1][i];
	}

	for (int i = 2; i <= n; i++)
	{
		d[i][1] = d[i - 1][2] + p[i][1];
		if (d[i][1] > d[i - 1][3] + p[i][1])
			d[i][1] = d[i - 1][3] + p[i][1];


		d[i][2] = d[i - 1][3] + p[i][2];
		if (d[i][2] > d[i - 1][1] + p[i][2])
			d[i][2] = d[i - 1][1] + p[i][2];
		

		d[i][3] = d[i - 1][1] + p[i][3];
		if (d[i][3] > d[i - 1][2] + p[i][3])
			d[i][3] = d[i - 1][2] + p[i][3];
	}

	int min = d[n][1];

	for (int i = 2; i <= 3; i++)
	{
		if (min > d[n][i])
			min = d[n][i];
	}

	cout << min << '\n';

	return 0;
}

//1 = red, 2 = green, 3 = blue
// i-1, i -> d[i][1]= min(d[i-1][2]+p[i][1],d[i-1][3]+p[i][1]) ...