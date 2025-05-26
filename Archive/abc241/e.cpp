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
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    int cnt = 0;
    vector<bool> visit(N);
    vector<int> ord{};
    ll a = 0, sm = 0;
    int ordst;
    while(K > 0){
        int nx = a%N;
        if(visit[nx]) {
            rep(i, ord.size()) {
                if(ord[i] == nx) {
                    ordst = i;
                    break;
                }
            }
            break;
        }
        visit[nx] = true;
        ord.push_back(nx);
        a += A[nx];
        
        K--;
    }
    vector<int> ord2{};
    for(int i = ordst; i < ord.size(); i++) {
        ord2.push_back(ord[i]);
        sm += A[ord[i]];
    }
    swap(ord2, ord);
    ll sz = ord.size();
    ll x = K/sz;
    a += x*sm;
    K -= x*sz;
    while(K){
        int nx = a % N;
        a += A[nx];
        K--;
    }
    cout << a << endl;
    return 0;
}