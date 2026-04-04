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
typedef pair<ll,ll> pll;
int main(){
    ll N,Q;
    cin >> N >> Q;
    vector<pll> XV(N);

    CC<ll> cv;
    rep(i,N) {
        cin>>XV[i].first>>XV[i].second;
        cv.add(XV[i].second);
    }
    sort(XV.begin(),XV.end());
    ll sM = sqrt(Q);
    ll MoSize = (N/sM)+1;
    vector Mo(MoSize, vector<tuple<ll,ll,int>>{});
    rep(i,Q){
        ll L,R; cin>>L>>R;
        pll key = {L,0};
        int l = lower_bound(XV.begin(), XV.end(), key)-XV.begin();
        key = {R,INF};
        int r = lower_bound(XV.begin(), XV.end(), key)-XV.begin();
        if(l<N) {
            ll p=l/sM;
            Mo[p].push_back(make_tuple(r,l,i));
        }
    }
    rep(p,MoSize) {
        if(p%2==0) sort(Mo[p].begin(), Mo[p].end());
        else  sort(Mo[p].rbegin(), Mo[p].rend());
    }
    vector<int> vlist(N);
    rep(i,N) vlist[i] = cv(XV[i].second);
    int l=0, r=0;
    ll sm = 0, ln = 0;
    ll Mv = cv.size();
    vector<ll> cnt(Mv);
    auto exec = [&](ll tl, ll tr)->void{
        auto update = [&](int i, bool flg)->void{
            ll v = vlist[i];
            if(flg) {
                cnt[v]++;
                ln++;
                sm += cnt[v];
            } else {
                sm -= cnt[v];
                cnt[v]--;
                ln--;
            }
        };
        while(r < tr) {
            update(r,true);
            r++;
        }
        while(l > tl) {
            l--;
            update(l,true);
        }
        while(r > tr) {
            r--;
            update(r,false);
        }
        while(l < tl) {
            update(l,false);
            l++;
        }
    };
    vector<ll> ans(Q);
    for(auto vv : Mo) {
        for(auto [tr,tl,q] : vv) {
            exec(tl,tr);
            //cerr<<tl<<" "<<tr<<endl;
            ll a = ln * (ln+1) / 2;
            a -= (sm - ln);
            ans[q] = a;
        }
    }
    for(auto a:ans) cout<<a<<endl;
    return 0;
}