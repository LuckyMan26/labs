#include <iostream>
#include <cmath>
#include <time.h>
#include <vector>
using namespace std;

struct monster{
vector<string> name_of_monsters={"Bogeyman","Vampire","Dybbuk","Banshee","Pontianak","Zombie","Hydra","Chimera","Yeti","Dragon","Unicorn","Basilisk","Phoenix","Griffin"};
string name;
int hp;
int attack;
double probability;
int type_of_attack;
void create_random(){
name=name_of_monsters[rand()%name_of_monsters.size()];
hp=rand()%50000;
attack=rand()%2000;
probability=(double)(rand())/RAND_MAX;
type_of_attack=rand()%3;
}
void print(){
cout<<"Name: "<<name<<endl;
cout<<"Hp: "<<hp<<endl;
cout<<"Damage: "<<attack<<endl;
cout<<"Probability of ulti: "<<probability<<endl;
cout<<"Type of ulti: "<<type_of_attack<<endl;
cout<<"------------------------------------\n";
}
};
bool compare(monster m1,monster m2,vector<int> criterias){
    for(int i=0;i<criterias.size();i++){
        switch(criterias[i]){
    case 1:
        if(m1.name==m2.name){
            continue;
        }
        else{
            return m1.name>m2.name;
            break;
        }
    case 2:
        if(m1.hp==m2.hp){
            continue;
        }
        else{
            return m1.hp>m2.hp;
            break;
        }
    case 3:
        if(m1.attack==m2.attack){
            continue;
        }
        else{
            return m1.attack>m2.attack;
            break;
        }
    case 4:
        if(m1.type_of_attack==m2.type_of_attack){
            continue;
        }
        else{
            return m1.type_of_attack>m2.type_of_attack;
            break;
        }
    case 5:
            if(m1.probability==m2.probability){
                continue;
            }
            else{
                return m1.probability>m2.probability;
                break;
            }
        }
    }
    return false;
}
void merge(monster* arr,monster temp[],int bot,int mid,int top,int length,vector<int> criterias){
int i=bot;
int j=mid+1;
int cur=bot;
while(i<=mid&&j<=top){
    if(compare(arr[j],arr[i],criterias)){
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

}
void merge_sort(monster* arr,int length,vector<int> criterias){
monster* tmp=new monster[length];
for(int i=0;i<length;i++){
    tmp[i]=arr[i];
}
for(int width=1;width<length;width=2*width){
    for(int i=0;i<length;i+=2*width){
        int bot=i;
        int mid=i+width-1;
        int top=min(length-1,i+2*width-1);
        merge(arr,tmp,bot,mid,top,length,criterias);
    }
}
}
void counting_sort(monster* arr,int length){
int max=arr[0].type_of_attack;
for(int i=0;i<length;i++){
    if(arr[i].type_of_attack>max){
        max=arr[i].type_of_attack;
    }

}
int* a=new int[max+1];
monster* res=new monster[length];

for(int i=0;i<max+1;i++){
   a[i]=0;
}
for(int i=0;i<length;i++){
    a[arr[i].type_of_attack]++;
}
for(int i=1;i<max+1;i++){
   a[i]+=a[i-1];
}

for(int i=length-1;i>-1;i--){
    res[a[arr[i].type_of_attack]-1]=arr[i];
    a[arr[i].type_of_attack]--;
}
for(int i=0;i<length;i++){
    arr[i]=res[i];
}
}
void sort(monster* arr,int length,int rank){
int max=10;
int temp;
int* a=new int[max];
monster* res=new monster[length];

for(int i=0;i<max;i++){
   a[i]=0;
}
for(int i=0;i<length;i++){
    temp=abs((arr[i].hp/rank));
    a[temp%10]++;
}
for(int i=1;i<max;i++){
   a[i]+=a[i-1];
}

for(int i=length-1;i>-1;i--){
    temp=abs((arr[i].hp/rank));
    res[a[temp%10]-1]=arr[i];
    a[temp%10]--;
}
for(int i=0;i<length;i++){
    arr[i]=res[i];
}
}

void radix_sort(monster* arr,int length,vector<int> criterias){
int max=arr[0].hp;
int count=0;
for(int i=1;i<length;i++){
    if(arr[i].hp>max){
        max=arr[i].hp;
    }
}
for(int i=1;max/i>0;i=i*10){
    sort(arr,length,i);
}
}
void print(monster* arr,int length){
for(int i=0;i<length;i++){
    arr[i].print();
}
}
int main(){
srand(time(NULL));
int x;
int n;
cout<<"Enter size of array: \n";
cin>>n;
monster* arr=new monster[n];
for(int i=0;i<n;i++){
    arr[i].create_random();
}
vector<int> criterias;
int e;
bool cond=true;
while(cond){
    cout<<"1 to sort by criteria\n2 counting sort(type of ulti attack)\n3 radix sort(health)\n4 print list\n -1 exit\n";
    cin>>x;
    if(x==1){
        cout<<"Enter number of criteria\n";
        cin>>x;
        for(int i=0;i<x;i++){
            cout<<"Enter criteria\n";
            cin>>e;
            criterias.push_back(e);
        }
        merge_sort(arr,n,criterias);
        criterias.clear();
    }
    else if(x==2){
        counting_sort(arr,n);
    }
    else if(x==3){
        radix_sort(arr,n,criterias);
    }
    else if(x==4){
        print(arr,n);
    }
    else if(x==-1){
        cond=false;
        break;
    }
}
}
