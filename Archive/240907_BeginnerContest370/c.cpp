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
    string S,T;
    cin >> S >> T;
    vector<string> ans{};

    bool flg = true;
    while(flg){
        set<string> st;
        flg = false;
        rep(i, S.size()) {
            if (S[i] != T[i]) {
                flg = true;
                string SS = S;
                SS[i] = T[i];
                st.insert(SS);
            }
        }
        for(auto s: st) {
            ans.push_back(s);
            S = s;
            break;
        }
    }

    cout << ans.size() << endl;
    for(auto s: ans) cout<<s<<endl;
    return 0;
}