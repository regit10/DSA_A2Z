#include<iostream>
#include<utility>
#include<vector>
#include<set>
#include<map>
using namespace std;

void sorter(vector<int> &arr,int min,int mid,int max){
    vector<int> tempo;
    int left = min;
    int right = mid+1;

    while (left<=mid && right<=max)
    {
        if(arr[left]<=arr[right]){
            tempo.emplace_back(arr[left]);
            left++;
        }
        else{
            tempo.emplace_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        tempo.emplace_back(arr[left]);
        left++;
    }
    while(right<=max){
        tempo.emplace_back(arr[right]);
        right++;
    } 
    for(int i=min;i<=max;i++){
        arr[i] = tempo[i-min];
    }
}

void splittingAndMerging(vector<int> &arr,int min,int max){
    if(min>=max) return;
    int mid = (min+max)/2;
    splittingAndMerging(arr,min,mid);
    splittingAndMerging(arr,mid+1,max);
    sorter(arr,min,mid,max);
}

void mergeSort(vector<int> &arr,int n){
    splittingAndMerging(arr,0,n-1);
    for(auto it:arr) cout<<it<<" ";
}

int largestEle(vector<int> &arr,int n){
    int largest = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest) largest = arr[i];
    }
    cout<<"\nLargest = "<<largest<<endl;
    return largest;
}

void secondLargest(vector<int> &arr,int n){
    /* Brute Force:
        Sorting the array and then choosing the second largest by 
        reverse iteration
     */
    // int secLar = -1;   //INT_MIN if the array has even negative numbers!
    // for(int i=n-2;i>=0;i++){
    //     if(arr[i]<arr[n-1]){
    //         secLar = arr[i];
    //         cout<<"\nSecond Largest = "<<secLar;
    //         break;
    //     }
    // }

    /* Better case */
    // int lar = largestEle(arr,n) ;
    // int secLar = INT_MIN ;

    // for(int i=0;i<n;i++){
    //     if(arr[i]>secLar && arr[i]!=lar ){
    //         secLar = arr[i];
    //     }
    // }
    // cout<<"\nSecond Largest = "<<secLar;

    /* Optimal Solution */
    // int largest = arr[0];
    // int second = -1;
    // for(int i=1;i<n;i++){
    //     if(arr[i]>largest){
    //         second = largest;
    //         largest = arr[i];
    //     }
    //     if(arr[i]>second && arr[i]<largest){
    //         second =arr[i];
    //     }
    // }
    // cout<<"Second Largest = " <<second<<endl;

}

void checkSorted(vector<int> &arr,int n){
    for(int i=1;i<n;i++){
        if((arr[i]<arr[i-1])) {
            cout<<"The array is not sorted!\n";
            break;
        }
        if(i == n-1) cout<<"The array is Sorted!\n";
    }
}

void removeDuplicates(int arr[],int n){      //(vector<int> &arr,int n){
    /* Brute Force Approach */
    // set<int> st;
    // for(int i=0;i<n;i++){
    //     st.insert(arr[i]);
    // }                                            
    // int index=0;                    // arr.clear();
    // for(auto it:st){                // for(auto it:st){
    //     arr[index] = it;            //     arr.emplace_back(it);
    //     index++;                    // }
    // }                               // for(auto it:arr) cout<<it<<" ";
    // for(int i=0;i<index;i++) cout<<arr[i]<<" ";

    /* Optimal Solution */
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[i]!=arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    for(int j=0;j<i+1;j++) cout<<arr[j]<<" ";
    
}

