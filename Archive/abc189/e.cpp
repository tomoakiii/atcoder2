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

vector<vector<ll>> matmul(vector<vector<ll>> &A, vector<vector<ll>> &B) {
    vector ret(3, vector<ll>(3));
    rep(i, 3) {
        rep(j, 3) {
            rep(k, 3) {
                ret[i][j] += A[i][k] * B[k][j];
            }            
        }
    }
    return ret;
}

void ans(vector<vector<ll>> &A, vector<ll> &X) {
    vector<ll> ans(3);
    rep(i, 3) {
        rep(j, 3) {            
            ans[i] += A[i][j] * X[j];            
        }
    }
    cout << ans[0] << " " << ans[1] << endl;
}


int main () {
    ll N; cin >> N;
    vector<vector<ll>> rotA = {{0, -1, 0}, {1, 0, 0}, {0, 0, 1}};
    vector<vector<ll>> rotB = {{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}};    
    vector<ll> X(N), Y(N);
    rep(i,N) cin>>X[i]>>Y[i];
    ll M; cin >> M;
    vector MAT(M+1, vector(3, vector<ll>(3)));
    MAT[0] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};    
    rep(i,M) {
        int opi; cin >> opi;
        if(opi == 1) {
            MAT[i+1] = matmul(rotB, MAT[i]);
        } else if (opi == 2) {
            MAT[i+1] = matmul(rotA, MAT[i]);
        } else if(opi == 3) {
            ll p; cin >> p;
            vector<vector<ll>> flip = {{-1, 0, 2*p}, {0, 1, 0}, {0, 0, 1}};
            MAT[i+1] = matmul(flip, MAT[i]);
        } else {
            ll p; cin >> p;
            vector<vector<ll>> flip = {{1, 0, 0}, {0, -1, 2*p}, {0, 0, 1}};
            MAT[i+1] = matmul(flip, MAT[i]);
        }        
    }
    ll Q; cin>>Q;
    while(Q--) {
        int A, B; cin >> A >> B;
        B--;
        vector<ll> XY = {X[B], Y[B], 1};
        ans(MAT[A], XY);
    }
    return 0;
}
