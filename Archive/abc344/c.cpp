#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main () {
    int N,  M, L, Q;
    cin >> N;
    vector<ll> A(N);
    for(auto &a:A) cin>>a;
    cin >> M;
    vector<ll> B(M);
    for(auto &b:B) cin>>b;
    cin >> L;
    vector<ll> C(L);
    for(auto &c:C) cin>>c;
    cin >> Q;
    vector<ll> X(Q);
    for(auto &x:X) cin>>x;

    set<ll> sum;
    for(auto a:A) for(auto b:B) for(auto c:C) sum.insert(a+b+c);
    
    for(auto &x:X) {
        if (sum.find(x) != sum.end()) cout << "Yes" << endl;
        else cout << "No" << endl;
    };

    return 0;
}

