#include<bits/stdc++.h>
#define ever (;;) 
typedef long long ll;
using namespace std;

//given index i, parent is i/2, leftchild is 2*i, rightchild is 2*i+1
//modifiedto i, parent (i+1)/2 -1 ,  leftchild 2*(i+1) -1 , rightchild 2*(i+1)

int parent(int n){return (n+1)/2 -1;}
int left(int n){return 2*(n+1)-1;}
int right(int n){return 2*(n+1);}

void insertHeap(vector<int>& v, int val){
    v.push_back(val);
    int n = v.size()-1;

    //float up
    while(n>0){
        if(v[n] < v[parent(n)]){
            swap(v[n],v[parent(n)]);
            n = parent(n);
        }
        else{
            break;
        }    
    }
}

void heapify(vector<int>& v, int n){
    //n in index of root
    //find min of left and right chld
    int lc = left(n);
    int rc = right(n);
    int minval,mindex;
    if(lc <v.size() && rc<v.size()){
        if(v[lc]<=v[rc]){
            minval = v[lc];
            mindex=lc;
        }
        else{
            minval = v[rc];
            mindex = rc;
        }
    }
    else if(rc >=v.size()){
        if(lc<v.size()){
            minval = v[lc];
            mindex = lc;
        }
    }
    else{
        return;
    }
    //swap current and recursive
    if(v[n] > minval){
        swap(v[n],v[mindex]);
        heapify(v, mindex);
    }
}
int deleteHeap(vector<int>& v){
    int min =v[0];
    swap(v[0],v[v.size()-1]);
    v.pop_back();
    heapify(v,0);

    return min;
}


int main(){
    vector<int> minheap;
    for ever{
        int in;
        cout<<"1.Insert\n2.Delete Top\n3.Bulk creation for n elements\n4.Show\n5.Quit\n$~/";
        cin>>in;
        int val;
        if(in ==1){
            cout<<"Value:";cin>>val;
            cout<<"Size before: "<<minheap.size()<<endl;
            insertHeap(minheap,val);
            cout<<"Size after: "<<minheap.size()<<endl;
        }
        else if(in ==2){
           cout<<"Root element was: "<<deleteHeap(minheap);

        }
        else if(in==3){
            int size;cin>>size;
            vector<int> vtemp;
            for(int i =0;i<size;i++){
                int ll ;cin>>ll;vtemp.push_back(ll);
            }
            cout<<"Resulting Minheap is:\n";
            for(int i=vtemp.size()/2;i>=0;i--){
                heapify(vtemp,i);
            }
            for(auto i: vtemp){
                    cout<<i<<" ";
            }
            cout<<endl;
        }
        else if (in ==4){
            for(auto i: minheap){
                    cout<<i<<" ";
            }
            cout<<endl;
            
        }
        else if(in==5){
            break;
        }

        
    }

return 0;
}
