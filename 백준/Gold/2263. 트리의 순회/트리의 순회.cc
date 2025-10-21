#include <bits/stdc++.h>
using namespace std;

#define MAX 1e9
#define ll long long

int n;
int INDEX[100001];
int inorder[100001];
int postorder[100001];

void input(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> inorder[i];
        INDEX[inorder[i]] = i;
    }


    for(int i = 1 ; i <= n ; i++){
        cin >> postorder[i];
    }
}

void printPreOrder(int inStart, int inEnd, int postStart, int postEnd){
    if(inStart > inEnd || postStart > postEnd){
        return;
    }

    int rootIndex = INDEX[postorder[postEnd]];
    int leftSize = rootIndex - inStart;
    int rightSize = inEnd - rootIndex;

    cout << inorder[rootIndex] << " "; // postEnd의 인덱스 값에 해당하는 것이

    printPreOrder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
    printPreOrder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);

}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    printPreOrder(1, n, 1, n);
    return 0;
}