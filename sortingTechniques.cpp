#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void selectionSort(int n,int arr[]){
    for(int i=0;i<n-1;i++){
        int minn = i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[minn]) minn = j;
        }
        int temp = arr[i];
        arr[i] = arr[minn];
        arr[minn] = temp;
    }
}

void bubbleSort(int n, int arr[]){
    for(int i=n-1;i>0;i--){
        int didSwap = 0;
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1])
            {
                arr[j] = arr[j] + arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
                didSwap = 1;
            }
        }
        if(didSwap == 0) break;
    }   
}

void insertionSort(int n,int arr[]){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    // selectionSort(n,arr);

    // bubbleSort(n,arr);

    insertionSort(n,arr);

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

    return 0;
}