#include<bits/stdc++.h>
using namespace std;

 // checking for github
 
struct Node{
    int val;
    Node* next;
    Node* random;

    Node(int x){
        val=x;
        this->next=NULL;
        this->random=NULL;
    }
};


int main(){
    Node* head=new Node(1);
    Node* node2=new Node(2);
    Node* node3=new Node(3);
    head->next=node2;
    node2->next=node3;
    head->random=node3;
    node2->random=head;
    node3->random=node2;

    


}