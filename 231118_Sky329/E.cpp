#include <bits/stdc++.h>
using namespace std;

struct node {    
    int prev;
    int count;
};

vector<node> A;

int main(){
    int N, M;
    string S, T;
    cin >> N >> M >> S >> T;
    A.resize(N);
    priority_queue<int> matchT;
    string ts = "";
    for (int i = 0; i < N - M + 1; i++){
        matchT.push(i);
    }
    while (!matchT.empty()){
        auto i = matchT.top();
        matchT.pop();
        bool allmatch = true;
        for (int j = 0; j < M; j++){
            if (S[i+j] != ' ' && S[i+j] != T[j]){
                allmatch = false;
                break;
            }              
        }
        if (allmatch){
            if (S[i] != ' '){
                for (int j=i-M+1; j<i; j++){
                    if (j >= 0){
                        matchT.push(j);
                    }
                }
            }
            if (S[i+M-1] != ' '){
                for (int j=i+M; j<i+M+M-1; j++){
                    if (j < N){
                        matchT.push(j-M+1);
                    }
                }
            }
            for (int j = i; j < i + M; j++){
                S[j] = ' ';
            }
        }
    }


    for (auto x : S){
        if (x != ' '){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}