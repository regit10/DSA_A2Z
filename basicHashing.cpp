#include<iostream>
// #include<utility>
#include<map>
using namespace std;

// int hashh[10000000]={0};

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    // string s;
    // cin>>s;  
    // int hashh[256] = {0};
    // for(int i=0;i<s.size();i++) hashh[s[i]]++;
    //for(int i=0;i<n;i++) hashh[a[i]]+=1;

    map<int,int> mpp;
    for(int i=0;i<n;i++) mpp[a[i]]++;
    
    for(auto it:mpp) cout<<it.first<<"-> "<<it.second<<endl;
    cout<<endl;
    int q;
    cin>>q;
    while(q--){
        // char findChar;
        // cin>>findChar;
        // cout<<findChar<<" -> "<<hashh[findChar]<<endl;

        int num;
        cin>> num;
        cout<<mpp[num]<<endl;
    }

    return 0;
}