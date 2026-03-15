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
    ll N,L,R;
    cin >> N >> L >> R;
    string S; cin>>S;
    auto func = [&](int k)->ll{
        vector<ll> cnt('z'-'a' + 1);
        ll ret = 0;
        rep(i,N) {
            int a = S[i]-'a';
            ret += cnt[a];
            cnt[a]++;
            if(i>=k) {
                int b = S[i-k]-'a';
                cnt[b]--;
            }
        }
        return ret;
    };

    cout << func(R)-func(L-1)<<endl;
    return 0;
}