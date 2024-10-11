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
    vector<ll> A(N, 0);
    rep(i, N) cin>>A[i];
    ll Q;
    cin >> Q;
    vector<ll> aA(N, 0);
    ll sm = 0;
    for(int i=1; i<N; i++) {
        if (i%2 == 0){
            sm += A[i] - A[i-1];
        }        
        aA[i] = sm;
    }
    while(Q--){
        ll l, r;
        cin >> l >> r;
        ll st, end;
        auto it = lower_bound(A.begin(), A.end(), l);
        auto idx = distance(A.begin(), it);
        it = lower_bound(A.begin(), A.end(), r);
        auto idx2 = distance(A.begin(), it);
        if (idx == idx2) {
            if (idx % 2 == 1) { // l,r in wake
                cout << 0 << endl;
                continue;
            } else {
                cout << (r-l) << endl;
                continue;
            }
        }
        ll a=0, b=0;        
        if (idx % 2 == 0) { // l in sleep
            a = A[idx] - l;
        }
        if (idx2 % 2 == 0) { // r in sleep
            b = r - A[idx2-1];
        }
        ll c = aA[idx2-1] - aA[idx];
        cout << (a+b+c) << endl;
        continue;
    }

    return 0;
}