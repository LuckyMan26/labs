#include <iostream>
#include <time.h>
using namespace std;
int statemenu;
struct node{
int value;
node* link;
};
node* XOR(node* x, node* y) {
    return (node*)((uintptr_t)(x) ^ (uintptr_t)(y));
}
struct list{
node* head;
list(){
head=nullptr;
}
void print(){
node* curr=new node();
node* prev=new node();
node* next=new node();
curr=head;
prev=nullptr;
while(curr){
    cout<<curr->value<<" ";
    next=XOR(prev,curr->link);
    prev=curr;
    curr=next;
}
cout<<endl;
}
void print_reverse(){
node* curr=new node();
node* prev=new node();
node* next=new node();
curr=head;
prev=nullptr;
while(curr){
    next=XOR(prev,curr->link);
    prev=curr;
    curr=next;
}
curr=prev;
while(curr){
    cout<<curr->value<<" ";
    prev=XOR(next,curr->link);
    next=curr;
    curr=prev;
}
cout<<endl;
}
void insert_beg(int elem){
node* n=new node();
n->value=elem;
n->link=head;
if(head){
    head->link=XOR(n,head->link);
}
head=n;
}
int length(){
node* curr=new node();
node* prev=new node();
node* next=new node();
curr=head;
prev=nullptr;
int count=0;
while(curr){
    count++;
    next=XOR(prev,curr->link);
    prev=curr;
    curr=next;
}
return count;
}
void append(int elem){
node* curr=new node();
node* prev=new node();
node* next=new node();
curr=head;
prev=nullptr;
node* temp=new node();
temp->value=elem;
int n=this->length();
if(n>0){
for(int i=0;i<n-1;i++){
    next=XOR(prev,curr->link);
    prev=curr;
    curr=next;
}
curr->link=XOR(prev,temp);
temp->link=curr;
}
else{
    temp->link=head;
    head=temp;
}
}
void insert_pos(int elem,int pos){
if(pos>this->length()-1||pos<0){
    cout<<"Invalid position\n";
}
else{
node* curr=new node();
node* prev=new node();
node* next=new node();
curr=head;
prev=nullptr;
node* temp=new node();
temp->value=elem;
if(pos==0){
    this->insert_beg(elem);
}
else{
    for(int i=0;i<=pos-1;i++){
    next=XOR(prev,curr->link);
    prev=curr;
    curr=next;
    }
    next=XOR(prev,curr->link);
    prev->link=XOR(XOR(prev->link,curr),temp);
    temp->link=XOR(prev,curr);
    curr->link=XOR(temp,next);
}
}
}
void delete_elem(int pos){
if(pos>this->length()-1||pos<0){
    cout<<"Invalid position\n";
}
else{
node* curr=new node();
node* prev=new node();
node* next=new node();
curr=head;
prev=nullptr;

if(pos==0){
     next=head->link;
     next->link=XOR(prev,XOR(next->link,curr));
     head=next;
}
else{
    if(pos!=this->length()-1){
    for(int i=0;i<=pos-1;i++){
    next=XOR(prev,curr->link);
    prev=curr;
    curr=next;
    }
    next=XOR(prev,curr->link);
    next->link=XOR(prev,XOR(next->link,curr));
    prev->link=XOR(XOR(prev->link,curr),next);
    free(curr);
    }
    else{
    for(int i=0;i<=pos-1;i++){
    next=XOR(prev,curr->link);
    prev=curr;
    curr=next;
    }
    prev->link=XOR(XOR(prev->link,curr),nullptr);
    free(curr);
    }
}
}
}
int get(int pos){
if(pos>this->length()-1||pos<0){
    cout<<"Invalid position\n";

}
else{
node* curr=new node();
node* prev=new node();
node* next=new node();
curr=head;
prev=nullptr;
if(pos==0){
    cout<<head->value<<endl;
    return head->value;
}
else{
    for(int i=0;i<=pos-1;i++){
    next=XOR(prev,curr->link);
    prev=curr;
    curr=next;
    }
    //cout<<curr->value<<"\n";
    return curr->value;
}
}
}
void set(int pos,int elem){
if(pos>this->length()-1||pos<0){
    cout<<"Invalid position\n";
}
else{
node* curr=new node();
node* prev=new node();
node* next=new node();
curr=head;
prev=nullptr;
if(pos==0){
    head->value=elem;
    return;
}
else{
    for(int i=0;i<=pos-1;i++){
    next=XOR(prev,curr->link);
    prev=curr;
    curr=next;
    }
    curr->value=elem;
    return;
}
}
}
node* search(int key){
int index=0;
node* curr=new node();
node* prev=new node();
node* next=new node();
curr=head;
prev=nullptr;
    while(curr){
    if(curr->value==key){
        //cout<<"Element was founded at position: "<<index<<endl;
        return curr;
    }
    next=XOR(prev,curr->link);
    prev=curr;
    curr=next;
    index++;
    }
//cout<<"Nothing was founded\n";
return nullptr;
}
};
void interactive(){
list l;
while(statemenu!=-1){
    cout<<"1 Append element\n";
    cout<<"2 Add in the beginning\n";
    cout<<"3 Insert at any position\n";
    cout<<"4 Delete element\n";
    cout<<"5 Get element\n";
    cout<<"6 Search element\n";
    cout<<"7 Print list\n";
    cout<<"8 Print list in reverse direction\n";
    cout<<"9 Set element\n";
    cin>>statemenu;
    if(statemenu==1){
        int elem;
        cout<<"Enter element\n";
        cin>>elem;
        l.append(elem);
    }
    else if(statemenu==2){
        int elem;
        cout<<"Enter element\n";
        cin>>elem;
        l.insert_beg(elem);
    }
    else if(statemenu==3){
        int elem;
        int index;
        cout<<"Enter element\n";
        cin>>elem;
        cout<<"Enter index\n";
        cin>>index;
        l.insert_pos(elem,index);
    }
    else if(statemenu==4){
        int index;
        cout<<"Enter index\n";
        cin>>index;
        l.delete_elem(index);
    }
     else if(statemenu==5){
        int index;
        cout<<"Enter index\n";
        cin>>index;
        cout<<l.get(index);
    }
    else if(statemenu==6){
        int elem;
        cout<<"Enter element to search\n";
        cin>>elem;
       l.search(elem);
    }
    else if(statemenu==7){
        l.print();
    }
    else if(statemenu==8){
        l.print_reverse();
    }
    else if(statemenu==9){
        int index;
        int element;
        cout<<"Enter element to set\n";
        cin>>element;
        cout<<"Enter index\n";
        cin>>index;
        l.set(index,element);
    }
}
}
void demo(){
list l;
int elem;
int index;
cout<<"Random generated xor-linked list\n";
for(int i=0;i<100;i++){
    elem=rand()%50;
    l.append(elem);
}
l.print();
elem=rand()%50;
cout<<"Add  element at the beginning\n";
cout<<"Element: "<<elem<<endl;
l.insert_beg(elem);
l.print();
elem=rand()%50;
index=rand()%50;
cout<<"Insert element: "<<elem<<" Position: "<<index<<endl;
l.insert_pos(elem,index);
l.print();
cout<<"Delete element\n";
index=rand()%50;
cout<<"Position: "<<index<<endl;
l.delete_elem(index);
l.print();
cout<<"Get element from the index\n";
index=rand()%50;
cout<<"Index: "<<index<<endl;
l.get(index);
elem=rand()%50;
cout<<"Random element to search: "<<elem<<endl;
l.search(elem);
cout<<"Set element\n";
index=rand()%50;
elem=rand()%50;
cout<<"Index: "<<index<<endl;
cout<<"Element: "<<elem<<endl;
l.set(index,elem);
cout<<"List in reverse direction:\n";
l.print_reverse();
cout<<"Final list:\n";
l.print();
}
void benchamrk(){
int n=52428800;
int elem;
list l;
for(int i=0;i<n;i++){
    elem=rand()%50;
    l.insert_beg(elem);
}
cout<<clock()/1000.0<<endl;
l.append(-1);
cout<<clock()/1000.0<<endl;
l.insert_pos(10,n/2);
cout<<clock()/1000.0<<endl;
l.delete_elem(n-1);
cout<<clock()/1000.0<<endl;
l.get(n-1);
cout<<clock()/1000.0<<endl;
l.search(314);
cout<<clock()/1000.0;
}
int main(){
srand(time(NULL));
benchamrk();
}
