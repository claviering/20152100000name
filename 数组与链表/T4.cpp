#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool searchBin(int s[],int x,int n)
{
    int low = 1;
    int high = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (x > s[mid])
            low = mid + 1;
        else if (x < s[mid])
            high = mid - 1;
        else 
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int x;
    int n;
    while (cin >> x >> n)
    {
        vector<int> v;
        int s[n];

        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            v.insert(v.begin(),tmp);
        }
        sort(v.begin(),v.end());

        for (int j = 0; j < n; j++)
            s[j] = v[j];

        bool ok = searchBin(s,x,n);
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
     
    return 0;
}

