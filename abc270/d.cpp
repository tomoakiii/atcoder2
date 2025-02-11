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
    ll N, K;
    cin >> N >> K;
    vector<int> A(K);
    rep(i,K) cin>>A[i];    
    vector str(N+1, vector<int>(2, -1));
    // return (how many I can get, )
    auto func = [&](auto func, int rem, bool turn) -> vector<int> {        
        int me = 0, you = 1;
        if(!turn) swap(me, you);
        vector<int> ret(2);
        for(auto a: A) {
            int rem2 = rem - a;
            if(rem2 < 0) continue;
            vector<int> out(2);
            out[me] = a;
            vector<int> r(2);
            if(str[rem2][you] == -1){
                r = func(func, rem2, !turn);
            } else {
                r = str[rem2];
            }
            out[me] += r[me];
            out[you] += r[you];
            if(out[me] > ret[me]) {
                ret[me] = out[me], ret[you] = out[you];                
            }
        }
        str[rem][me] = ret[me], str[rem][you] = ret[you];
        return ret;
    };
    auto out = func(func, N, true);
    cout << out[0] << endl;

    return 0;
}