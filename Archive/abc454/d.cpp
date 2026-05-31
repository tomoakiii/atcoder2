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


vector<pair<char, int>> encode(const string& str) {
    int n = (int)str.size();
    vector<pair<char, int>> ret;
    for (int l = 0; l < n;) {
        int r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}
int main(){
    ll T;
    cin >> T;
    while(T--){
        string S,T; cin>>S>>T;
        string S2="",T2="";
        rep(kkk,2) {
            auto vp = encode(S);
            string tmp="";
            int N=vp.size();
            rep(i,N) {
                if(i>0 && vp[i].first=='x' && vp[i].second==2
                && vp[i-1].first=='(' && i<N-1 && vp[i+1].first==')') {
                    int mn = min(vp[i-1].second, vp[i+1].second);
                    vp[i-1].second-=mn;
                    vp[i+1].second-=mn;
                }
            }
            for(auto [c,nm]:vp) {
                rep(i,nm) S2.push_back(c);
            }
            swap(S,T); swap(S2,T2);
        }
        if(S2==T2) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }


    return 0;
}