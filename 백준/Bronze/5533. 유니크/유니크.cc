#include <iostream>
#include <vector>
using namespace std;

int games[201][4]; // [사람번호, 게임 번호] =
int scores[201];

int main(){
    int N;
    cin >> N;

    for(int num = 1 ; num <= N; num++){
        for(int game = 1 ; game <= 3 ; game++){
            cin >> games[num][game];
        }
    }

    // 게임 시작!!!!!!

    for(int game = 1 ; game <= 3 ; game++){
        for(int i = 1 ; i <= N ; i++){ // 사람
            bool PS = true;
            for(int k = 1 ; k <= N ; k++){
                if(games[i][game] == games[k][game] && i != k){
                    PS = false;
                }
            }
            if(PS){
                scores[i] += games[i][game];
            }
        }
    }

    for(int i = 1 ; i<= N ; i++){
        cout << scores[i] << '\n';
    }
}