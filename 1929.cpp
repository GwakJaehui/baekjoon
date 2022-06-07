#include <iostream>
#define MAX 1000001
using namespace std;

class getResult
{
private:
	long start, end;
	long prime[MAX];
public:

	getResult():start(2),end(MAX)
	{
		for (long i = start; i <= end; i++)
		{
			prime[i] = i;
		}
	}

	getResult(long n,long m):start(n),end(m)
	{
		for (long i = 2; i <= end; i++)
		{
			prime[i] = i;
		}
	}

	void getPrime() //소수 구하기
	{
		for (long i = 2; i <= end; i++)
		{
			for (long j = 2*i; j <= end; j+=i)
			{
				prime[j] = 0;
			}
		}
	}

	void prlongPrime() //소수 출력
	{
		getPrime();

		for (long i = start; i <= end; i++)
		{
			if (prime[i] != 0)
				cout << prime[i] << '\n';
		}
	}
	
};

long main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long n, m;
	cin >> n >> m;

	getResult result(n, m);
	result.prlongPrime();

	return 0;
}