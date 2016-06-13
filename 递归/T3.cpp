#include<stdio.h>
#include<string.h>
int main()
{ 
    int i,j,n,f[21][191];    //f[i][j]代表i条直线是否能产生j个交点，如果能f[i][j]=1，否则为0；
    
    memset(f,0,sizeof(f));

    for(i=0;i<21;i++)            //零个交点置零
        f[i][0]=1;

    for(n=2;n<21;n++)        //从两条直线开始求
       for(i=n-1;i>=1;i--)    //取出n-i条做变化
            for(j=0;j<191;j++)    //j变化
                if(f[n-i][j]==1)  //如果取出的n-i条能过产生j个交点，置f[n][j+(n-i)*i]=1，j+(n-i)*i为取出n-i条直线做变化情况下的交点数
                     f[n][j+(n-i)*i]=1;   

     while(scanf("%d",&n)!=EOF)
     {
         printf("0");

         for(j=1;j<=n*(n-1)/2;j++)    //统计
              if(f[n][j])
                printf(" %d",j);

        printf("\n");
     }

    return 0;
}
