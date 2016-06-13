#include <iostream>

int total;
int split(int *table, int n, int k, int count, int start);
int main(){
  using namespace std;

  int n = 1, k = 0;
  while (n){
    total = 0;
    cin >> n >> k;
    int *table = new int[n];
    for (int i = 0; i < n; ++i)
      table[i] = -1;
    
    cout << split(table, n, k, k, 1) << endl;
    delete[]table;
  }
  return 0;
}
int split(int *table, int n, int k, int count, int start){
  using namespace std;
  //  cout << "n: " << n << " start: " << start << " count: " << count << endl;
  int result = 0;
  if (n < start){
    //    cout << "return n < start" << endl;
    return 0;
  }
  else if (table[n - 1] > -1){
    //    cout << " return table " << n << endl;
    return table[n - 1];
  }
  else if (count == 1){
    total++;
    return total;
  }
  for (int i = start; i <= n; ++i){
    int temp = split(table, n - i, k, count - 1, i);
    if (temp <= 0)
      break;
    else{
      if (temp > table[n-1]){
	table[n-1] = temp;
      }
    }
  }
  return table[n - 1];
}

