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
    int gkey();
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
int node :: gkey(){
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
    left=n;
    return;
}
void node::addRight(node *n){
    right=n;
    return;
}
void node::setParent(node *n){
    parent=n;
    return;
}
class avl{
    public:
    node* root;
    avl(){
        root = NULL;
    }
    void insert(node*);
    void leftrotate(node*,node* &r);
    void rightrotate(node*,node* &r);
    void right_left_rotate(node*,node* &r);
    void left_right_rotate(node*,node* &r);
    void create();
    node* search(int);
    void inorder();
    node* minimum(node*);
    node* maximun(node*);
    void tinorder(node*);
    node* inorder_successor(int);
    node* inorder_predecessor(int);
};
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
void avl ::create(){
    root = NULL;
}
void avl :: insert(node* n){
    if(root== NULL){
        root = n;
        return ;
    }
    //cout<<n->key<<" In insert function\n";
    node *temp = root;
    node *temp1;
    while(temp){
        temp1=temp;
        if((temp->key) > (n->key)){
            //cout<<n->key<<" Inside while loop for right\n";
            temp = temp->right;
        }
        else{
            //cout<<n->key<<" Inside while loop for left\n";
            temp = temp->left;
        }
    }
    if(temp1->key > n->key){
        //cout<<n->key<<" Adding to right\n";
        n->setParent(temp1);
        temp1->addRight(n);
        temp1->r_height = 1;
    }
    else{
        //cout<<n->key<<" Adding to left\n";
        n->setParent(temp1);
        temp1->addLeft(n);
        temp1->l_height = 1;
    }

    //updating height
    node *temp2,*temp3;
    temp3 = temp1;
    temp2 = temp1->parent;
    while(temp2){
        if(temp1 == temp2->left){
            temp2->l_height = max(temp1->glh(),temp1->grh())+1;
        }
        else if (temp1 == temp2->right){
            temp2->r_height = max(temp1->glh(),temp1->grh())+1;
        }
        if((abs(temp2->glh() - temp2->grh())>1)){
            break;
        }
        temp1 = temp2;
        temp2 = temp2->parent;
    }
    
    // unbalance at
    node *t1,*t2,*t3;
    t3 = n;
    t2 = temp3;
    t1 = temp3->parent;
    if(t1 == NULL){
        return ;
    }
    // if(t2 == t1->left){
    //     t1->l_height = (max(t2->glh(),t2->grh()))+1;
    // }
    // else if (t2 == t1->right){
    //     t1->r_height = (max(t2->glh(),t2->grh()))+1;
    // }
    while(t1 && (abs(t1->glh() - t1->grh())<2)){
        t3 = t2;
        t2 = t1;
        t1 = t1->parent;
    }
    if(t1 == NULL){
        return;
    }
    else{
        //cout<<t1->key<<" "<<t1->l_height<<" "<<t1->r_height<<endl;
        if(t2 == t1->left && t3 == t2->left){
            rightrotate(t1,root);
        }
        else if(t2 == t1->right && t3 == t2->right){
            leftrotate(t1,root);
        }
        else if(t2 == t1->left && t3 == t2->right){
            left_right_rotate(t1,root);
        }
        else if(t2 == t1->right && t3 == t2->left){
            right_left_rotate(t1,root);
        }
    }
    // node* temp5,*temp6;
    // temp5 = t1;
    // temp6 = t1->parent;
    // while(temp6){
    //     if(temp5 == temp6->left){
    //         temp6->l_height = (temp6->glh())-1;
    //     }
    //     else if (temp5 == temp6->right){
    //         temp6->r_height = (temp6->grh())-1;
    //     }
    //     temp5 = temp6;
    //     temp6 = temp6->parent;
    // }
    return ;
}

void avl :: leftrotate(node* n1,node* &root){
    node* n2 = n1->right;
    node* n3 = n2->right;
    node* n4 = n1->parent;
    node* n5 = n2->left;
    n2->parent = n4;
    if(n4 == NULL){
        root = n2;
    }
    if(n4 != NULL && n1 == n4->left){
        n4->left = n2;
    }
    else if(n4 !=NULL && n1 == n4->right){
        n4->right = n2;
    }
    n2->left = n1;
    n1->parent = n2;
    n1->right =  n5;
    if(n5 != NULL){
        n1->right->parent = n1;
    }
    //updating height
    if(n5 != NULL){
        n1->r_height = (max(n5->glh(),n5->grh())) +1;
    }
    if(n5 == NULL){
        n1->r_height = 0;
    }
    n2->l_height = (max(n1->glh(),n1->grh())) +1;
    return;
}

