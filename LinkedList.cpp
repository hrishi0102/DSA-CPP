#include <iostream>
#include <stdlib.h>
using namespace std;

//Creating the Node Structure
struct Node {
    int data;
    Node* next;
};

//Setting up a global Variable Head(when list is empty)
Node* head = NULL;

void InsertatStart(int x){
    Node* temp = new Node();
    temp -> data = x;
    temp -> next = head;
    head = temp;
}

void InsertatEnd(int x){
    Node* temp = new Node();
    Node* last = head;
    temp ->data = x;
    temp -> next = NULL;
    if(head == NULL){
        head = temp;
        return;
    }
    while(last ->next != NULL){
        last = last ->next;
    }
    last ->next = temp;
    return;
}

void InsertatN(int x, int n){
    Node* temp = new Node();
    temp ->data = x;
    temp ->next = NULL;
    if(n == 1){
        temp -> next = head;
        head = temp;
        return;
    }
    Node* temp2 = head;
    for(int i = 0; i< n-2; i++){
        temp2 = temp2 -> next;
    }
    temp ->next = temp2 ->next;
    temp2-> next = temp;

}

void DeleteatStart(){
    head = head-> next;
}

void DeleteatEnd(){
    Node* trav = head;
    while(trav -> next ->next != NULL){
        trav = trav->next;
    }
    trav-> next = NULL;
}

void DeleteatN(int n){
    Node* trav = head;
    if( n==1 ){
        head = trav->next;
        delete trav;
        return;
    }
    for(int i=0; i<n-2; i++){
        trav = trav-> next;
    }
    Node* temp = trav -> next;
    trav -> next = temp ->next;
    delete temp;
}

void Print(){
    Node* trav = head;
    cout<<"List is:";
    while(trav != NULL){
        cout << " " <<trav -> data;
        trav = trav->next;
    }
}

int main() {
    int n,val;
    cout<<"Enter total numbers in LinkedList: "<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        cout<<"Enter Value: ";
        cin>>val;
        InsertatEnd(val);
        Print();
        cout<<endl;
    }
    // DeleteatStart();
    // DeleteatEnd();
    // DeleteatN(1);
    // Print();
    // InsertatN(3,1);
    // InsertatN(6,2);
    // InsertatN(5,3);
    // InsertatN(4,2);
    // Print();
}
