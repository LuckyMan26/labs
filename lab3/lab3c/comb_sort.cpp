#include <iostream>
#include <time.h>
using namespace std;
int show_regime;
void print(int* arr,int length){
for(int i=0;i<length;i++){
  cout<<arr[i]<<" ";
}
cout<<endl;
}
int nextGap(int gap){
 gap=(gap*1000)/(1247);
if(gap<1){
    return 1;
}
return gap;
}

void sort(int* arr,int length){
int gap=length-1;
bool swapped=true;
while(gap!=1||swapped==true){
swapped=false;
for(int i=0;i<length-gap;i++){
    if(arr[i]>arr[i+gap]){
        swap(arr[i],arr[i+gap]);
        swapped=true;
        if(show_regime==1){
            print(arr,length);
        }

    }
    gap=nextGap(gap);
}
}
}

void create_random(int* arr,int length){
for(int i=0;i<length;i++){
   arr[i]=rand()%length;
}
}
void benchmark(){
int n=320;
show_regime=0;
int* arr=new int[n];
create_random(arr,n);
clock_t t1=clock();
sort(arr,n);
cout<<(clock()-t1)/1000.0;
}
void demo(){
int n=10;
int* arr=new int[n];
show_regime=1;
create_random(arr,n);
cout<<"Array: \n";
print(arr,n);
sort(arr,n);
cout<<"Sorted array: \n";
print(arr,n);
}
int main(){
benchmark();
}
