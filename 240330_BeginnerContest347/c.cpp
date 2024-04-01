#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    int N;
    ll A, B, d;
    cin >> N >> A >> B;
    ll AB = A+B;
    map<ll, int> st;
    for (int i=0; i<N; i++){
        cin >> d;
        st[d % AB]++;
    }
    st[AB + st.begin()->first]++;
    ll prev = -1;
    ll dist = 0;
    for (auto it=st.begin(); it!=st.end(); it++){
        dist = max(dist, it->first - prev - 1);
        prev = it->first;
    }
    dist = max(dist, AB - prev - 1);
    if (dist >= B){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }  
    return 0;
}