#include<iostream>  
#include<stdio.h>  
#include<string.h>  
using namespace std;  
#define MAX_LEN 100  
char a[MAX_LEN],b[MAX_LEN],stack[MAX_LEN],top,op[MAX_LEN];  
void print(int  k){  
    int i;  
    for(i=0;i<k;i++)  
        /*if(i)cout<<" "<<op[i]; 
        else 
            cout<<op[i];*/  
        cout<<op[i]<<" ";  
    cout<<endl;  
}  
void dfs(int i,int j,int k){  
    if(j==strlen(b)){  
        print(k);  
        return ;  
    }  
    //in  
    if(i<strlen(a)){  
        stack[++top]=a[i++];  
        op[k++]='i';  
    //  print(k);  
        dfs(i,j,k);  
        top--;  
        i--;  
        k--;  
    }  
    //out  注意 恢复状态时 要将原来的b[j]重新放入栈中，如果只是通过top++ 可能原来的值已经发生改变  
    if(top!=-1){  
        if(b[j]==stack[top]){  
            j++;  
            top--;  
            op[k++]='o';  
            //  print(k);  
            dfs(i,j,k);  
            stack[++top]=b[--j];  
            k--;  
        }  
    }  
      
}  
int main()  
{  
    while(cin>>a>>b){  
        top=-1;  
        cout<<"[\n";  
        if(strlen(a)==strlen(b))dfs(0,0,0);  
        cout<<"]\n";  
    }  
    return 0;  
  
} 
