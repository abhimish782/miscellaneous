#include<bits/stdc++.h>
using namespace std;
 // this was a ques in some contest
bool valid(vector<int>perm,vector<vector<int>>& happyTable){
    for(int i:perm){
        cout<<i<<" ";
    }
    cout<<"->";
    for(int i=0;i<perm.size();i++){
        perm[i]=happyTable[i][perm[i]];
    }
    for(int i:perm){
        cout<<i<<" ";
    }
    cout<<endl;
    
    int all=0;
    for(int i=0;i<perm.size();i++){
        if(perm[i]==2) all++;
        else if(perm[i]==3) return true;
    }
    return all==perm.size();
}

void search(vector<int>&childAndHappy,vector<int>&perm,int &cnt,vector<vector<int>>&happyTable,vector<bool>&bits){
    if(perm.size()==childAndHappy.size()){
        if(valid(perm,happyTable)) {
            cnt++;
            return;
        }
    }

    else{
        for(int i=0;i<bits.size();i++){
            if(bits[i]){
                bits[i]=false;
                perm.push_back(childAndHappy[i]);
                search(childAndHappy,perm,cnt,happyTable,bits);
                perm.pop_back();
                bits[i]=true;
            }
        }
    }

}
int findNoOfHappy(int a,vector<vector<int>>&happyTable){
    vector<int>childrenAndGift(a);
    for(int i=0;i<a;i++){
        childrenAndGift[i]=i;
    }
    for(int i=0;i<a;i++){
        cout<<i<<"->"<<childrenAndGift[i]<<endl;
    }
    vector<int>perm;
    vector<bool>bits(a,true);
    int cnt=0;
    search(childrenAndGift,perm,cnt,happyTable,bits);
    return cnt;


}
int main(){
    int a=13;
    vector<vector<int>>happyTable;
    happyTable={{1,1,3,2,3},{3,3,3,3,3},{2,3,1,1,3},{2,2,2,1,2},{2,1,1,2,1},{1,1,3,2,3},{3,3,3,3,3},{2,3,1,1,3},{2,2,2,1,2},{2,1,1,2,1},{1,1,3,2,3},{3,3,3,3,3},{2,3,1,1,3}};
    cout<<findNoOfHappy(a,happyTable)<<endl;
    return 0;

}