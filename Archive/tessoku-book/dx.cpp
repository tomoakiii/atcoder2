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
typedef pair<ll, pair<int,int>> pl;
typedef modint1000000007 mint;

int main(){
    string S; cin>>S;
    int N = S.size();
    vector<int> last(N,-1);
    int d = 0;
    rep(i,N) {
        if(S[i] == '(') {
            last[d] = i;
            d++;
        } else {
            d--;
            cout << last[d]+1 << " " << i+1 << endl;
        }
    }
    return 0;
}