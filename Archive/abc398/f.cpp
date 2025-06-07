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
    string S;
    cin >> S;
    int N = S.size();
    if(N==1) {
        cout << S << endl;
        return 0;
    }
    string T = S;
    reverse(T.begin(), T.end());
    T = T + S;    
    vector v = z_algorithm(T);
    int mx= 0;
    rep(i,N) {
        if(v[N+i] == N-i) {
            cout << S;
            if(i>0) {
                for(int j=i-1; j>=0; j--) cout<<S[j];                
            }
            cout<<endl;
            return 0;
        }
    }
    return 0;
}