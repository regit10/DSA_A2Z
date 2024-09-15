#include<iostream>
using namespace std;

void print1(int n){
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<"* ";
            }
            cout<<endl;
    }
    cout<<endl;
}
void print2(int n){
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                cout<<"* ";
            }
            cout<<endl;
    }
    cout<<endl;
}
void print3(int n){
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                cout<<j+1<<" ";
            }
            cout<<endl;
    }
    cout<<endl;
}
void print4(int n){

    for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                cout<<i+1<<" ";
            }
            cout<<endl;
    }
    cout<<endl;
}
void print5(int n){
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                cout<<"* ";
            }
            cout<<endl;
    }
    cout<<endl;
}
void print6(int n){
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                cout<<j+1<<" ";
            }
            cout<<endl;
    }
    cout<<endl;
}
void print7(int n){
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                cout<<" ";
            }
            for(int j=0;j<((2*i)+1);j++){
                cout<<"*";
            }
            cout<<endl;
    }
    cout<<endl;
}
void print8(int n){
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                cout<<" ";
            }
            
            for(int j=0;j<(2*n-((2*i)+1));j++){
                cout<<"*";
            }
            cout<<endl;
    }
    cout<<endl;
}
void print9(int n){
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                cout<<" ";
            }
            for(int j=0;j<((2*i)+1);j++){
                cout<<"*";
            }
            cout<<endl;
    }
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                cout<<" ";
            }
            
            for(int j=0;j<(2*n-((2*i)+1));j++){
                cout<<"*";
            }
            cout<<endl;
    }
    cout<<endl;
}
void print10(int n){
    for(int i=1;i<=2*n-1;i++)
        {
            int stars = i;
            if(i>n) stars = 2*n-i;
            for(int j=0;j<stars;j++)
            {
                cout<<"*";
            }
            cout<<endl;
    }
    cout<<endl;

}
void print11(int n){
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if((i+j)%2==0) cout<<"1 ";
                else cout<<"0 ";
            }
            cout<<endl;
    }
    cout<<endl;
}
void print12(int n){
    for(int i=1;i<=n;i++){
        int x=i;
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        for(int j=1;j<(n-i+1);j++){
            cout<<"    ";
        }
        for(int j=1;j<=i;j++){
            cout<<x<<" ";
            x=x-1;
        }

        cout<<endl;
    
    }
    cout<<endl;
}
void print13(int n){
    int alt =1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<alt<<" ";
            alt+=1;
        }
        cout<<endl;
    }
    cout<<endl;

}
void print14(int n){
    for(int i=1;i<=n;i++){
        for(char j='A';j<'A'+i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}
void print15(int n){
    for(int i=1;i<=n;i++){
        for(char ch = 'A';ch<='A'+n-i;ch++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void print16(int n){
    char ch = 'A';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<ch<<" ";
        }
        ch+=1;
        cout<<endl;
    }
    cout<<endl;
}
void print17(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<"  ";
        }
        char ch ='A';
        int breakpoint =((2*i)+1)/2;
        for(int j=1;j<=2*i-1;j++){
            cout<<ch<<" ";
            if(j<breakpoint) ch+=1;
            else ch-=1;
        }

        cout<<endl;
    }
    cout<<endl;

    /* 
    Alternate Soln.
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<"  ";
        }
        for(char j='A';j<'A'+i;j++){
            cout<<j<<" ";
        }
        char ch = 'A'+i-2;
        for(char j='A';j<'A'+i-1;j++){
            cout<<ch<<" ";
            ch = ch-1;
        }

        cout<<endl;
    }

    */
}
void print18(int n){
    char ch = 'A'+n-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<ch<<" ";
            ch+=1;
        }
        ch-=i+1;
        cout<<endl;
    }
    cout<<endl;

    
    //Alternate Pattern:
    //  char ch = 'A'+n-1;
    // for(int i=1;i<=n;i++){
    //  for(int j=1;j<=i;j++){
    //      cout<<ch<<" ";
    //      ch-=1;
    //  }
    //  ch+=i;
    //  cout<<endl;
    // }
    // cout<<endl;
    
}
void print19(int n){
    for(int i=0;i<n;i++){
        
            for(int j=0;j<n-i;j++){
                cout<<"*";
            }

            for(int j=0;j<2*i;j++){
                cout<<" ";
            }

            for(int j=0;j<n-i;j++){
                cout<<"*";
            }
            cout<<endl;

    }
    for(int i=0;i<n;i++){
        
            for(int j=0;j<=i;j++){
                cout<<"*";
            }

            for(int j=0;j<2*(n-i-1);j++){
                cout<<" ";
            }

            for(int j=0;j<=i;j++){
                cout<<"*";
            }

            cout<<endl;

    }
    cout<<endl;

}
void print20(int n){
    int spaces = 2*n-2;
    for(int i=1;i<=2*n-1;i++){
        int stars = i;
        if(i>n) stars = 2*n-i;
        for(int j=0;j<stars;j++){
            cout<<"* ";
        }
    

        for(int j=0;j<spaces;j++){
            cout<<"  ";
        }

        for(int j=0;j<stars;j++){
            cout<<"* ";
        }
        cout<<endl;
        if(i<n) spaces-= 2;
        else spaces += 2;
    }
    cout<<endl;

    // for(int i=0;i<n;i++){
    //  for(int j=0;j<=i;j++){
    //      cout<<"* ";
    //  }

    //  for(int j=0;j<2*(n-i-1);j++){
    //      cout<<"  ";
    //  }

    //  for(int j=0;j<=i;j++){
    //      cout<<"* ";
    //  }
    //  cout<<endl;
    // }
    // for(int i=0;i<n-1;i++){
    //  for(int j=0;j<n-i-1;j++){
    //      cout<<"* ";
    //  }

    //  for(int j=0;j<2*(i+1);j++){
    //      cout<<"  ";
    //  }

    //          for(int j=0;j<n-i-1;j++){
    //      cout<<"* ";
    //  }
    //  cout<<endl;
    // }
    // cout<<endl;

}
void print21(int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0||i==n-1||j==0||j==n-1) cout<<"*";
                else cout<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
}
void print22(int n){
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            int top = i;
            int left = j;
            int bottom = (2*n-2)-i;
            int right = (2*n-2)-j;
            cout<< (n - min(min(top,bottom),min(left,right)));
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        print10(n);
    }
    return 0;
}
