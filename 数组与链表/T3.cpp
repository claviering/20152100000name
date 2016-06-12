#include <iostream>
using namespace std;
int main()
{
    int n;
    int m;
    while (cin >> n >> m)
    {
        int tmp = m;
        int arr[m];
        int ok = 1;
        while (tmp--)
        {
            cin >> arr[tmp];
        }

        for (int i = 0; i < m; i++)
        {
            if (n == arr[i])
            {
                cout << "YES" << endl;
                ok = 0;
                break;
            }
        }
        if (ok)
            cout << "NO" << endl;

    }
    return 0;
}

