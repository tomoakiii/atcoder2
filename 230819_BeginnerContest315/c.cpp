#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{    
    int N;
    cin >> N;
    vector<pll> SF(N);
    map<ll, vector<ll>> FS;
    for(int i=0; i<N; i++){
        cin >> SF[i].second >> SF[i].first;
        FS[SF[i].second].push_back(SF[i].first);
    }
    sort(SF.begin(), SF.end());
    for (auto &m: FS){
        sort(m.second.begin(), m.second.end());
    }
    ll sm = 0;
    ll s = SF[N-1].first;
    set<ll> st;
    set<ll> __cmb;
    for (int i=N-1; i>=0; i--){
        if (SF[i].second != SF[N-1].second){
            sm = max(sm, s + SF[i].first);
            __cmb.insert(s + SF[i].first);
        }
        int sz = FS[SF[i].second].size();
        if (sz > 1) {
            sm = max(sm, FS[SF[i].second][sz-1] + FS[SF[i].second][sz-2]/2);
            __cmb.insert(FS[SF[i].second][sz-1] + FS[SF[i].second][sz-2]/2);
        }
    }
    cout << sm << endl;
    return 0;
}