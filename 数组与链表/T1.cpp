#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int f0 = 0;
    int f1 = 1;
    int f;
    if (t == 1 || t == 2)
    {
        cout << "1" << endl;
        return 0;
    }
    for (int i = 2; i <= t; i++)
    {
        f = f0 + f1;
        f0 = f1;
        f1 = f;
    }
    cout << f << endl;
    return 0;
}

