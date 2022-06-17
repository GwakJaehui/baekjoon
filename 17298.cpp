#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int arr[1000000];
	stack<int>idx;
	stack<int>result;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	idx.push(0);

	for (int i = 1; i < n; i++)
	{
		while (arr[idx.top()] < arr[i])
		{
			arr[idx.top()] = arr[i];
			idx.pop();

			if (idx.empty())
				break;
		}
		idx.push(i);
	}


	while (!idx.empty())
	{
		arr[idx.top()] = -1;
		idx.pop();
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}