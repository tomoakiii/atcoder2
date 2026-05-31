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
    vector<string> S(3);
    vector Si(3,vector<int>{});
    rep(i,3) {
        cin>>S[i];
        reverse(S[i].begin(),S[i].end());
        for(auto c: S[i]) Si[i].push_back(c-'a');
    }
    int turn = 0;
    while(true) {
        if(Si[turn].size() == 0) {
            cout << char(turn + 'A') << endl;
            return 0;
        }
        int nx = Si[turn].back();
        Si[turn].pop_back();
        turn = nx;
    }
    return 0;
}