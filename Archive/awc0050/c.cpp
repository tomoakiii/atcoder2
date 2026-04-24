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
    vector<ll> vec;
    ll xo=0;
    stack<ll> que;
    rep(i,N) {
        string s; cin>>s;
        if(s=="PUT") {
            ll x; cin>>x;
            xo ^= x;
            que.push(x);
        } else if(s=="REMOVE"){
            ll x=que.top();
            que.pop();
            xo ^= x;
        } else {
            vec.push_back(xo);
        }
    }
    map<ll,ll>mp;
    rep(i,vec.size()){
        if(mp.contains(vec[i])) {
            cout<<mp[vec[i]]<<endl;
        } else {
            cout<<-1<<endl;
        }
        mp[vec[i]]=i+1;
    }
    return 0;
}