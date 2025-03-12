#include<iostream>
#include<set>
using namespace std;

int main(){
    set<string>st;
    st.insert({ "geeks", "for", "geeks", "org" });

    for(auto it = st.begin();it!=st.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}