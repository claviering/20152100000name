#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int i,j;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n - i - 1; j++)
            {
                if (a[j] > a[j + 1])
                    swap(a[j],a[j + 1]);

            }
        }

        for (int p = 0; p < n; p++)
            cout << a[p] << " ";
        cout << endl;
    }
     
    return 0;
}

