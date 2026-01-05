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
    string S;
    cin >> N >> S;
    string T="";
    T.push_back('b');
    rep(k, N) {
        if(k%3==0) {
            T.push_back('c');
            reverse(T.begin(),T.end());
            T.push_back('a');
            reverse(T.begin(),T.end());
        } else if(k%3==1){
            T.push_back('a');
            reverse(T.begin(),T.end());
            T.push_back('c');
            reverse(T.begin(),T.end());
        } else {
            T.push_back('b');
            reverse(T.begin(),T.end());
            T.push_back('b');
            reverse(T.begin(),T.end());
        }
        if(S==T) {
            cout << k+1 << endl;
            break;
        }
        if(T.size() > S.size()) {
            cout << -1 << endl;
            break;
        }
    }
    return 0;
}