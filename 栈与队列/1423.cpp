#include<stdio.h>  
#include<string.h>  
#define N 260  
int main()  
{  
    int t,i,j,del[N],mark[N],used[N];  
    char s[N],str[N];  
    scanf("%d",&t);  
    getchar();  
    while(t--)  
    {  
        gets(s);  
        for(j=0,i=0;s[i];i++)  
            if(s[i]!=' ')str[j++]=s[i];  
        str[j]=0;  
        memset(used,0,sizeof(used));  
        memset(mark,-1,sizeof(mark));//保存右括号的匹配左括号的下标  
        for(i=0;str[i];i++)  
        {  
            if(str[i]==')' && mark[i]==-1)  
            {  
                for(j=i-1;j>=0;j--)  
                    if(str[j]=='(' && used[j]==0)  
                    {  
                        used[j]=1,mark[i]=j;break;  
                    }  
            }  
        }  
      
        memset(del,0,sizeof(del));  
        for(i=0;str[i];i++)  
        {  
            if(!del[i] && str[i]==')')  
            {  
                int flag=0;               //无运算符  
                for(j=i-1;j>mark[i];j--)  
                    if(str[j]=='+' || str[j]=='-')    
                    {  
                        flag=1;break;           //有运算符，即对'-'敏感  
                    }  
                if(mark[i]==0 || str[mark[i]-1]!='-' || (str[mark[i]-1]=='-'&&!flag) )  
                    del[i]=1,del[mark[i]]=1;  
            }  
        }  
        for(i=0;str[i];i++)  
            if(!del[i])printf("%c",str[i]);  
        puts("");     
    }  
    return 0;  
} 
