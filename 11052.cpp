#include <iostream>
using namespace std;

int p[10001];
int d[1001];
int getMaxPrice(int n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> p[i];

	cout << getMaxPrice(n) << '\n';

	return 0;
}

int getMaxPrice(int n)
{
	int max = -1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (max < d[j] + p[i - j])
			{
				max = d[j] + p[i - j];
			}
		}
		d[i] = max;
	}

	return d[n];
}