#include <iostream>
#include <vector>
using namespace std;

int main(){
  int T;
  cin >> T;

  for (int i = 0; i < T; i++)
  {
    int N, K;
    cin >> N >> K;

    int result = 0;

    for (int j = 0; j < N; j++){
      int A;
      cin >> A;
      
        result += A/K;
    }

    //cout << "result : ";
    cout << result << endl;
  }

}
