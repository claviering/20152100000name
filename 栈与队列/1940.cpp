#include <cstdio>
#include<iostream>
#include <queue>
using namespace std;
const int N = 85;
char map[N][N][N];   
int l,r,c;
struct Node
{
    int x,y,z;
    int step;
};

int dir[8][4]=
{
    {0,0,1},
    {0,0,-1},
    {0,1,0},
    {0,-1,0},
    {1,0,0},
    {-1,0,0}
};

int Bfs(Node st,Node en)
{
    queue<Node> q;
    Node tmd,tmp;
    q.push(st);
    while(!q.empty())
    {
        tmd=q.front();q.pop();   
        if(tmd.x==en.x && tmd.y==en.y && tmd.z==en.z)
            return tmd.step;
        for(int i=0;i<6;i++)
        {
            tmp.x=tmd.x+dir[i][0];
            tmp.y=tmd.y+dir[i][1];
            tmp.z=tmd.z+dir[i][2];
            tmp.step=tmd.step+1;
            if(map[tmp.x][tmp.y][tmp.z]!='#'&&tmp.x>=0 &&tmp.y>=0 && tmp.z>=0 &&tmp.x<l&&tmp.y<r&&tmp.z<c)
            { 
                q.push(tmp);
                map[tmp.x][tmp.y][tmp.z]='#';

            }
        }
    }
    return -1;
}
int main()
{
    while(~scanf("%d%d%d",&l,&r,&c))
    {
        if(l==0 && r==0 &&c==0)
            break;
        getchar();
        Node st,en;
        for(int i=0;i<l;i++)
        {
            for(int j=0;j<r;j++)
            {
                for(int k=0;k<c;k++)
                {
                    scanf("%c",&map[i][j][k]);
                    if(map[i][j][k]=='S')
                    {
                        st.x=i; st.y=j; st.z=k;st.step=0;
                    }
                    if(map[i][j][k]=='E')
                    {
                        en.x=i,en.y=j,en.z=k;
                    }
                }
                getchar();
            }
            if(i!=l-1)
                getchar();
        }
        int ans = Bfs(st,en);
        if(ans == -1){
            printf("Trapped!\n");
        }else
        {
            printf("Escaped in %d minute(s).\n",ans);
        }
    }
    return 0;
}

