#include <stdio.h>  
#include <stdlib.h>  
#include <iostream>  
#include <string.h>  
using namespace std;  
int fb[500][105];  
int len[500],x,nn,bb;  
int find(int s[],int n)  
{  
    int k;  
    for(int i=1; i<=498; i++)  
    {  
        if( len[i] < n )  
            continue;  
        if( len[i] == n )  
        {  
            int flag = 0;  
            for(k=n-1; k>=0; k--)  
            {  
                if( fb[i][k] > s[k] )  
                    return i;  
                else  
                    if( fb[i][k] == s[k] )  
                        continue;  
                    else  
                    {  
                        flag = 1;  
                        break;  
                    }  
            }  
            if( flag == 0 )  
            {  
                x++;  
                return i;  
            }  
        }  
        if( len[i] > n )  
            return i;  
    }  
    return 0;  
}  
int main(void)  
{  
    char s1[105],s2[105];  
    int low[105],high[105];  
    memset(fb,0,sizeof(fb));  
    memset(len,0,sizeof(len));  
    fb[1][0] = 1; fb[2][0] = 2;  
    len[1] = len[2] = 1;  
    for(int i=3; i<=498; i++)  
    {  
        int l = max(len[i-1],len[i-2]);  
        for(int k=0; k<l; k++)  
        {  
            fb[i][k] += (fb[i-1][k] + fb[i-2][k]);  
        }  
        for(int k=0; k<l; k++)  
            if( fb[i][k] > 9 )  
            {  
                fb[i][k+1] += fb[i][k]/10;  
                fb[i][k] %= 10;  
            }  
        if( fb[i][l] == 0 )  
            len[i] = l;  
        else  
            len[i] = l+1;  
    }  
    while( scanf("%s %s",s1,s2)!=EOF && ( s1[0]!='0' || s2[0]!='0' ))  
    {  
        int len1 = strlen(s1);  
        int len2 = strlen(s2);  
        x = 0;  
        for(int i=len1-1; i>=0; i--)  
            low[len1-i-1] = s1[i] - '0';  
        for(int i=len2-1; i>=0; i--)  
            high[len2-i-1] = s2[i] - '0';  
        int a = find(low,len1);  
        nn = x; x = 0;  
        int b = find(high,len2);  
        bb = x;  
        if( nn == 1 && bb == 1 )  
        {  
            cout << b-a+1<< endl;  
            continue;  
        }  
        if( nn == 1 && bb == 0 )  
            cout << b-a << endl;  
        else  
            if( nn == 0 && bb == 1 )   
                cout << b-a+1 << endl;  
            else  
                cout << b-a << endl;  
    }  
return 0;  
}  
