#include<bits/stdc++.h>
using namespace std;

// same thing here

void adjacencymatrix(vector<pair<int,int>>v)
{
    int m=INT_MIN;
    for(auto k:v)
    {
        if(k.first>k.second)
        m=max(m,k.first);
        else
        m=max(m,k.second);
    }
vector<vector<int>>ans2(m+1, vector<int>(m+1 , 0));
    for(auto k:v)
    {
        ans2[k.first][k.second]=1;
        ans2[k.second][k.first]=1;
    }
    for(int i=1;i<ans2.size();i++)
    {
        for(int j=1;j<ans2[i].size();j++)
        {
            cout<<ans2[i][j]<<",";
        }
        cout<<endl;
    }
}

void getadjacencylist(vector<pair<int,int>>v)
{
    vector<vector<int>>ans(v.size());
    for(int i=0;i<v.size();i++)
    {
        ans[v[i].first].push_back(v[i].second);
        ans[v[i].second].push_back(v[i].first);
    }
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<",";
        }
        cout<<endl;
    }
}
void printgraph(vector<pair<int,int>>v)
{
     getadjacencylist(v);
    adjacencymatrix(v);
}
int main()
{
    vector<pair<int,int>>v(6);
    v.push_back({3,5});
    v.push_back({4,5});
    v.push_back({1,5});
    v.push_back({2,1});
    v.push_back({2,4});
    v.push_back({4,1});
    printgraph(v);
    return 0;
}