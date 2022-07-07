//d[i]=max(a[i]+d[i-1], a[i])
//d[i]=i번째 수까지의 연속합의 최대값.

#include <iostream>
using namespace std;

int a[100001];
int d[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	d[1] = a[1];

	for (int i = 2; i <= n; i++)
	{
		if (d[i - 1] + a[i] < a[i])
		{
			d[i] = a[i];
		}
		else
		{
			d[i] = d[i - 1] + a[i];
		}
	}


	int max = d[1];

	for (int i = 2; i <= n; i++)
	{
		if (max < d[i])
			max = d[i];
	}

	cout << max << '\n';

	return 0;
}