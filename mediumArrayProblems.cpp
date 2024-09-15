#include<iostream>
#include<utility>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
using namespace std;

void revArr(vector<vector<int>> &arr,int n){
    for(int i=0;i<n;i++){ 
        int begin = 0;
        int end = n-1;
        while(begin<=end){
            swap(arr[i][begin],arr[i][end]);
            begin++;
            end--;
        }
    }
    return;
}

void setRow(vector<vector<int>> &arr,int i,int m){
    for(int j=0;j<m;j++){
       if(arr[i][j]!=0) arr[i][j] = -1;
    }

}
void setColumn(vector<vector<int>> &arr,int j,int n){
    for(int i=0;i<n;i++){
       if(arr[i][j]!=0) arr[i][j] = -1;
    }
}

int lS(vector<int> arr,int num){
    for(int i=0;i<arr.size();i++){
        if(arr[i] == num) return true;
    }
    return false;
}

void twoSum(vector<int> arr, int k){
    int n = arr.size();

    /* Brute Force */
    // int pre=0;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(arr[i]+arr[j] == k) {
    //             cout<<"The position the elements are present are is "<<i<<","<<j<<"\n";
    //             pre++;
    //             break;
    //         }
    //     }     
    // }
    // if(pre==0) cout<<"No valid pairs exist!\n";

    /* Better Case */
    // map<int ,int> mpp;
    // int preMark =0;
    // for(int i=0;i<n;i++){
    //     int atPos = arr[i];
    //     int finding  = k - atPos;
    //     if(mpp.find(finding) != mpp.end()){
    //         cout<<"The pairs are Present!\n"; 
    //         preMark=1;
    //         break;
    //     }
    //     mpp[atPos] = i;
    // }
    // if(preMark==0) cout<<"No such pairs in the array!\n";

    /* Optimal Approach */
    sort(arr.begin(),arr.end());
    int right = n-1; 
    int left = 0;
    int preMark = 0;
    while(left<right){
        int Sum = arr[left]+arr[right];
        if(Sum == k){
            cout<<"Pair Exists!\n";
            preMark =1;
            break;
        }
        if(Sum<k) left++;
        else right--;
    }
    if(preMark==0) cout<<"No such pairs in the array!\n";
}

void sortArrOfOTT(vector<int> arr,int n){
    /* Brute Force */
    /* Use any of the sorting algos (merge is the best shot) */

    /* Better Approach */
    // int cnt0 = 0;
    // int cnt1 = 0;
    // int cnt2 = 0;
    // for(int i=0;i<n;i++){
    //     if(arr[i] == 0) cnt0++;
    //     else if(arr[i] == 1) cnt1++;
    //     else cnt2++;
    // }
    // for(int i=0;i<cnt0;i++) arr[i] = 0;
    // for(int i=cnt0;i<cnt0+cnt1;i++) arr[i] = 1;
    // for(int i=cnt0+cnt1;i<n;i++) arr[i] = 2;
    // for(auto it:arr) cout<<it<<" ";

    /* Optima approach */ /* Dutch National Flag Algorithm */
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    for(auto it:arr) cout<<it<<" ";

}

void majorityElement(vector<int> arr,int n){
    /* Brute Force */
    // for(int i=0;i<n;i++){
    //     int count=0;
    //     for(int j=0;j<n;j++){
    //         if(arr[i]==arr[j]) count++;
    //     }
    //     if(count>n/2){
    //         cout<<arr[i]<<" is the element in majority!";
    //         break;
    //     }
    // }

    /* Better Approach */
    // map<int,int> mpp;
    // for(int i=0;i<n;i++){
    //     mpp[arr[i]]++;
    // }
    // for(auto it:mpp){
    //     if(it.second>n/2){
    //          cout<<it.first<<" is the element in majority!";
    //          break;
    //     }
    // }

    /* Optimal Solution */
    /* Moore's Voting Algorithm */
    int cnt = 0;
    int ele = 0;
    for(int i=0;i<n;i++){
        if(cnt == 0){
            cnt = 1;
            ele = arr[i];
        }
        else if(arr[i]==ele){
            cnt++;
        }
        else cnt--;
    }
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(arr[i] == ele ) cnt1++;
    }
    if(cnt1>n/2)  cout<<ele<<" is the element in majority!";
    
}

void maxSubArrSum(vector<int> arr,int n){
    int maxi = INT_MIN;

    /* Brute Force Approach */
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         int sum = 0;
    //         for(int k=i;k<j;k++){
    //             sum+=arr[k];
    //         }
    //         maxi = max(maxi,sum);
    //     }
    // }
    // cout<<"Maximum Sub-Array sum is : "<<maxi;

    /* Better Approach */
    // for(int i=0;i<n;i++){
    //     int Sum = 0;
    //     for(int j=i;j<n;j++){
    //         Sum += arr[j];
    //         maxi = max(maxi,Sum);
    //     }
    // }
    // cout<<"Maximum Sub-Array sum is : "<<maxi;
    int ansStart =-1;
    int ansEnd =-1;
     int start=-1;
    int Sum=0;
    for(int i=0;i<n;i++){
        if(Sum == 0) start = i;
        Sum += arr[i];
       if(Sum>maxi){
        maxi = Sum;
        ansStart=start; ansEnd = i;
       }
        if(Sum<0) Sum = 0;
    }
    cout<<"Maximum Sub-Array sum is : "<<maxi;
    cout << " from positions "<< ansStart <<" to "<< ansEnd<<endl;
}

