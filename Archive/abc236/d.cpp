#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (unsigned int i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int N;
    cin >> N;
    vector A(2*N-1, vector<ll>(2*N));
    rep(i,2*N-1) for(int j=i+1; j<2*N; j++) cin>>A[i][j];
    ll mx = 0;
    auto f = [&](auto f, int visit, ll sm)->void{        
        vector<int> arr{};
        rep(i, 2*N) {
            if(visit>>i & 1) arr.push_back(i);
        }        
        rep(i, 1) {
            for(unsigned int j=i+1; j<arr.size(); j++) {
                ll sm2 = sm ^ A[arr[i]][arr[j]];
                int visit2 = visit;
                visit2 &= ~(1<<arr[i]);
                visit2 &= ~(1<<arr[j]);
                if(visit2 == 0) {
                    chmax(mx, sm2);
                    continue;
                }
                f(f, visit2, sm2);
            }            
    	}
    };
    f(f, (1<<(2*N)) - 1, 0);
    cout << mx << endl;
    return 0;
}