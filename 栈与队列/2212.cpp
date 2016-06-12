#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Instrut
{
	int id;
	double ReturnTime; 
	double period;
	Instrut(int i, double p):id(i), ReturnTime(p), period(p){}

};

bool operator < (const Instrut& x, const Instrut& y)
{
    if(x.ReturnTime != y.ReturnTime)
        return x.ReturnTime > y.ReturnTime;
    return x.id > y.id;
}

int main()
{
	string str;
	int k, id, period;
	priority_queue<Instrut> que;
	for(int i = 0; cin >> str; ++i)
	{
		if(str == "#") break;
		else
			cin >> id >> period;
        Instrut tmp(id, period);
        que.push(tmp);
	}
    cin >> k;
    while(k--)
    {
        Instrut tmp = que.top();
        que.pop();
        cout << tmp.id << endl;
        tmp.ReturnTime += tmp.period;
        que.push(tmp);
    }
	return 0;
}
