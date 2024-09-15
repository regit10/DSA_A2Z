#include<iostream>
#include<math.h>
#include<utility>
#include<vector>
using namespace std;

int countDigits(int n){
    int cnt = 0;
    while(n>0){
        cnt = cnt+1;
        n = n/10;
    }
    return cnt;
}

int reverseNumber(int n){
        int r=0;
        while(n>0){
            int ld = n%10;
            r = r*10 + ld;
            n = n/10; 
        }
        return r;
}

int isPalindrome(int n){
    int r=0;
    int dup = n;
            while(n>0){
                int ld = n%10;
                r = r*10 + ld;
                n = n/10; 
            }
            if(dup == r) return 1; 
            else return 0;   
}

void armstrongNumber(int n){
   int dup = n;
   int exp = (int)log10(n)+1;
   int r=0;
        while(n>0){
            int ld = n%10;
            r = r + pow(ld,exp);
            n = n/10; 
        }
    if(r == dup) cout<<dup<< " is an Armstrong number!"<<endl;
    else cout<<dup<< " is not an Armstrong number!"<<endl; 
}

void printDivisor(int n){
    // for(int i=1;i<=n;i++){
    //     if(n%i == 0) cout<<i<<" ";
    // }
    // cout<<endl;

    vector<int> ls;
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
         ls.emplace_back(i);
         if((n/i) != i) ls.emplace_back(n/i);
        }
    }
    sort(ls.begin(),ls.end());
    for(auto i:ls){
        cout<<i<<" ";
    }

}

void checkPrime(int n){
    int count =0;
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
         count++;
         if((n/i) != i) count++;
        }
        if(count>2) {
            cout<<n<<" is not a Prime Number!"<<endl;
            break;
        }
    } if(count==2) cout<<n<<" is a Prime Number!"<<endl;
}

void gCD(int n1,int n2){
    // int hcf =1;
    //  int minimum = min(n1,n2);

    // for(int i=1;i<=minimum;i++){
    //     if(n1%i==0 && n2%i==0) hcf=i;
    // }
    // cout<<"GCD of "<<n1<<" and "<<n2<<" = "<<hcf;

    // for(int i=minimum;i>=1;i--){
    //     if(n1%i==0 && n2%i==0){
    //          hcf=i;
    //          cout<<"GCD of "<<n1<<" and "<<n2<<" = "<<hcf;
    //         break;
    //     }
    // }

    while(n1>0 && n2>0){
        if(n1>n2) n1= n1%n2;
        else n2 = n2%n1;
    }
    if(n1==0) cout<<n2<<" is the GCD";
    else cout<<n1<<" is the GCD";
    
}
int main(){
    
    int m,n;
    cin>>m>>n;

    // int noOfDigits =  countDigits(n);
    // cout<<"The number of digits in "<<n<<" = "<<noOfDigits<<endl;

    // int reversed = reverseNumber(n);
    // cout<<"The reverse of "<<n<<" is "<<reversed<<endl;

    // bool palindrome = isPalindrome(n);
    // if(palindrome) cout<<"The number "<<n<<" is a Palindrome"<<endl;
    // else cout<<"The number "<<n<<" is not a Palindrome"<<endl;

    // armstrongNumber(n);

    // printDivisor(n); 

    // checkPrime(n);

    gCD(m,n);
    
    return 0;
}