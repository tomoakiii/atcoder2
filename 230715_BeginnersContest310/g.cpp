#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector A(N, 0);

    ll sm = 0;
    for(int i=0; i<N;i++) {
        cin >> A[i];
        sm += A[i];
    }
    
    cout << sm << endl;
    return 0;
}