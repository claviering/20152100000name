#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 200;
int val[maxn],opr[maxn],val_top,opr_top;
void insert(int Bool)
{
	while(opr_top >= 0 && opr[opr_top] == 3)	
	{											
		Bool = !Bool;							
		opr_top --;
	}
	val[++val_top] = Bool;
}
void calc()									
{
	int b = val[val_top --];
	int a = val[val_top --];
	int op = opr[opr_top --];
	if(op == 1)		insert(a | b);
	else if(op == 2)insert(a & b);
}
int main()
{
	char c;
	int loop = 1;
	while((c = getchar()) != EOF)
	{
		val_top = opr_top = -1;
		do{
			if(c == '(')		opr[++opr_top] = 0;
			else if(c == ')')
			{
				while(opr_top >= 0 && opr[opr_top] != 0)	calc();
				opr_top --;		
				insert(val[val_top--]);		
			}
			else if(c == '!')	opr[++opr_top] = 3;
			else if(c == '&')
			{
				while(opr_top >= 0 && opr[opr_top] >= 2)	calc();
				opr[++opr_top] = 2;
			}
			else if(c == '|')
			{
				while(opr_top >= 0 && opr[opr_top] >= 1)	calc();
				opr[++opr_top] = 1;
			}
			else if(c == 'V')	insert(1);
			else if(c == 'F')	insert(0);
		}while((c = getchar()) != '\n' && c != EOF);
		while(opr_top >= 0)
			calc();
		printf("Expression %d: %c\n",loop ++,val[0] ? 'V' : 'F');
	}
	return 0;
}
