#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <ctime>
#define SIZE 100001

int statemenu;
using namespace std;
struct point{
float x;
float y;
float z;
void input(){
cout<<"Enter x\n";
cin>>this->x;
cout<<"\nEnter y\n";
cin>>this->y;
cout<<"\nEnter z\n";
cin>>this->z;
}
void print(){
cout<<"{"<<x<<","<<y<<","<<z<<"}"<<endl;
}
void random_creation(){
float a=20.0;
this->x=float(rand()*a)/float((RAND_MAX));
this->y=float(rand()*a)/float((RAND_MAX));
this->z=float(rand()*a)/float((RAND_MAX));
}
};
struct node{
point data;
node* next;
};
struct list_array{
int current;
point array[SIZE];
list_array(){
memset(array,0,sizeof(array));
current=0;
}
void print(){
    for(int i=0;i<current;i++){
        array[i].print();
    }
}
void append(point elem){
if(current<SIZE){
array[current]=elem;
current++;
}
else{
    cout<<"Out of bounds\n";
}
}
void insert(int index,point elem){
if(current<SIZE-1){
point temp[current+1];
for(int i=0;i<index;i++){
    temp[i]=array[i];
}

temp[index]=elem;
for(int i=index;i<current;i++){
    temp[i+1]=array[i];
}
for(int i=0;i<current+1;i++){
    array[i]=temp[i];
}
}
else{
    cout<<"Out of bounds\n";
}
current++;
}
void remove(int index){
if(current==0){
    cout<<"list is empty\n";
}
else{
for(int i=index;i<current-1;i++){
    array[i]=array[i+1];
}
}
current--;
}
point get(int index){
    if(index<0||index>current){
        cout<<"Invalid index\n";
    }
    else{
return array[index];
    }
}
void set(int index,point elem){

if(index<0||index>current){
        cout<<"Invalid index\n";
    }
    else{
        array[index]=elem;
    }

}
int len(){
    return current;
    }
};
struct vector_list{
vector<point> v;
vector_list(){
v={};
}
void append(point elem){
v.push_back(elem);
}
void insert(int index,point p){
if(index>v.size()||index<0){
    cout<<"Invalid index\n";
}
v.insert(v.begin()+index,p);
}
void remove(int index){
v.erase(v.begin()+index);
}
point get(int index){
if(index<0||index>v.size()){
    cout<<"Invalid index\n";
}
else{
    return v[index];
}
}
void set(int index,point p){
if(index<0||index>v.size()){
    cout<<"Invalid index\n";
}
else{
    v[index]=p;
}
}
void print(){
for(int i=0;i<v.size();i++){
    v[i].print();
}
}
int len(){
return v.size();
}
};

struct list{
node* head;
list(){
head=nullptr;
}
void append(point p){
node* n=new node();
n=head;
if(n){
while(n->next){
    n=n->next;
}
node* tmp=new node();
tmp->next=nullptr;
tmp->data=p;
n->next=tmp;
}
else{
node* tmp=new node();
tmp->next=nullptr;
tmp->data=p;
head=tmp;
}
}
int length(){
node* n=head;
int count=0;
while(n->next){
        count++;
    n=n->next;
}
return count+1;
}
void remove(int index){
node* n=head;
if(index<0||index>this->length()){
    cout<<"Invalid index\n";
}
else{
    for(int i=0;i<index-1;i++){
        n=n->next;
    }
    node* t=new node();
    t=n;
    n->next=n->next->next;
}
}
void print(){
node* n=new node();
n=head;
while(n->next){
    n->data.print();
    n=n->next;
}
n->data.print();
}
void insert(int index,point p){
node* tmp=new node();

node* n=head;
if(index==this->length()-1){
    this->append(p);
}
else{
    for(int i=0;i<index-1;i++){
        n=n->next;
    }
    tmp->data=p;
    node* t=new node();
    t=n->next;
    n->next=tmp;
    tmp->next=t;
}
}

int len(){
node* n=new node();
n=head;
int count=0;
while(n->next){
    count++;
    n=n->next;
}
return (count+1);
}
void set(int index,point p){
if(index<0||index>this->len()){
    cout<<"Invalid index\n";
}
else{
        node* n=new node();
        n=head;
    for(int i=0;i<index-1;i++){
        n=n->next;
    }
    n->data=p;
}
}
point get(int index){
if(index<0||index>this->len()){
    cout<<"Invalid index\n";
}
else{
        node* n=new node();
        n=head;
    for(int i=0;i<index-1;i++){
        n=n->next;
    }
    return n->data;
}
}
};
void interactive(){
vector_list l;
while(statemenu!=-1){
cout<<"1 To append element\n";
cout<<"2 To insert element\n";
cout<<"3 To remove element\n";
cout<<"4 Get element\n";
cout<<"5 Set element\n";
cout<<"6 Length of list\n";
cout<<"7 Print list\n";
cout<<"-1 to abort program\n";
cout<<"----------------------\n";
cin>>statemenu;

if(statemenu==1){
    point x;
    x.input();
    l.append(x);
}
else if(statemenu==2){
    point x1;
    int a;
    cout<<"Enter element to insert\n";
    x1.input();
    cout<<"Enter index\n";
    cin>>a;
    l.insert(a,x1);
}
else if(statemenu==3){
    int b;
    cout<<"Enter index to remove\n";
    cin>>b;
    l.remove(b);
}
else if(statemenu==4){
    cout<<"Enter index to get element\n";
    point res;
    int z;
    cin>>z;
    res=l.get(z);
    res.print();
}
else if(statemenu==5){
    point st;
    cout<<"Enter element to set\n";
    st.input();
    int index;
    cout<<"Enter index\n";
    cin>>index;
    l.set(index,st);
}
else if(statemenu==6){
    cout<<l.len()<<endl;
}
else if(statemenu==7){
    l.print();
}
}
}
void demo(){
list_array l;
cout<<"Empty list was created\n";
point p;
cout<<"Now 10 random elements will be appended in the list\n";
for(int i=0;i<10;i++){
    p.random_creation();
    cout<<"Point that was added\n";
    p.print();
    l.append(p);
}
cout<<"Elements were appended successfully\n";
l.print();
int x=rand()%l.len();
p.random_creation();
cout<<"Random point inserted in random place\n Index: ";
cout<<x<<endl;
cout<<"Point: ";
p.print();
l.insert(x,p);
cout<<"Point was inserted successfully\n";
l.print();
int r=rand()%l.len();
cout<<"Index that was deleted: "<<r<<endl;
l.remove(r);
cout<<"Index was deleted successfully\n";
l.print();
r=rand()%l.len();
cout<<"Point on position: "<<r<<endl;
l.get(r).print();
r=rand()%l.len();
p.random_creation();
cout<<"Point that was modified on position: "<<r<<endl;
cout<<"Point: ";
p.print();
l.set(r,p);
l.print();
cout<<"Length of list: "<<l.len()<<endl;
cout<<"Final list\n";
l.print();
}
void benchmark(){
int n=190000000;
point p;
vector_list l;
for(int i=0;i<n;i++){
    p.random_creation();
    l.append(p);
}
cout<<clock()/1000.0<<endl;
p.random_creation();
l.insert(l.len()-1,p);
cout<<clock()/1000.0<<endl;
l.remove(l.len()-1);
cout<<clock()/1000.0<<endl;
l.get(l.len()-1);
cout<<clock()/1000.0<<endl;
l.len();
cout<<clock()/1000.0<<endl;
cout<<l.len()*sizeof(point)<<endl;
}
int main()
{
srand(time((NULL)));
benchmark();
}
