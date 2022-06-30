#include <iostream>
using namespace std;

int d[1001];
int p[10001];

int getMin(int n);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> p[i];

    cout << getMin(n) << '\n';

    return 0;
}

int getMin(int n)
{

    for (int i = 1; i <= n; i++)
    {
        int min = 10000001;

        for (int j = 1; j <= i; j++)
        {
            if (min > d[i - j] + p[j])
                min = d[i - j] + p[j];
        }
        d[i] = min;
    }

    return d[n];
}