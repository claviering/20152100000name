#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int s[n];

        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }

        int j;
        for (int k = 1; k < n; k++)
        {
            if (s[k] < s[k-1])
            {
                int tmp = s[k];
                for (j = k - 1; j >= 0 && s[j] > tmp; j--)
                {
                    s[j+1] = s[j];
                }
                s[j+1] = tmp;
            }
        }

        for (int p = 0; p < n; p++)
            cout << s[p] << " ";
        cout << endl;
    }
     
    return 0;
}

