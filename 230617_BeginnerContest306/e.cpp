#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, K, Q;
    cin >> N >> K >> Q;
    vector<ll> A(N);
    vector<ll> X(Q), Y(Q);
    set<pair<ll, int>> st1, st2;
    rep(i, K) st1.insert({0, i});
    for(int i=K; i<N; i++) st2.insert({0, i});
    st1.insert({INF, -1});
    st2.insert({-INF, -1});
     ll sm = 0;
    rep(i, Q) {
        cin >> X[i] >> Y[i];
        X[i]--;
        pair<ll, int> p0 = {A[X[i]], X[i]};
        A[X[i]] = Y[i];
        pair<ll, int> p1 = {Y[i], X[i]};
        auto it = st1.begin();
        auto p2 = *it;
        auto it2 = st2.end();
        it2--;
        auto p3 = *it2;
        if (st1.count(p0)) {
            st1.erase(p0);
            sm -= p0.first;
            if (p3.first > p1.first) {
                st2.insert(p1);
                st2.erase(p3);
                st1.insert(p3);
                sm += p3.first;
            } else {
                st1.insert(p1);
                sm += p1.first;
            }
        } else {
            st2.erase(p0);
            if (p2.first < p1.first) {
                st1.insert(p1);
                st1.erase(p2);
                st2.insert(p2);
                sm += p1.first;
                sm -= p2.first;
            } else {
                st2.insert(p1);
            }
        }
        cout << sm << endl;
    }    
    return 0;
}