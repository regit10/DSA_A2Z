#include<iostream>
#include<vector>
#include<utility>
#include<set>
#include<map>
using namespace std;

void nCR(int x,int r){
    /* printing Particular element */
    // long long rem=1;
    // for(int i=0;i<r;i++){
    //     rem = rem*(x-i);
    //     rem = rem/(i+1); 
    // }
    // cout<<rem<<"\n";
}
void printRow(int row){
    int ele = 1;
    cout<< ele <<" ";
    for(int col=1;col<row;col++){
        ele *= (row - col);
        ele /= col ;
        cout<< ele <<" ";
    }
    cout<<endl;

}
void printPascalTriangle(int rows){
   for(int i=1;i<=rows;i++){
        printRow(i); 
   }
}

void majorityEle1by3(vector<int> arr){
    int n = arr.size();
    map<int,int> mpp;
    vector<int> store;
    int  mini = ( n/3 )+1;

    /* Brute force */
    // for(int i=0;i<n;i++){
    //     if(store.size() ==0 || store[0] != arr[i]){
    //         int count = 0;
    //         for(int j=0;j<n;j++){
    //             if(arr[i]==arr[j]) count+=1;
    //         }
    //         if(count > (n/3)) {
    //             store.emplace_back(arr[i]);
    //         }
    //     }
    //     if(store.size()==2) break;
    // }

    /* Better Case */
    // for(int i=0;i<n;i++){ 
    //     mpp[arr[i]]++;
    //     if(mpp[arr[i]] == mini)
    //     store.emplace_back(arr[i]);
    //     if(store.size()==2) break;
    // }

    /* Optimal Case */
    int cnt1 = 0 ; int ele1 = INT_MIN;
    int cnt2 = 0 ; int ele2 = INT_MIN;
    for(int i=0;i<n;i++){
        if(cnt1 == 0 && ele2 != arr[i]){
            cnt1 = 1; 
            ele1 = arr[i];
        }
        else if(cnt2 == 0 && ele1 != arr[i]){
            cnt2 = 1;
            ele2 = arr[i];
        }
        else if(arr[i] == ele1) cnt1++; 
        else if(arr[i] == ele2) cnt2++;
        else{
            cnt1--; cnt2--;
        }
    }
    cnt1=0; cnt2=0;
    for(int i=0;i<n;i++){
        if(arr[i] == ele1) cnt1++;
        if(arr[i] == ele2) cnt2++;
    }
    if(cnt1 >= mini) store.emplace_back(ele1);
    if(cnt2 >= mini) store.emplace_back(ele2);
    sort(store.begin(),store.end());
    for(auto it:store) cout<<it<<" ";
}

void threeSumProb(vector<int> arr){
    int n = arr.size();
    int targ=0;

    /* Brute Force */
    // set<vector<int>> st;
    // int n = arr.size();
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         for(int k=j+1;k<n;k++){
    //             if(arr[i]+arr[j]+arr[k]==targ){
    //                 vector<int> temp = {arr[i],arr[j],arr[k]};
    //                 sort(temp.begin(),temp.end());
    //                 st.insert(temp);
    //             }
    //         }
    //     }
    // }
    // for (const auto& vec : st) {
    //     std::cout << "{ ";
        
    //     for (const auto& elem : vec) {
    //         std::cout << elem << " ";
    //     }
    //     std::cout << "}" << std::endl;
    // }

    /* Better Case */
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        set<int> hashset;
        for(int j=i+1;j<n;j++){
            int third = -(arr[i]+arr[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int> temp = {arr[i],arr[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    for(auto it:st){
        cout<<"{";
        for(auto itt: it) cout<<itt << " ";
        cout<<"}\n";
    }


}

int main(){
    int n;
    cin >> n;        // declaration of n
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int targ;
    cin>>targ;

    // int R;int C;
    // cin>>R;
    // cin>>C;      //Column

    /* Chapter 1 */
    // nCR(R-1,C-1);   //Type 1 : printing Particular element
    // printRow(R);
    // printPascalTriangle(R);

    /* Chapter 2 */
    // majorityEle1by3(arr);

    /* Chapter 3*/
    threeSumProb(arr);

    return 0;
}
