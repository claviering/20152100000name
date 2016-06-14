#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int e;
        int arr[100];
        for (int i = 0; i < 100; i++)
            arr[i] = 0;
        while (cin >> n >> e && n != 0 || e != 0)
        {
            arr[e] += n;
        }

        for (int k = 0; k < 100; k++)
        {
            if (arr[k])
                cout << arr[k] << " " << k << endl;
        }

    }
    return 0;
}

