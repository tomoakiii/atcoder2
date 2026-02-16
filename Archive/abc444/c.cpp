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
    multiset<ll> A;
    ll mn = INF;
    ll mx = 0;
    rep(i,N) {
        ll a; cin>>a; A.insert(a);
        chmax(mx, a);
        chmin(mn, a);
    }

    vector<ll> ans;
    ans.push_back(mx);
    ans.push_back(mn+mx);

    vector<bool> isOK(2);
    rep(kkk,2) {
        ll t = ans[kkk];
        bool flg = true;
        auto B = A;
        while(!A.empty()) {
            ll a = *A.begin();
            A.erase(A.find(a));
            if(a == t) continue;
            else {
                if(A.contains(t-a)) A.erase(A.find(t-a));
                else {
                    flg = false;
                    break;
                }
            }
        }
        isOK[kkk] = flg;
        swap(B,A);
    }
    rep(i,2) if(isOK[i]) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}