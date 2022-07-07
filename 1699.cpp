#include <iostream>
using namespace std;

int d[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	d[1] = 1;

	for (int i = 2; i <= n; i++)
	{	
		int min = 100001;
	
		for (int j = 1; j*j <= i; j++)
		{
			if (min > d[i - (j * j)] + 1)
			{
				d[i] = d[i - (j * j)] + 1;
				min = d[i];
			}
		}
	}

	cout << d[n] << '\n';

	return 0;
}