void leftRotate(int* arr,int n){
    int temp = arr[0];
    for(int i=1;i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
   
}

void leftRotate(int *arr,int n,int d){
     d = d%n;
     /* Brute Force */
    // vector<int> temp;
    // for(int i=0;i<d;i++) temp.emplace_back(arr[i]);

    // for(int i=d;i<n;i++){
    //     arr[i-d] = arr[i];
    // }

    // for(int i=n-d;i<n;i++){
    //     arr[i] = temp[i-(n-d)];
    // }
    // for(int i=0;i<n;i++) cout<<arr[i]<<" ";

    /* Optimal Solution */
    reverse(arr,arr+d);
    reverse(arr+d,arr+n);
    reverse(arr,arr+n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}

void zeroAtEnd(int arr[],int n){
    /* Better Approach */
    // int count = 0;
    // for(int i=0;i<n; i++){
    //     if(arr[i] == 0) count++;
    //    else{
    //         arr[i-count] =arr[i];
    //     }
    // }
    // for(int i=n-count;i<n;i++) arr[i] = 0;
    // for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    
    /* Optimal Approach */
    int j=-1;
    for(int i=0;i<n;i++) {
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}

void unionOfArray(int *arr1,int *arr2,int n,int m){
    
    /* Brute Force Approach */
    // set<int> st;
    // for(int i=0;i<n1;i++) st.insert(arr1[i]);
    // for(int i=0;i<n2;i++) st.insert(arr2[i]);
    // int s = st.size();
    // int arr[s];
    // int j=0;
    // for(auto it:st){
    //     arr[j] = it;
    //     j++;
    // } 
    // for(int i=0;i<s;i++) cout<<arr[i]<<" ";
    /*  Optimal Approach */
    int i = 0, j = 0; // pointers
  vector < int > Union; // Uninon vector
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j]) // Case 1 and 2
    {
      if (Union.size() == 0 || Union.back() != arr1[i]){
             Union.push_back(arr1[i]); }
            i++;
    }
    else // case 3
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n) // If any element left in arr1
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
   for(auto it:Union) cout<<it<<" ";
}

void intersectionOfArray(int *arr1,int *arr2,int n1,int n2){
    vector<int> store;
    // vector<int> com(n2,0);
    // for(int i=0;i<n1;i++){
    //     for(int j=0;j<n2;j++){
    //         if(arr1[i]==arr2[j] && com[j]==0){
    //             store.emplace_back(arr1[i]);
    //             com[j] = 1;
    //             break;
    //         }
    //         if(arr2[j]>arr1[i]) break;
    //     }
    // }
    int i=0;int j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]) i++;
        else if(arr1[i]>arr2[j]) j++;
        else{
            store.push_back(arr1[i]);
            i++; j++;
        }

    }

    for(auto it:store) cout<<it<<" ";
}

void missingEle(int *arr,int n){
    /* Brute force */
    // for(int i=1;i<=n;i++){
    //     int flag = 0;
    //     for(int j=0;j<n-1;j++){
    //         if(arr[j] == i ) {
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if(flag==0){
    //         cout<<i<<" is missing!";
    //          break;
    //     }
    // }

    /* Better Approach */
    // vector<int> hashh(n+1,0);
    // int tempo=0;
    // for(int i=0;i<n-1;i++){
    //     hashh[arr[i]]=1;
    // }

    // for(int i=1;i<=n;i++){
    //     if(hashh[i]==0){
    //         tempo = i;
    //         break;
    //     }
    // }
    

    /* Optimal Approach */
    /* Sum Method */
    // int Sum = (n*(n+1))/2;
    // int S2;
    // for(int i=0;i<n-1;i++) S2+=arr[i];
    // int tempo = Sum - S2;

    /* XOR Method */
     int tempo =0;
    int XOR1 = 0;
    int XOR2 = 0;
    // int N=n-1;
    for(int i=0;i<n-1;i++){
        XOR2 = XOR2^arr[i];
        XOR1 = XOR1^(i+1);
    }
    XOR1 = XOR1^n;
    tempo = XOR1^XOR2;

    cout<<tempo<<" is the missing ele\n";
}

void contiOnes(int *arr,int n){
    int count=0;
    int maxi=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count++;
            if(maxi<count) maxi = count;
        }
        else count=0;
    }
    cout<<maxi<<" Max continuos 1s\n";

}

