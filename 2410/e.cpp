#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int T;
    cin >> T;
    while(T--) {
        int N, K;
        cin >> N >> K;
        vector<ll> A(N), B(N);
        rep(i,N) cin>>A[i];
        rep(i,N) cin>>B[i];
        vector<int> ord(N);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j) { return B[i] < B[j]; });        
        ll ans = INF;        
        ll Bsm = 0, Bsmp = 0;
        ll tAm = 0;
        set<pair<ll,int>> stA;
        bool flg = false;
        rep(i, K) {
            int id = ord[i];
            stA.insert({A[id], id});
            Bsm += B[id];       
        }
        auto id = stA.end();
        id--;
        auto [a, b] = *id; 
        ans = a * Bsm;        
        ll tAm2;
        ll Bsm2 = Bsm - B[b];
        if (K==1) {
            tAm2 = 0;
        } else {
            id--;
            auto [a, b] = *id;         
            tAm2 = a;

            
        }

        for(int i=K; i<N; i++) {
            int id = ord[i];
            ll tans = max(A[id], tAm2) * (Bsm2+B[id]);
            chmin(ans, tans);
        }
        cout << ans << endl;

    }
    return 0;
}