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
    set<int> st, ng;
    rep(i,S.size()) {
        if(S[i] == 'o') st.insert(i);
        if(S[i] == 'x') ng.insert(i);
    }
    int ans = 0;
    rep(i, 10000) {
        string T;
        int I = i;
        while(I) {
            T = T + (char)(I%10 + '0');
            I /= 10;
        }
        rep(i, 4-T.size()) T = '0' + T;
        auto st2 = st;
        int flg = 0;
        for(auto t: T) {
            int tx = t - '0';
            if(ng.contains(tx)) flg = -1;
            if(st2.contains(tx)) st2.erase(tx);
        }
        if(st2.size() == 0 && flg != -1) ans++;
    }
    cout << ans << endl;
    return 0;
}