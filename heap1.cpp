#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;
class heap{
    int capacity;
    int heap_size;
    int *keys;
    public:
    heap(int a){
        heap_size = 0;
        capacity = a;
        keys = new int(a+1);
    }
    bool insert(int);
    int extract_min();
    bool decrease_key(int at,int n_key);
    void heapify(int);
    bool create_bulk(int);
    int parent(int);
    int left_child(int);
    int right_child(int);
    int minimum();
    void print();
};
bool heap :: insert(int v){
    if(heap_size==capacity){
        cout<<"Out of limit\n";
        return false;
    }
    heap_size = heap_size+1;
    keys[0] = heap_size;
    keys[heap_size] = INT_MAX;
    decrease_key(heap_size,v);
    return true;
}
int heap :: extract_min(){
    if(heap_size<1){
        cout<<"No element in heap\n";
        return -1;
    }
    keys[0] -=1;
    int mi = keys[1];
    if(heap_size==1){
        heap_size = heap_size -1;
        return mi;
    }
    swap(keys[1],keys[heap_size]);
    heap_size = heap_size -1;
    heapify(1);
    return mi;
}
bool heap :: decrease_key(int a,int k){
    if(keys[a]<k){
        cout<<"Keys already less then your key\n";
        return false;
    }
    keys[a] = k;
    while(a>1 && keys[parent(a)]>k){
        swap(keys[parent(a)],keys[a]);
        a = parent(a);
    }
    return true;
}
void heap :: heapify(int i){
    int l = left_child(i);
    int r = right_child(i);
    int small = i;
    if(l<=heap_size && keys[l]<keys[i]){
        small = l;
    }
    if(r<=heap_size && keys[r]<keys[small]){
        small = r;
    }
    if(small !=i){
        swap(keys[i],keys[small]);
        heapify(small);
    }
    return ;
}
int heap :: right_child(int i){
    return ((2*i)+1);
}
int heap :: left_child(int i){
    return (2*i);
}
int heap :: parent(int i){
    return floor(i/2);
}
void heap :: print(){
    cout<<"Total elements : "<<keys[0]<<" "<<heap_size<<endl;
    if(heap_size<1){
        cout<<"Currently no element in the heap\n";
        return ;
    }
    int i;
    for(i=1;i<=heap_size;i++){
        cout<<keys[i]<<" ";
    }
    cout<<endl;
}
int heap :: minimum(){
    if(heap_size>0){
        return keys[1];
    }
    cout<<"No element in heap\n";
    return -1;
}
bool heap :: create_bulk(int s){
    cout<<"Now enter the elements\n";
    int i;
    heap_size = s;
    keys[0] = s;
    for(i=1;i<=s;i++){
        cin>>keys[i];
    }
    int m = floor(s/2);
    for(i=m;i>0;i--){
        heapify(i);
    }
    return true;
}
int main (){
    int a;
    heap *t =NULL;
    while(true){
        cout<<"1.To create an empty heap of size\n";
        cout<<"2.To insert one element\n";
        cout<<"3.Status of the heap currently\n";
        cout<<"4.To get the minimum \n";
        cout<<"5.To extract the minimum\n";
        cout<<"6.To decrease the key\n";
        cout<<"7.Create a heap in bulk\n";
        cout<<"8.Exit\n";
        cout<<"Enter your choice\n";
        cin>>a;
        switch(a){
        case 1:
            int s1;
            cout<<"Enter the size of the heap\n";
            cin>>s1;
            t = new heap(s1);
            break;
        case 2:
            int n;
            cout<<"Enter the element to be inserted\n";
            cin>>n;
            t->insert(n);
            break;
        case 3:
            t->print();
            break;
        case 4:
            if(t->minimum() != -1){
                cout<<t->minimum()<<endl;
                break;
            }
            break;
        case 5:
            if(t->minimum() != -1){
                cout<<t->extract_min()<<endl;
                break;
            }
            break;
        case 6:
            int c,b;
            cout<<"Enter the position and decreased val\n";
            cin>>c>>b;
            if(t->decrease_key(c,b)){
                cout<<"Key is decreased succesfully\n";
                break;
            }
            break;
        case 7:
            cout<<"Enter the size of the input array\n";
            int s;
            cin>>s;
            t = new heap(s);
            t->create_bulk(s);
            break;
        case 8:
            return 0;
        default:
            cout<<"Enter a valid choice\n";
            break;
        }
    }
    return 0;
}