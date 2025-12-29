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
    string S; cin>>S;
    vector<string> ans = {"SS", "SW", "WS", "WW"};
    for(auto t:ans) {
        auto dfs = [&](auto dfs, int cur, string &X)->void{
            if(cur == N) return;
            char p = X[cur - 1];
            char q;
            if(p=='W')  q = 'S';
            else q = 'W';
            if(S[cur] == 'o') {
                if(X.back()== 'S') {
                    X.push_back(p);
                } else {
                    X.push_back(q);
                }
            } else {
                if(X.back()== 'S') {
                    X.push_back(q);
                } else {
                    X.push_back(p);
                }
            }
            dfs(dfs, cur+1, X);
        };
        dfs(dfs, 1, t);
        if(t.back() != t[0]) continue;
        t.pop_back();
        if(t[0] == 'S') {
            if( (S[0] == 'o' && t[1] == t.back()) || 
                (S[0] == 'x' && t[1] != t.back()) ) {
                cout << t << endl;
                return 0;
            }
        } else {
            if( (S[0] == 'x' && t[1] == t.back()) || 
                (S[0] == 'o' && t[1] != t.back()) ) {
                cout << t << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}