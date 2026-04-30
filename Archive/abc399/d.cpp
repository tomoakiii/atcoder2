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
    ll T;
    cin >> T;
    while(T--){   
        ll n, N;
        cin >> n;
        N = n*2;
        vector<ll> A(N), NG(n);
        rep(i, N) {
            cin>>A[i];
            A[i]--;
        }
        rep(i,N-1) if(A[i] == A[i+1]) NG[A[i]] = 1;
        map<int, set<pair<int, int>>> vs;
        vector<ll> visit(n);        
        int cnt = 0;        
        rep(i,N) {
            if(NG[A[i]] == 1) continue;
            set<pair<int, int>> nei{};
            if(i>0) {
                if(A[i] < A[i-1]) nei.insert({A[i-1], i-1});        
            }
            if(i<N-1) {
                if(A[i] < A[i+1]) nei.insert({A[i+1], i+1});
            }
            if(visit[A[i]]) {
                for(auto [nx, p]: nei) {
                    if(NG[nx] == 1) continue;
                    for(auto [anx, ap] : vs[A[i]]) {
                        if(p != ap && anx == nx) cnt++;
                    }                    
                }
            } else {
                vs[A[i]] = nei;
                visit[A[i]] = true;
            }            
        }
        cout << cnt << endl;
    }
    return 0;
}