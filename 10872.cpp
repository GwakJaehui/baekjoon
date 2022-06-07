#include <iostream>
using namespace std;

class Factorial
{
private:
	long num;
public:
	Factorial(long n) :num(n)
	{}

	long getResult()
	{
		long result = 1;
		
		for (long i = 2; i <= num; i++)
		{
			result *= i;
		}

		return result;
	}
};

long main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long n;
	cin >> n;
	Factorial f(n);

	cout << f.getResult() << '\n';

	return 0;
}