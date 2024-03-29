#include <bits/stdc++.h>

using namespace std;

int main(){
    long long N, ru=0;
    cin >> N;

    vector<long long> v(36, 0);
    int ind=0;
    for (long long i=1; i<112222222233; i*=10){
        ru += i;
        v[ind++] = v[ind++] = v[ind++] = ru;
    }

    long long minans = 112222222233;
    map<long long, int> comb;
    vector<bool> b(36, false);
    fill(b.end() - 3, b.end(), true);
    do {
        vector<long long> c = {};
        for (long long i=0; i < 36; i++) if (b[i]) c.push_back(i);
        comb[v[c[0]] + v[c[1]] + v[c[2]]]++;
    } while (std::next_permutation(b.begin(), b.end()));


    auto itr=comb.begin(); N--;
    while(N>0){
        N--;
        itr++;
    }
    cout << itr->first << endl;
    return 0;
}