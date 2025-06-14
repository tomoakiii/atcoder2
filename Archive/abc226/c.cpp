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
    vector A(N, vector<int>{});
    vector<ll> T(N);
    rep(i,N) {
        int L; cin>>T[i]>>L;
        A[i].resize(L);
        rep(j,L) {
            cin >> A[i][j];
            A[i][j]--;
        }        
    }
    ll time = 0;
    vector<bool> visit(N);
    auto f=[&](auto f, int cur)->void{        
        for(int a: A[cur]){
            if(visit[a]) continue;
            f(f, a);
        }
        time += T[cur];
        visit[cur] = true;
    };

    f(f,N-1);
    cout<<time<<endl;

    return 0;
}