#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> tree;
vector<vector<pair<int, int>>> T;
vector<vector<int>> subNode;

void make_tree()
{

}

void input()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    subNode.resize(N + 1);
    subNode[0].push_back(1);

    for(int i = 1; i <= N; i++){

        int a, b;
        cin >> a >> b;

        if(subNode[a] == subNode[b] && a == 0){
            subNode[i].push_back(2);
        }
        else{
            for(auto& j : subNode[a]){
                subNode[i].push_back(j);
            }
            for(auto& j : subNode[b]){
                subNode[i].push_back(j);
            }
        }
        
    }

    for(auto& i : subNode){
        for(auto& j : i){
            cout << j;
        }

        cout << endl;
    }
}

int main() {
    
    input();

    for(int i=1;i<=N;i++){
        for(int j = i; j<=N;j++){

        }
    }

    return 0;
}
