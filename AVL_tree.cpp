#include<iostream>
using namespace std;
//node class
class node{
    public:
    int key;
    int l_height;
    int r_height;
    node* left;
    node* right;
    node* parent;
    node(int );
    void addLeft(node*);
    void addRight(node*);
    void setParent(node*);
    int glh();
    int grh();
    int gk();
    node* gparent();
    node* glchild();
    node* grchild();
};
//node function
int node :: glh(){
    return (l_height);
}
int node :: grh(){
    return (r_height);
}
int node :: gk(){
    return (key);
}
node* node :: gparent(){
    return (parent);
}
node* node :: glchild(){
    return (left);
}
node* node :: grchild(){
    return (right);
}
node::node(int v){
    key=v;
    l_height=r_height=0;
    left=right=parent=NULL;
}
void node::addLeft(node *n){
    l_height++;
    left=n;
}
void node::addRight(node *n){
    r_height++;
    right=n;
}
void node::setParent(node *n){
    parent=n;
}

//avl class and function
class avl{
    public:
    node* root;
    avl(){
        root = NULL;
    }
    void insert(node*);
    void leftrotate(node*);
    void rightrotate(node*);
    void create();
    node* search(int);
    void inorder();
    node* minimum(node*);
    node* maximun(node*);
    void tinorder(node*);
    node* inorder_successor(int);
    node* inorder_predecessor(int);
};
void avl :: insert(node* n){
    if(root== NULL){
        root = n;
        return ;
    }
    if(root->left == NULL && root->right == NULL){
        node *temp = root;
        if((temp->key) > (n->key)){
            temp->addRight(n);
            temp->right->setParent(temp);
        }
        else{
            temp->addLeft(n);
            temp->left->setParent(temp);
        }
        return ;
    }
    node *temp = root;
    node *temp1 =NULL;
    while(temp){
        temp1=temp;
        if((temp->key) > (n->key)){
            temp->r_height = temp->grh()+1;
            temp = temp->right;
        }
        else{
            temp->l_height = temp->glh()+1;
            temp = temp->left;
        }
    }
    if(temp1->key > n->key){
        temp1->r_height = temp1->grh()-1;
        n->setParent(temp1);
        temp1->addRight(n);
    }
    else{
        temp1->l_height =temp1->grh()-1;
        n->setParent(temp1);
        temp1->addLeft(n);
    }
    // node *temp2,*temp3;
    // temp1 = n;
    // temp2 = temp1->parent;
    // temp3 = temp2->parent;
    // if(temp2 == temp3->left && temp3 != NULL){
    //     temp3->l_height = max(temp2->l_height,temp2->r_height);
    // }
    // else if(temp2 == temp3->right && temp3 != NULL){
    //     temp3->r_height = max(temp2->l_height,temp2->r_height);
    // }
    // while(temp3 && abs(temp3->l_height - temp3->r_height)<2){
    //     temp1 = temp2;
    //     temp2 = temp2->parent;
    //     temp3 = temp3->parent;
    //     if(temp1 == temp2->left){
    //         temp2->l_height = max(temp1->l_height,temp1->r_height);
    //     }
    //     else if(temp1 == temp1->right){
    //         temp2->r_height = max(temp1->l_height,temp1->r_height);
    //     }
    //     if(temp2 == temp3->left && temp3 != NULL){
    //         temp3->l_height = max(temp2->l_height,temp2->r_height);
    //     }
    //     else if(temp2 == temp3->right && temp3 != NULL){
    //         temp3->r_height = max(temp2->l_height,temp2->r_height);
    //     }
    // }
    // if(temp2 == temp3->left && temp1 == temp2->left){
    //     rightrotate(temp3);
    // }
    // else if(temp2 == temp3->right && temp1 == temp2->right){
    //     leftrotate(temp3);
    // }
    // else if(temp2 == temp3->left && temp1 == temp2->right){
    //     leftrotate(temp2);
    //     rightrotate(temp3);
    // }   
    // else if(temp2 == temp3->right && temp1 == temp2->left){
    //     rightrotate(temp2);
    //     leftrotate(temp3);
    // } 
    return ;
}    
void avl :: rightrotate(node* n){
    node* temp = n->left;
    node* temp1 ;
    temp->parent = n->parent;
    if(n->parent !=NULL && n == n->parent->left) {
        n->parent->left = temp;
    }
    else if(n->parent !=NULL && n == n->parent->right){
        n->parent->right = temp;
    }
    temp1 = temp->right;
    temp->right = n;
    n->parent = temp; 
    temp->right->left = temp1;
    temp1->parent = temp->right;
    //updating height
    temp->l_height = max(temp->left->l_height,temp->left->r_height);
    temp->right->l_height = max(temp->right->left->l_height,temp->right->left->r_height);
    temp->right->r_height = max(temp->right->right->l_height,temp->right->right->r_height);
    temp->r_height = max(temp->right->l_height,temp->right->r_height);
    return;
}
void avl :: leftrotate(node* n){
    node* temp = n->right;
    node* temp1 ;
    temp->parent = n->parent;
    if(n->parent !=NULL && n == n->parent->left) {
        n->parent->left = temp;
    }
    else if(n->parent !=NULL && n == n->parent->right){
        n->parent->right = temp;
    }
    temp1 = temp->left;
    temp->left = n;
    n->parent = temp; 
    temp->left->right = temp1;
    temp1->parent = temp->left;
    //updating height
    temp->r_height = max(temp->right->l_height,temp->right->r_height);
    temp->left->l_height = max(temp->left->left->l_height,temp->left->left->r_height);
    temp->left->r_height = max(temp->left->right->l_height,temp->left->right->r_height);
    temp->l_height = max(temp->left->l_height,temp->left->r_height);
    return;
}
void avl :: create(){
    root = NULL;
    return;
}
node* avl :: maximun(node *r){
    node* temp = r;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
node* avl :: minimum(node* r){
    node* temp = r;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}
node* avl :: inorder_successor(int v){
    node* temp = search(v);
    if(temp->right!=NULL){
        return maximun(temp->right);
    }
    node* temp1=temp->parent;
    while(temp1!=NULL && temp != temp1->left){
        temp = temp1;
        temp1 = temp1->parent;
    }
    return temp1; 
}
node* avl :: inorder_predecessor(int v){
    node* temp = search(v);
    if(temp->left!=NULL){
        return minimum(temp->left);
    }
    node* temp1=temp->parent;
    while(temp1!=NULL && temp != temp1->right){
        temp = temp1;
        temp1 = temp1->parent;
    }
    return temp1;
}
void avl :: tinorder(node *t){
    if(t==NULL){
        return ;
    }
    tinorder(t->left);
    cout<<t->key<<" "<<t->l_height<<" "<<t->r_height<<endl;
    tinorder(t->right);
    return;
}
void avl :: inorder(){
    tinorder(root);
    return;
}
node* avl :: search(int v){
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
int main(){
    avl *b = NULL;
    node *h2 = NULL;
    int a,n,n1,n3;
    while(true){
        cout<<"1.To create an empty AVL tree\n";
        cout<<"2.To insert one element\n";
        cout<<"3.Status of the AVL tree currently\n";
        cout<<"4.To search a value in AVL tree\n";
        cout<<"5.To get inorder predecessor\n";
        cout<<"6.To get inorder successor\n";
        cout<<"7.To exit\n";
        cout<<"Enter your choice\n";
        cin>>a;
        switch(a){
            case 1 :
                b = new avl();
                b->create();
                break;
            case 2 : 
                cout<<"Enter the element to be inserted\n";
                cin>>n;
                h2 = new node(n);
                b->insert(h2);
                break;
            case 3 :
                cout<<"Current status of the AVL tree\n";
                b->inorder();
                break;
            case 4 :
                cout<<"Enter value to be searched\n";
                cin>>n1;
                b->search(n1);
                break;
            case 5 :
                cout<<"Enter value who's inorder predecessor you want\n";
                cin>>n3;
                b->inorder_predecessor(n3);
                break;
            case 6 :
                cout<<"Enter value who's inorder successor you want\n";
                int n2;
                cin>>n2;
                b->inorder_successor(n2);
                break;
            case 7 :
                return 0;
            default : 
                cout<<"Please enter a valid choice\n";
                break;
        }
    }
    return 0;
}