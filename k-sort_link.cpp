#include <iostream>
using namespace std;
class SLLNode
{
    public:
        SLLNode();
        virtual ~SLLNode();
        int getData();
        bool setData(int );
        SLLNode* getNextPtr();
        SLLNode* getPrePtr();
        bool setNextPtr(SLLNode*);
        bool setPrePtr(SLLNode*);

    protected:

    private:
        int data;
        SLLNode* next;
        SLLNode* pre;
};



class DoublyLinkedList
{
    public:
        DoublyLinkedList();
        virtual ~DoublyLinkedList();
        void addB(SLLNode* nodePtr);
        void addE(SLLNode* nodePtr);
        SLLNode* getLastNodeAddress();
        SLLNode* getHead();
        void printList();
        bool isEmpty();

    protected:

    private:
        SLLNode* head;
};

SLLNode::SLLNode(){
    data=0;
    next=NULL;
    pre=NULL;
}

int SLLNode::getData(){
    return(data);
}

bool SLLNode::setData(int val){
    data=val;
    return(true);
}

SLLNode* SLLNode::getNextPtr(){
    return(next);
}
SLLNode* SLLNode::getPrePtr(){
    return(pre);
}
bool SLLNode::setNextPtr(SLLNode* nodePtr){
    next=nodePtr;
    pre= NULL;
    return(true);
}
bool SLLNode::setPrePtr(SLLNode* nodePtr){
    pre=nodePtr;
    next=NULL;
    return(true);
}

SLLNode::~SLLNode(){
    //dtor
}
DoublyLinkedList::DoublyLinkedList(){
    head=NULL;
    cout<<head<<endl;

}
void DoublyLinkedList::addB(SLLNode* nodePtr){
    nodePtr->setNextPtr(head);
    nodePtr->setPrePtr(NULL);
    if(head==NULL){
        head=nodePtr;
    }
    else{
        head->setPrePtr(nodePtr);
        head=nodePtr;
    }    
}

SLLNode* DoublyLinkedList::getLastNodeAddress(){
    SLLNode* curr;
    curr=head;
    if(curr==NULL){
        return(curr);
    }
    while(curr->getNextPtr()){
        curr=curr->getNextPtr();
    }
    return(curr);

}

void DoublyLinkedList::addE(SLLNode* nodePtr){
    SLLNode* lnode=getLastNodeAddress();
    if(lnode!=NULL){
        lnode->setNextPtr(nodePtr);
        nodePtr->setNextPtr(NULL);
        nodePtr->setPrePtr(lnode);
        
    }else{
        addB(nodePtr);
    }
}
void DoublyLinkedList::printList(){
    SLLNode* curr;
    curr=head;
    cout<<"The Doubly linked list is "<<endl;
    while(curr!=NULL){
        cout<<" "<<curr->getData()<<" ";
        curr=curr->getNextPtr();
    }
    cout<<endl;
}


SLLNode* DoublyLinkedList::getHead(){
    return(head);
}

bool DoublyLinkedList::isEmpty(){
    if(head==NULL){
        return(true);
    }
    return(false);
}
DoublyLinkedList::~DoublyLinkedList(){
    //dtor
}
int main()
{
     cout << "Singly linked list implementation" << endl;
    DoublyLinkedList* l1=NULL;
    SLLNode* n1;

    int choice;
    while(true){
        cout<<"1. Create new empty list"<<endl;
        cout<<"2. Add element at the beginning of the list"<<endl;
        cout<<"3. Add element at the end of the list"<<endl;
        cout<<"4. Print the list"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice "<<endl;
        cin>>choice;
        switch(choice){
        case 1:
            l1=new DoublyLinkedList();
            break;

        case 2:
            cout<<"Enter the element value "<<endl;
            int valB;
            cin>>valB;
            n1=new SLLNode();
            n1->setData(valB);
            l1->addB(n1);
            break;

        case 3:
            cout<<"Enter the element value "<<endl;
            int valE;
            cin>>valE;
            n1=new SLLNode();
            n1->setData(valE);
            l1->addE(n1);
            break;
        case 4:
            l1->printList();
            return(0);
        case 5:
            return 0;
        default:
            cout<<"wrong input"<<endl;
            return(0);
        }
    }
}