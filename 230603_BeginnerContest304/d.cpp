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
<<<<<<< HEAD
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
=======
    ll N;
    cin >> N;
    vector<pair<ll, ll>> pq(N, {0,0}), pq2(N, {0,0});
    rep(i,N){
        cin >> pq[i].first >> pq[i].second;        
    }
    sort(pq.begin(), pq.end()); // x
    rep(i,N){
        pq2[i].first = pq[i].second;
        pq2[i].second = pq[i].first;
    }    
    ll A, B;
    cin >> A;
    vector<ll> a(A+2, 0);
    for(int i=1; i<=A; i++) cin >> a[i];
    a[A+1] = W;
    cin >> B;
    vector<ll> b(B+2, 0);
    for(int i=1; i<=B; i++) cin >> b[i];
    b[B+1] = H;

    ll mx=0, mn=INF, cnt=0;
    set<pair<ll,ll>> st;
    ll lx1=-1, lx2=-1, ly1=-1, ly2=-1;
    int indx, indy;
    int ind1, ind2;            
    rep(i, N) {
        if (lx1 <= pq[i].first && pq[i].first <= lx2) {
        } else {
            ly1=-1, ly2=-1;
            auto itx = lower_bound(a.begin(), a.end(), pq[i].first);
            indx = distance(a.begin(), itx);

            auto f = [&](ll key)->int{
                int ok, ng;
                ok = N-1;
                ng = 0;
                while(ok-ng > 1) {
                    int mid = (ok+ng)/2;
                    if (pq[mid].first > key) ok = mid;
                    else ng = mid;
                }
                return ok;
            };
            lx1 = a[indx-1];
            lx2 = a[indx];
            if (pq[0].first > lx1) {
                ind1 = 0;
            } else {
                ind1 = f(lx1);
            }            
            if (lx2 > pq[N-1].first) {
                ind2 = N;
            } else {
                ind2 = f(lx2);
            }
            sort(pq2.begin()+ind1, pq2.begin()+ind2);
        }

        if (ly1 <= pq[i].second && pq[i].second <= ly2) {
        } else {
            cnt++;
            auto ity = lower_bound(b.begin(), b.end(), pq[i].second);
            indy = distance(b.begin(), ity);
            ly1 = b[indy-1];
            ly2 = b[indy];

            auto f2 = [&](ll key)->int{
                int ok, ng;
                ok = ind2;
                ng = ind1;
                while(ok-ng > 1) {
                    int mid = (ok+ng)/2;
                    if (pq2[mid].first > key) ok = mid;
                    else ng = mid;
                }
                return ok;
            };
            
            int ind3, ind4;
            if (pq2[ind1].first > ly1) {
                ind3 = ind1;
            } else {
                ind3 = f2(ly1);
            } 

            if (ly2 > pq2[ind2-1].first) {
                ind4 = ind2;
            } else {
                ind4 = f2(ly2);
            }
            ll x = ind4 - ind3;
            mx = max(x, mx);
            mn = min(x, mn);
        }
    }
    if (cnt < (A+1)*(B+1)) {
        mn = 0;
    }    
>>>>>>> ed69aec9ce59af355a2a749389207fd99e3e4f60
    cout << mn << " " << mx << endl;
    return 0;
}