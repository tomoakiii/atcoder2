#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main(){

    int N;
    cin >> N;
    struct edge{
        int val;
        int index;
    };
    auto comp = [](edge &a, edge &b){return a.val < b.val;}; // > (<) is smallest (largest) first
    priority_queue<edge, vector<edge>, decltype(comp)> pq(comp);
    vector<long long> accsum(N);
    for (int i = 0; i < N; i++){
        edge e;
        cin >> e.val;
        e.index = i;
        pq.push(e);
    }
    long long tmpsum = 0;
    long long tmpsum2 = 0;
    int tmpval = 10E6;
    while(!pq.empty()){
        auto e = pq.top();
        pq.pop();
        if (tmpval > e.val){
            tmpsum += tmpsum2;
            tmpsum2 = 0;
        }
        accsum[e.index] = tmpsum;
        tmpsum2 += e.val;
        tmpval = e.val;
    }
    for (auto a : accsum){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
