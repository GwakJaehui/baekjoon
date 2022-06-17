#include <iostream>
#include <stack>
using namespace std;

int cnt[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int arr[1000001];


	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		cnt[arr[i]]++;
	}

	stack<int>st;
	st.push(0);

	for (int i = 1; i < n; i++)
	{
		/*if (st.empty())
			st.push(i);*/

		while (cnt[arr[st.top()]]<cnt[arr[i]])
		{
			arr[st.top()] = arr[i];
			st.pop();

			if (st.empty())
				break;
		}

		st.push(i);
	}

	while (!st.empty())
	{
		arr[st.top()] = -1;
		st.pop();
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}

	cout << '\n';

	return 0;
}
