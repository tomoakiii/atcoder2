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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    struct node{
        ll p,t;
    };
    vector<node> PT(N);
    rep(i,N) {
        node pt;
        cin>>pt.t>>pt.p;
        PT[i]=pt;
    }
    auto comp = [&](const node &a, const node &b)->bool{
        ll tsm = a.t+b.t;
        if(tsm * b.p + a.t * a.p < tsm * a.p + b.t * b.p) return true;
        else return false;
    };
    sort(PT.begin(),PT.end(),comp);
    ll ans = 0;
    ll sm = 0;
    for(auto pt:PT){
        sm += pt.t;
        ans += pt.p*sm;
    }
    cout<<ans<<endl;
    return 0;
}