void avl :: rightrotate(node* n1,node* &root){
    node* n2 = n1->left;
    node* n3 = n2->left;
    node* n4 = n1->parent;
    node* n5 = n2->right;
    n2->parent = n4;
    if(n4 == NULL){
        root = n2;
    }
    if(n4 != NULL && n1 == n4->left){
        n4->left = n2;
    }
    else if(n4 != NULL && n1 == n4->right){
        n4->right = n2;
    }
    n2->right = n1;
    n1->parent = n2;
    n1->left =  n5;
    if(n5 != NULL){
        n1->left->parent = n1;
    }
    //updating height
    if(n5 != NULL){
        n1->l_height = (max(n5->glh(),n5->grh())) +1;
    }
    if(n5 == NULL){
        n1->l_height = 0;
    }
    n2->r_height = (max(n1->glh(),n1->grh())) +1;
    return;
}

void avl :: left_right_rotate(node* n1,node* &root){
    node* n2 = n1->left;
    node* n3 = n2->right;
    node* n4 = n1->parent;
    node* n5 = n3->left;
    node* n6 = n3->right;
    n3->parent = n4;
    if(n4 == NULL){
        root = n3;
    }
    if(n4 != NULL && n1 == n4->left){
        n4->left = n3;
    }
    else if(n4 != NULL && n1 == n4->right){
        n4->right = n3;
    }
    n3->left = n2;
    n3->left->parent = n3;
    n3->right = n1;
    n3->right->parent = n3;
    n2->right =  n5;
    if(n5 != NULL){
        n2->right->parent = n2;
    }
    n1->left =  n6;
    if(n6 != NULL){
        n1->left->parent = n1;
    }

    //update height
    if(n5 != NULL){
        n2->r_height = (max(n2->right->glh(),n2->right->grh())) +1;
    }
    if(n5 == NULL){
        n2->r_height = 0;
    }
    if(n6 != NULL){
        n1->l_height = (max(n1->left->glh(),n1->left->grh())) +1;
    }
    if(n5 == NULL){
        n1->l_height = 0;
    }
    n3->l_height = (max(n3->left->glh(),n3->left->grh()))+1;
    n3->r_height = (max(n3->right->glh(),n3->right->grh()))+1;
    return ;
}

void avl :: right_left_rotate(node* n1,node* &root){
    node* n2 = n1->right;
    node* n3 = n2->left;
    node* n4 = n1->parent;
    node* n5 = n3->left;
    node* n6 = n3->right;
    n3->parent = n4;
    if(n4 == NULL){
        root = n3;
    }
    if(n4 != NULL && n1 == n4->left){
        n4->left = n3;
    }
    else if(n4 != NULL && n1 == n4->right){
        n4->right = n3;
    }
    n3->left = n1;
    n3->left->parent = n3;
    n3->right = n2;
    n3->right->parent = n3;
    n1->right =  n5;
    if(n5 != NULL){
        n1->right->parent = n1;
    }
    n2->left =  n6;
    if(n6 != NULL){
        n2->left->parent = n2;
    }

    //update height
    if(n5 != NULL){
        n1->r_height = (max(n1->right->glh(),n1->right->grh())) +1;
    }
    if(n5 == NULL){
        n1->r_height = 0;
    }
    if(n6 != NULL){
        n2->l_height = (max(n2->left->glh(),n2->left->grh())) +1;
    }
    if(n5 == NULL){
        n2->l_height = 0;
    }
    n3->l_height = (max(n3->left->glh(),n3->left->grh()))+1;
    n3->r_height = (max(n3->right->glh(),n3->right->grh()))+1;
    return ;
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
                cout<<endl;
                break;
            case 4 :
                cout<<"Enter value to be searched\n";
                cin>>n1;
                if(b->search(n1)){
                    cout<<"Given node is present in AVL tree\n";
                }
                break;
            case 5 :
                cout<<"Enter value who's inorder predecessor you want\n";
                cin>>n3;
                if(b->inorder_predecessor(n3))
                    cout<<b->inorder_predecessor(n3)->key<<endl;
                break;
            case 6 :
                cout<<"Enter value who's inorder successor you want\n";
                int n2;
                cin>>n2;
                if(b->inorder_successor(n3))
                    cout<<b->inorder_successor(n3)->key<<endl;
                break;
            case 7 :
                return 0;
            default :
                cout<<"Please enter a valid choice\n";
                break;
        }
    }
    delete b;
    return 0;
}
