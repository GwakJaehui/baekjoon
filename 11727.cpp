#include <iostream>
using namespace std;

int d[1001];
int getResult(int n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	cout << getResult(n) << '\n';

	return 0;
}

int getResult(int n)
{
	if (n <= 1)
		d[n] = 1;

	if (d[n] != 0)
		return d[n];

	d[n] = (getResult(n - 1) + 2 * getResult(n - 2)) % 10007;
	return d[n];

}