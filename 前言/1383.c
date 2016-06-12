#include <stdio.h>
int main()
{
    int t;
    scanf ("%d",&t);
    while (t--)
    {
        int d;
        scanf ("%d",&d);
        int i;
        int b = 0;
        for (i = 0; i < 32 && b <= d; i++)
        {
            int b = d & (1 << i);
            if (b)
            {
                printf ("%d",i);
                if ((1 << (i+1)) < d)
                    printf (" ");
            }
        }
        printf ("\n");
    }
    return 0;
}


