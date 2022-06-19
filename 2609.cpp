#include <iostream>
using namespace std;

int getGCD(int a, int b);
int getLCM(int a, int b);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	cin >> a >> b;


	cout << getGCD(a,b) << '\n';
	cout << getLCM(a,b) << '\n';


	return 0;
}

int getGCD(int a,int b)
{

	while (b!=0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int getLCM(int a,int b)
{
	return (a * b) / getGCD(a,b);
}
