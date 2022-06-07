#include <iostream>
using namespace std;

long getCnt2(long n);
long getCnt5(long n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long cnt2 = 0, cnt5 = 0;
	long n, m;
	cin >> n >> m;

	cnt2 = getCnt2(n) - (getCnt2(n - m) + getCnt2(m));
	cnt5 = getCnt5(n) - (getCnt5(n - m) + getCnt5(m));

	if (cnt2 <= cnt5)
		cout << cnt2 << '\n';
	else
		cout << cnt5 << '\n';

	return 0;
}

long getCnt2(long n)
{
	long cnt = 0;

	for (long i = 2; i <= n; i *= 2)
	{
		cnt += n / i;
	}

	return cnt;
}

long getCnt5(long n)
{
	long cnt = 0;

	for (long i = 5; i <= n; i *= 5)
	{
		cnt += n / i;
	}

	return cnt;
}