#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    ll A[100];
    string S[100];
    ll mn = INF;
    int mnind;
    rep(i, N){
        cin >> S[i] >> A[i];
        if (A[i] < mn) {
            mn = A[i];
            mnind = i;
        }
    }
    for(int i=mnind; i<N; i++) {
        cout << S[i] << endl;
    }
    for (int i=0; i<mnind; i++){
        cout << S[i] << endl;
    }
    return 0;
}