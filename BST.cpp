//seccessor and predsessor
#include<iostream>
using namespace std;
class node{
    public:
    int key;
    node* left;
    node* right;
    node* parent;
    node(int );
    void addLeft(node*);
    void addRight(node*);
    void setParent(node*);
};
node::node(int v){
    key=v;
    left=right=parent=NULL;
}
void node::addLeft(node *n){
    left=n;
}
void node::addRight(node *n){
    right=n;
}
void node::setParent(node *n){
    parent=n;
}
class bst{
    public:
    node* root;
    bst (){
        root = NULL;
    }
    void create();
    void insert(node*);
    void remove(int);
    node* search(int);
    void inorder();
    node* minimum(node*);
    node* maximun(node*);
    void tinorder(node*);
    node* inorder_successor(int);
    node* inorder_predecessor(int);
};
node* bst :: maximun(node *r){
    node* temp = r;
    while(temp->left){
        temp=temp->left;
    }
    return temp;
}
node* bst :: minimum(node* r){
    node* temp = r;
    while(temp->right){
        temp=temp->right;
    }
    return temp;
}
node* bst :: inorder_successor(int v){
    node* temp = search(v);
    if(temp->right!=NULL){
        return minimum(temp);
    }
    node* temp1=temp->parent;
    while(temp1!=NULL && temp == temp1->right){
        temp = temp1;
        temp1 = temp1->parent;
    }
    return temp1;
    
}
node* bst :: inorder_predecessor(int v){
    node* temp = search(v);
    if(temp->left!=NULL){
        return minimum(temp);
    }
    node* temp1=temp->parent;
    while(temp1!=NULL && temp == temp1->left){
        temp = temp1;
        temp1 = temp1->parent;
    }
    return temp1;
    
}
void bst:: tinorder(node *t){
    if(t==NULL){
        return ;
    }
    tinorder(t->left);
    cout<<t->key<<" ";
    tinorder(t->right);
    return;
}
void bst :: inorder(){
    tinorder(root);
    return;
}
void bst :: remove(int v){
    if(search(v)==NULL){
        cout<<"Element not found\n";
        return ;
    }
    node *temp = search(v);
    node* temp1;
    temp1 =  temp->parent;
    if(temp->left == NULL && temp->right == NULL){
        if(temp == temp1->left){
            temp1->left = NULL;
            delete temp;
        }
        else{
            temp1->right = NULL;
            delete temp;
        }
    }
    else if(temp->left == NULL){
        if(temp == temp1->left){
            temp1->left = temp->right;
            (temp->right)->parent = temp1;
            delete temp;
        }
        else{
            temp1->right = temp->right;
            (temp->right)->parent = temp1;
            delete temp;
        }
    }
    else if(temp->right ==NULL){
        if(temp == temp1->left){
            temp1->left = temp->left;
            (temp->left)->parent = temp1;
            delete temp;
        }
        else{
            temp1->right = temp->left;
            (temp->left)->parent = temp1;
            delete temp;
        }
    }
    else{
        node * temp2;
        temp2 = temp->left;
        node * temp3;
        temp3 = temp2;
        while(temp2->right !=NULL){
            temp2 = temp2->right;
        }
        node* temp4 = temp2;
        node* temp5 = new node(temp4->key);
        // cout<<temp5->key<<endl;
        remove(temp4->key);
        if(temp == temp1->left){
            temp1->left = temp5;
            temp5->parent = temp1;
            temp5->left = temp->left;
            (temp->left)->parent = temp5;
            temp5->right = temp->right;
            (temp->right)->parent = temp5;
            delete temp;
        }
        else{
            temp1->right = temp5;
            temp5->parent = temp1;
            temp5->left = temp->left;
            (temp->left)->parent = temp5;
            temp5->right = temp->right;
            (temp->right)->parent = temp5;
            delete temp;
        }
    }
}
node* bst :: search(int v){
    node* temp;
    temp=root;
    while(temp){
        if(temp->key == v){
            return temp;
        }
        else if(temp->key > v){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
    return NULL;
}
void bst::create(){
    root = NULL;
}
void bst :: insert(node* n){
    if(root== NULL){
        root = n;
        return ;
    }
    cout<<n->key<<" In insert function\n";
    node *temp = root;
    node *temp1 =NULL;
    while(temp){
        temp1=temp;
        if((temp->key) > (n->key)){
            cout<<n->key<<" Inside while loop for right\n";
            temp = temp->right;
        }
        else{
            cout<<n->key<<" Inside while loop for left\n";
            temp = temp->left;
        }
    }
    if(temp1->key > n->key){
        cout<<n->key<<" Adding to right\n";
        n->setParent(temp1);
        temp1->addRight(n);
        
    }
    else{
        cout<<n->key<<" Adding to left\n";
        n->setParent(temp1);
        temp1->addLeft(n);
        
    }
}
int main(){
    node * h1 = NULL;
    bst *b = NULL;
    b = new bst();
    h1 = new node(300);
    b->insert(h1);
    node* h2 = new node(400);
    b->insert(h2);
    node* h3 = new node(100);
    b->insert(h3);
    node* h4 = new node(50);
    b->insert(h4);
    node* h5 = new node(150);
    b->insert(h5);
    node* h6 = new node(175);
    b->insert(h6);
    node* h7 = new node(10);
    b->insert(h7);
    // node* h8 = new node(70);
    // b->insert(h8);
    // node* h9 = new node(81);
    // b->insert(h9);
    // node* h10 = new node(60);
    // b->insert(h10);
    b->inorder();
    cout<<endl;
    // b->remove(50);
    // b->remove(25);
    b->remove(100);
    // b->remove(175);
    b->remove(50);
    // cout<<(b->search(25))->key<<endl;
    // b->inorder();
    // cout<<(b->inorder_predecessor(25))->key<<endl;
    // cout<<"sdfg"<<endl;
    // cout<<(b->inorder_successor(20))->key<<endl;
    // b->remove(2011);
    b->inorder();
    return 0;
}