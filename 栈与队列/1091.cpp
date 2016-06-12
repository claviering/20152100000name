#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int state[9][9];
int count[9][9];
int Queue[100000];
int step[8][2] = {1,2, 1,-2, -1,2, -1,-2, 2,1, 2,-1, -2,1, -2,-1};
int head,tail;
int push(int x)
{
    Queue[head++] = x;
}
int pop(void)
{
    return Queue[tail++];
}
int Qempty(void)
{
    if( head == tail )
        return 1;
    return 0;
}
void init(void)
{
    head = 0; tail = 0;
    memset( state,0,sizeof(state) );
    memset( count,0,sizeof(count) );
    memset( Queue,0,sizeof(Queue) );
}
int main(void)
{
    int a,b,x,y,temp,tempa,tempx,ta,tx,i;
    char ch1,ch2,n;
    while( scanf("%c%d %c%d%c",&ch1,&x,&ch2,&y,&n)!=EOF )
    {
        init();
        a = ch1 - 'a' + 1;
        b = ch2 - 'a' + 1;
        push(a); push(x);
        state[a][x] = 1;
        while( !Qempty() )
        {
            tempa = pop();
            tempx = pop();
            if( tempa == b && tempx == y)
                break;
            for(i=0; i<8; i++) 
            {
                ta = tempa + step[i][0];
                tx = tempx + step[i][1];
                if(state[ta][tx] == 0 && ta>=1 && ta<=8 && tx>=1 && tx<=8 )
                {
                    push(ta); push(tx);
                    state[ta][tx] = 1;
                    count[ta][tx] = count[tempa][tempx] + 1;
                }
            }
        }
        printf("To get from %c%d to %c%d takes %d knight moves.\n",ch1,x,ch2,y,count[tempa][tempx]);
    }
return 0;
}
