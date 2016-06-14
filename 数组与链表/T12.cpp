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

        for (int i = 0; i < n; i++)
        {
                cout << arr[i] << " ";
        }
        cout << endl;

    }
    return 0;
}

