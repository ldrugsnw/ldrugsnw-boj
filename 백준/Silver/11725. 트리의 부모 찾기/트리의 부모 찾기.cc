#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
public:
    Node()
    :data(0), parent(nullptr){}

    Node* parent;
    int data;
    vector<int> connections;
};

Node* node_list[100001];

int main(){
    int N;
    cin >> N;
    

    for(int i = 1; i <= N; i++){
        node_list[i] = new Node();
    }
    
    
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        node_list[a]->connections.push_back(b);
        node_list[b]->connections.push_back(a);
    }
    
    
    node_list[1]->data = 1;
    
    
    queue<int> Q;
    Q.push(1);
    
    while(!Q.empty()){
        int current = Q.front();
        Q.pop();
        
        
        for(int next : node_list[current]->connections){
          
            if(node_list[next]->data == 0){
                node_list[next]->data = next;
                node_list[next]->parent = node_list[current];
                Q.push(next);
            }
        }
    }
    

    for(int i = 2; i <= N; i++){
        cout << node_list[i]->parent->data << '\n';
    }
    
    return 0;
}
