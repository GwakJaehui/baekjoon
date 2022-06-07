#include <iostream>
using namespace std;

class Que
{
private:
	int arr[10000];
	int begin;
	int end;

public:
	Que() :begin(0), end(0)
	{}
	int front();
	int back();
	bool empty();
	int pop();
	void push(int n);
	int size(); 

};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	Que q;

	int i = 1;
	for (; i <= n; i++)
		q.push(i);

	cout << "<";

	i = 1;
	while (!q.empty())
	{
		if (i++ % k != 0)
		{
			q.push(q.front());
			q.pop();
		}
		else
		{
			cout << q.pop();
			if (!q.empty())
				cout << ", ";
		}

	}

	cout << ">" << '\n';
	return 0;
}

int Que::front()
{
	return arr[begin];
}
int Que::back()
{
	return arr[end - 1];
}
bool Que::empty()
{
	if (begin == end)
		return true;
	return false;
}
int Que::pop()
{
	if (empty())
		return -1;
	return arr[begin++];
}
void Que::push(int n)
{
	arr[end++] = n;
}
int Que::size()
{
	return end - begin;
}