#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int a[35];
bool vis[35], flag;

void DFS(int start, int len, int sum)
{
    if(len == 0)
    {
        for(int i = start; i<n && sum>=a[i]; ++i)
        {
            if(sum == a[i])
            {
                flag = true;
                for(int j = 0; j <= i; ++j)
                {
                    if(vis[j])
                    {
                        if(sum == a[j])  
                            printf("%d=%d\n", a[j], a[i]);
                        else
                            printf("%d+", a[j]);
                        sum -= a[j];
                    }
                }
            }
        }
    }
    else
    {
        for(int i = start; i<n; ++i)
        {
            if(sum + a[i] <= a[n-1])
            {
                sum += a[i];
                vis[i] = true;
                --len;
                DFS(i+1, len, sum);
                sum -= a[i];
                vis[i] = false;
                ++len;
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        sort(a, a+n);
        memset(vis, false, sizeof(vis));
        flag = false;
        for(int i = 2; i < n; ++i)
            DFS(0, i, 0);
        if(!flag)
            printf("Can't find any equations.\n\n");
        else
            printf("\n");
    }
    return 0;
}
