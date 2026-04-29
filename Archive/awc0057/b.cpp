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
    ll N;
    cin >> N;
    vector S(N, vector<string>{});
    vector dict(N, vector<vector<vector<int>>>{});
    rep(i,N) {
        int K; cin>>K;
        dict[i].resize(K, vector<vector<int>>(26));
        rep(j,K) {
            string s; cin>>s;
            S[i].push_back(s);
            rep(p,s.size()) {
                int ci = s[p]-'a';
                dict[i][j][ci].push_back(p);
            }
        }
    }

    auto jdg = [&](string x, vector<vector<int>> dic)->bool{
        int last=-1;
        for(auto c:x) {
            int ci=c-'a';
            int it = upper_bound(dic[ci].begin(),dic[ci].end(),last)-dic[ci].begin();
            if(it==dic[ci].size()) {
                return false;
            }
            last=dic[ci][it];
        }
        return true;
    };
    int Q; cin>>Q;
    while(Q--) {
        string t; cin>>t;
        int ans=0;
        rep(i,N) {
            int K=S[i].size();
            bool flg=false;
            rep(j,K){
                if(jdg(t, dict[i][j])) {
                    flg=true; break;
                }
            }
            if(flg) ans++;
        }
        cout<<ans<<endl;
    }

    return 0;
}