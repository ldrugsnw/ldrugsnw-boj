
#include <iostream>
using namespace std;
int main()
{
    int _N, _Temp, _Res = 0;
    cin >> _N;
    _Res += (_N - 1) * 8;
    for (int i = 0; i < _N; i++) {
        cin >> _Temp;
        _Res += _Temp;
    }
    cout << _Res / 24 << " " << _Res % 24;
    return 0;
}