#include <iostream>
#include <time.h>
#include <algorithm>
#include <cstdlib>

#define length 10 //length of array
int show_regime;
using namespace std;
struct point{
double x,y,z;
void print(){
cout<<"("<<x<<","<<y<<","<<z<<") ";
}
void create_rand(){
x=(double)(rand())/RAND_MAX * length;
y=(double)(rand())/RAND_MAX * length;
z=(double)(rand())/RAND_MAX * length;

}
bool operator <=(const point& p){
    if(x<=p.x){
        return true;
    }
    else if(!(x<=p.x)){
        return false;
    }
    else if((y<=p.y)){
        return true;
    }
    else if(!(y<=p.y)){
        return false;
    }
    else if((z<=p.z)){
        return true;
    }
    else if(!(z<=p.z)){
        return false;
    }
    else{
        return true;
    }
}
bool operator <(const point& p){
   if(x<p.x){
        return true;
    }
    else if(!(x<p.x)){
        return false;
    }
    else if((y<p.y)){
        return true;
    }
    else if(!(y<p.y)){
        return false;
    }
    else if((z<p.z)){
        return true;
    }
    else if(!(z<p.z)){
        return false;
    }
    else{
        return true;
    }
}
};
void print(point* arr){
for(int i=0;i<length;i++){
    arr[i].print();
}
cout<<endl;
}
void merge(point* arr,point temp[],int bot,int mid,int top){

int i=bot;
int j=mid+1;
int cur=bot;
while(i<=mid&&j<=top){
    if(arr[i]<=arr[j]){
        temp[cur]=arr[i];
        cur++;
        i++;
    }
    else{
        temp[cur]=arr[j];
        cur++;
        j++;
    }
}
while(i<length&&i<=mid){
    temp[cur]=arr[i];
    cur++;
    i++;
}
for(int i=bot;i<=top;i++){
    arr[i]=temp[i];
}
if(show_regime==1){
    print(arr);
}
}
void merge_sort(point* arr){
point* tmp=new point[length];
for(int i=0;i<length;i++){
    tmp[i]=arr[i];
}
for(int width=1;width<length;width=2*width){
    for(int i=0;i<length;i+=2*width){
        int bot=i;
        int mid=i+width-1;
        int top=min(length-1,i+2*width-1);

        merge(arr,tmp,bot,mid,top);
    }
}
delete tmp;
}

int partition(point* arr,int low,int high){
int pivot=high;
int i=low-1;
for(int j=low;j<high;j++){
    if(arr[j]<=arr[pivot]){
        i++;
        swap(arr[i],arr[j]);
        if(show_regime==1){
            print(arr);
        }
    }
}
    swap(arr[i+1],arr[high]);
    return i+1;
}
void quicksort(point* arr,int low,int high){
if(low<high){
int pivot=partition(arr,low,high);
    quicksort(arr,low,pivot-1);
    quicksort(arr,pivot+1,high);
}
}
void insertion_sort(point* arr,int size){
int i, j;
point key;
for (i=1;i<size;i++){
    key=arr[i];
    j =i-1;
    while ((j >= 0)&&( key <= arr[j])){
        arr[j+1] = arr[j];
        j=j-1;
    }
    arr[j+1] = key;
    }
}
void timsort_8(point* arr){
const int block=8;
point* temp=new point[length];
for(int i=0;i<length;i++){
    temp[i]=arr[i];
}
for(int i=0;i<length;i+=block){
    if(i+block>length-1){
        insertion_sort(arr+i,length-i);
    }
    else{
        insertion_sort(arr+i,block);
    }
}
for(int i=block;i<length;i=i*2){
    for(int left=0;left<length;left+=2*i){
        int mid=left+i-1;
        int right=min(left+2*i-1,length-1);
        if(mid<right){
        merge(arr,temp,left,mid,right);
        }
    }
}
}
void timsort_16(point* arr){
const int block=16;
point* temp=new point[length];
for(int i=0;i<length;i++){
    temp[i]=arr[i];
}
for(int i=0;i<length;i+=block){
    if(i+block>length-1){
        insertion_sort(arr+i,length-i);
    }
    else{
        insertion_sort(arr+i,block);
    }
}
for(int i=block;i<length;i=i*2){
    for(int left=0;left<length;left+=2*i){
        int mid=left+i-1;
        int right=min(left+2*i-1,length-1);
        if(mid<right){
        merge(arr,temp,left,mid,right);
        }
    }
}
}
void timsort_32(point* arr){
const int block=32;
point* temp=new point[length];
for(int i=0;i<length;i++){
    temp[i]=arr[i];
}
for(int i=0;i<length;i+=block){
    if(i+block>length-1){
        insertion_sort(arr+i,length-i);
    }
    else{
        insertion_sort(arr+i,block);
    }
}
for(int i=block;i<length;i=i*2){
    for(int left=0;left<length;left+=2*i){
        int mid=left+i-1;
        int right=min(left+2*i-1,length-1);
        if(mid<right){
        merge(arr,temp,left,mid,right);
        }
    }
}
}
void timsort_64(point* arr){
const int block=64;
point* temp=new point[length];
for(int i=0;i<length;i++){
    temp[i]=arr[i];
}
for(int i=0;i<length;i+=block){
    if(i+block>length-1){
        insertion_sort(arr+i,length-i);
    }
    else{
        insertion_sort(arr+i,block);
    }
}
for(int i=block;i<length;i=i*2){
    for(int left=0;left<length;left+=2*i){
        int mid=left+i-1;
        int right=min(left+2*i-1,length-1);
        if(mid<right){
        merge(arr,temp,left,mid,right);
        }
    }
}
}
void timsort_128(point* arr){
const int block=128;
point* temp=new point[length];
for(int i=0;i<length;i++){
    temp[i]=arr[i];
}
for(int i=0;i<length;i+=block){
    if(i+block>length-1){
        insertion_sort(arr+i,length-i);
    }
    else{
        insertion_sort(arr+i,block);
    }
}
for(int i=block;i<length;i=i*2){
    for(int left=0;left<length;left+=2*i){
        int mid=left+i-1;
        int right=min(left+2*i-1,length-1);
        if(mid<right){
        merge(arr,temp,left,mid,right);
        }
    }
}
}
void bubblesort(point* arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<=arr[j]){
                swap(arr[j],arr[j+1]);
                if(show_regime==1){
                    print(arr);
                }
            }
        }
    }
}

