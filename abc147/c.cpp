#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int N; cin>>N;
    vector rel(N, vector<int>(N, -1));
    rep(i,N) {
        int A; cin>>A;
        while(A--) {
            int x, y; cin>>x>>y; x--;
            rel[i][x] = y;
        }
    }
    int ans = 0;
    rep(k, 1<<N) {
        vector<int> honest(N, -1);
        bool flg = true;
        rep(i, N) {
            bool my_honest = (k>>i & 1);
            if( (my_honest && honest[i] == 0) || 
                (!my_honest && honest[i] == 1) ) {
                flg = false;
                break;
            }
            honest[i] = 1;
            if(my_honest) {
                rep(j, N) {
                    bool your_honest_assump = (k>>j & 1);
                    int your_honest_decl = rel[i][j];
                    if( (your_honest_decl == 1 && !your_honest_assump) || 
                        (your_honest_decl == 0 && your_honest_assump) ){
                        flg = false;
                        break;
                    }                    
                    honest[j] = your_honest_decl;
                }
            }            
        }
        if(flg) {
            chmax(ans, (int)popcount(k));
        }
    }
    cout << ans << endl;
    return 0;
}