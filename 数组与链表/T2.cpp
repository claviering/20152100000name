#include <iostream>
using namespace std;
int main()
{
    int n;
    int p;
    while (cin >> n >> p)
    {
        int c;
        int m = 0;
        int s[100];

        while (n)
        {
            c = n % p;
            n /= p;
            m++;
            s[m] = c;
        }

        for (int i = m; i >= 1; i--)
            cout << s[i];
        cout << endl;
    }
    return 0;
}

