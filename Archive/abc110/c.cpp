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
    cin>>S>>T;
    map<char,char> to;
    set<char> visit;
    rep(i,S.size()) {
        if(to.contains(S[i])) {
            if(to[S[i]] == T[i]) continue;
            else {
                cout << "No" << endl;
                return 0;
            }
        } else {
            if(visit.contains(T[i])) {
                cout << "No" << endl;
                return 0;
            }
            to[S[i]] = T[i];
            visit.insert(T[i]);
        }
    }
    cout << "Yes" << endl;
    return 0;
}