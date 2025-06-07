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
    string S; cin>>S;
    ll K; cin>>K;
    string T=S;
    const int N = S.size();
    reverse(T.begin(), T.end());
    vector<int> P1(N), P2(N);
    int cnt = 0, cnt2 = 0;
    rep(i,N) {
        if(S[i] == '.') cnt++;
        if(T[i] == '.') cnt2++;
        P1[i] = cnt;
        P2[i] = cnt2;
    }
    if(cnt<=K) {
        cout<<N<<endl;
        return 0;
    }
    reverse(P2.begin(), P2.end());

    int r = 0;
    int lst = 0;
    int mx = 0;
    for(int i=0; i<N; i++) {
        int rm = cnt - (K + lst);
        if(rm<=0) {
            chmax(mx,N-i);
            continue;
        }
        lst = P1[i];
        while(r<N && P2[r] >= rm) r++;
        chmax(mx, r-1-i);
    }
    cout<<mx<<endl;
    return 0;
}
