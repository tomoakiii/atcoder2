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
    string S, T;
    cin >> S >> T;
    ll st=0, tt=0;
    rep(i,N){
        if(S[i]=='1') st=st*2 + 1;
        else st=st*2;
        if(T[i]=='1') tt=tt*2 + 1;
        else tt=tt*2;
    }
    if(st==tt){
        cout<<0<<endl;
        return 0;
    }
    if(N==1){
        cout<<1<<endl;
        return 0;
    }
    unordered_set<ll> visit;
    ll ans=-1;
    ll s = st;
    ll d = 0;
    bool flg = true;
    while(s != tt && flg){
        visit.insert(s);
        vector<ll> nexts;
        rep(i,N){
            ll ns = s ^ (1LL<<i);
            bool flg=true;
            rep(j,N-2){
                int a=(ns>>(j))%2ll;
                int b=(ns>>(j+1))%2ll;
                int c=(ns>>(j+2))%2ll;
                if(a==b && b==c) {
                    flg=false;
                    break;
                }
            }
            if(flg) nexts.push_back(ns);
        }
        sort(nexts.begin(), nexts.end());
        flg = false;
        for(auto ns: nexts){
            if(visit.contains(ns)) continue;
            s = ns;
            flg = true;
            d++;
            break;
        }
    };
    if(s == tt) cout << d << endl;
    else cout << -1 << endl;
    return 0;
}