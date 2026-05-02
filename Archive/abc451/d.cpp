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
// Coodinate Compression
// https://youtu.be/fR3W5IcBGLQ?t=8550
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
    ll N;
    cin >> N;
    vector<unordered_set<ll>> st(13);
    ll p=1;

    auto count_d = [&](ll x)->ll{
        ll ret=0;
        while(x){
            ret++;
            x/=10;
        }
        return ret;
    };

    while(p <= 1e10){
        ll d = count_d(p);
        st[d].insert(p);
        p*=2;
    }

    vector<bool> visit(20);
    visit[1]=true;

    ll p1=1;
    vector<ll> pow10(15,1);
    rep(i,14){
        pow10[i+1] = pow10[i] * 10;
    }

    for(ll x=1; x<=9; x++) {
        for(ll p=1; p<=x; p++) {
            ll q = x-p;
            if(q<p) break;
            for(auto s1:st[p]){
                for(auto s2:st[q]) {
                    st[x].insert(s1*pow10[q] + s2);
                    st[x].insert(s2*pow10[p] + s1);
                }
            }
        }
        if(st[x].size() < N) {
            N-=st[x].size();
            continue;
        }
        vector<ll> vec(st[x].size());
        int id=0;
        for(auto s: st[x]) vec[id++]=s;
        sort(vec.begin(),vec.end());
        cout<<vec[N-1]<<endl;
        return 0;
    };

    return 0;
}