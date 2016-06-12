#include<stdio.h>
#include<iostream>
#include<limits.h>
#include<algorithm>
#include<string.h>
#define MAX 1010
using namespace std;
int d[MAX];
int g[MAX];
int main()
{
    int t,n,x,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans=0;
        for(i=1;i<=n;i++)g[i]=INT_MAX;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            int k=lower_bound(g+1,g+n+1,x)-g;
            d[i]=k;
            g[k]=x;
            ans=max(ans,k);
        }
        printf("%d\n",ans);
        if(t)
        	printf("\n");
    }
}
