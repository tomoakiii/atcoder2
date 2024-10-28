#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    int N;
    cin >> N;
    string s = ".14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706790";
    cout << "3.";
    for (int i=1; i<=N; i++){
        cout << s[i];
    }
    return 0;
}

