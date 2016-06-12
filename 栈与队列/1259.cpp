#include <iostream>  
#include <stack>  
  
using namespace std;  
  
const int maxn = 1000 + 10;  
  
int main()  
{  
    int N, i;  
    int target[maxn];       //用来存目标序列  
    while(cin>>N)  
    {  
        if(N == 0) return 0;  
  
        while(cin>>target[1])  
        {  
            if(target[1] == 0) break;       //一组测试结束  
  
            for(i = 2; i <= N; i++)  
                cin>>target[i];  
  
            stack<int> st;  
            int init = 1, cur = 1, ok = 1;      //init为初始序列，即1,2,3...，cur为目标序列的下标，ok为能否转换的标记  
            while(cur <= N)     //一直到匹配完所有的车厢  
            {  
                if(init == target[cur])     //当驶来的车厢号与目标序列车厢号匹配时  
                {  
                    init++;     //转到匹配下一节车厢  
                    cur++;      //转到匹配下一节车厢  
                }  
                else if(!st.empty() && st.top() == target[cur])     //当栈中的车厢号与目标序列车厢号匹配时  
                {  
                    st.pop();       //退栈，转到匹配下一节车厢  
                    cur++;          //转到匹配下一节车厢  
                }  
                else if(init <= N)      //如果不相匹配但还没到始入的最后一辆车厢时  
                {  
                    st.push(init++);        //驶入车厢进栈，且转到下一节车厢  
                }  
                else        //如果不相匹配且已到始入的最后一辆车厢时  
                {  
                    ok = 0;  
                    break;  
                }  
            }  
            if(ok) cout<<"Yes"<<endl;  
            else cout<<"No"<<endl;  
        }  
        cout<<endl;  
    }  
    return 0;  
}
