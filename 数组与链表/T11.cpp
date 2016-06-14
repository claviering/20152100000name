#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        int tmp = n;
        int arr[tmp];
        while (tmp)
        {
            cin >> arr[--tmp];
        }

        int i;
        for (i = 0; i < n; i++)
        {
            if (arr[i] < 0)
                cout << arr[i] << " ";
        }

        for (i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                cout << arr[i] << " ";
        }

        for (i = 0; i < n; i++)
        {
            if (arr[i] > 0)
                cout << arr[i] << " ";
        }
        cout << endl;

    }
    return 0;
}

