#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    int arr[100000];
    int cnt;
public:
    Stack() :cnt(0)
    {}
    void push(int n);
    void pop();
    int top();
    bool empty();

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int n,bMax=0;
    string result;
    Stack s;
    bool check;

    cin >> n;

    while (n--)
    {
        int in;
        cin >> in;
        check = false;

        if (bMax < in)
        {
            for (int i = bMax+1; i <= in; i++)
            {
                s.push(i);
                result += '+';
            }
             
            bMax = in;
        }

        while (s.top()>=in)
        {
			s.pop();
			result += '-';
            check = true;
        }

        if (!check)
            break;
    }

    if (check)
    {
        for (int i = 0; i < (int)result.size(); i++)
        {
            cout << result[i] << '\n';
        }
    }
    else
    {
        cout << "NO" << '\n';
    }


    return 0;
}

void Stack::push(int n)
{
    arr[cnt++] = n;
}
void Stack::pop()
{
    if (empty())
        return;
    cnt--;
}
int Stack::top()
{
    if (empty())
        return -1;
    return arr[cnt - 1];
}
bool Stack::empty()
{
    if (cnt <= 0)
        return true;
    return false;
}