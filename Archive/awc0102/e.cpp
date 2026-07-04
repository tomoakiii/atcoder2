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
    string Ns;
    ll N,M;
    cin >> Ns >> M;

    map<ll,ll> mp;
    for(auto i=2;i<=M;i++){
        while(M%i == 0) {
            M/=i;
            mp[i]++;
        }
    }
    ll sz = mp.size();

    vector<ll> pf(10);
    for(auto [v,c]:mp) {
        if(v>9) {
            cout << 0 << endl;
            return 0;
        }
        pf[v]=c;
    }
    map<vector<ll>, ll> even, low;
    even[pf] = 1;
    vector<vector<pair<ll,ll>>> one_nine(10);

    one_nine[2].push_back({2,1});
    one_nine[3].push_back({3,1});
    one_nine[4].push_back({2,2});
    one_nine[5].push_back({5,1});
    one_nine[6].push_back({2,1});
    one_nine[6].push_back({3,1});
    one_nine[7].push_back({7,1});
    one_nine[8].push_back({2,3});
    one_nine[9].push_back({3,2});
    map<vector<ll>, ll> even2, low2;
    auto debug = [&](int c)->void{
        cerr<<c<<"-------------"<<endl;
        for(auto [rem,vol]:even) {
            cerr<<vol<<" : ";
            rep(i,10) cerr<<rem[i]<<" \n"[i==9];

        }
        cerr<<c<<"-------------"<<endl;
        for(auto [rem,vol]:low) {
            cerr<<vol<<" : ";
            rep(i,10) cerr<<rem[i]<<" \n"[i==9];
        }
    };

    rep(s_i, Ns.size()){
        char c = Ns[s_i];
        ll cn=c-'0';
        even2.clear();
        low2.clear();
        // debug(c);

        auto decrease = [&](vector<ll> rem2, int i) -> vector<ll>{
            for(auto [fct, cnt]: one_nine[i]) {
                rem2[fct] -= cnt;
                if(rem2[fct] < 0) rem2[fct] = 0;
            }
            return rem2;
        };

        if(s_i < Ns.size() - 1) low2[pf] = 1;
        for(auto [rem, vol] : even) {
            for(int i=1;i<=9;i++){
                auto rem2 = decrease(rem, i);
                if(i<cn) {
                    low2[rem2] += vol;
                } else if (i==cn)  {
                    even2[rem2] += vol;
                }
            }
        }
        for(auto [rem, vol] : low) {
            for(int i=1;i<=9;i++){
                auto rem2 = decrease(rem, i);
                low2[rem2] += vol;
            }
        }
        swap(low2,low);
        swap(even2,even);
    }
    // debug(99999);
    ll ans = 0;
    vector<ll> zeros(10);
    ans += even[zeros] + low[zeros];
    cout<<ans<<endl;
    return 0;
}