#include <iostream>
using namespace std;


void Josephus ( int n , int start , int m )
{
    int count, j, *A = new int [n];
    for (j = 0; j < n; j++) 
    {
        A[j] = j + 1;
    }
    count = 1;
    start--;
    while (count < n) 
    {
    cout << A[start]; 
    for (j = start;  j < n - count; j++)
        A[j]=A[j+1]; 
    start = (start + m - 1) % (n - count);
    count++;
    }
    cout<<A[0];
}

int main()
{
    int n;
    int s;
    int m;
    cin >> n >> s >> m;
    Josephus(n,s,m);
    cout << endl;

    return 0;
}

