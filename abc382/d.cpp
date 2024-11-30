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
    int N, M;
    cin >> N >> M;
    
    vector ans(1E7, vector<int>(N));
    int id = 0;
    auto func = [&](auto func, vector<int> T, int cnt)->void {
        if(cnt == N) {
            rep(i,N) {
                ans[id][i] = T[i];
            }
            id++;
            return;
        }
        for(int i = 10; i <= M ; i++ ) {
            T[cnt] = T[cnt-1] + i;
            if (T[cnt] + 10*(N-1-cnt) > M) break;
            func(func, T, cnt+1);
        }
    };

    vector<int> A(N);
    for(int i=1; i<=M-10*(N-1); i++) {
        A[0] = i;
        func(func, A, 1);
    }

    cout << id << endl;
    rep(i, id) {
        rep(j, N) cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}