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
    ll N,K;
    cin >> N >> K;
    vector<string> S(N);
    rep(i,N) cin>>S[i];
    auto comp2 = [&](const string &a1, const string &a2)->bool{
        if(a2.size() > a1.size()) return false;
        if(a2.size() < a1.size()) return true;
        return (a2 < a1);
    };
    sort(S.begin(), S.end(), comp2);
    vector<string> ans1(K),ans2(K);
    rep(j,K) ans1[j] = ans2[j] = S[j];
    vector<pair<ll,string>> vec;
    for(int j=K;j<N;j++) vec.push_back({stol(S[j]), S[j]});
    sort(vec.rbegin(), vec.rend());
    if(!vec.empty()) ans2[K-1] = vec[0].second;
    auto conv = [&](vector<string> ax)->string{
        auto comp = [&](const string &a1, const string &a2)->bool{
            if(a1+a2 > a2+a1) return true;
            else return false;
        };
        sort(ax.begin(), ax.end(), comp);
        string s = "";
        rep(i,K) s += ax[i];
        reverse(s.begin(), s.end());
        while(s.back() == '0') s.pop_back();
        reverse(s.begin(), s.end());
        if(s.empty()) s="0";
        return s;
    };
    auto a1 = conv(ans1);
    auto a2 = conv(ans2);
    if(comp2(a1,a2)) cout<<a1<<endl;
    else cout<<a2<<endl;
    return 0;
}