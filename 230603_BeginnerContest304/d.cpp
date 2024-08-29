#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll W, H;
    cin >> W >> H;
    int N;
    cin >> N;
    vector<ll> p(N), q(N);
    rep(i, N) cin>>p[i]>>q[i];
    int A;
    cin >> A;
    vector<ll> a(A); 
    rep(i,A) cin>>a[i];
    int B;
    cin >> B;
    vector<ll> b(B);    
    rep(i,B) cin>>b[i];
    int indS=0, indL = 0;
    vector<pair<ll,ll>> gXY(N);
    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return p[i] < p[j]; });
    while(indS < N) {
        if (indL >= A) {
            gXY[ord[indS]].first = A;
            indS++;
            continue;
        }
        if(a[ord[indS]] < p[indL]) {
            gXY[ord[indS]].first = indL;
            indS++;
        } else {
            indL++;
        }
    }
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return q[i] < q[j]; });
    indS=0, indL = 0;
    while(indS < N) {
        if (indL >= B) {
            gXY[ord[indS]].second = B;
            indS++;
            continue;
        }
        if(b[ord[indS]] < q[indL]) {
            gXY[ord[indS]].second = indL;
            indS++;
        } else {
            indL++;
        }
    }
    map<pair<ll,ll>, ll> mp;
    rep(i,N) {
        mp[gXY[i]]++;
    }
    ll mn=INF, mx=0;
    for(auto m: mp) {
        mn = min(mn, m.second);
        mx = max(mx, m.second);
    }
    if(mp.size() < (A+1)*(B+1)) {
        mn = 0;
    }
    cout << mn << " " << mx << endl;
    return 0;
}