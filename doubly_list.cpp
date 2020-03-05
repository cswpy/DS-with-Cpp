//Doubly linked list, @author Phillip Wang
#include<iostream>
#include<exception>
#include<string>
using namespace std;

class Node
{
	private:
		string elem; //data element (type string in this case)
		Node* next; //Link (pointer) to the next Node
		Node* prev; //Link (pointer) to the previous Node
		friend class MyDoublyLinkedList;
		
	public:
		Node(): next(NULL), prev(NULL)
		{}
		Node(string elem) : elem(elem)
		{}
};
//==============================================================
class MyDoublyLinkedList
{
	private:
		Node* head; // pointer to the head of list
		Node* tail; 
	public:
		MyDoublyLinkedList (); // empty list constructor
		~MyDoublyLinkedList (); // destructor to clean up all nodes
		bool empty() const; // is list empty?
		const string& front() const; // get front element
		const string& back() const;  //get last element 
		void add(Node *ptr, const string& elem);	 //add a new node before ptr
		void addBefore(const string& elem, string newElem); 	//add a new element before some specific element 
		void addFront(const string& elem); // add to front of list
		void addBack(const string & elem); //add to the back of the list
		void removeFront(); // remove front item from list
		void removeBack();  // remove last item from list
		void reverseList();	// reverse the list
		void displayAll() const;	// display all element of the list
};
//===================================

MyDoublyLinkedList::MyDoublyLinkedList() {
    this->head = new Node();
    this->tail = new Node();
    this->head->next=this->tail; 
    this->tail->prev=this->head;
    }

bool MyDoublyLinkedList::empty() const {return this->head->next==this->tail;}
const string& MyDoublyLinkedList::front() const {return this->head->elem;}
const string& MyDoublyLinkedList::back() const {return this->tail->elem;}

void MyDoublyLinkedList::add(Node *ptr, const string& elem){
    Node* data = new Node(elem);
    data->next = ptr;
    data->prev = ptr->prev;
    ptr->prev->next = data;
    ptr->prev = data;
}

void MyDoublyLinkedList::addBefore(const string& elem, string newElem){
    Node* curr = this->head;
    while(curr!=NULL){
        if(curr->elem==elem)
            break;
        curr = curr->next;
    }
    this->add(curr,newElem);
}

void MyDoublyLinkedList::addFront(const string& elem){
    //cout<<(this->head==tail)<<endl;
    this->add(this->head->next, elem);
}

void MyDoublyLinkedList::addBack(const string& elem){
    this->add(this->tail,elem);
}

void MyDoublyLinkedList::removeFront(){
    if(!this->empty()){
        Node* tmp = this->head->next;
        this->head->next = tmp->next;
        tmp->next->prev = this->head;
        delete tmp;
    }
}

void MyDoublyLinkedList::displayAll() const{
    Node* curr = this->head->next;
    while(curr!=NULL){
        cout<<curr->elem<<" ";
        curr = curr->next;
    }
}

MyDoublyLinkedList::~MyDoublyLinkedList(){
    while(!this->empty())
        this->removeFront();
    delete this->head;
    delete this->tail;
}

void MyDoublyLinkedList::removeBack(){
    if(!this->empty()){
        Node* tmp = this->tail->prev;
        tmp->prev->next = this->tail;
        this->tail->prev = tmp->prev;
        delete tmp;
    }
}


void MyDoublyLinkedList::reverseList(){
if(!empty())
	{
		Node *tmp = head;			//tmp variable used to swap tail and head
		head = tail;
		tail = tmp;
		Node *ptr = head;			//start from head (old tail)
		while(ptr!=NULL)			//while ptr is not the end of the list	
		{							//keep swapping next and prev pointers of every node
			Node *tmp = ptr->next;
			ptr->next = ptr->prev;
			ptr->prev = tmp;
			ptr = ptr->next;
		}
	}
}

int main()
{

	MyDoublyLinkedList myList;
	myList.addFront("c");
	myList.addFront("b");
	myList.addFront("a");
	myList.addBack("z");
    myList.displayAll();
	myList.addBefore("z","y");
	cout<<"Original List :"<<endl;
	myList.displayAll();
	myList.removeBack();
    myList.displayAll();
	myList.removeFront();
	myList.displayAll();
	cout<<"Reversed List:"<<endl;
	myList.reverseList();
	myList.displayAll();
	return EXIT_SUCCESS;
}