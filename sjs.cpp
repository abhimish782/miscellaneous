#include<bits/stdc++.h>
using namespace std;
 // class examples in cpp
 
class something{
    private:
        int x;
        int y;
    public:
    void set(int a, int b){
        x = a;
        y = b;
        }
        void get(){
            cout<<"x = "<<x<<" y = "<<y<<endl;
            }
};
int main(){
    something s1;
    s1.set(50, 70);
    s1.get();
    return 0;
}