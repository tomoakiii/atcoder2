#include <bits/stdc++.h>
using namespace std;


int main(){
    const int INF = 0x0F0F0F0F;
    int N, D;
    cin >> N >> D;
    vector<int> A(N);
    for(auto &a : A) cin >> a;
    vector<int> d(N, 1);
    for(int i=1; i<N; i++){
        for (int j = i-1; j >= 0; j--){
            if (abs(A[j]-A[i]) <= D){
                d[i] = d[j] + 1;
                break;
            }
        }
    }
    cout << *(max_element(d.begin(), d.end())) << endl;

    return 0;
}

