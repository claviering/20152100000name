#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
using namespace std;
int c1[10005], c2[10005];

int main()
{
	int n,m;
	int i, j, k,t=0; 
	int value[100],num[100];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(t==0) t=1;
		else cout<<endl;
		for(i=1;i<=m;i++)
		{scanf("%d%d",&value[i],&num[i]);}
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for(i=0; i<=num[1]*value[1]; i+=value[1])
		{
			c1[i] = 1;
		}
		for(i=2; i<=m; i++)
		{
			for(j=0; j<=n; j++)
			for(k=0; k<=value[i]*num[i]; k+=value[i])
			{
				c2[j+k] += c1[j];
			}
			for(j=0; j<=n; j++)
			{
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
		printf("%d\n",c1[n]);
	}
}