void stockBuyAndSell(vector<int> arr,int n){
    int small =arr[0];
    int profit = 0;
    for(int i=1;i<n;i++){
        int cost = arr[i] - small;
        profit = max(profit,cost);
        small = min(small,arr[i]);
    }
    cout<<"\nProfit derivable profit is:  "<<profit<<endl;
}

void altPosNegEles(vector<int> arr,int n){
//    /* Type 1 : no. of (pos == neg ) */
//    /* Brute Force */ 
//     // vector<int> pos;
//     // vector<int> neg;
//     // for(auto it:arr){
//     //     if(it >= 0) pos.emplace_back(it);
//     //     else neg.emplace_back(it);
//     // }
//     // for(int i=0;i<n/2;i++){
//     //     arr[i*2] = pos[i];
//     //     arr[i*2+1] = neg[i];
//     // }
//     // for(auto it:arr) cout<<it<<" ";

//     /* Optimal Soln */
//     // vector<int> ans(n);
//     // int pos=0,neg=1;

//     // for(int i=0;i<n;i++){
//     //     if(arr[i]<0){
//     //         ans[neg] = arr[i];
//     //         neg += 2;
//     //     } 
//     //     else{
//     //         ans[pos] = arr[i];
//     //         pos += 2;
//     //     }
//     // }
//     // for(auto it:ans) cout<<it<<" ";

        vector<int> pos,neg;
        for(auto it:arr){
            if(it >= 0) pos.emplace_back(it);
            else neg.emplace_back(it);
        }

        if(pos.size()>neg.size()){
                for(int i=0;i<neg.size();i++){
                    arr[2*i] = pos[i];
                    arr[2*i+1] = neg[i];
                }
                int ind = neg.size()*2;
                for(int i = neg.size();i<pos.size();i++){
                        arr[ind] = pos[i];
                        ind++;
                }
        }
        else{
            for(int i=0;i<pos.size();i++){
                    arr[2*i] = pos[i];
                    arr[2*i+1] = neg[i];
                }
                int ind = pos.size()*2;
                for(int i = pos.size();i<neg.size();i++){
                        arr[ind] = neg[i];
                        ind++;
                }

        }

        for(auto it:arr) cout<<it<<" ";

}

void nextPermutation(vector<int> arr,int n){
    int indx = -1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            indx = i;
            break;
        }
    }
    if(indx == -1){
        reverse(arr.begin(),arr.end());
        for(auto it:arr) cout<<it<<" ";
    }
    for(int i=n-1;i>indx;i--){
        if(arr[i]>arr[indx]){
            swap(arr[i],arr[indx]);
            break;
        }
    }
    reverse(arr.begin()+indx+1,arr.end());
    for(auto it:arr) cout<<it<<" ";
}

void arrLeader(vector<int> arr,int n){
    vector<int> ans;
    
    /* Brute Force */
    // for(int i=0;i<n;i++){
    //     int leader = 1;
    //     for(int j=i+1;j<n;j++){
    //         if(arr[j]>arr[i]){
    //             leader = 0;
    //             break;
    //         }
    //     }
    //     if(leader == 1) ans.emplace_back(arr[i]);
    // }
    // for(auto it:ans) cout<<it<<" ";
    
    /* Optimal Solution */
    int maxi = INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxi){
            maxi = arr[i];
            ans.emplace_back(maxi);
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto it:ans) cout<<it<<" ";
}

void longestConsecSeq(vector<int> arr,int n){
    /* Brute Force */
    // int maxlen = 1;
    // for(int i=0;i<n;i++){
    //     int x = arr[i];
    //     int len = 1;
    //     while(lS(arr,x+1) == true){
    //         x += 1;
    //         len++;
    //     }
    //     if(len>maxlen) maxlen = len;
    // }
    // cout<<maxlen<<" \n";

    /* Better Case*/
    // sort(arr.begin(),arr.end());
    // int curLen = 0;
    // int maxLen = 1;
    // int lastSmall = INT_MIN;

    // for(int i=0;i<n;i++){
    //     if(arr[i]-1 == lastSmall){
    //         curLen += 1;
    //         lastSmall = arr[i];
    //     }
    //     else if(arr[i] != lastSmall){
    //         curLen = 1;
    //         lastSmall = arr[i];
    //     }
    //     maxLen = max(maxLen,curLen);
    // }
    // cout<<maxLen<<" \n";   

    /* Optimal Case */ 
    int maxLen = 1;
    unordered_set<int> st;
    for(int i=0;i<n;i++) st.insert(arr[i]);

    for(auto it:st){
        if(st.find(it-1) == st.end()){
            int x = it;
            int len = 1;
            while(st.find(x+1) != st.end()){
                x += 1;
                len += 1; 
            }
            maxLen = max(maxLen,len);
        }
    }
    cout<<maxLen<<" ";

}

