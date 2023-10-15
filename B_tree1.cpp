#include <iostream>
#include <stack>
#include<queue>
using namespace std;

class node
{
public:
    int *keys;
    node **children;
    int numKeys;
    int capacity;
    bool isLeaf;

    // function
    node(bool, int);
    bool isFull();
    node* splitNode(int &v, node *n);
    void printKey();
    int numk();

};
int node :: numk(){
    return numKeys;
}
void node ::printKey()
{
    int i;
    cout << "In print function" << endl;
    for (i = 0; i < numKeys; i++)
    {
        cout << keys[i] << " ";
    }
    cout << endl;
    return;
}
node* node ::splitNode(int &v, node *n)
{
    int ky[capacity + 1];
    node* nd[capacity + 2];
    int i, j;
    for (i = 0; i < capacity; i++)
    {
        ky[i] = keys[i];
    }
    ky[i] = v;
    for (i = 0; i < capacity + 1; i++)
    {
        nd[i] = children[i];
    }
    nd[i] = n;
    j = capacity;
    while (j > 0 && ky[j - 1] < ky[j])
    {
        swap(ky[j - 1], ky[j]);
        swap(nd[j], nd[j + 1]);
        j--;
    }
    // if (j == 0)
    // {
    //     swap(nd[j], nd[j + 1]);
    // }
    node* rt;
    rt = new node(isLeaf, capacity);
    for (i = 0; i < capacity; i++)
    {
        if (i < (capacity / 2))
        {
            keys[i] = ky[i];
        }
        else
        {
            keys[i] = -1;
        }
    }
    for (i = 0; i < capacity + 1; i++)
    {
        if (i < ((capacity / 2) + 1))
        {
            children[i] = nd[i];
        }
        else
        {
            children[i] = NULL;
        }
    }
    numKeys = (capacity / 2);
    for (i = 0; i < capacity; i++)
    {
        if (i < (capacity / 2))
        {
            rt->keys[i] = ky[i + (capacity / 2) + 1];
        }
        else
        {
            rt->keys[i] = -1;
        }
    }
    for (i = 0; i < capacity + 1; i++)
    {
        if (i < ((capacity / 2) + 1))
        {
            rt->children[i] = nd[i + (capacity / 2) + 1];
        }
        else
        {
            children[i] = NULL;
        }
    }
    rt->numKeys = (capacity / 2);
    v = ky[capacity / 2];
    return rt;
}
bool node ::isFull()
{
    if (numKeys == capacity)
    {
        return true;
    }
    return false;
}
node ::node(bool leaf, int cap)
{
    isLeaf = leaf;
    numKeys = 0;
    capacity = cap;
    keys = new int[capacity];
    for (int j = 0; j < capacity; j++)
    {
        keys[j] = -1;
    }
    children = new node *[capacity + 1];
    for (int i = 0; i < capacity + 1; i++)
    {
        children[i] = NULL;
    }
}

class BTree
{
public:
    node *root;
    int maxcap;
    BTree()
    {
        root = NULL;
    }
    BTree(int v)
    {
        root = NULL;
        maxcap = v;
    }
    void insert(int key);
    node*search( int val, int &pos);
    node* sch(node*,int,int &);
    void printTree();
    void ptr(node*);
};
void BTree :: ptr(node* n){
    node* t = n;
    queue <node*> ip;
    ip.push(t);
    int i;
    while(!ip.empty() && ip.front() != NULL){

    for(i=0;i<ip.front()->numKeys;i++){
        cout<<ip.front()->keys[i]<<" ";
        ip.push(ip.front()->children[i]);
    }
        ip.push(ip.front()->children[i]);
        ip.pop();

    }
    while(!ip.empty()){
            ip.pop();
        }
    return ;
}
void BTree :: printTree(){
    ptr(root);
} 

