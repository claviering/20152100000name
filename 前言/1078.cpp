#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    while (cin >> n && n > 0)
    {
        int ans[16];
        int index = 0;
        for (int basis = 2; basis <= 16; basis++)
        {
            vector<int> tran;
            int other = n;
            while (other > 0)
            {
                int tmp = other % basis;
                tran.insert (tran.begin(),tmp);
                other /= basis;
            }
            int len = tran.size() - 1;
            int ok = 1;
            for (int i = 0; i <= len / 2; i++)
            {
                if (tran[i] != tran[len - i])
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
            {
                ans[index] = basis;
                index++;
            }
        }
        if (index > 0)
        {
            cout << "Number " << n << " is palindrom in basis";
            for (int p = 0; p < index; p++)
                cout << " " << ans[p];
            cout << endl;
        }
        else
        {
            cout << "Number " << n << " is not a palindrom";
            cout << endl;
        }
    }
    return 0;
}

