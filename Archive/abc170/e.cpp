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
    ll N,Q;
    cin >> N >> Q;
    vector<ll> A(N);
    vector<multiset<ll>> els(2E5+1);
    vector<ll> where(N);
    rep(i,N) {
        ll B;
        cin >> A[i] >> B;
        els[B].insert(A[i]);
        where[i] = B;
    }

    multiset<ll> ans;
    for(auto e: els) {
        if(e.size() > 0) {
            ans.insert(*e.rbegin());
        }
    }
    while(Q--) {
        ll C,D;
        cin >> C >> D;
        C--;
        ll org = where[C];
        where[C] = D;

        ll omx = *els[org].rbegin();
        els[org].erase(els[org].find(A[C]));
        ans.erase(ans.find(omx));
        if(!els[org].empty()){
            ll nmx = *els[org].rbegin();
            ans.insert(nmx);
        }
        if (!els[D].empty()){
            omx = *els[D].rbegin();
            ans.erase(ans.find(omx));
        }
        els[D].insert(A[C]);
        ans.insert(*els[D].rbegin());
        cout << *ans.begin() << endl;
    }
    return 0;
}