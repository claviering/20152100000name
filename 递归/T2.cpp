#include <iostream>

int total = 0;
int split(int **table, int n, int start);
int main(){
  using namespace std;

  int n = 1;
  while (n){
    total = 0;
    cin >> n;
    int **table = new int*[n];
    for (int i = 0; i < n; ++i)
      table[i] = new int[n];
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
	table[i][j] = -1;
    int result = split(table, n, 1) - 1;
    cout << result << endl;
    for (int i = 0; i < n; ++i)
      delete[]table[i];
    delete[]table;
  }
  
  return 0;
}
int split(int **table, int n, int start){
  using namespace std;
  cout << "n: " << n << " start: " << start << endl;
  int result = 1;
  if (start == n){
    return 1;
  }
  else if (start > n){
    return 0;
  }
  else if (table[start-1][n-1] > -1){
    return table[start-1][n-1];
  }
  else{
    for (int i = start; i < n; ++i){
      result += split(table, n - i, i);
      cout << "result: " << result << endl;
    }
  }
  cout << "return result: " << result << endl;
  table[start-1][n-1] = result;
  return result;
}
