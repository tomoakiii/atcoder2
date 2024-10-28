#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<vector<int>> A(N);
    int a;
    for (int i=0; i<N; i++) for (int j=0; j<N; j++){
        cin >> a;
        if (a==1) A[i].push_back(j);
    }
    for (int i=0; i<N; i++) {
        sort(A[i].begin(), A[i].end());
        for (auto a:A[i]) cout << a + 1 << " ";
        cout << endl;
    }
    return 0;
}