void setMatrixZeroes(vector<vector<int>> arr){
    int n = arr.size();
    int m = arr[0].size();

    /* Brute Force*/
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(arr[i][j]==0)
    //         {
    //           setRow(arr,i,n);
    //           setColumn(arr,j,m);
    //         }
            
    //     }
    // }
    //  for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(arr[i][j]==-1) arr[i][j]=0;
    //     }
    //  }

    /* Better */
    // vector<int> rowCnt(n,0);
    // vector<int> colCnt(m,0);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(arr[i][j] == 0){
    //             rowCnt[i] = 1;
    //             colCnt[j] = 1;
    //         }

    //     }
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(rowCnt[i] || colCnt[j]){
    //             arr[i][j] = 0;    
    //         }

    //     }


    /* Optimal Solution */
    int col0 = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                arr[i][0] = 0;
               if(j!=0) arr[0][j] = 0;
               else col0 = 0;
            }
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][j]!=0){
                if(arr[i][0] == 0 || arr[0][j] == 0) arr[i][j] = 0;
            }
        }
    }
    if(arr[0][0]==0) {
        for(int j=0;j<m;j++) arr[0][j] = 0;
    }
    if(col0 == 0){
        for(int i=0;i<n;i++) arr[i][0] = 0;
    }

     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
     }

}

void rotateImage(vector<vector<int>> arr){          //i' = j && j' = (n-1)-i
    int n = arr.size();
    
    /* Brute Force */
    // vector<vector<int>> ans(n,vector<int>(n));      //i' = j && j' = (n-1)-i
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         ans[j][n-1-i] = arr[i][j] ;
    //     }
    // }

    /* Optimal approach */

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }  
    revArr(arr,n);   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void spiralPrint(vector<vector<int>> arr){
    vector<int> ans;
    int n = arr.size();
    int m = arr[0].size();
    int left=0; int right=m-1; 
    int top=0; int bottom=n-1;
    while(left<=right && top<=bottom){
        for(int i=left;i<=right;i++) cout<<arr[top][i]<<" ";
        top++;
        
        for(int i=top;i<=bottom;i++) cout<<arr[i][right]<<" ";
        right--;

        for(int i=right;i>=left;i--) cout<<arr[bottom][i]<<" ";
        bottom--;

        for(int i=bottom;i>=top;i--) cout<<arr[i][left]<<" ";
        left++;

    }
}

void noOfSubArrays(vector<int> arr,int K){
    int n = arr.size();
    int cnt = 0;

    /* Brute Force */
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         int Sum = 0;
    //         for(int k=i;k<=j;k++){
    //             Sum+=arr[k];
    //         }
    //         if(Sum==K) cnt++;
    //     }
    // }
    // cout<<"No. of subarrays = "<<cnt<<endl;

    /* Better */
    // for(int i=0;i<n;i++){
    //     int Sum = 0;
    //     for(int j=i;j<n;j++){
    //         Sum += arr[j];
    //         if(Sum == K) cnt++;
    //     }
    // }

    /* Optimal Solution */
    map<int,int> mpp;
    int preSum = 0;
    mpp[0] = 1;
    for(int i=0;i<n;i++){
        preSum += arr[i];
        int rem = preSum - K;
        cnt += mpp[rem];
        mpp[preSum] += 1;

    }


     cout<<"No. of subarrays = "<<cnt<<endl;
}

int main(){
    int n;
    int m;
    cin>>n;
    // cin>>m;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    // vector<vector<int>> arr(n,vector<int>(m));    //Matrix declarataion of size n*m
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //          cin>>arr[i][j];
    //     }
    // }

    int k;
    cin>>k;

    /* Chapter 4 */
    // twoSum(arr,k);

    /* Chapter 5 */
    // sortArrOfOTT(arr,n);

    /* Chapter 6 */
    // majorityElement(arr,n);

    /* Chapter 7 */
    // maxSubArrSum(arr,n);

    /* Chapter 8 */
    // stockBuyAndSell(arr,n);  
    
    /* Chapter 9 */
    // altPosNegEles(arr,n);
    
    /* Chapter 10 */
    // nextPermutation(arr,n);

    /* Chapter 11 */
    // arrLeader(arr,n);

    /* Chapter 12 */
    // longestConsecSeq(arr,n);

    /* Chapter 13 */
    // setMatrixZeroes(arr);

    /* Chapter 14 */
    // rotateImage(arr);

    /* Chapter 15 */
    // spiralPrint(arr);

    /* Chapter 16 */
    noOfSubArrays(arr,k);


   return 0;
}