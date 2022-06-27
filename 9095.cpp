#include <iostream>
using namespace std;

int sum[15]={0,1,2,4};
int getCase(int n);

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
		cout << getCase(n) << '\n';
	}

	return 0;
}

int getCase(int n)
{
	if (sum[n] != 0)
		return sum[n];

	sum[n] = getCase(n - 1) + getCase(n - 2) + getCase(n - 3);
	return sum[n];
}