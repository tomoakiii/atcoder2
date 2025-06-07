#include <bits/stdc++.h>
using namespace std;


struct Person {
public:
    Person(const string &name, int height)
        : m_name(name)
        , m_height(height)
        {}
public:
    string m_name;
    int    m_height;
};

bool operator<(const Person &lhs, const Person &rhs)
{
    return lhs.m_name < rhs.m_name;
}

int main(){
    std::set<int> st{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    std::set<int> x(st);      // コピーコンストラクタ
    auto itr = st.begin();       // 最初の要素へのイテレータを取得
    
    for(itr = st.begin(); itr != st.end(); ++itr) {
        // cout<<*itr<<endl;
    }
    cout<<*(st.end())<<endl;
    cout<<*(st.begin())<<endl;
    cout<<*(st.lower_bound(9))<<endl;
    cout<<*(st.lower_bound(10))<<endl;
    /*
    multiset<ll> st;
    ll sm = 0;
    sm += A[0];
    st.insert(A[1]);
    for(int i=2; i<2*N; i+=2) {
        st.insert(A[i]);
        sm += *st.rbegin();
        st.erase(st.find(*st.rbegin())); // multisetから要素を1つだけ削除するには、findで指定する必要がある
        st.insert(A[i+1]);
    } 
    */       
    return 0;
}