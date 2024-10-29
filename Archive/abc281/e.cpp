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
    ll N,M,K;
    cin >> N >> M >> K;    
    vector<ll> A(N+1, 0);
    rep(i,N) cin>>A[i+1];
    set<pair<ll, int>> main, sub, NG;
    ll sum = 0;
    vector<pair<ll,int>> tmp(M);


    for(int i=1; i<=M; i++) tmp[i-1] = {A[i], i};
    sort(tmp.begin(), tmp.end());

    for(int i=0; i<K; i++) {
        sum += tmp[i].first;
        main.insert(tmp[i]);
    }
    

    for(int i=1; i<=M; i++) {
        if (main.count({A[i], i}) == 0) {
            sub.insert({A[i], i});
        }
    }
    cout << sum << " ";



    for(int i=2; i<=N-M+1; i++){
        int tgt = i+M-1;
        if (K == M) {
            sum -= A[i-1];
            sum += A[tgt];
            cout << sum << " ";
            continue;
        }
        if (main.count({A[i-1], i-1}) > 0) {
            main.erase({A[i-1], i-1});
            sum -= A[i-1];
            auto its = sub.begin();
            if ((*its).first < A[tgt]) {
                main.insert(*its);
                sum += (*its).first;
                sub.erase(*its);
                sub.insert({A[tgt], tgt});
            } else {
                main.insert({A[tgt], tgt});
                sum += A[tgt];
            }
        } else {
            sub.erase({A[i-1], i-1});
            auto itm = main.end();
            itm--;
            if ((*itm).first > A[tgt]) {
                sum -= (*itm).first;
                sub.insert(*itm);
                main.erase(*itm);
                main.insert({A[tgt], tgt});
                sum += A[tgt];
            } else {
                sub.insert({A[tgt], tgt});
            }
        }
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}