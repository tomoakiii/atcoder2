#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    string S; cin>>S;
    ll N; cin >> N;
    set<string> st;
    string t = "";  
    int cnt = 0;
    sort(S.begin(), S.end());
    for(auto c1: S) {
        t.push_back(c1);
        for(auto c2:S) {
            t.push_back(c2);
            cnt++;
            if(cnt == N) {
                cout << t << endl;
                return 0;
            }
            t.pop_back();
        }
        t.pop_back();
    }
    return 0;
}