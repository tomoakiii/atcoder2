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
    ll N,K; string S;
    cin >> N >> K >> S;
    vector<pair<ll,ll>> num{};
    int col = -1;
    ll cnt = 0;
    int cnt0 = 0;
    int sz = S.size();
    
    for(auto c:S) {
        int cn = c-'0';
        if(cn != col){
            num.push_back({cnt,col});
            if(col==0) cnt0++;
            cnt = 1;
        }
        else cnt++;
        col = cn;
    }
    num.push_back({cnt,col});
    if(col==0) cnt0++;
    if(cnt0 <= K) {
        cout << sz << endl;
        return 0;
    }    
    ll sm = 0;
    int r = 0;
    for(;r<N;++r){
        if(num[r].second == 0) {
            K--;
            if(K<0) break;
        }
        sm += num[r].first;
    }
    int l = 0;    
    ll ans = sm;
    while(r<num.size()) {
        sm += num[r++].first;
        if(r<num.size())sm += num[r++].first;
        while(num[l].second != 0) {
            sm -= num[l].first;
            l++;
        }
        sm -= num[l++].first;
        chmax(ans,sm);
    }

    cout << ans << endl;
    return 0;
}