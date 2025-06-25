#include<bits/stdc++.h>
using namespace std ;

class Node{
    public :
    int data ; 
    Node *next ; 
    
    Node(int data){
        this->data = data ; 
        this->next = NULL;
    }
};

class LinkedList{
    Node *head ; 
    Node *tail ; 

    public : 
    LinkedList(){
        this->head = NULL;
        this->tail = NULL;

    }

    void Accept(int nodeCount){
        for(int i = 0 ;  i < nodeCount ; i++){
            int data ; 
            cout<<"Enter data in linkedList : ";
            cin>>data ;

            Node *newNode = new Node(data);
            if(this->head == NULL){
                this->head = newNode ;
                this->tail = newNode ;
            }else{
                this->tail->next = newNode ; 
                this->tail = newNode;
            }
        }
    }
    void InsertAtTheBeginning(Node *n){
        if(this->head == NULL){
            this->head = n ; 
            this->tail = n ;
        }else{
            n->next = this->head ; 
            this->head = n ;
        }
        return ;
    }
    void InsertAtTheEnd(Node *n){
        if(this->head == NULL){
            this->head = n ;
            this->tail = n ;
        }else{
            this->tail->next = n ;
            this->tail = n;
        }
        return ;
    }

    int FindLength(){
        Node *itr = this->head ;
        int count = 0 ;
        while(itr != NULL){
            count++;
            itr = itr->next ;
        }
        return count ;
    }

   void InsertInBetween(int pos){
    int data;
    cout << "Enter data: ";
    cin >> data;

    Node *newNode = new Node(data);

    if(pos <= 0 || head == nullptr){
        InsertAtTheBeginning(newNode);
        return;
    }

    if(pos >= FindLength()){
        InsertAtTheEnd(newNode);
        return;
    }

    Node *itr = head;
    for(int i = 0; i < pos - 1 && itr != nullptr; i++){
        itr = itr->next;
    }

    newNode->next = itr->next;
    itr->next = newNode;
}

   
    void Display(){
        if(this->head == NULL) {
            cout<<"Please Insert Nodes in linked List\n";
            return ;
        }
        Node *itr = this->head ;
        while(itr != NULL){
            cout<<itr->data<<" ";
            itr=itr->next ; 
        }
        cout<<"\n";

        return;
    }
};


int main(){
    LinkedList ll = LinkedList();
    ll.Accept(5);
    ll.Display();
return 0;
}