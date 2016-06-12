#include <cstdio>
#include <algorithm>
using namespace std;

struct Mouse
{
    int id, w, s;
    bool operator < (const Mouse &m) const
    {
        if (w != m.w)  return w < m.w;
        return s > m.s;
    }
} mouse[1100];
int lis[1100], pre[1100];

void print_lis(int p)
{
    if (pre[p] != -1)  print_lis(pre[p]);
    printf("%d\n", mouse[p].id);
}

int main()
{
    int n = 0, a, b;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        mouse[n].w = a;
        mouse[n].s = b;
        mouse[n].id = n + 1;
        n++;
    }
    sort(mouse, mouse+n);
    lis[0] = 1;
    int p = 0;
    for (int i = 0; i < n; i++)
        pre[i] = -1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (mouse[i].w > mouse[j].w && mouse[i].s < mouse[j].s)
            {
                if (lis[j]+1 > lis[i])
                {
                    lis[i] = lis[j] + 1;
                    pre[i] = j;
                }
            }
        if (lis[i] > lis[p])  p = i;
    }
    printf("%d\n", lis[p]);
    print_lis(p);
    return 0;
}

