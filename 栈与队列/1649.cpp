#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
using namespace std;
typedef long long int LL;
const int MAXN =  0x3f3f3f3f;
const int  MINN =  -0x3f3f3f3f;
const double eps = 1e-9;
const int dir[8][2] = {{0,1},{1,0},{0,-1},{-1,0},{-1,1},
  {1,1},{1,-1},{-1,-1}};

typedef struct point{
  int a, b, t;
}point;
point p[220][220], st, en;
char s[220][220];
int n, m, T, si, sj, di, dj; 
queue<point> qt;
void bfs(){
  qt.push(st);
  while (!qt.empty()){
    point po = qt.front();
    qt.pop();
    for (int k = 0; k < 4; ++k){
      int nexti=po.a+dir[k][0],nextj=po.b+dir[k][1];
      if (nexti>=0&&nexti<=n&&nextj>=0&&nextj<=m&&s[nexti][nextj]!='#'){
        int nowt = po.t+1; if(s[nexti][nextj]=='x') nowt++;
        if (nowt<p[nexti][nextj].t){
          p[nexti][nextj].t = nowt;
          qt.push(p[nexti][nextj]);
        }
      }
    }
  }
}
int main(void){
  while (~scanf("%d%d", &n, &m)){
    getchar();
    for (int i = 1; i <= n; ++i){
      for (int j = 1; j <= m; ++j){
        scanf("%c", &s[i][j]);
        if (s[i][j] == 'r') {si = i; sj = j;}
        else if (s[i][j] == 'a') {di = i; dj = j;}
        p[i][j].t = MAXN; p[i][j].a = i; p[i][j].b = j;
      } getchar();
    }
    st.a = si; st.b = sj; st.t = 0;
    bfs();
    if (p[di][dj].t == MAXN){
      printf("Poor ANGEL has to stay in the prison all his life.\n");
    } else printf("%d\n", p[di][dj].t);
  }
 return 0;
}
