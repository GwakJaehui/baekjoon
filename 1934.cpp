#include <iostream>
using namespace std;

class getResult
{
private:
    long x, y;
public:
    getResult() :x(0), y(0)
    {}
    getResult(long a, long b) :x(a), y(b)
    {}

    long getGCD()
    {
        long a = x, b = y;
        while (b != 0)
        {
            long r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    long getLCM()
    {
        return x * y / getGCD();
    }
};

long main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long n;
    cin >> n;

    while (n--)
    {
        long a, b;
        cin >> a >> b;

        getResult result(a, b);

        cout << result.getLCM() << '\n';

    }


    return 0;
}