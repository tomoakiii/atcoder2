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
    ll N,K;
    cin >> N >> K;
    vector A(N, vector(K+1, vector<vector<ll>>{}));
    auto func = [&](auto func, ll k, ll id)->void{
        if(id==1){
            A[0][k].push_back(vector<ll>(1,k));
            return;
        }
        rep(i,k+1){
            ll rm = k - id*i;
            if(rm<0)break;
            if(rm==0){
                ll p = k/id;
                vector<ll> v(id);
                rep(j,id-1) v[j]=0;
                v[id-1]=p;
                A[id-1][k].push_back(v);
                continue;
            }

            if(A[id-2][rm].empty()) func(func, rm, id-1);
            if(A[id-2][rm].empty()) A[id-2][rm].push_back(vector<ll>(1,-1));
            if(A[id-2][rm][0][0] == -1) continue;
            for(auto v2: A[id-2][rm] ) {
                vector<ll> v(id);
                rep(i,id-1) v[i]=v2[i];
                v[id-1]=i;
                A[id-1][k].push_back(v);
            }

        }
    };
    func(func, K, N);
    sort(A[N-1][K].begin(), A[N-1][K].end());
    for(auto g:A[N-1][K]){
        rep(i,N) cout<<g[i]<<" \n"[i==N-1];
    }
    return 0;
}