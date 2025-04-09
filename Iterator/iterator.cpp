#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  vector<int>v{1,2,3,4,5,6};
  for(auto i : v){
    cout<<i<<endl;
  }
  cout<<endl;
  //using iterators
  auto it = v.begin();
  for(advance(it,2);it!=v.end();it++){
    cout<<*it<<endl;
  }
  return 0;
}