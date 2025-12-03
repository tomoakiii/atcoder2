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
    ll N, M;
    cin >> N >> M;
    vector<string> S(N), T(M);
    unordered_set<string> NG;
    int tLen = 0;
    rep(i,N) {
        cin>>S[i];
        tLen += S[i].size();
    }
    if(tLen + N - 1 > 16) {
        cout << -1 << endl;
        return 0;
    }
    rep(i,M) {
        cin>>T[i];
        NG.insert(T[i]);
    }

    bool flg = false;
    string ans;
    vector<int> arr(N);
    rep(i,N) arr[i] = i;
    int mk = 16-tLen-(N-1);

    do {         
        
        auto func=[&](auto func, string in, int nx, int r)->void{
            if(flg) return;
            if(nx == N-1) {
                if(in.size()>=3 && in.size() <= 16){
                    if (NG.count(in) == 0) {
                        flg = true;
                        ans = in;
                        cout << ans << endl;
                        exit(0);
                    }
                }
                return;
            }
            
            if(flg) return;
            int k=1;
            in = in + "_";
            for(int k=0; k<=r; k++) {
                if(flg) return;                    
                func(func, in + S[arr[nx+1]], nx+1, r-k);
                in = in + "_";
            }
                
        };
        func(func, S[arr[0]], 0, mk);
        if(flg) break;
	} while (next_permutation(arr.begin(), arr.end()));

    
    cout << -1 << endl;
    return 0;
}