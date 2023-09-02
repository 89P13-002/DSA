#include<iostream>
using namespace std;
void swap(int *a,int l,int r){
    int  t;
    t =a[l];
    a[l]=a[r];
    a[r]= t;
    return ;
}
int main(){
    int arr[12] = {1,1,2,0,1,1,0,0,2,2,2,2};
    int i;
    for(i=0;i<12;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int low,high,mid;
    mid = low = 0;
    high = 11;
    while(mid<=high){
        if(arr[i]==0){
            swap(arr,low,mid);
            low++;mid++;
        }
        else if(arr[i]==1){
            mid++;
        }
        else{
            swap(arr,mid,high);
            high--;
        }
    }
    for(i=0;i<12;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}