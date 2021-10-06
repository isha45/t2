#include<bits/stdc++.h>
using namespace std;

class que{
    stack<int>s1,s2;
    public:
    int empty(){
        return s1.empty() && s2.empty();
    }
    void push(int val){
        if(s1.empty()&&s2.empty()){
            s1.push(val);
        }
        else if(!s1.empty()){
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            s1.push(val);
        }

        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s2.push(val);
        }
    }

    void pop(){
        if(!s1.empty()){
            s1.pop();
        }
        else{
            s2.pop();
        }
    }

    int front(){
        if(!s1.empty()){
            return s1.top();
        }
        return s2.top();
    }
};

int main(){
    que q;
    cout<<"Is queue empty ? "<<q.empty()<<endl;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    return 0;
}
