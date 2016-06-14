#include <stdio.h>
int main()
{
    float n;
    while (scanf ("%f",&n) != EOF && n > 0)
    {
        float sum = 0.00f;
        int i = 1;
        while (sum < n)
        {
            i++;
            sum += (float)1 / i;
        }
        printf ("%d card(s)\n",--i);
    }
    return 0;
}


