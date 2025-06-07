/* https://atcoder.jp/contests/abc398/tasks/abc398_f */
/* https://atcoder.jp/contests/abc284/editorial/5469?lang=ja */
/* THERE --> EREHT THERE と並べて、EREHT内のPrefixとTHERE内のSuffixが最長何文字一致しているかを測る */
/* EREHT THEREを入れたときのz-algorithmの出力は [10 0 1 0 0 0 0 3 0 1] になるので N-1-3 の要素で3文字一致していることがわかる */
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