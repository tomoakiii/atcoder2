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
typedef pair<ll,pair<ll,int>> pll;
template<typename T=int>
struct CC {
  bool initialized;
  vector<T> xs;
  CC(): initialized(false) {}
  void add(T x) { xs.push_back(x);}
  void init() {
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    initialized = true;
  }
  int operator()(T x) {
    if (!initialized) init();
    return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
  }
  T operator[](int i) {
    if (!initialized) init();
    return xs[i];
  }
  int size() {
    if (!initialized) init();
    return xs.size();
  }
};
int main(){
    ll N,Q;
    cin >> N >> Q;
    vector<pair<ll,ll>> XV(N);
    CC cc;
    CC cv;
    rep(i,N) {
        cin>>XV[i].first>>XV[i].second;
        cv.add(XV[i].second);
    }
    sort(XV.begin(),XV.end());
    vector<ll> L(Q),R(Q);
    rep(i,Q){
        cin>>L[i]>>R[i];
        cc.add(L[i]);
    }
    ll sM = sqrt(cc.size());
    vector Mo(Q, vector<tuple<ll,ll,int>>{});
    rep(i,Q) {
        ll p=cc(L[i])/sM;
        Mo[p].push_back(make_tuple(R[i],L[i],i));
    }
    rep(p,Q) {
        if(p==0) sort(Mo[p].begin(), Mo[p].end());
        else  sort(Mo[p].rbegin(), Mo[p].rend());
    }
    int l=0, r=0;
    ll sm = 1;
    ll ln = 1;
    ll Mv = cv.size();
    vector<ll> cnt(Mv);
    cnt[cv(XV[0].second)]++;
    auto exec = [&](ll tl, ll tr)->void{
        auto update = [&](ll v, bool flg)->void{
            if(flg) {
                cnt[v]++;
                if(cnt[v] == 1) ln++;
                sm += cnt[v];
            } else {
                sm -= cnt[v];
                cnt[v]--;
                sm += cnt[v];
                if(cnt[v] == 0) ln--;
            }
        };
        while(r<N && XV[r].first <= tr) {
            r++;
            if(r==N) break;
            update(cv(XV[r].second),true);        
        }
        while(r>=0 && XV[r].first > tr) {
            update(cv(XV[r].second),false);
            if(r==0) break;
            else r--;
        }
        while(l>=0 && XV[l].first >= tl) {
            update(cv(XV[l].second),false);
            if(l==0) break;
            else l--;
        }
        while(l<r && XV[l].first < tl) {
            l++;
            update(cv(XV[l].second),true);
        }
    };
    vector<ll> ans(Q);
    for(auto vv : Mo) {
        for(auto [r,l,q] : vv) {
            exec(l,r);
            ll a = ln * (ln+1) / 2;
            a -= (sm - ln);
            ans[q] = a;
        }
    }
    for(auto a:ans) cout<<a<<endl;
    return 0;
}