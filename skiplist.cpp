#include <iostream>
#include <ctime>
#include <cstring>
#define MaxLvL 3

int statemenu;
using namespace std;
struct node{
int data;
node** next;
node(int value,int level){
this->data=value;
next=new node*[level+1];
memset(next,0,sizeof(node*)*(level+1));
}
};
int random_level(){
int lvl=0;
int a=rand()%2;
while(a==1&&lvl<MaxLvL){
    a=rand()%2;
    lvl++;
}
return lvl;
}
struct skiplist{
node* head;
int cur_level;
skiplist(){
cur_level=0;
node* n=new node(-1,MaxLvL);
head=n;
}
void print(){
node* n;

for(int i=0;i<=cur_level;i++){
    n=head->next[i];
    while(n){
    cout<<n->data<<" ";
    n=n->next[i];
    }
    cout<<endl;
}
}
void insert(int elem){
node* n;
n=head;

node* update[MaxLvL+1];
memset(update,0,sizeof(node*)*(MaxLvL+1));
for(int i=cur_level;i>=0;i--){
    while((n->next[i]!=NULL)&&(n->next[i]->data<elem)){
        n=n->next[i];
    }
    update[i]=n;
}
n=n->next[0];

if(n==nullptr||n->data!=elem){
    int lev=random_level();
    if(lev>cur_level){
        for(int i=cur_level+1;i<lev+1;i++){
            update[i]=head;
        }
        cur_level=lev;
    }
    node* temp=new node(elem,lev);
    for(int i=0;i<lev+1;i++){
        temp->next[i]=update[i]->next[i];
        update[i]->next[i]=temp;
    }
}
}
void search(int key){
node* n=head;
for(int i=cur_level;i>=0;i--){
    while(n->next[i]&&n->next[i]->data<key){
        n=n->next[i];
    }
}
n=n->next[0];
if(n&&n->data==key){
    cout<<"Element was founded\n";
}
else{
    cout<<"Element was not founded\n";
}
}

};
void interactive(){
int elem;
skiplist l;
while(statemenu!=-1){
    cout<<"1 add element\n";
    cout<<"2 found element\n";
    cout<<"3 print skiplist\n";
    cout<<"-1 to abort program\n";
    cin>>statemenu;
    if(statemenu==1){
        cout<<"Enter element to add\n";
        cin>>elem;
        l.insert(elem);
    }
    if(statemenu==2){
        cout<<"Enter element to search\n";
        cin>>elem;
        l.search(elem);
    }
    if(statemenu==3){
        l.print();
    }

}
}
void demo(){
skiplist l;
int elem;
for(int i=0;i<30;i++){
    cout<<"Random element that was added to the list\n";
    elem=rand()%500;
    cout<<elem<<endl;
    l.insert(elem);
}
cout<<"Skiplist now:\n";
l.print();
cout<<endl;
for(int i=0;i<15;i++){
    cout<<"Random elements that was searched\n";
    elem=rand()%500;
    cout<<"Element that was searched: "<<elem<<endl;
    l.search(elem);
}
}
void benchmark(){
int n=25600000;
skiplist l;
int elem;
for(int i=0;i<n;i++){
    elem=rand()%500;
    l.insert(elem);
}
cout<<clock()/1000.0<<endl;
elem=rand()%500;
l.search(elem);
cout<<clock()/1000.0<<endl;
}
int main(){
srand(time(NULL));
benchmark();
}
