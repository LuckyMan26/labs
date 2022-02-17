#include <iostream>
#include<string>
using namespace std;

int count(int n){
    if(n<10){
        return 1;
    }
    return 1 + count(n/10);

}
int main(){
int n;
cin>>n;
int k=1;
while(n>k*k){
k+=2;
}
int l=1;
int array[k][k];
for(int i=0;i<k;i++){
    for(int j=0;j<k;j++){
        array[i][j]=0;
    }
}
int posx=k/2;
int posy=k/2;
array[posx][posy]=1;

int number=1;
//cout<<posx<<" "<<posy<<" "<<k;
while(number<=n){
    if(l%2==1){
        for(int i=0;i<l;i++){
            if(number>n){
                    break;
                }
            posy++;
            number++;
            array[posx][posy]=number;
        }
        for(int i=0;i<l;i++){
                if(number>n){
                    break;
                }
            posx--;
            number++;
            array[posx][posy]=number;
        }
    }
    if(l%2==0){
         for(int i=0;i<l;i++){
                if(number>n){
                    break;
                }
            posy--;
            number++;
           array[posx][posy]=number;
        }
        for(int i=0;i<l;i++){
                if(number>n){
                    break;
                }
            posx++;

            number++;
            array[posx][posy]=number;
        }
    }
l++;
}


int f;
f = count(n);
string space="";
int f_copy=f;
while(f>-1){
    space+=" ";
    f--;
}
f=f_copy;
for(int i =0; i<k; i++){
    for(int j = 0; j<k; j++){
        if((array[i][j]==0)||(array[i][j]>n)){
            cout<<space;
        }
        else{
        cout.width(f);
        cout << array[i][j] << " ";
       }
        }
        cout << endl;
    }

}


