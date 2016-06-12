#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<iostream>
using namespace std;
struct st
{
 char a[50];
 int pa,pr;
 bool operator < (const st &x)const
 {
 return x.pr<pr;
 }
}ss;
priority_queue<st>q;
int main()
{
 char s[10];
 while(scanf("%s",s)!=EOF)
 {
 if(s[0]=='P')
 {
 scanf("%s%d%d",ss.a,&ss.pa,&ss.pr);
 q.push(ss);
 }
 else
 {
 if(!q.empty())
 {
 st now=q.top();
 q.pop();
 printf("%s %d\n",now.a,now.pa);
 }
 else printf("EMPTY QUEUE!\n");
 }
 }
}
