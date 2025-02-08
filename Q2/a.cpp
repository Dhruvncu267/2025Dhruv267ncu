#include<iostream>
using namespace std;

int main() {
    int arr[5];
    int i;
    int count=0;
    for(i=0;i<5;i++){
        count+=1;
        cout<<"enter number  "<<count<<endl;
        cin>>arr[i];
    }
    cout<<endl;
    for(i=0;i<5;i++){
        cout<<arr[i];
    }
    cout<<endl;
    for(i=4;i>=0;i--){
        cout<<arr[i];
    }
}
