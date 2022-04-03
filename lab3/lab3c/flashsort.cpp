#include <iostream>
#include <ctime>
using namespace std;

int show_regime;
void print(int* arr,int length){
for(int i=0;i<length;i++){
  cout<<arr[i]<<" ";
}
cout<<endl;
}
int findmin(int* arr,int length){
int min;
min=0;
for(int i=0;i<length;i++){
    if(arr[i]<arr[min]){
        min=i;
    }
}
return min;
}
int findmax(int arr[],int length){
int max;
max=0;
for(int i=0;i<length;i++){
    if(arr[i]>arr[max]){
        max=i;
    }
}
return max;
}
void sort(int* arr,int length){
int key;
for(int i=1;i<length;i++){
    key=arr[i];
    int j=i-1;
    while(j>=0&&arr[j]>key){
        arr[j+1]=arr[j];
        j=j-1;
    }
    arr[j+1]=key;
}
}
void flashsort(int* arr,int length){
int Mn=arr[findmin(arr,length)];
int Mx=arr[findmax(arr,length)];
int m;
m=0.42*length;
int* tmp=new int[m];
double c=(m-1)/(Mx-Mn);
for(int i=0;i<m;i++){
    tmp[i]=0;
}
int k;
for(int i=0;i<length;i++){
    ++tmp[int(c*(arr[i]-Mn))];
}
for(int i=1;i<m;i++){
    tmp[i]+=tmp[i-1];
}
int i=0;
int count=0;
while(count<length){
    int k=(c*(arr[i]-Mn));
    while(i>=tmp[k]){
        k=(c*(arr[++i]-Mn));
    }
    int z=arr[i];
    while(i!=tmp[k]){
        k=c*(z-Mn);
        int y=arr[tmp[k]-1];
        arr[--tmp[k]]=z;
        z=y;
        count++;
        if(show_regime==1){
            print(arr,length);

        }
    }
}
sort(arr,length);
}
void create_random(int* arr,int length){
for(int i=0;i<length;i++){
   arr[i]=rand()%length;
}
}
void benchmark(){
int n=81920;
show_regime=0;
int* arr=new int[n];
create_random(arr,n);
clock_t t1=clock();
flashsort(arr,n);
cout<<(clock()-t1)/1000.0;
}
void demo(){
int n=10;
show_regime=1;
int* arr=new int[n];
create_random(arr,n);
cout<<"Array: \n";
print(arr,n);
flashsort(arr,n);
cout<<"Sorted array: \n";
print(arr,n);
}
int main(){
srand(time(NULL));
benchmark();
}
