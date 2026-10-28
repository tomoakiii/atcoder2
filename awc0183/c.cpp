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
typedef modint998244353 mint;
using ull = unsigned long long;

class StringHash {
private:
    // 基数は奇数である必要があります。ここでは衝突しにくい素数を採用しています。
    const ull base = 1000000007ULL;
    vector<ull> hash;
    vector<ull> pow;
public:
    int N;
    StringHash(const string& S = "") {
        N = S.size();
        hash.assign(N + 1, 0);
        pow.assign(N + 1, 1);
        for (int i = 0; i < N; i++) {
            hash[i + 1] = hash[i] * base + (S[i] - 'a' + 1);
            pow[i + 1] = pow[i] * base;
        }
    }
    ull GetHash(int l, int r) {
        ull h1 = hash[r + 1];
        ull h2 = hash[l] * pow[r - l + 1];
        return h1 - h2;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    set<ull> st;
    vector<pair<ll,string>> S(N);
    rep(i,N){
        cin>>S[i].second;
        S[i].first=S[i].second.size();
    }
    sort(S.begin(),S.end());
    ll ans=0;
    for(auto [sz,s]:S){
        set<ull> visit;
        StringHash SH(s);
        rep(l,sz){
            for(int r=l;r<sz;r++){
                ll hs = SH.GetHash(l,r);
                int len = r-l+1;
                if(st.contains(hs) && !visit.contains(hs)){
                    ans++;
                    visit.insert(hs);
                    /*
                    cerr<<s<<" ";
                    for(int i=l;i<=r;i++)cerr<<s[i];
                    cerr<<endl;
                    */
                }
            }
        }
        st.insert(SH.GetHash(0,sz-1));
    }
    cout << ans << endl;
    return 0;
}