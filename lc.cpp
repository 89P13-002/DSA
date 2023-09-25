#include<iostream>
#include<vector>
using namespace std;
struct node{
    int data;
    node *left,*right;
    node(int v){
        data = v;
        left=right=NULL;

    }

};
bool getpath(node*root,int key,vector<int> &path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==key){
        return true;
    }

    if(getpath(root->left,key,path) || getpath(root->right,key,path)){
        return true;
    }
    path.pop_back();
    return false;
}
int lca(node* root,int n1,int n2){
    vector<int> path1,path2;
    if(!getpath(root,n1,path1) || !getpath(root,n2,path2)){
        return -1;
    }
    int pc;
    for(pc=0;pc<path1.size() && path2.size();pc++){
        if(path1[pc] != path2[pc]){
            break;
        }
    }
    return (path1[pc-1]);
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->left=new node(5);
    root->right->right= new node(6);
    root->right->left->left=new node(7);
    int n1 =6;
    int n2= 7;
    int l = lca(root,n1,n2);
    if(l==-1){
        cout<<"LCA not exist\n";
    }
    else{
        cout<<"LCA : "<<lca <<endl;
    }
    return 0;
}


node* lca1(node* root,int n2,int n1){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data == n2){
        return root;
    }
    node* leftlca = lca1(root->left,n2,n1);
    node* rightlca = lca1(root->right,n2,n1);
    if(leftlca && rightlca){
        return root;
    }
    if(leftlca!=NULL){
        return leftlca;
    }
    return rightlca;
}