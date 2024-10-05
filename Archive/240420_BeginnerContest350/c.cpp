#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> O(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
        A[i]--;
        O[A[i]] = i;
    }

    vector<pair<int, int>> ans;
    for (int i=0; i<N; i++){
        if (A[i] == i) continue;
        else {
            int a = A[i];
            int k = O[i];
            ans.push_back({i, O[i]});
            swap(A[i], A[O[i]]);
            O[i] = i;
            O[a] = k;
        }
    }
    cout << ans.size() << endl;
    for(auto a: ans) {
        cout << a.first+1 << " " << a.second+1 << endl;
    }
    
    return 0;
}