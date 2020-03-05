//Singly Linked List Implementation, created Feb 27, 2020, author Phillip Wang


#include<string>
#include<iostream>
using namespace std;

class Node{
    private:
    string elem;
    Node* next;
    public:
    Node(string elem): elem(elem), next(NULL) {}
    friend class MyLinkedList;
};

class MyLinkedList{
    private:
    Node* head;
    public:
    MyLinkedList();
    ~MyLinkedList();
    bool isEmpty();
    const string& front() const;
    void addFront(const string& elem);
    void removeFront();
    void displayAll();
};

MyLinkedList::MyLinkedList(): head(NULL) {}

void MyLinkedList::addFront(const string& elem){
    Node* newNode = new Node(elem);
    newNode->next = this->head;
    this->head = newNode;
}

const string& MyLinkedList::front() const{
    return this->head->elem;
}


bool MyLinkedList::isEmpty(){
    return (this->head==NULL ? true : false);
}

void MyLinkedList::removeFront(){
    Node* tmp = this->head;
    this->head = tmp->next;
    delete tmp;
}

void MyLinkedList::displayAll(){
    Node* curr = this->head;
    while(curr!=NULL){
        cout<<curr->elem<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

MyLinkedList::~MyLinkedList(){
    while(this->isEmpty()==false){
        this->removeFront();
    }
}

int main(){
    MyLinkedList ll1 = MyLinkedList();
    ll1.addFront("A");
    ll1.addFront("B");
    ll1.addFront("C");
    ll1.addFront("D");
    ll1.displayAll();
    ll1.removeFront();
    cout<<"First element: "<<ll1.front()<<endl;
    ll1.~MyLinkedList();
    cout<<ll1.isEmpty()<<endl;
    return 0;
}