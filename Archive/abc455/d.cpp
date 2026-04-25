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
    ll N,Q;
    cin >> N >> Q;
    vector<ll> nM(N), nC(N,-1), pC(N);
    rep(i,N) {
        nM[i] = i;
        pC[i] = i + N;
    }
    rep(i,Q) {
        int c,p; cin>>c>>p;
        c--,p--;
        if(pC[c] >= N) {
            int pM = pC[c]-N;
            nM[pM] = -1;
        } else {
            nC[pC[c]] = -1;
        }
        pC[c] = p;
        nC[p] = c;
    }
    rep(i,N) {
        int cnt=0;
        int cur=nM[i];
        while(cur != -1) {
            cnt++;
            cur = nC[cur];
        }

        cout<<cnt<<" \n"[i==N-1];
    }
    return 0;
}