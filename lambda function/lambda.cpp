#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v{1,2,3,4,5,6};
    
    int lastresult = -1;
    // passing the copy of a value thats why it is not mutable and it is read only variable . 
    // auto sum = [lastresult](int n){
    //     lastresult = n;
    //     cout<<n<<endl;
    //     // for(int i=0;i<v.size();i++){
    //     //     v[i]*=2;
    //     //     cout<<v[i]<<", ";
    //     // }
    // };

    //using mutable allows us to change the value of variable . 
    auto sum = [lastresult](int n) mutable{
        lastresult=n;
        cout<<n<<endl;
    };
    sum;
    cout<<lastresult<<endl;
    for(int i =0; i< v.size(); i++){
        cout<<v[i]<<" ";
    }

}