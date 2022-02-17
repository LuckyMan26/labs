#include <iostream>

using namespace std;
bool prime_checker(int n){
for(int i=2;i*i<=n;i++){
    if((n%i)==0){
    return false;
    }
}
return true;
}
int main(){

int n;
cin>>n;
int array[n];
int counter=0;
int i=2;
while(counter<n){
    if(prime_checker(i)){
        array[counter]=i;
        counter++;


    }
    i++;

}

int res=0;
int product=1;
for(int i=0;i<n;i++){
    product*=array[i];
}
for(int i=0;i<n;i++){
    res+=(product/array[i]);

}
cout<<res<<"/"<<product;

}
