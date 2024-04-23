#include<bits/stdc++.h>
using namespace std;
struct cmp{
    bool operator()(pair<int,int>p1,pair<int,int>p2){
        if(p1.first==p2.first){
            return p1.second<p2.second;
        }
        return p1.first<p2.first;
    }
};
int findTime(vector<pair<int,int>>&students,int d){
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq(students.begin(),students.end());
    int cnt=0;
    map<int,pair<int,int>>s1;
    while(!pq.empty()&&d--){
        s1[cnt+pq.top().second]=(pq.top());
        cnt++;
        pq.pop();
        if(s1.find(cnt)!=s1.end()) pq.push(s1[cnt]);
        if(s1.size()==students.size()) break;
    }
    return cnt;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        vector<pair<int,int>>students;
        for(int i=0;i<n;i++){
            pair<int,int>temp;
            cin>>temp.first>>temp.second;
            students.push_back(temp);
        }
        cout<<"answer is"<<findTime(students,d)<<endl;

    }
    return 0;
}