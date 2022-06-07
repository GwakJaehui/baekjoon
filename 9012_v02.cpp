#include <iostream>
#include <string>
using namespace std;

class strStack
{
private:
	char bracket[60];
	int cnt;

public:
	strStack() :cnt(0)
	{}

	void push(char ch);
	void pop();
	char top();
	bool empty();
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int num;

	cin >> num;
	cin.ignore();

	while (num--)
	{
		strStack stack;
		string str;
		bool check = true;

		getline(cin, str);

		for (int i = 0; i < (int)str.size(); i++)
		{
			if (str[i] == '(')
			{
				stack.push(str[i]);
			}
			else if (str[i] == ')')
			{
				if (stack.empty())
				{
					check = false;
					break;
				}
				stack.pop();
			}
		}

		if (check==false||!stack.empty())
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';

	}


	return 0;
}

void strStack::push(char ch)
{
	bracket[cnt++] = ch;
}
void strStack::pop()
{
	if (empty())
		return;

	bracket[--cnt] = '\0';
}
char strStack::top()
{
	return bracket[cnt - 1];
}
bool strStack::empty()
{
	if (cnt != 0)
		return false;
	return true;
}