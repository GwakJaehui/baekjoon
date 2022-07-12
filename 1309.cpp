#include <iostream>
using namespace std;

int d[100001][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int mod = 9901;
	cin >> n;

	d[1][0] = 1;
	d[1][1] = 1;
	d[1][2] = 1;

	for (int i = 2; i <= n; i++)
	{
		d[i][0] = d[i - 1][0] + d[i - 1][1] + d[i - 1][2];
		d[i][0] %= mod;

		d[i][1] = d[i - 1][0] + d[i - 1][2];
		d[i][1] %= mod;

		d[i][2] = d[i - 1][0] + d[i - 1][1];
		d[i][2] %= mod;
	}

	int result = d[n][0] + d[n][1] + d[n][2];
	result %= mod;
	cout << result << '\n';

	return 0;
}

//d[n][0] : 한 마리도 배치하지 않은 경우, d[n][1] : 왼쪽에 배치한 경우, d[n][2] : 오른쪽에 배치한 경우
//d[n][0]=d[n-1][1]+d[n-1][2]+d[n-1][0], d[n][1]=d[n-1][0]+d[n-1][2], d[n][2]=d[n-1][1]+d[n-1][0]