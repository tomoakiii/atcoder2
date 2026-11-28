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

/* encode: ランレングス圧縮を行う*/
template <class Type> class encode{
    private:
    deque<pair<Type, int>> ret;

    public:
     encode(vector<Type> str) {
        int n = (int)str.size();
        for (int l = 0; l < n;) {
            int r = l + 1;
            for (; r < n && str[l] == str[r]; r++) {};
            ret.push_back({str[l], r - l});
            l = r;
        }
    }

    deque<pair<Type, int>> get(){
        return ret;
    }

    // vectorで返すとき
    vector<pair<Type, int>> get_vector(){
        vector<pair<Type, int>> retv(ret.size());
        rep(i,ret.size()) retv[i]=ret[i];
        return retv;
    };
};

/* decode: ランレングス圧縮の復元を行う*/
template <class Type> class decode{
    private:
    deque<Type> ret;

    public:
     decode(const deque<pair<Type, int>>& code) {
        for (auto p : code) {
            for (int i = 0; i < p.second; i++) {
                ret.push_back(p.first);
            }
        }
    }

    deque<Type> get(){
        return ret;
    };
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];

    encode<ll> EN(A);
    auto R = EN.get();
    decode<ll> DE(R);
    auto D = DE.get();
    for(auto d:D) cerr<<d<<" ";
    cerr<<endl;

    vector<ll> ans;
    auto [l0,c0] = R[0];
    for(int i=1; i<=c0; i++){
        ans.push_back(c0-i+1);
    }
    R.pop_front();
    while(R.size()>1){
        auto [l,c] = R[0];
        for(int i=1; i<=c; i++){
            ans.push_back(min(i, c-i+1));
        }
        R.pop_front();
    }
    while(R.size()){
        auto [l1,c1] = R[0];
        for(int i=1; i<=c1; i++){
            ans.push_back(i);
        }
        R.pop_front();
    }
    rep(i,N)cout<<ans[i]<<" \n"[i==N-1];
    return 0;
}