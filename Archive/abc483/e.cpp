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
    ll N,M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i,N) cin>>S[i];
    ll ans = 0;

    auto func = [&](ll x)->ll{
        unordered_map<string, ll> mp;
        ll cnt = 0;
        rep(i,N){
            string s=S[i];
            vector<string> st;
            if(x==1){
                rep(j,M){
                    char c=s[j];
                    s[j]='?';
                    st.push_back(s);
                    s[j]=c;
                }
            } else if (x == 0){
                st.push_back(s);
            } else if (x == 2){
                rep(j,M-1){
                    char c=s[j];
                    s[j]='?';
                    for(int j2=j+1; j2<M; j2++){
                        char c2=s[j2];
                        s[j2]='?';
                        st.push_back(s);
                        s[j2]=c2;
                    }
                    s[j]=c;
                }
            }
            for(auto s:st){
                if(mp.contains(s))cnt+=mp[s];
            }
            for(auto s:st) mp[s]++;
        }
        return cnt;
    };
    ll a = func(0);
    ll b = func(1);
    ll c = func(2);
    cerr << a << " " << b << " " << c << endl;
    b -= a * M;
    ll Mc2 = M * (M-1) / 2;
    c -= a * Mc2 + b * (M-1);
    cout << a + b + c << endl;
    return 0;
}