void create_random(point* arr){
for(int i=0;i<length;i++){
    arr[i].create_rand();
}
}
void create_almost_sorted(point* arr){
int i,j;
for(int i=0;i<length;i++){
    arr[i]={(double)i,(double)i,(double)i};
}
for(int a=0;a<length/100;a++){

    i=rand()%length;
    j=rand()%length;
    swap(arr[i],arr[j]);
}

}
void create_almost_unsorted(point* arr){
int i,j;
for(int i=0;i<length;i++){
    arr[i]={(double)(length-i),(double)(length-i),(double)(length-i)};
}
for(int a=0;a<length/100;a++){
    i=rand()%length;
    j=rand()%length;
    swap(arr[i],arr[j]);
}
}
void benchmark(){
point* arr1=new point[length];
point* arr2=new point[length];
point* arr3=new point[length];
point* arr4=new point[length];
point* arr5=new point[length];
point* arr6=new point[length];
point* arr7=new point[length];
point* arr8=new point[length];
point* arr9=new point[length];
create_random(arr1);
for(int i=0;i<length;i++){
    arr9[i]=arr1[i];
    arr8[i]=arr1[i];
    arr7[i]=arr1[i];
    arr6[i]=arr1[i];
    arr5[i]=arr1[i];
    arr4[i]=arr1[i];
    arr3[i]=arr1[i];
    arr2[i]=arr1[i];
}
clock_t t1,t2,t3,t4,t5,t6,t7,t8,t9;
t1=clock();
merge_sort(arr1);
cout<<"Merge sort: "<<(clock()-t1)/1000.0<<endl;
t2=clock();
quicksort(arr2,0,length-1);
cout<<"Quicksort: "<<(clock()-t2)/1000.0<<endl;
t3=clock();
bubblesort(arr3,length);
cout<<"Bubble sort: "<<(clock()-t3)/1000.0<<endl;
t4=clock();
timsort_8(arr4);
cout<<"Timsort 8: "<<(clock()-t4)/1000.0<<endl;
t5=clock();
timsort_16(arr5);
cout<<"Timsort 16: "<<(clock()-t5)/1000.0<<endl;
t6=clock();
timsort_32(arr6);
cout<<"Timsort 32: "<<(clock()-t6)/1000.0<<endl;
t7=clock();
timsort_64(arr7);
cout<<"Timsort 64: "<<(clock()-t7)/1000.0<<endl;
t8=clock();
timsort_128(arr8);
cout<<"Timsort 128: "<<(clock()-t8)/1000.0<<endl;
t9=clock();
sort(arr9,arr9+length);
cout<<"Library sort: "<<(clock()-t9)/1000.0<<endl;
}
void demo(){
show_regime=1;
point* arr1=new point[length];
point* arr2=new point[length];
point* arr3=new point[length];
point* arr4=new point[length];
point* arr5=new point[length];
point* arr6=new point[length];
point* arr7=new point[length];
point* arr8=new point[length];
point* arr9=new point[length];
create_random(arr1);
for(int i=0;i<length;i++){
    arr9[i]=arr1[i];
    arr8[i]=arr1[i];
    arr7[i]=arr1[i];
    arr6[i]=arr1[i];
    arr5[i]=arr1[i];
    arr4[i]=arr1[i];
    arr3[i]=arr1[i];
    arr2[i]=arr1[i];
}
cout<<"Array: \n";
print(arr1);
cout<<"Merge sort: \n";
merge_sort(arr1);
print(arr1);
cout<<"Bubble sort: \n";
bubblesort(arr2,length);
print(arr2);
cout<<"Timsort with 8 elements: \n";
timsort_8(arr3);
print(arr3);
cout<<"Timsort with 16 elements: \n";
timsort_16(arr4);
print(arr4);
cout<<"Timsort with 32 elements: \n";
timsort_32(arr5);
print(arr5);
cout<<"Timsort with 64 elements: \n";
timsort_64(arr6);
print(arr6);
cout<<"Timsort with 128 elements: \n";
timsort_128(arr7);
print(arr7);
cout<<"Quicksort: \n";
quicksort(arr8,0,length-1);
print(arr8);
}
int main(){
srand(time(NULL));
benchmark();
}
