#include<iostream>
using namespace std;
void wavesort(int a[],int n){
    for(int i=1;i<n-1;i+=2){
        if(a[i]>a[i-1]){
            swap(a[i],a[i-1]);
        }
        if(a[i]>a[i+1] && i<=n-2){
            swap(a[i],a[i+1]);
        }
    }
}
int main(){
    int arr[8] = {1,3,4,7,5,6,2};
    int i;
    wavesort(arr,8);
    for(i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}