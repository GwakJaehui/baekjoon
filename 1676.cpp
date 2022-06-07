#include <iostream>
using namespace std;

class Factorial
{
private:
	long result;
	long num;
public:
	Factorial() :result(1),num(0)
	{}

	void getFac(long n)
	{
		for (long i = 2; i <= n; i++)
		{
			result *= i;

			if (i % 5 == 0)
				num++;
			if (i % 25 == 0)
				num++;
			if (i % 125 == 0)
				num++;
		}
	}

	long getResult()const
	{
		return result;
	}

	long getnum() const
	{
		return num;
	}

};


long main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long n;
	cin >> n;

	Factorial f;
	f.getFac(n);

	cout << f.getnum() << '\n';

	return 0;
}