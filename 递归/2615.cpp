#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>

using namespace std;

#define MAXN 300010
#define MAXM 1000010

int vis[MAXM],n,m,q,father[MAXM];
vector<int>adj[MAXM];
vector<int>que[MAXM];
vector<int>which[MAXM];
int sum[MAXM];

bool ans[MAXM];
int f[MAXM];
stack<int> stack1;

int find(int i)
{
 while (!stack1.empty())
 stack1.pop();
 while (father[i]!=i)
 {
 stack1.push(i);
 i=father[i];
 }
 int resu=i;
 while (!stack1.empty())
 {
 i=stack1.top();
 stack1.pop();
 father[i]=resu;
 }
 return resu;
}

stack<int> stack2;
stack<int> stackj;
void tarjan()
{
 while (!stack2.empty()) stack2.pop();
 while (!stackj.empty()) stackj.pop();
 vis[1] = 1;
 father[1] = 1;
 stack2.push(1);
 stackj.push(0);
 while (!stack2.empty())
 {
 int i=stack2.top();
 int j=stackj.top();
 if (j==adj[i].size())
 {
 stack2.pop();
 stackj.pop();
 if(!stack2.empty())
 father[i]=stack2.top();
 else
 father[i]=i;
 }
 else
 {
 stackj.pop();
 stackj.push(j+1);

 int ite=adj[i][j];
 vis[ite] = 1;
 father[ite] = ite;
 for(int j=0;j<que[ite].size();j++)
 if(vis[que[ite][j]] == 1)
 {
 int temp = find(que[ite][j]);
 if(temp==f[which[ite][j]])
 ans[which[ite][j]]=true;
 else
 ans[which[ite][j]]=false;
 }
 stack2.push(ite);
 stackj.push(0);
 }
 }
}
int getfather(int x)
{
 int l=0, r=n;
 while (l<r)
 {
 int h=(l+r)/2;
 if(x<=sum[h])
 r=h;
 else
 l=h+1;
 }
 return r;
}
int main()
{
 int i,j,k,t;
 int T,cas=0;
 scanf("%d",&T);
 while(T--)
 {
 scanf("%d",&n);
 sum[0]=1;
 for(int i=0;i<=n;i++)
 {
 adj[i].clear();
 que[i].clear();
 which[i].clear();
 }
 memset(father,0,sizeof(father));
 memset(vis,0,sizeof(vis));
 memset(ans,false,sizeof(ans));
 int son=1;
 for(int i=1;i<=n;i++)
 {
 int num;
 scanf("%d",&num);
 sum[i]=sum[i-1]+num;
 while(num-- && son+1<=n)
 {
 son++;
 if(son<=n)
 adj[i].push_back(son);
 }
 }
 scanf("%d",&q);
 for(int i=1;i<=q;i++)
 {
 int u,v;
 scanf("%d%d",&u,&v);
 u++;
 v++;
 if(u==v)
 {
 ans[i]=false;
 continue;
 }
 if(u>n)
 continue;
 if(v>n)
 v=getfather(v);
 if(u==v)
 {
 ans[i]=true;
 continue;
 }

 f[i]=u;
 que[u].push_back(v);
 que[v].push_back(u);
 which[u].push_back(i);
 which[v].push_back(i);
 }
 tarjan();
 printf("Case %d:\n",++cas);
 for(int i=1;i<=q;i++)
 if(ans[i])
 puts("Yes");
 else
 puts("No");
 if(T)
 puts("");
 }
 return 0;
}
