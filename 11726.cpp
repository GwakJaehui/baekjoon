#include <iostream>
using namespace std;

int getResult(int n);
int num[1001] = { 1,1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	cout << getResult(n)<< '\n';

	return 0;
}

int getResult(int n)
{
	for (int i = 2; i <= n; i++)
	{
		num[i] = (num[i - 1] + num[i - 2])%10007;
	}
	
	return num[n];
}