void singleOccurence(int *arr,int n){
    /* Brute Force */
    // for(int i=0;i<n;i++){
    //     int num = arr[i];
    //     int count = 0;
    //     for(int j=0;j<n;j++){
    //         if(arr[j] == num) count++;
    //     }
    //     if(count == 1){
    //         cout<<num<<" ";
    //         break;
    //     } 
    // }

    /* Better Approach */
    // map<int, int> mpp;
    // int num = 0;
    // for(int i=0;i<n;i++){
    //     mpp[arr[i]]++;
    // }

    // for(auto it:mpp){
    //     if(it.second == 1){
    //         num = it.first;
    //         break;
    //     }    
    // }
    // cout<<num<<" ";

    /* Optimal Solution */
    int XoR = 0;
    for(int i=0;i<n;i++) XoR = XoR^arr[i];
    cout<<XoR<<" ";
}

void longestSubarrayWithSumK(vector<int> arr,long long k){
    /* Brute Force */
    int maxLen = 0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        int Sum = 0;
        for(int j=i;j<n;j++){
            Sum += arr[j];
            if(Sum == k) maxLen = max(maxLen,j-i+1); 
        }
    }
    
    /* Better Approach*/
    // long long Sum = 0;
    // int maxLen  = 0;
    // map<long long,int> preSumMap;
    // for(int i=0;i<arr.size();i++){
    //     Sum+=arr[i];
    //     if(Sum==k){
    //         maxLen = max(maxLen,i+1);
    //     }
    //     long long remm = Sum-k;
    //     if(preSumMap.find(remm) != preSumMap.end()){
    //         int len  = i - preSumMap[remm];
    //         maxLen = max(maxLen,len);
    //     }
    //      if(preSumMap.find(Sum) == preSumMap.end()){
    //         preSumMap[Sum] = i;
    //     }
        
    // }

    /* Optimal Approach */
    // int r=0;
    // int l=0;
    // long long Sum = arr[0];
    // int maxLen = 0;
    // int n = arr.size();
    // while(r<n){
    //     while(l<=r && Sum>k){
    //         Sum -= arr[l];
    //         l++ ;
    //     }
    //     if(Sum == k){
    //         maxLen = max(maxLen,r-l+1);
    //     }
    //     r++;
    //     if(r<n){
    //         Sum += arr[r];
    //     }
    // }
    cout<<maxLen<<" ";
}

void longestSubarrayWithSumKposAndNeg(vector<int> arr,long long k){
    map<long long,int> storeSum;
    int maxLen = 0;
    int n = arr.size();
    long long Sum = 0;
    for(int i=0;i<n;i++){
        Sum += arr[i];
        if(Sum==k) maxLen= max(maxLen, i+1);
        long long rem = Sum-k;
        if(storeSum.find(rem) != storeSum.end()){
            int len = i - storeSum[rem];
            maxLen = max(maxLen,len); 
        } 
        if(storeSum.find(Sum) == storeSum.end()){
            storeSum[Sum] = i;
        }
    }
    cout<<maxLen<<" ";
}

int main(){
    int n;
    cin>>n;
    // vector<int> arr(n);
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int k;
    cin>>k;

    // int n2;
    // cin>>n2;
    // int arr2[n2];
    // for(int i=0;i<n2;i++) cin>>arr2[i];
    // int d;
    // cin>>d;
    
    /* Easy Problems */
    /* Chapter 1 */
    // mergeSort(arr,n);
    // largestEle(arr,n);
    // secondLargest(arr,n);
    // checkSorted(arr,n);
    // removeDuplicates(arr,n);

    /* Chapter 2 */
    // leftRotate(arr,n);
    // leftRotate(arr,n,d);
    // zeroAtEnd(arr,n);
    // unionOfArray(arr1,arr2,n1,n2);
    // intersectionOfArray(arr1,arr2,n1,n2);

    /* Chapter 3 */
    // missingEle(arr,n);
    // contiOnes(arr,n);
    //  singleOccurence(arr,n);
    // longestSubarrayWithSumK(arr,k);
    // longestSubarrayWithSumKposAndNeg(arr,k);
    
    /* Easy problems end here */

    return 0;
}