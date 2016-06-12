#include<iostream>  
#include<algorithm>  
#include<memory.h>  
#include<queue>  
using namespace std;  

struct point  
{  
    int x,y;  
    int state;  
    int val;  
}start, temp, other;  

int n1,n2,m1,m2;  
int num[8][8];  
int status[8][8][5];  
int direction[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};  
int cost;  

void BFS()  
{  
    queue<point> que;  
    start.x = n1;  
    start.y = n2;  
    start.state = 1;  
    start.val = 0;  
    que.push(start);  

    while (!que.empty())  
    {  
        temp = que.front();  
        que.pop();  
        if( temp.x == m1 && temp.y == m2)   
        {  
            if(temp.val < cost)  
                cost = temp.val;  
        }  

        for(int i=0; i<4; i++)  
        {  
            int x = temp.x + direction[i][0];  
            int y = temp.y + direction[i][1];  
            if( x>0 && x<=8 && y>0 && y<=8 )  
            {  
                other.x = x;  
                other.y = y;  
                other.val = temp.val + temp.state * num[x-1][y-1];  
                other.state = (temp.state * num[x-1][y-1]) % 4 + 1;   
                if( status[x-1][y-1][other.state] == 0 || other.val < status[x-1][y-1][other.state] )  
                {  
                    status[x-1][y-1][other.state] = other.val;  
                    que.push(other);  
                }  
            }  
        }  
    }  
}  

int main()  
{  
    while( cin>>n1>>n2>>m1>>m2 && n1!=0 && n2!=0 && m1!=0 && m2!=0 )  
    {  
        for( int i=0; i<8; i++)  
            for( int j=0; j<8; j++)  
                cin>>num[i][j];     
        memset(status, 0, sizeof(status));  
        cost = (1 << 30);  
        BFS();  
        cout<<cost<<endl;  
    }  
    return 0;  
}
