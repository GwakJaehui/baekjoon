#include <iostream>
#include <vector>
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


	for (int i = 1; i <= n; i++)
	{
		int max = 0;

		for (int j = 1; j < i; j++)
		{
			if (a[i] > a[j])
			{
				if (max < d[j])
					max = d[j];
			}
		}
		d[i] = max + 1;
	}

	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		if (max < d[i])
			max = d[i];
	}

	cout << max << '\n';
	//길이가 n일 떄의 i번째 수열의 인자.. -> d[i]=max(d[0~i-1])+1


	return 0;
}