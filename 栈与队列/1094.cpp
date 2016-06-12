#include <iostream>  
#include <stack>  
  
using namespace std;  
  
struct Matrix     //矩阵类型，包括行数和列数  
{  
    int row;        //行数  
    int col;        //列数  
};  
  
int main()  
{  
    int n, i;       //n为输入的矩阵个数  
    Matrix mat[30];     //用来存储各个单矩阵（最多只有26个，所以开30的空间有了！！！）  
    char c;  
    cin>>n;  
    for(i = 0; i < n; i++)  
    {  
        cin>>c;  
        int index = (int)(c-'A');       //让矩阵数组的下标0,1,2...就标志着A,B,C...  
        cin>>mat[index].row>>mat[index].col;      //存入对应的行数和列数  
    }  
  
    string s;       //以字符串的形式输入每行测试数据  
    while(cin>>s)  
    {  
        long long sum = 0;      //基本乘法数之和，初始为0  
        int len = s.length();  
        stack<char> st_sign;        //该栈用来存储"("  
        stack<Matrix> st_node;        //该栈用来存储"矩阵"  
        int ok = 1;     //ok用来标志是否出现error的现象  
        for(i = 0; i < len; i++)        //扫描各个字符  
            if(s[i] == ')')     //当出现")"时，必有"("与其对应  
            {  
                int right_value = st_node.top().col;      //从栈中取出矩阵数据，右矩阵的列数  
                int mid_value_right = st_node.top().row;      //右矩阵的行数  
                st_node.pop();  
                int left_value = st_node.top().row;       //从栈中取出矩阵数据，左矩阵的行数  
                int mid_value_left = st_node.top().col;     //左矩阵的列数  
                if(mid_value_left != mid_value_right)       //当 左矩阵的列数 != 右矩阵的行数 时  
                {  
                    ok = 0;  
                    break;  
                }  
                st_node.pop();  
                st_sign.pop();  
                sum += left_value * mid_value_left * right_value;       //累加基本乘法次数  
                Matrix newmat;  
                newmat.row = left_value;  
                newmat.col = right_value;  
                st_node.push(newmat);      //新建一个矩阵，行数为左矩阵的行数，列数为右矩阵的列数，进栈  
            }  
            else if(s[i] == '(')        //碰到"("直接放入符号栈即可  
                st_sign.push('(');  
            else        //当扫到字母即矩阵的时候  
            {  
                int new_index = (int)(s[i]-'A');        //转换下标  
                st_node.push(mat[new_index]);       //将该矩阵放入矩阵栈  
            }  
        if(ok)  
            cout<<sum<<endl;  
        else  
            cout<<"error"<<endl;  
    }  
    return 0;  
}  
