// ZOJ 2812
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    char s[256];
    while (cin.getline(s,256))
    {
        int sum=0;
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            if (s[i] == '#') 
                return 0;
            sum += (i+1) * (s[i] - 'A' + 1);
        }
        cout << sum << endl;
    }
    return 0;
}