void BTree ::insert(int key)
{
    if (root == NULL)
    {
        root = new node(true, maxcap);
        root->keys[0] = key;
        root->numKeys = 1;
    }
    else
    {
        node *temp;
        temp = root;
        stack<node *> ip;
        //temp->printKey();
        ip.push(temp);
        while (!temp->isLeaf)
        {
            int i = 0;
            while (i < temp->numKeys && temp->keys[i] > key)
            {
                i++;
            }
            temp = temp->children[i];
            //temp->printKey();
            ip.push(temp);
        }
        // if(root->isLeaf && !(root->isFull())){
        //     root->keys[root->numKeys] = key;
        //     int b = root->numk() ;
        //     root->numKeys = b+1;
        //     return ;
        // }
        node *tt;
        tt = ip.top();
        ip.pop();
        node *tt1 = NULL;
        int b = 0;
        if(root->isFull()){
            b=1;
        }
        while (tt->isFull())
        {   
            //tt->printKey();
            tt1 = tt->splitNode(key, tt1);
            if(ip.empty()){
                break;
            }
            tt = ip.top();
            ip.pop();
        }
        //tt->printKey();
        //if( key == 2 && b !=0){tt1->printKey();}
        if (ip.empty() && b==1)
        {
            node *t1 = new node(false, maxcap);
            t1->keys[0] = key;
            t1->numKeys = 1;
            t1->children[0] = root;
            t1->children[1] = tt1;
            root = t1;
        }
        else
        {   
            int b = tt->numk();
            tt->keys[b] = key;
            tt->children[b+1] = tt1;
            tt->numKeys = b + 1;
            
            int g;
            int f =0;
            for (g = b; g > 0; g--)
            {   
                f=1;
                if (tt->keys[g] > tt->keys[g - 1])
                {
                    swap(tt->keys[g], tt->keys[g - 1]);
                    swap(tt->children[g+1],tt->children[g]);
                }
                else
                {
                    break;
                }
            }
            // if(g==0 && f==1){
            //     swap(tt->children[g+1],tt->children[g]);
            // }
        }
        while(!ip.empty()){
            ip.pop();
        }
    }
    return;
}
node* BTree :: sch(node* r,int val ,int &pos){
    if(r==NULL){
        return NULL;
    }
    int i = 0;
    while (i < r->numKeys && val < r->keys[i])
    {
        i++;
    }
    if (i < r->numKeys && val == r->keys[i])
    {
        pos = i;
        cout<<"Found"<<endl;
        return r;
    }
    else if (r->isLeaf)
    {
        return NULL;
    }
    return (sch(r->children[i], val, pos));
}
node* BTree :: search( int val, int &pos)
{
    
    return (sch(root,val,pos));
}

int main()
{
    BTree* bt;
    bt = new BTree(2);
    bt->insert(40);
    bt->insert(30);
    bt->insert(50);
    bt->insert(55);
    // bt->insert(25);
    bt->insert(60);
    bt->insert(65);
    bt->insert(75);
    bt->insert(61);
    bt->insert(62);
    bt->insert(63);
    bt->insert(64);
    // bt->insert(3);
    // bt->insert(2);
    // bt->insert(-10);
    // bt->insert(-2);
    // bt->insert(-3);
    // bt->insert(-5);
    // bt->insert(-7);
    // bt->insert(-8);
    // bt->insert(-13);
    // bt->insert(-12);
    // bt->insert(-15);
    // bt->insert(-14);
    // bt->insert(12);
    // bt->root->children[1]->printKey();
     bt->printTree();
    //bt->root->printKey();
    bt->root->children[2]->children[1]->printKey();
    // int v=0;
    // node* b ;
    // b = bt->search(90,v);
    //bt->root->children[1]->printKey();
    return 0;
}


// node* ng;
//     node* tt1 = NULL;
//     ng = new node(true,4);
//     for(int i=0;i<4;i++){
//         ng->keys[i] = 4-2*i;
//     }
//     ng->numKeys = 4;
//     if(ng->isFull()){
//         cout<<"Full"<<endl;
//     }
//     ng->printKey();
//     int v = 3;
//     cout<<v<<endl;
//     tt1 = ng->splitNode(v,tt1);
//     cout<<v<<endl;
//     if(ng->isFull()){
//         cout<<"Full"<<endl;
//     }
//     ng->printKey();
//     if(tt1->isFull()){
//         cout<<"Full"<<endl;
//     }
//     tt1->printKey();
