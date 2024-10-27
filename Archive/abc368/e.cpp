#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M, X;
    cin >> N >> M;
    vector<ll> X(M, 0);
    cin >> X[0];
    vector<ll> A(M), B(M), S(M), T(M);
    vector<int> last(N, -1), lastT(M);

    // last: last arrival train on each station
    // lastT: last Need-To-Wait train on each train
    rep(i,M) {
        cin>>A[i]>>B[i]>>S[i]>>T[i];
    }
    
    vector<int> ord_d(M);
    iota(ord_d.begin(), ord_d.end(), 0);
    vector ord_a = ord_d;
    sort(ord_d.begin(), ord_d.end(), [&](int i, int j) { return S[i] < S[j]; });
    sort(ord_a.begin(), ord_a.end(), [&](int i, int j) { return T[i] < T[j]; });

    int i0=0, i1=0;
    while(i0 < M && i1 < M){
        
        A[i]--, B[i--];
        last[B[i]] = i;
        lastT[i] = last[A[i]];
    }

    auto comp = [](vector&)->bool{

    };
   
    cout << sm << endl;
    return 0;
}