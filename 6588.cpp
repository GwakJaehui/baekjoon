#include <iostream>
using namespace std;
#define MAX 1000001

class Gold
{
private:
	long prime[MAX];
public:
	Gold()
	{
		for (long i = 0; i <MAX; i++)
			prime[i] = i;

		for (long i = 2; i < MAX; i++)
		{
			for (long j = i + i; j < MAX; j += i)
				prime[j] = 0;
		}
	}


	void prlongResult(long num)
	{
		long a=-1, b=-1;

		for (long i = 3; i < num; i++)
		{
			if (prime[num - i] != 0 && prime[i]!=0)
			{
				a = i;
				b = prime[num - i];
				break;
			}
		}

		if (a != -1 && b != -1)
			cout << num << " = " << a << " + " << b << '\n';
		else
			cout << "Goldbach's conjecture is wrong." << '\n';
	}

};


long main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long n;
	Gold g;

	while (true)
	{
		cin >> n;
		if (n <= 0)
			break;

		g.prlongResult(n);
	}

	return 0;
}