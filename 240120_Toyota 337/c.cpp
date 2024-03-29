#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, t;
    cin >> N;
    vector<int> inp(N), lin(N);
    
    for (int i = 0; i < N; i++){
        cin >> t;
        if (t == -1){
            lin[0] = i;
        } else {
            inp[t-1] = i;
        }        
    }
    for (int i = 1; i < N; i++){
        lin[i] = inp[lin[i-1]];        
    }

    for (auto &l: lin){
        cout << l+1 << " ";
    }
    cout << endl;
    
    return 0;
}