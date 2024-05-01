#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main()
{
    int i = 3;
    ll k = (1<<(i-1)) - 1;
    cout << "k: " << k << endl;
    bitset<16> k2(k);
    cout << "k2: " << k2 << endl;
    k2.reset(1);
    cout << "k2: " << k2 << endl;

    bitset<16> k3(k);
    cout << "k3: " << k3 << endl;
    k2.reset(2);
    cout << "k3: " << k3 << endl;
    return 0;
}