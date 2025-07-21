#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;
    unordered_map<int, int> frequency;

    int howManySangGeunCard = 0;
    cin >> howManySangGeunCard;
    for (int i = 0; i < howManySangGeunCard; i++) {
        int num;
        cin >> num;
        S.push(num);
        frequency[num]++;
    }

    int howManyAnswer = 0;
    cin >> howManyAnswer;
    for (int i = 0; i < howManyAnswer; i++) {
        int num;
        cin >> num;
        cout << frequency[num] << " ";
    }

    return 0;
}
