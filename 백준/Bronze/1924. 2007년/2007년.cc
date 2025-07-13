#include <iostream>

using namespace std;

int month[13] = {0, 31, 28, 31, 30, 31, 30 ,31, 31, 30, 31, 30, 31};

int main(){

int x,y;

cin >> x >> y;

int RR = y;

for(int i = 1; i < x; i++){

RR += month[i];

}

int S = RR % 7;

if(S == 0){

cout << "SUN";

}

if(S == 1){

cout << "MON";

}

if(S == 2){

cout << "TUE";

}

if(S == 3){

cout << "WED";

}

if(S == 4){

cout << "THU";

}

if(S == 5){

cout << "FRI";

}

if(S == 6){

cout << "SAT";

}

}