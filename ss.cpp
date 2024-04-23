#include<bits/stdc++.h>
using namespace std;
int fib(int n){
    if(n<=1) return n;
    int n1=fib(n-1)+fib(n-2);
    cout<<n1<<endl;
    return n1;

}
using namespace std;
int main(){
    int a;
    cin>>a;
    int n=fib(a);
    cout<<(long long)(LLONG_MAX);
}