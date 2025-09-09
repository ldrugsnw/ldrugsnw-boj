#include <iostream>
using namespace std;

int colors[11][5];

void init() {
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 5; j++){
            colors[i][j] = 0;
        }
    }

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> colors[i][j];
        }
    }
}

int main(){
    init();

    string ownership, trade_request;
    cin >> ownership >> trade_request;

    string collateral;
    cin >> collateral;

    int my_money, opponent_money;
    cin >> my_money >> opponent_money;

    int my_offer, opponent_offer;
    cin >> my_offer >> opponent_offer;

    int A, B;
    cin >> A >> B;

    // 트레이드 전 상황 계산
    int my_cities[11] = {0}; // 색상별 내가 소유한 도시 개수
    int opponent_cities[11] = {0}; // 색상별 상대가 소유한 도시 개수
    int my_collateral = 0; // 내 담보 도시 개수
    int opponent_collateral = 0; // 상대 담보 도시 개수

    for(int i = 0; i < 40; i++){
        int color = i / 4 + 1;
        
        if(ownership[i] == '1'){
            my_cities[color]++;
            if(collateral[i] == '1'){
                my_collateral++;
            }
        } else if(ownership[i] == '2'){
            opponent_cities[color]++;
            if(collateral[i] == '1'){
                opponent_collateral++;
            }
        }
    }

    // 트레이드 전 재산 가치 계산
    int my_value_before = 0, opponent_value_before = 0;
    
    // 도시 가치
    for(int i = 1; i <= 10; i++){
        if(my_cities[i] > 0){
            my_value_before += colors[i][my_cities[i]];
        }
        if(opponent_cities[i] > 0){
            opponent_value_before += colors[i][opponent_cities[i]];
        }
    }
    
    // 현금 가치 (소수점 아래 버림)
    my_value_before += (my_money * A) / 100;
    opponent_value_before += (opponent_money * A) / 100;
    
    // 담보 페널티
    my_value_before -= my_collateral * B;
    opponent_value_before -= opponent_collateral * B;

    int diff_before = my_value_before - opponent_value_before;

    // 트레이드 수행 - 도시 소유권 변경
    for(int i = 0; i < 40; i++){
        int color = i / 4 + 1;
        
        if(trade_request[i] == '1'){ // 내가 상대의 도시를 원함
            if(ownership[i] == '2'){ // 상대가 소유한 도시
                opponent_cities[color]--;
                my_cities[color]++;
                
                // 담보도 함께 이전
                if(collateral[i] == '1'){
                    opponent_collateral--;
                    my_collateral++;
                }
            }
        } else if(trade_request[i] == '2'){ // 상대가 내 도시를 원함
            if(ownership[i] == '1'){ // 내가 소유한 도시
                my_cities[color]--;
                opponent_cities[color]++;
                
                // 담보도 함께 이전
                if(collateral[i] == '1'){
                    my_collateral--;
                    opponent_collateral++;
                }
            }
        }
    }

    // 트레이드 후 재산 가치 계산
    int my_value_after = 0, opponent_value_after = 0;
    
    // 도시 가치
    for(int i = 1; i <= 10; i++){
        if(my_cities[i] > 0){
            my_value_after += colors[i][my_cities[i]];
        }
        if(opponent_cities[i] > 0){
            opponent_value_after += colors[i][opponent_cities[i]];
        }
    }
    
    // 현금 가치 (트레이드 후 현금)
    int my_money_after = my_money - my_offer + opponent_offer;
    int opponent_money_after = opponent_money - opponent_offer + my_offer;
    
    my_value_after += (my_money_after * A) / 100;
    opponent_value_after += (opponent_money_after * A) / 100;
    
    // 담보 페널티
    my_value_after -= my_collateral * B;
    opponent_value_after -= opponent_collateral * B;

    int diff_after = my_value_after - opponent_value_after;

    // 유리한 트레이드 판단
    if(diff_after >= diff_before){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}