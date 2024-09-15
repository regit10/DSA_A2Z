#include<iostream>
#include<math.h>
using namespace std;

void print1(int i){
    if(i==5) return;
    cout<<i<<endl;
    i++;
    print1(i);
}

void printName(int i,int n){
  if(i>n) return;
  cout<<"Hey there ,Tiger!"<<endl;
  printName(i+1,n);
}

void printLinearly(int i,int n){
  if(i>n) return;
  cout<<i<<" ";
  printLinearly(i+1,n);
}

void printReverse(int i,int n){
    if(i<1) return;
    cout<<i<<" ";
    printReverse(i-1,n); 
}

void pLinearBT(int i,int n){
    if(i<1) return;
    pLinearBT(i-1,n);
    cout<<i<<" ";
}

void pRevBT(int i,int n){
    if(i>n) return;
    pRevBT(i+1,n);
    cout<<i<<" ";
}

void pParaSum(int i,int sum){
    if(i<1){
        cout<<sum<<" ";
        return;
    }
    pParaSum(i-1,sum+i);

}

int pFunSum(int n){
    if(n==0) return 0;
    return n + pFunSum(n-1);
}

int pFactFun(int n){
    if(n==1) return 1;
    return n * pFactFun(n-1);
}

void revArr(int i,int arr[],int n){
    if(i>=n/2) return;
    swap(arr[i],arr[n-1-i]);
    revArr(i+1,arr,n);
}

bool isPali(int i,string &s){
    if(i>s.size()/2) return true;
    if(s[i] != s[s.size()-i-1]) return false;
    return isPali(i+1,s); 
}

int printFibonacci(int n){
    if(n<=1) return n;
    return printFibonacci(n-1)+printFibonacci(n-2);
}

int main(){
    int n;
    cin>>n;
    
    // print1(0);

    // printName(1,n);

    // printLinearly(1,n);

    // printReverse(n,n);

    // pLinearBT(n,n);

    // pRevBT(1,n);

    // pParaSum(n,0);

    // cout<<pFunSum(n)<<endl;

    // cout<<pFactFun(n)<<endl;
    
    // int arr[n];
    // for(int i=0;i<n;i++) cin>>arr[i];
    // revArr(0,arr,n);
    // for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    
    // string s;
    // cin>>s;
    // if(isPali(0,s)) cout<<s<<" is a Palindrome!"<<endl;
    // else cout<<s<<" is not a palindrome!\n";

    cout<<printFibonacci(n)<<" is the "<<n<<"th fibonacci number!"<<endl;
    
    return 0;
}  