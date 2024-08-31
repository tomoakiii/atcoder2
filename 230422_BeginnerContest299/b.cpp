#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, T;
    cin >> N >> T;
    vector<ll> C(N), R(N);
    rep(i,N) cin>>C[i];
    rep(i,N) cin>>R[i];
    
    ll mx=0, mwin=-1;
    rep(i,N){
        if(C[i]==T && mx<R[i]){
            mx = R[i];
            mwin = i;
        }
    }
    if(mwin > -1) {
        cout << (mwin+1) << endl;
        return 0;
    }
    T = C[0];
    mx=0, mwin=-1;
    rep(i,N){
        if(C[i]==T && mx<R[i]){
            mx = R[i];
            mwin = i;
        }
    }
    cout << (mwin+1) << endl;
    return 0;
}