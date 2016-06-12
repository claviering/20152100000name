#include <iostream>
#include <cmath>
#include <limits>

using namespace std;
const int MAXSIZE = 100;
int pos[100];
struct RGB
{
 
    double red;
 
    double green;
 
    double blue;
 
}colors[MAXSIZE];
 
double distance(RGB* color1,RGB* color2)
 
{
    double r = color1->red-color2->red;
 
    double g = color1->green-color2->green;
 
    double b = color1->blue-color2->blue;
 
    return sqrt(r*r+g*g+b*b);
 
}
 
int main(void)
{
 
    double r,g,b,dist;
 
    int count=0,i,j,k;
 
    while (cin>>r>>g>>b&&(r!=-1&&g!=-1&&b!=-1))
 
    {
 
        colors[count].red = r;
 
        colors[count].green = g;
 
        colors[count].blue = b;
 
        ++count;
 
    }
 
    double min;
 
    k = 0;
 
    for (i=16;i<count;++i)
 
    {
 
        min = numeric_limits<double>::max();
 
        for (j=0;j<16;++j)
 
        {
 
            dist = distance(&colors[i],&colors[j]);
 
            if (dist<min)
 
            {
 
                min = dist;
 
                pos[k] = j;
 
            }
 
        }
 
        k++;
 
    }
 
    for (i=16,k=0;i<count;++i,++k)
 
    {
 
        cout<<'('<<colors[i].red<<','<<colors[i].green<<','<<colors[i].blue<<')'<<" maps to ";
 
        cout<<'('<<colors[pos[k]].red<<','<<colors[pos[k]].green<<','<<colors[pos[k]].blue<<')'<<endl;
 
    }
 
    return 0;
 
}
