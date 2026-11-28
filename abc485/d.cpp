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
    ll N;
    cin >> N;
    string S; cin>>S;
    vector<ll> R(N, N);
    vector<ll> L(N, N);
    rep(kkk,2){
        unordered_map<char,int> mp;
        int r = -1;
        rep(l,N){
            while(r+1<N && mp.size() < 3){
                r++;
                mp[S[r]]++;
            }
            if(mp.size() == 3) R[l]=r;
            mp[S[l]]--;
            if(mp[S[l]] == 0) mp.erase(S[l]);
        }
        swap(R,L);
        reverse(S.begin(),S.end());
    }

    int st = R[0];
    int ed = N-1-L[0];
    ll ans = 0;
    for(int i = st+1; i<ed; i++){
        if(R[i] < ed) ans+=ed-R[i];
    }
    cout << ans << endl;
    return 0;
}