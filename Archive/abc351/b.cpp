#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    int N;
    cin >> N;
    vector<string> A(N), B(N);

    for(auto &a: A) cin>>a;
    for(auto &b: B) cin>>b;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) {
        if (A[i][j] != B[i][j]) {
            cout << i+1 << " " << j+1 << endl;
            return 0;
        }
    }


    return 0;
}