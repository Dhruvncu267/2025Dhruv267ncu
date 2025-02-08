#include<iostream>
using namespace std;

int main() {
    int n;
    int i;
    cout<<" enter number "<<endl;
    cin>>n;
    cout<<endl;

    bool is_prime=true;
    if(n<=1){
        cout<<"number is neither prime nor composite "<<endl;
    }
    else {
        for(i=2;i*i<=n;i++){
            if(n%i==0){
                is_prime=false;
                break;
            }
        }
    }
    if(is_prime){
        cout<<"number is prime "<<endl;
    }
    else{
        cout<<"number is composite "<<endl;
        for(i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<endl;
            
        }
    }
}
    

    
   
    return 0;

}
