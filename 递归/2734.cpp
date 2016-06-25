#include <stdio.h>  
#include <stdlib.h>  
#include <iostream>  
#include <string.h>  
using namespace std;  
int sum,ways;  
int num[1010];  
int value,n;  
void DFS(int x)  
{  
    if( sum == value )  
    {  
        ways++;  
        return ;  
    }  
    for(int i=x; i<=value; i++)  
    {  
        if( num[i] && sum + i <= value )  
        {  
            num[i]--;  
            sum += i;  
            DFS(i);  
            num[i]++;  
            sum -= i;  
        }  
    }  
}  
int main(void)  
{  
    int x,y;  
    int pe = 0;  
    while( cin >> value >> n )  
    {  
        if( pe )  
            cout << endl;  
        pe = 1;  
        memset(num,0,sizeof(num));  
        sum = ways = 0;  
        for(int i=0; i<n; i++)  
        {  
            cin >> x >> y;  
            num[x] = y;  
        }  
        DFS(1);  
        cout << ways << endl;  
    }  
return 0;  
}
