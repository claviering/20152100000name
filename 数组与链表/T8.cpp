#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        int b;
        cin >> a;
        int arr[1000];

        for (int i = 0; i < 1000; i++)
            arr[i] = 0;

        int index;
        for (int j = 0; j < a; j++)
        {
            cin >> index;
            arr[index] = 1;
        }

        cin >> b;
        for (int j = 0; j < b; j++)
        {
            cin >> index;
            arr[index] = 1;
        }

        int num = 0;
        for (int k = 0; k < 1000; k++)
        {
            if (arr[k])
                num++;
        }

        cout << num << endl;

    }
    return 0;
}

