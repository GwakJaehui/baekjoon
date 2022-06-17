#include <iostream>
#include <string>
#include <stack>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string arr;
	getline(cin, arr);

	int cnt = 0;

	stack<int>idx;

	for (int i = 0; i < (int)arr.size(); i++)
	{
		if (arr[i] == '(')
		{
			idx.push(i);
		}
		else if (arr[i] == ')')
		{
			if (i - idx.top() == 1)
			{
				idx.pop();
				cnt += idx.size();
			}
			else
			{
				idx.pop();
				cnt += 1;
			}
		}
	}

	cout << cnt << '\n';

	return 0;
}