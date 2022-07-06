#include <iostream>
using namespace std;

int a[1001];
int d[1001];
int v[1001]; // a[i]이전 수의 인텍스 번호. 
//ex) 10 20 10 30 50에서 a[i]가 30일때, v[i]는 20을 가리키는 a[i]의 인덱스 번호.

void go(int p);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;


    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int count = 1;

    for (int i = 1; i <= n; i++)
    {
        int max = 0;

        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j] && max < d[j])
            {
				max = d[j]; // 이전 인덱스에서 가장 최대 횟수
				v[i] = j;
            }
        }

        d[i] = max + 1;
    }

    int max = 0;
    int idx = 0;

    for (int i = 1; i <= n; i++)
    {
        if (max < d[i])
        {
            max = d[i];
            idx = i; // 최대 횟수를 갖는 d[i]의 a[i]인덱스
        }
    }
    cout << max << '\n';

    go(idx);

    return 0;
}

void go(int p)
{
    if (p <= 0)
        return;

    go(v[p]); //최대 횟수를 갖는 d[i]의 a[i]의 이전 인덱스로 가기.
    cout << a[p] << ' ';
}