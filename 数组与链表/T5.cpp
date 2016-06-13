#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool searchBin(int s[],int x,int low,int high)
{
    if (low > high)
        return 0;
    else
    {
        int mid = (low + high) / 2;
        if (x > s[mid])
            return searchBin(s,x,mid+1,high);
        else if (x < s[mid])
            return searchBin(s,x,low,mid-1);
        else 
        {
            return 1;
        }

    }
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

        bool ok = searchBin(s,x,0,n);
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
     
    return 0;
}

