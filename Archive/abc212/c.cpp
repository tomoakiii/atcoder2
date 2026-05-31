#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    int N, M;
    cin >> N >> M;
    set<ll> A, B;
    ll a;
    for (int i=0; i<N; i++) {
        cin>>a;
        A.insert(a);
    }
    for (int j=0; j<M; j++) {
        cin>>a;
        B.insert(a);
    }
    ll mn = INF;
    auto ita = A.begin();
    auto itb = B.begin();
    while (ita != A.end() && itb != B.end()){
        mn = min(mn, abs(*ita - *itb));
        if (*ita > *itb) itb++;
        else ita++;
    }
    cout << mn << endl;
    return 0;
}

