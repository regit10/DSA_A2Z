#include<iostream>
#include<vector>
#include<utility>
#include<list>
#include<stack>
#include<queue>

using namespace std;

void explainPair(){
    pair<int,int> p1 = {1,2};  // Can also hold any other DTs or combos of both.
    cout<<p1.first<<" "<<p1.second<<endl;
    
    pair<int,pair<int,int>> p2 = {1,{2,3}};
     cout<<p2.first<<" "<<p2.second.first<<" "<<p2.second.second<<endl;
}

void explainVector(){
  vector<int> v1(5,10);
  
    v1.push_back(1);
    v1.emplace_back(2); 
    v1.erase(v1.begin()+1);
    v1.erase(v1.begin()+3,v1.end()-1);

    for(auto it:v1){               // for(vector<int>::iterator it =v1.begin();it<v1.end();it++)
        cout<< it <<" ";
    } cout<< endl;
    
    v1.insert(v1.begin(),11);
    v1.insert(v1.begin()+3,2,12);
    vector<int> copy(2,50);
    v1.insert(v1.begin()+2,copy.begin(),copy.end());
     for(auto it:v1){               
        cout<< it <<" ";
    } cout<< endl;
    cout<<v1.size()<<endl;
    v1.pop_back();
    for(auto it:v1){               
        cout<< it <<" ";
    } cout<< endl;
    for(auto it:copy){
        cout<<it<<" ";
    }cout<<endl;
    copy.clear();
    for(auto it:copy){
        cout<<it<<" ";
    }cout<<endl;

}

void explainList(){
    list<int> ls;
    ls.push_back(5);
    for(auto it:ls){
        cout<<it<<" ";
    }
    cout<<endl;

    ls.emplace_back(6);
    for(auto it:ls){
        cout<<it<<" ";
    }
    cout<<endl;

    ls.push_front(4);
    for(auto it:ls){
        cout<<it<<" ";
    }
    cout<<endl;

    ls.emplace_front(3);
     for(auto it:ls){
        cout<<it<<" ";
    }
    cout<<endl;

}

void explainStack(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(6);
    st.push(5);
    st.push(7);

 
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
    cout<<st.empty()<<endl;;
    cout<<st.top();

}

void explainQueue(){
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.emplace(3);
    q1.emplace(4);
    q1.back()+= 5;
    cout<<q1.back()<<endl;
    q1.pop();
    cout<<q1.front();
    // Size swap empty same as stack

}

using namespace std;
int main(){
    // explainPair();
    // explainVector();
    // explainList();
    // explainStack();
    explainQueue();
    return 0;

}