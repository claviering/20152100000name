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

        int i,j,min;

        for (i = 0; i < n; i++)
        {
            min = i;
            for (j = i + 1; j < n; j++)
            {
                if (a[min] > a[j])
                    min = j;

            }
            swap(a[i],a[min]);
        }

        for (int p = 0; p < n; p++)
            cout << a[p] << " ";
        cout << endl;
    }
     
    return 0;
}

