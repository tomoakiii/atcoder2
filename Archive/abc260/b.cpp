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
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<pair<int, int>> a(n), b(n), sm(n);
    rep(i,n) {
        cin>>a[i].first;
        a[i].first *= -1;
        a[i].second = i;
    }
    rep(i,n) {
        cin>>b[i].first;
        b[i].first *= -1;
        b[i].second = i;
    }
    rep(i,n){
        sm[i].first = a[i].first + b[i].first;
        sm[i].second = i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(sm.begin(), sm.end());
    vector<bool> pas(n);
    rep(i, x) {
        pas[a[i].second] = true;
    }
    int id = 0, cnt = 0;
    while(cnt < y) {
        if (!pas[b[id].second]) {
            pas[b[id].second] = true;
            cnt++;
        }
        id++;
    }
    id = 0;
    cnt = 0;
    while(cnt < z) {
        if (!pas[sm[id].second]) {
            pas[sm[id].second] = true;
            cnt++;
        }
        id++;
    }
    rep(i, n) if(pas[i]) cout << (i+1) << endl;
    cout << endl;
    return 0;
}