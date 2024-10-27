#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, Q;
    cin >> N >> Q;
    const ll M = 200005;
    vector<ll> hash(M, 1);
    rep(i, M) {
        hash[i] = rand()<<30 | rand();
    }
    vector<ll> A(N+1), B(N+1);
    int a;
    for(int i=1; i<=N; i++) {
        cin >> a;
        A[i] = hash[a];
    }
    for(int i=1; i<=N; i++) {
        cin >> a;
        B[i] = hash[a];
    }
    for(int i=1; i<=N; i++) {
        A[i] = (A[i] + A[i-1]);
        B[i] = (B[i] + B[i-1]);
    }
        
    while(Q--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if ((r1-l1 == r2-l2) && (B[r2] - B[l2-1] == A[r1] - A[l1-1])) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

   return 0;
}