#include <iostream>
#include <map>
using namespace std;

int main() {
    int S1, S2, S3;
    cin >> S1 >> S2 >> S3;
    
    map<int, int> frequency; // 합과 빈도를 저장할 맵
    
    // 모든 가능한 조합을 계산
    for (int i = 1; i <= S1; i++) {
        for (int j = 1; j <= S2; j++) {
            for (int k = 1; k <= S3; k++) {
                int sum = i + j + k;
                frequency[sum]++;
            }
        }
    }
    
    // 최대 빈도 찾기
    int max_frequency = 0;
    for (auto& pair : frequency) {
        if (pair.second > max_frequency) {
            max_frequency = pair.second;
        }
    }
    
    // 최대 빈도를 가진 합 중에서 가장 작은 값 찾기
    int min_sum = -1;
    for (auto& pair : frequency) {
        if (pair.second == max_frequency) {
            if (min_sum == -1 || pair.first < min_sum) {
                min_sum = pair.first;
            }
        }
    }
    
    cout << min_sum << endl;
    
    return 0;
}