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

double angle(ll xi, ll yi){
    if(xi == 0) {
        if(yi > 0) return 0;
        else return 180;
    }
    if(yi == 0) {
        if(xi > 0) return 90;
        else return 270;
    }
    double x = xi, y = yi;
    if(x >= 0 && y >= 0) {
        return atan(x/y);
    } else if (x >= 0 && y < 0) {
        return 180. - atan(x/(-y));
    } else if (x < 0 && y < 0) {
        return 180. + atan(x/y);
    } else {
        return 360. - atan((-x)/y);
    }
}



int main(){
    ll N,Q;
    cin >> N >> Q;
    map<pair<ll,ll>, int> mp;
    int id = 0;
    set<pair<double, int>> st;
    vector member(N, vector<int>{});
    rep(i,N) {
        ll x, y;
        cin>>x>>y;
        pair<int,int> p;
        if(x==0) {
            if(y>0) p = {0,1};
            else p ={0,-1};
        } else if(y==0) {
            if(x>0) p={1,0};
            else p={-1,0};
        } else {
            ll g = gcd(x,y);
            x/=g; y/=g;
            p={x,y};
        }
        if(!mp.contains(p)) {
            mp[p] = id;
            id++;
            double ag = angle(x,y);
            st.insert({ag, mp[p]});
        }
        member[mp[p]].push_back(i);
    }

    vector<int> ord;
    vector<int> posA(N), posB(N);
    int indx = 0;
    for(auto [ag, q]: st) {
        indx = ord.size() - 1;
        for(auto i: member[q]) {
            ord.push_back(i);
            posA[i] = indx;
            posB[i] = indx + member[q].size();
        }
    }
    while(Q--) {
        int A, B; cin>>A>>B; A--,B--;
        if(posA[B] >= posA[A]) {
            cout << posB[B] - posA[A] << endl;
        } else {
            ll ans = N;
            ans -= posB[A] - posA[B];
            ans += posB[A] - posA[A];
            ans += posB[B] - posA[B];
            cout << ans << endl;
        }
    }

    return 0;
}