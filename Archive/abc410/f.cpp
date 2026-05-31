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
typedef pair<ll,ll> pll;

int main(){
    ll T; cin>>T;
    while(T--){
        int H,W; cin>>H>>W;        
        vector<string> S(H);
        rep(i,H) cin>>S[i];
        if(H>W) {
            vector<string> S2(W, string(H, '.'));
            rep(i,H) rep(j,W) S2[j][i] = S[i][j];
            swap(S, S2);
            swap(H,W);
        }
        vector A(H, vector<ll>(W));
        rep(i,H)rep(j,W){
            if(S[i][j] == '#') A[i][j]++;
            if(S[i][j] == '.') A[i][j]--;
        }
        rep(i,H) rep(j,W-1) A[i][j+1] += A[i][j];            
        rep(j,W) rep(i,H-1) A[i+1][j] += A[i][j];
        ll ans = 0;
        ll P=H*W;
        vector<ll> mp(2*P+2);
        vector<ll> st{};
        rep(i,H) {            
            for(int i2=-1; i2<i; i2++) {
                if(i2<0) {                    
                    mp[P]++;
                    rep(j,W) {
                        ans += mp[A[i][j]+P];
                        mp[A[i][j]+P]++;
                        st.emplace_back(A[i][j]+P);
                    }
                } else {
                    ll cnt = 0;
                    ll sm = 0;                
                    mp[P]++;
                    rep(j,W) {
                        ans += mp[A[i][j] - A[i2][j] + P];
                        mp[A[i][j] - A[i2][j] + P]++;
                        st.emplace_back(A[i][j] - A[i2][j] + P);
                    }
                }
                mp[P]--;
                for(auto s: st) mp[s]--;                
                st.clear();
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}