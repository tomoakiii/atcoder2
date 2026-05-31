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
    vector<ll> V(5);
    rep(i,5) cin>>V[i];
    vector<int> ord(5);
    rep(i,3) ord[i] = 1;
    sort(ord.begin(), ord.end());
    priority_queue<ll> que;
    do{
        ll sm = 0;
        rep(i,5) {
            if(ord[i] == 1) sm += V[i];
        }
        que.push(sm);

    }while(next_permutation(ord.begin(), ord.end()));
    rep(i,2) que.pop();
    cout << que.top() << endl;
    return 0;
}