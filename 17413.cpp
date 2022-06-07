#include <iostream>
#include <stack>
#include <string>
using namespace std;

void stackPrint(stack <char>&st)
{
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	stack <char> st;
	getline(cin, str);
	str += '\0';

	bool tag = false;

	for (char ch : str)
	{
		if (ch == '<')
		{
			stackPrint(st);

			cout << ch;
			tag = true;
		}
		else if (ch == '>')
		{
			cout << ch;
			tag = false;
		}
		else if (tag)
		{
			cout << ch;
		}
		else
		{
			if (ch == ' ')
			{
				stackPrint(st);
				cout << ch;
			}
			else if (ch == '\0')
			{
				stackPrint(st);
			}
			else
			{
				st.push(ch);
			}
		}
	}



	return 0;
}