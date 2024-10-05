#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<long long> R, Rsum;
bool is_even(int x, long long q) { return x > q; }

int main(){
    cin >> N >> Q;
    R.resize(N), Rsum.resize(N, 0);
    for (auto &r : R) cin >>r;
    sort(R.begin(), R.end());
    Rsum[0]=R[0];
    for (int i=1; i<N; i++){
        Rsum[i] = Rsum[i-1]+R[i];
    }
    while(Q>0){
        Q--;
        long long q;
        cin >> q;
        auto it = std::upper_bound(Rsum.begin(), Rsum.end(), q);
        if (*it==q) it++; 
        cout << it-Rsum.begin() << endl;
    }

    return 0;
}