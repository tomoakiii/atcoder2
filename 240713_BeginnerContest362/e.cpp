#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
using mint = modint998244353;


int main(){
    ll N;
    cin >> N;
    vector<ll> A(N, 0);

    rep(i, N) {
        cin >> A[i];
    }

    vector<mint> cnt(81);
    cnt[1] = N;
    

    auto f = [&](auto f, int from, ll d, int len) -> ll {
        ll l=len;
        for(int i = from+1; i<N; i++){
            ll d2 = A[i] - A[from];
            if (d2 != d) continue;
            visit[i] = true;
            l = max(l, f(f, i, d, len+1));
        }
        return l;
    };
    map<ll, vector<bool>> mp;
    rep(i,N){
        for(int j=i+1; j<N; j++) {
            ll d = A[j]-A[i];
            if (mp.find(d) != mp.end())continue;
            vector<bool> visit(N, false);            
            ll len = f(f, j, d, 2);
            mp[d] = visit;
            ll k = 1;
            for(int i=len; i>1; i--) {
                cnt[i] += k;
                k++;
            }
        }        
    }
    for(auto m : mp) {
        rep(i, N){
            if (!visit[i]) {
                
            }
        }
    }
    for(int i=1; i<=N; i++) {
        cout << cnt[i].val() << " ";
    }    
    cout << endl;
    return 0;
}