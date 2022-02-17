#include <iostream>
#include <array>
using namespace std;


int main(){
int a,b;
bool condition=true;
cin>>a>>b;
int array[int(b)];
array[0]=int(a)%int(b);
int count=0;
for(int i=1;i<b;i++){
    array[i]=(array[i-1]*10)%(int(b));
}
for(int i=0;i<b;i++){
    for(int j=i+1;j<b;j++){
        if(array[i]==array[j]){
            if(array[i]!=0){
            condition=false;
            cout<<(j-i);
            return 0;
        }
    }
}
}
if(condition){
    cout<<"No period";
}
}
