#include <iostream>
using namespace std;

int a[1001];
int d[1001];

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
		d[i] = a[i]; //a[1]<a[i]라는 보장이 없으므로  초기값이 d[i]=a[1]+a[i]일 수 없다.
		for (int j = 1; j < i; j++)
		{
			if (a[j] < a[i] && d[i] < d[j] + a[i])
			{
				d[i] = d[j] + a[i];
			}
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
//d[i]=a[i]가 포함된 증가 부분 수열의 최대 합.
// 1. 증가하는 부분 수열인가.
// 2. 합이 최대인가. 