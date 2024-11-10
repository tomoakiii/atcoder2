#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main()
{    
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(auto &a:A) cin>>a;
    sort(A.begin(), A.end());
    ll last = A[0];
    for(int i=1; i<=N; i++) {
        if (A[i] != ++last) {
            cout << last << endl;
            return 0;
        }

    }
    return 0;
}