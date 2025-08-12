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
    vector<string> ans;
    while(N) {
        if(N%2 == 1) {
            ans.push_back("A");
            N--;
        } else {
            ans.push_back("B");
            N/=2;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto a: ans) cout<<a;
    return 0;
}