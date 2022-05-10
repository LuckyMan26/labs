#include <iostream>
#include <time.h>
#include <math.h>
#include <vector>
#include <fstream>
#include <algorithm>
int statemenu;
using namespace std;
struct point{
int x;
int y;
int z;
bool operator<(point& d){
if(sqrt(x*x+y*y+z*z)<sqrt(d.x*d.x+d.y*d.y+d.z*d.z)){
    return true;
}
if(sqrt(x*x+y*y+z*z)>sqrt(d.x*d.x+d.y*d.y+d.z*d.z)){
    return false;
}
if(sqrt(x*x+y*y+z*z)==sqrt(d.x*d.x+d.y*d.y+d.z*d.z)){
    if(x<d.x){
        return true;
    }
    if(x>d.x){
        return false;
    }
    if(x==d.x){
        if(y<d.y){
            return true;
        }
        if(y>d.y){
            return false;
        }
        if(y==d.y){
            if(z<d.z){
                return true;
            }
            if(z>d.z){
                return false;
            }
            if(z==d.z){
                return false;
            }
        }
    }
}
}
bool operator==(point& d){
if(sqrt(x*x+y*y+z*z)==sqrt(d.x*d.x+d.y*d.y+d.z*d.z)){
       if((x==d.x)&&((y==d.y)&&(z==d.z))){

    return true;
}

}
return false;
}
bool operator>(point& d){
if(!(*this<d)&&(!(*this==d))){
    return true;
}
return false;
}
friend ostream& operator<<(ostream& os, const point& p)
{
    os<<"("<<p.x << "," << p.y << "," <<p.z<<")"<<endl;
    return os;
}
void create_random(int n){
x=rand()%(2*n);
y=rand()%(2*n);
z=rand()%(2*n);

}
void enter(){
cout<<"Enter point\n";
cout<<"x: "<<endl;
cin>>this->x;
cout<<"y: "<<endl;
cin>>this->y;
cout<<"z: "<<endl;
cin>>this->z;
}
};
bool is_in_vector(vector<point> v,point elem){
for(int i=0;i<v.size();i++){
    if(v[i]==elem){
        return true;
    }
}
return false;
}
struct node{
point data;
node* next;
};
struct List{
node* header;
List(){
header=nullptr;
}
void print(){
node* temp=new node();
temp=header;
while(temp){
    cout<<temp->data<<" ";
    temp=temp->next;
}
}
void add_elem(point elem){
node* cur=new node();
node* prev=new node();
cur=header;
prev=nullptr;
if(header){

while(cur){
        if(cur->data>elem){
            break;
        }
        else{

            prev=cur;
            cur=cur->next;
        }
}


if(cur){
        if(prev){
        node* tmp=new node();
        tmp->data=elem;
        tmp->next=cur;
        prev->next=tmp;
        }
        else{
            node* tmp=new node();
        tmp->data=elem;
        tmp->next=cur;
            header=tmp;
        }

}
else{
    node* tmp=new node();
tmp->data=elem;
tmp->next=nullptr;
    prev->next=tmp;
}
}
else{
    node* cur=new node();
    cur->data=elem;
    cur->next=nullptr;
    header=cur;
}
}
void find_elem_range(point beg,point end){
node* temp=new node();
temp=header;
int count;
while(temp){
    if(((temp->data>beg)||(temp->data==beg))&&((temp->data<end)||(temp->data==end))){
            cout<<count<<" "<<temp->data<<endl;
    }
    count++;
            temp=temp->next;

}
}
int find_elem(point elem){
node* temp=new node();
temp=header;
int count;
while(temp){
    if((temp->data==elem)){
         return count;
    }
    if((temp->data>elem)){
         return -1;
    }
        count++;
            temp=temp->next;

}
return -1;
}
void create_random(int n){
point elem;
for(int i=0;i<n;i++){
    elem.create_random(n);
    this->add_elem(elem);
}
}
void del(point elem){
node* tmp=header;
node* prev=nullptr;

while(tmp){
    if(tmp->data==elem){
            if(tmp->next){
                prev->next=tmp->next;
                delete tmp;
            }
            else{
                prev->next=nullptr;
                delete tmp;
            }
            return;
    }
     if(tmp->data>elem){
       return;
    }
    prev=tmp;
    tmp=tmp->next;
}
}
};
struct ArrayList{
vector<point> v;
ArrayList(){
v={};
}
void add_elem(point elem){
point tmp;
if(v.size()>0){
if(v[v.size()-1]<elem){
    v.push_back(elem);
}
else{
    tmp=v[v.size()-1];
    v[v.size()-1]=elem;
    v.push_back(tmp);
}
}
else{
    v.push_back(elem);
}
}
void print(){
for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
}
cout<<endl;
}
int find_elem(point elem){
for(int i=0;i<v.size();i++){
    if(v[i]==elem){
        return i;
    }
    if(v[i]>elem){
        return -1;
    }
}
return -1;
}
void find_elem_range(point beg,point end){
for(int i=0;i<v.size();i++){
    if(((v[i]>beg)||(v[i]==beg))&&((v[i]<end)||(v[i]==end))){
        cout<<i<<" "<<v[i]<<endl;
    }
}

}
void create_random(int n){
point tmp;
for(int i=0;i<n;i++){
    tmp.create_random(n);
    this->add_elem(tmp);

}
}
void del(point p){
for(int i=0;i<v.size();i++){
    if(v[i]==p){
        v.erase(v.begin()+i);
        return;
    }
    if(v[i]>p){
        return;
    }
}
}
};
struct TreeNode{
point data;
TreeNode* left;
TreeNode* right;
TreeNode(point d,TreeNode* l=nullptr,TreeNode* r=nullptr){
this->data=d;
this->left=l;
this->right=r;
}
void print(){
if(this){
cout<<this->data<<"(";
		if (left) {
			left->print();
		} else {
			cout << " ";
		}
		cout<<",";
		if (right) {
			right->print();
		} else {
			cout << " ";
		}
		cout<<")";
}
}

TreeNode* build_array(point* arr,int size){
if(size==0){
    return nullptr;
}
else{
    int mid=size/2;
    return new TreeNode(arr[mid],build_array(arr,mid),build_array(arr+mid+1,size-mid-1));
}
}
};
void print(TreeNode* root,int cur_level){
if(root==NULL){
    return;
}
else{
    cout<<cur_level<<","<<root->data<<" ";
    if(root->left!=nullptr){
        print(root->left,cur_level+1);
    }
    if(root->right!=nullptr){
        print(root->right,cur_level+1);
    }
}
}
struct BinSearchTree{
TreeNode* root;
BinSearchTree(){
root=nullptr;
}
BinSearchTree(point* arr,int size){
root=root->build_array(arr,size);
}
void print_as_tree(){
root->print();
}
void print_as_tree_in_level_form(){
print(this->root,0);
}
TreeNode* insert(TreeNode* r,point key){
if(!r){
    r=new TreeNode(key);
    return r;
    }
    if((r->data>key)||(r->data==key)){
        r->left=insert(r->left,key);
    }
    if(r->data<key){
        r->right=insert(r->right,key);
    }
return r;
}
void add(point key){
root=insert(root,key);
}

TreeNode* search(TreeNode* r,point elem){
if(r){
if(r->data==elem){
    return r;
}
 if(r->data<elem){
   return(search(r->right,elem));
}
else if(r->data>elem){
    return(search(r->left,elem));
}
}
else{
    return nullptr;
}
}
void search_range(TreeNode* r,point beg,point end){
if (r) {
        search_range(r->left,beg,end);
        if(((r->data>beg)||(r->data==beg))&&((r->data<end)||(r->data==end))){
            cout<<r->data<<" ";

        }
        search_range(r->right,beg,end);
    }
    return;
}


TreeNode* delmax(TreeNode* p, TreeNode* t) {
  TreeNode* q=nullptr;
  if (p->right){
       p->right = delmax(p->right, t);
  }

  else {
    t->data = p->data;
    q = p;
    p = p->left;
    delete q;
  }
  return p;
}
void del(point key,TreeNode* cur,TreeNode* parent=nullptr){
if(cur){
    if(cur->data==key){
        if((!cur->left)&&(!cur->right)){

            if(parent->right==cur){
                parent->right=nullptr;
                delete cur;
                return;
            }
            else if(parent->left==cur){
                parent->left=nullptr;
                delete cur;
                return;
            }
        }

        if((cur->left)&&(!cur->right)){
            if(parent->left==cur){
                parent->left=cur->left;
                delete cur;
                return;
            }
            if(parent->right==cur){
                parent->right=cur->left;
                delete cur;
                return;
            }
        }
        if((!cur->left)&&(cur->right)){
            if(parent->left==cur){
                parent->left=cur->right;
                delete cur;
                return;
            }
            if(parent->right==cur){
                parent->right=cur->right;
                delete cur;
                return;
            }
        }
         if((cur->left)&&(cur->right)){
           cur->left=this->delmax(cur->left,cur);
        }
    }

  if(cur->data>key){
    del(key,cur->left,cur);
  }
  if(cur->data<key){
    del(key,cur->right,cur);
  }

}
}

void print_in_right_order(TreeNode* cur){
if (cur) {
        print_in_right_order(cur->left);
        cout<<cur->data<<" ";
        print_in_right_order(cur->right);
    }
    return;
}
void print1(){
this->print_in_right_order(this->root);
}
};
BinSearchTree random_create(int n){
point* arr=new point[n];
for(int i=0;i<n;i++){
    arr[i].create_random(n);
}
BinSearchTree t(arr,n);
return t;
}
struct AvlNode{
point data;
AvlNode* left;
AvlNode* right;
int height;
AvlNode(point d,int h=1,AvlNode* l=nullptr,AvlNode* r=nullptr){
this->data=d;
this->left=l;
this->right=r;
this->height=h;
}

void print(AvlNode* root,int cur_level){
if(root==NULL){
    return;
}
else{
    cout<<cur_level<<","<<root->data<<" ";
    if(root->left!=nullptr){
        print(root->left,cur_level+1);
    }
    if(root->right!=nullptr){
        print(root->right,cur_level+1);
    }
}
}

};
AvlNode* newNode(point key){
    AvlNode* node = new AvlNode(key,1);
    node->data = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return(node);
}
int height(AvlNode* n){
if(n==nullptr){
    return 0;
}
return n->height;
}
int getBalance(AvlNode *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) -
           height(N->right);
}
struct AvlTree{
AvlNode* root;
AvlTree(){
this->root=nullptr;
}
AvlNode* left_rotate(AvlNode *x)
{
    AvlNode *y = x->right;
    AvlNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;

    return y;
}
AvlNode* right_rotate(AvlNode *y)
{
    AvlNode *x = y->left;
    AvlNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;

    return x;
}
AvlNode* insert(point key,AvlNode* node){
if(node==nullptr){
    return(newNode(key));
}
else if((node->data>key)){
    node->left=insert(key,node->left);
}
else if(node->data<key){
    node->right=insert(key,node->right);
}
else{
    return node;
}
node->height=1+max(height(node->left),height(node->right));
int balance=getBalance(node);
if(balance>1 && key<node->left->data){
    return right_rotate(node);
}
if(balance<-1 && key>node->right->data){
    return left_rotate(node);
}
if(balance>1 && key>node->left->data){
    node->left=left_rotate(node->left);
    return right_rotate(node);
}
if(balance<-1 && key<node->right->data){
    node->right=right_rotate(node->right);
    return left_rotate(node);
}
return node;
}
void insert(point key){
root=insert(key,root);
}

void print(AvlNode* cur){
if(cur){
    print(cur->left);
    cout<<cur->data<<" ";
    print(cur->right);
}
}
void print(){
this->print(this->root);
}
void print_as_tree(){
this->root->print(this->root,0);
}
AvlNode* minValueNode(AvlNode* node){
AvlNode* curr=node;
while(curr->left!=NULL){
    curr=curr->left;
}
return curr;
}
AvlNode* DelNode(AvlNode* r,point key){
if(r==nullptr){
    return r;
}
if(key<r->data){
    r->left=DelNode(r->left,key);
}
if(key>r->data){
    r->right=DelNode(r->right,key);
}
else{
    if((r->left==NULL)||(r->right==NULL)){
        AvlNode* temp=r->left ?
                     r->left :
                     r->right;
        if(temp==NULL){
            temp=r;
            r=NULL;
        }
        else{
            *r=*temp;

            delete temp;
        }
    }
    else{
    AvlNode* temp=minValueNode(r->right);

    r->data=temp->data;

    r->right=DelNode(r->right,temp->data);
}
}
if(r==NULL){
    return r;
}
r->height=1+max(height(r->left),height(r->right));

int balance=height(r->left)-height(r->right);
if (balance > 1 &&getBalance(r->left) >= 0)
        return right_rotate(r);

    if (balance > 1 && getBalance(r->left) < 0)
    {
        r->left = left_rotate(r->left);
        return right_rotate(r);
    }

    if (balance < -1 && getBalance(r->right) <= 0)
        return left_rotate(r);

    if (balance < -1 && getBalance(r->right) > 0)
    {
        r->right = right_rotate(r->right);
        return left_rotate(r);
    }
    return r;
}
void del(point key){
this->DelNode(this->root,key);
}
void create_random(int n){
point x;
vector<point> v;
for(int i=0;i<n;i++){
    x.create_random(100);
    insert(x);
}

}
AvlNode* search(AvlNode* r,point key){
if(r){
if(r->data==key){
    return r;
}
 if(r->data<key){
   return(search(r->right,key));
}
else if(r->data>key){
    return(search(r->left,key));
}
}
else{

    return nullptr;
}
}
void search_range(AvlNode* cur,point beg,point end){
if(cur){
    search_range(cur->left,beg,end);
    if(((cur->data>beg)||(cur->data==beg))&&((cur->data<end)||(cur->data==end))){
    cout<<cur->data<<" ";
    }
    if(cur->data>end){
        return;
    }
    search_range(cur->right,beg,end);
}

}
void search_range(point beg,point end){
this->search_range(this->root,beg,end);
}
AvlNode* search(point key){
return this->search(this->root,key);
}
};
struct TwoThreeNode{
int size;
point key[3];
TwoThreeNode* first;
TwoThreeNode* second;
TwoThreeNode* third;
TwoThreeNode* fourth;
TwoThreeNode* parent;
TwoThreeNode(point k){
this->key[0]=k;
this->first=nullptr;
this->second=nullptr;
this->third=nullptr;
this->fourth=nullptr;
this->parent=nullptr;
size=1;
}
TwoThreeNode(point k,TwoThreeNode* f,TwoThreeNode* s,TwoThreeNode* t,TwoThreeNode* fourt_,TwoThreeNode* p){
this->key[0]=k;
this->first=f;
this->second=s;
this->third=t;
this->fourth=fourt_;
this->parent=p;
size=1;
}

bool find(point elem){
for(int i=0;i<size;i++){
    if(key[i]==elem){
        return true;
    }
}
return false;
}
void sort(){
for(int i=0;i<size;i++){
    for(int j=0;j<size-i-1;j++){
        if(key[j]>key[j+1]){
            swap(key[j],key[j+1]);
        }
    }
}
}
void insert(point elem){
key[size]=elem;
size++;
this->sort();
}
void remove(point k){
if((size>=1)&&(key[0]==k)){
    key[0]=key[1];
    key[1]=key[2];
    size--;
}
else if((size==2)&&(key[1]==k)){
    key[1]=key[2];
    size--;
}
}
void Convert2TwoThreeNode(point elem,TwoThreeNode* f,TwoThreeNode* s){
key[0]=elem;
size=1;
first=f;
second=s;
third=nullptr;
fourth=nullptr;
parent=nullptr;
}
bool is_leaf(){
return (first == nullptr) && (second == nullptr) && (third == nullptr);
}
void print(){
for(int i=0;i<size;i++){
    cout<<this->key[i]<<" ";
}
}
};
struct TwoThreeTree{
TwoThreeNode* root;
TwoThreeTree(){
root=nullptr;
}
TwoThreeNode* split(TwoThreeNode* item){
 if (item->size < 3) return item;

TwoThreeNode *x = new TwoThreeNode(item->key[0], item->first, item->second, nullptr, nullptr, item->parent);
TwoThreeNode *y = new TwoThreeNode(item->key[2], item->third, item->fourth, nullptr, nullptr, item->parent);
if (x->first){
    x->first->parent = x;
}
if (x->second){
x->second->parent = x;
    }
if (y->first){
y->first->parent = y;
    }
if (y->second){
y->second->parent = y;
}

if (item->parent) {
    item->parent->insert(item->key[1]);
    if (item->parent->first == item) item->parent->first = nullptr;
        else if (item->parent->second == item) item->parent->second = nullptr;
        else if (item->parent->third == item) item->parent->third = nullptr;

        if (item->parent->first == nullptr) {
            item->parent->fourth = item->parent->third;
            item->parent->third = item->parent->second;
            item->parent->second = y;
            item->parent->first = x;
        } else if (item->parent->second == nullptr) {
            item->parent->fourth = item->parent->third;
            item->parent->third = y;
            item->parent->second = x;
        } else {
            item->parent->fourth = y;
            item->parent->third = x;
        }

        TwoThreeNode *tmp = item->parent;
        delete item;
        return tmp;
    } else {
        x->parent = item;
        y->parent = item;
        item->Convert2TwoThreeNode(item->key[1], x, y);
        return item;
    }
}
TwoThreeNode* insert(TwoThreeNode* r,point elem){
if(!root){
    return new TwoThreeNode(elem);
}
if(r->is_leaf()){
    r->insert(elem);
}
else if((elem==r->key[0])||(elem<r->key[0])){
    this->insert(r->first,elem);
}
else if ((r->size==1)||((r->size==2) && (elem < r->key[1])||(elem==r->key[1]))) {
        insert(r->second, elem);
}
else {
    insert(r->third, elem);
}
return split(r);
}
void insert(point elem){
this->root=this->insert(this->root,elem);
}
TwoThreeNode* search(TwoThreeNode* r,point k){
    if (!r)
    {
    return nullptr;
    }

    if (r->find(k)) {
return r;
    }
    else if (k < r->key[0]) {
return search(r->first, k);
}
    else if ((r->size == 2) && (k < r->key[1]) || (r->size == 1)) {
return search(r->second, k);
    }
    else if (r->size == 2){
return search(r->third, k);
    }
}
TwoThreeNode *search_min(TwoThreeNode *p) {
    if (!p) return p;
    if (!(p->first)) return p;
    else return search_min(p->first);
}
TwoThreeNode* redistribute(TwoThreeNode *leaf) {
    TwoThreeNode *parent = leaf->parent;
    TwoThreeNode *first = parent->first;
    TwoThreeNode *second = parent->second;
    TwoThreeNode *third = parent->third;

    if ((parent->size == 2) && (first->size < 2) && (second->size < 2) && (third->size < 2)) {
        if (first == leaf) {
            parent->first=parent->second;
            parent->second=parent->third;
            parent->third=nullptr;
            parent->first->insert(parent->key[0]);
            parent->first->third = parent->first->second;
            parent->first->second = parent->first->first;

            if (leaf->first!=nullptr) {
    parent->first->first = leaf->first;
            }
            else if (leaf->second!=nullptr) {
        parent->first->first = leaf->second;
            }

            if (parent->first->first!=nullptr){
            parent->first->first->parent = parent->first;
            }
            parent->remove(parent->key[0]);
            delete first;
        }
        else if (second==leaf) {
            first->insert(parent->key[0]);
            parent->remove(parent->key[0]);
            if (leaf->first != nullptr) {
            first->third = leaf->first;
            }
            else if (leaf->second != nullptr) {
            first->third = leaf->second;
            }
            if (first->third != nullptr) {
            first->third->parent = first;
            }
            parent->second = parent->third;
            parent->third = nullptr;

            delete second;
        } else if (third == leaf) {
            second->insert(parent->key[1]);
            parent->third=nullptr;
            parent->remove(parent->key[1]);
            if (leaf->first != nullptr) second->third = leaf->first;
            else if (leaf->second != nullptr) second->third = leaf->second;

            if (second->third != nullptr)  second->third->parent = second;

            delete third;
        }
    } else if ((parent->size == 2) && ((first->size == 2) || (second->size == 2) || (third->size == 2))) {
        if (third == leaf) {
            if (leaf->first != nullptr) {
                leaf->second = leaf->first;
                leaf->first = nullptr;
            }

            leaf->insert(parent->key[1]);
            if (second->size == 2) {
                parent->key[1] = second->key[1];
                second->remove(second->key[1]);
                leaf->first = second->third;
                second->third = nullptr;
                if (leaf->first != nullptr) leaf->first->parent = leaf;
            } else if (first->size == 2) {
                parent->key[1] = second->key[0];
                leaf->first = second->second;
                second->second = second->first;
                if (leaf->first != nullptr) leaf->first->parent = leaf;

                second->key[0] = parent->key[0];
                parent->key[0] = first->key[1];
                first->remove(first->key[1]);
                second->first = first->third;
                if (second->first != nullptr) second->first->parent = second;
                first->third = nullptr;
            }
        } else if (second == leaf) {
            if (third->size == 2) {
                if (leaf->first == nullptr) {
                    leaf->first = leaf->second;
                    leaf->second = nullptr;
                }
                second->insert(parent->key[1]);
                parent->key[1] = third->key[0];
                third->remove(third->key[0]);
                second->second = third->first;
                if (second->second != nullptr) second->second->parent = second;
                third->first = third->second;
                third->second = third->third;
                third->third = nullptr;
            } else if (first->size == 2) {
                if (leaf->second == nullptr) {
                    leaf->second = leaf->first;
                    leaf->first = nullptr;
                }
                second->insert(parent->key[0]);
                parent->key[0] = first->key[1];
                first->remove(first->key[1]);
                second->first = first->third;
                if (second->first != nullptr) second->first->parent = second;
                first->third = nullptr;
            }
        } else if (first == leaf) {
            if (leaf->first == nullptr) {
                leaf->first = leaf->second;
                leaf->second = nullptr;
            }
            first->insert(parent->key[0]);
            if (second->size == 2) {
                parent->key[0] = second->key[0];
                second->remove(second->key[0]);
                first->second = second->first;
                if (first->second != nullptr) first->second->parent = first;
                second->first = second->second;
                second->second = second->third;
                second->third = nullptr;
            } else if (third->size == 2) {
                parent->key[0] = second->key[0];
                second->key[0] = parent->key[1];
                parent->key[1] = third->key[0];
                third->remove(third->key[0]);
                first->second = second->first;
                if (first->second != nullptr) first->second->parent = first;
                second->first = second->second;
                second->second = third->first;
                if (second->second != nullptr) second->second->parent = second;
                third->first = third->second;
                third->second = third->third;
                third->third = nullptr;
            }
        }
    } else if (parent->size == 1) {
        leaf->insert(parent->key[0]);

        if (first == leaf && second->size == 2) {
            parent->key[0] = second->key[0];
            second->remove(second->key[0]);

            if (leaf->first == nullptr) leaf->first = leaf->second;

            leaf->second = second->first;
            second->first = second->second;
            second->second = second->third;
            second->third = nullptr;
            if (leaf->second != nullptr) leaf->second->parent = leaf;
        } else if (second == leaf && first->size == 2) {
            parent->key[0] = first->key[1];
            first->remove(first->key[1]);

            if (leaf->second == nullptr) leaf->second = leaf->first;

            leaf->first = first->third;
            first->third = nullptr;
            if (leaf->first != nullptr) leaf->first->parent = leaf;
        }
    }
    return parent;
}
TwoThreeNode* merge(TwoThreeNode *leaf) {
TwoThreeNode *parent = leaf->parent;

    if (parent->first == leaf) {
        parent->second->insert(parent->key[0]);
        parent->second->third = parent->second->second;
        parent->second->second = parent->second->first;

        if (leaf->first != nullptr) {
        parent->second->first = leaf->first;
        }
        else if (leaf->second != nullptr) {
        parent->second->first = leaf->second;
        }
        if (parent->second->first != nullptr){
        parent->second->first->parent = parent->second;
        }
        parent->remove(parent->key[0]);
        delete parent->first;
        parent->first = nullptr;
    } else if (parent->second == leaf) {
        parent->first->insert(parent->key[0]);

        if (leaf->first != nullptr){
        parent->first->third = leaf->first;
        }
        else if (leaf->second != nullptr){
        parent->first->third = leaf->second;
        }
        if (parent->first->third != nullptr){
        parent->first->third->parent = parent->first;
        }
        parent->remove(parent->key[0]);
        delete parent->second;
        parent->second = nullptr;
    }

    if (parent->parent == nullptr) {
        TwoThreeNode *tmp = nullptr;
        if (parent->first != nullptr) {
        tmp = parent->first;
        }
        else{
        tmp = parent->second;
        }
        tmp->parent = nullptr;
        delete parent;
        return tmp;
    }
    return parent;
}
TwoThreeNode* fix(TwoThreeNode* leaf){
  if (leaf->size == 0&&leaf->parent==nullptr) {
        delete leaf;
        return nullptr;
    }
    if (leaf->size!=0) {
        if (leaf->parent) return fix(leaf->parent);
        else return leaf;
    }

    TwoThreeNode *parent = leaf->parent;
    if (parent->first->size == 2 || parent->second->size == 2 || parent->size == 2) {
leaf = redistribute(leaf);
    }
    else if ((parent->size == 2)&&(parent->third->size == 2)) {
leaf=redistribute(leaf);
}
    else {
leaf=merge(leaf);
}

    return fix(leaf);
}
TwoThreeNode* remove(TwoThreeNode* r,point elem){
TwoThreeNode* temp=this->search(r,elem);
if(!temp){
    return r;
}
TwoThreeNode* min=nullptr;
if(temp->key[0]==elem){
    min=this->search_min(temp->second);
}
else{
    min=this->search_min(temp->third);
}
point z;
if(min){
    if(elem==temp->key[0]){
        point &z=temp->key[0];
    }
    else{
        point &z=temp->key[1];
    }
    swap(z,min->key[0]);
    temp=min;
}
temp->remove(elem);
return fix(temp);
}
void del(point elem){
this->remove(this->root,elem);
}
void print(TwoThreeNode* r){
    if(r){
    if (r->is_leaf()){
        r->print();
    }
    else if ((r->first)&&(r->second)&&(!r->third)){
        this->print(r->first);
        r->print();
        this->print(r->second);

    } else if ((r->first)&&(r->second)&&(r->third)){

         this->print(r->first);
         cout<<r->key[0]<<" ";
         this->print(r->second);
         cout<<r->key[1]<<" ";
         this->print(r->third);

    }
    }
}
void print(){
this->print(this->root);
}
void search_range(TwoThreeNode* r,point beg,point end){
    if(r){
    if (r->is_leaf()){
        if((r->key[0]>beg)&&(r->key[0]<end)){
            cout<<r->key<<" ";
        }
    }
    else if ((r->first)&&(r->second)&&(!r->third)){
        this->print(r->first);
       if((r->key[0]>beg)&&(r->key[0]<end)){
            cout<<r->key[0]<<" ";
        }
        this->print(r->second);

    } else if ((r->first)&&(r->second)&&(r->third)){

        if((r->key[0]>beg)&&(r->key[0]<end)){
            cout<<r->key[0]<<" ";
        }
         this->print(r->second);
        if((r->key[1]>beg)&&(r->key[1]<end)){
            cout<<r->key[1]<<" ";
        }
         this->print(r->third);

    }
    }
}
void traverse(point beg,point end){
this->search_range(this->root,beg,end);
}
void create_random(int n){
point x;
for(int i=0;i<n;i++){
   x.create_random(n);
    this->insert(x);
}
}
TwoThreeNode* search(point k){
return this->search(this->root,k);
}
};
void interactive(){

while(statemenu!=-1){
    cout<<"1 To do operations with ordered list based on linked list\n";
    cout<<"2 To do operations with ordered list based on ArrayList\n";
    cout<<"3 To do operations with ordered list based on Binary search tree\n";
    cout<<"4 To do operations with ordered list based on AVL tree\n";
    cout<<"5 To do operations with ordered list based on 2-3 tree\n";
    cin>>statemenu;
    if(statemenu==1){
        List l;
        int x=0;

        while(x!=-1){
         cout<<"1 To create random ordered list\n";
        cout<<"2 To add an element\n";
        cout<<"3 To search for an element\n";
        cout<<"4 To search for an element, which fits in range\n";
        cout<<"5 To delete an element\n";
        cout<<"6 To print list in the right order\n";
        cout<<"-1 To abort\n";
        cin>>x;
        if(x==1){
                int n;
        cout<<"Enter number of elements\n";
        cin>>n;
            l.create_random(n);
        }
        if(x==2){
            point elem;
            cout<<"Enter element to add\n";
            elem.enter();
            l.add_elem(elem);
        }
        if(x==3){
             point elem;
              cout<<"Enter element to search\n";
            elem.enter();
           cout<<"Index: "<<l.find_elem(elem);
        }
        if(x==4){
             point beg,end;
              cout<<"Enter element, which fits in bounds\n";
            beg.enter();
            end.enter();
           l.find_elem_range(beg,end);
        }
        if(x==5){
            point elem;
            cout<<"Enter element to delete\n";
            elem.enter();
            l.del(elem);
        }
        if(x==6){
            l.print();
        }
    }
    }
       if(statemenu==2){
        ArrayList l;
        int x=0;

        while(x!=-1){
         cout<<"1 To create random ordered list\n";
        cout<<"2 To add an element\n";
        cout<<"3 To search for an element\n";
        cout<<"4 To search for an element, which fits in range\n";
        cout<<"5 To delete an element\n";
        cout<<"6 To print list in the right order\n";
        cout<<"-1 To abort\n";
        cin>>x;
        if(x==1){
                int n;
        cout<<"Enter number of elements\n";
        cin>>n;
            l.create_random(n);
        }
        if(x==2){
            point elem;
            cout<<"Enter element to add\n";
            elem.enter();
            l.add_elem(elem);
        }
        if(x==3){
             point elem;
              cout<<"Enter element to search\n";
            elem.enter();
           cout<<"Index: "<<l.find_elem(elem);
        }
        if(x==4){
             point beg,end;
              cout<<"Enter element, which fits in bounds\n";
            beg.enter();
            end.enter();
           l.find_elem_range(beg,end);
        }
        if(x==5){
            point elem;
            cout<<"Enter element to delete\n";
            elem.enter();
            l.del(elem);
        }
        if(x==6){
            l.print();
        }
    }
    }
      if(statemenu==3){
        BinSearchTree l;
        int x=0;

        while(x!=-1){
         cout<<"1 To create random ordered list\n";
        cout<<"2 To add an element\n";
        cout<<"3 To search for an element\n";
        cout<<"4 To search for an element, which fits in range\n";
        cout<<"5 To delete an element\n";
        cout<<"6 To print list in the right order\n";
        cout<<"-1 To abort\n";
        cin>>x;
        if(x==1){
                int n;
        cout<<"Enter number of elements\n";
        cin>>n;
           l=random_create(n);
        }
        if(x==2){
            point elem;
            cout<<"Enter element to add\n";
            elem.enter();
            l.add(elem);
        }
        if(x==3){
             point elem;
              cout<<"Enter element to search\n";
            elem.enter();
          if(l.search(l.root,elem)){
            cout<<"Element: "<<elem<<" exist"<<endl;

          }
        }
        if(x==4){
             point beg,end;
              cout<<"Enter element, which fits in bounds\n";
            beg.enter();
            end.enter();
          l.search_range(l.root,beg,end);
        }
        if(x==5){
            point elem;
            cout<<"Enter element to delete\n";
            elem.enter();
            l.del(elem,l.root);
        }
        if(x==6){
           l.print_in_right_order(l.root);
        }
    }
    }
     if(statemenu==4){
        AvlTree l;
        int x=0;

        while(x!=-1){
         cout<<"1 To create random ordered list\n";
        cout<<"2 To add an element\n";
        cout<<"3 To search for an element\n";
        cout<<"4 To search for an element, which fits in range\n";
        cout<<"5 To delete an element\n";
        cout<<"6 To print list in the right order\n";
        cout<<"-1 To abort\n";
        cin>>x;
        if(x==1){
                int n;
        cout<<"Enter number of elements\n";
        cin>>n;
          l.create_random(n);
        }
        if(x==2){
            point elem;
            cout<<"Enter element to add\n";
            elem.enter();
            l.insert(elem);
        }
        if(x==3){
             point elem;
              cout<<"Enter element to search\n";
            elem.enter();
          if(l.search(l.root,elem)){
            cout<<"Element: "<<elem<<" exist"<<endl;

          }
        }
        if(x==4){
             point beg,end;
              cout<<"Enter element, which fits in bounds\n";
            beg.enter();
            end.enter();
          l.search_range(l.root,beg,end);
        }
        if(x==5){
            point elem;
            cout<<"Enter element to delete\n";
            elem.enter();
            l.del(elem);
        }
        if(x==6){
           l.print();
        }
    }
    }
         if(statemenu==5){
        TwoThreeTree l;
        int x=0;

        while(x!=-1){
         cout<<"1 To create random ordered list\n";
        cout<<"2 To add an element\n";
        cout<<"3 To search for an element\n";
        cout<<"4 To search for an element, which fits in range\n";
        cout<<"5 To delete an element\n";
        cout<<"6 To print list in the right order\n";
        cout<<"-1 To abort\n";
        cin>>x;
        if(x==1){
                int n;
        cout<<"Enter number of elements\n";
        cin>>n;
          l.create_random(n);
        }
        if(x==2){
            point elem;
            cout<<"Enter element to add\n";
            elem.enter();
            l.insert(elem);
        }
        if(x==3){
             point elem;
              cout<<"Enter element to search\n";
            elem.enter();
          if(l.search(l.root,elem)){
            cout<<"Element: "<<elem<<" exist"<<endl;

          }
        }
        if(x==4){
             point beg,end;
              cout<<"Enter element, which fits in bounds\n";
            beg.enter();
            end.enter();
          l.search_range(l.root,beg,end);
        }
        if(x==5){
            point elem;
            cout<<"Enter element to delete\n";
            elem.enter();
            l.del(elem);
        }
        if(x==6){
           l.print();
        }
    }
    }
}
}
void demo(){
    List l1;
    ArrayList l2;
    BinSearchTree l3;
    AvlTree l4;
    TwoThreeTree l5;
    int n1;
    cout<<"Creating random ordered list based on linked list\n";
    n1=rand()%30;
    cout<<"Number of elements: "<<n1<<endl;
    l1.create_random(n1);
    cout<<"List: "<<endl;
    l1.print();
    point p1;
    p1.create_random(30);
    cout<<"Adding element: "<<p1;
    l1.add_elem(p1);
    cout<<"List: \n";
    l1.print();
    p1.create_random(30);
    cout<<"Searching element: "<<p1<<endl;
    cout<<"Index: "<<l1.find_elem(p1)<<endl;
    p1.create_random(30);
    point p2;
    p2.create_random(30);
    cout<<"Searching element that fits in range: "<<p1<<" "<<p2<<endl;
    l1.find_elem_range(p1,p2);
    p1.create_random(30);
    cout<<"Deleting element: "<<p1<<endl;
    l1.del(p1);
    cout<<"Printing list\n";
    l1.print();

    cout<<"Creating random ordered list based on arraylist\n";
    n1=rand()%30;
    cout<<"Number of elements: "<<n1<<endl;
    l2.create_random(n1);
    cout<<"List: "<<endl;
    l2.print();
    p1.create_random(30);
    cout<<"Adding element: "<<p1;
    l2.add_elem(p1);
    cout<<"List: \n";
    l2.print();
    p1.create_random(30);
    cout<<"Searching element: "<<p1<<endl;
    cout<<"Index: "<<l2.find_elem(p1)<<endl;
    p1.create_random(30);
    p2.create_random(30);
    cout<<"Searching element that fits in range: "<<p1<<" "<<p2<<endl;
    l2.find_elem_range(p1,p2);
    p1.create_random(30);
    cout<<"Deleting element: "<<p1<<endl;
    l2.del(p1);
    cout<<"Printing list\n";
    l2.print();


      cout<<"Creating random ordered list based on BinSearchTree\n";
    n1=rand()%30;
    cout<<"Number of elements: "<<n1<<endl;
    l3=random_create(n1);
    cout<<"List: "<<endl;
    l3.print_in_right_order(l3.root);
    p1.create_random(30);
    cout<<"Adding element: "<<p1;
    l3.add(p1);
    cout<<"List: \n";
    l3.print_in_right_order(l3.root);
    p1.create_random(30);
    cout<<"Searching element: "<<p1<<endl;
    if(l3.search(l3.root,p1)){
        cout<<"Element: "<<p1<<" exist"<<endl;
    }
    p1.create_random(30);
    p2.create_random(30);
    cout<<"Searching element that fits in range: "<<p1<<" "<<p2<<endl;
    l3.search_range(l3.root,p1,p2);
    p1.create_random(30);
    cout<<"Deleting element: "<<p1<<endl;
    l3.del(p1,l3.root);
    cout<<"Printing list\n";
    l3.print_in_right_order(l3.root);

    cout<<"Creating random ordered list based on AvlTree\n";
    n1=rand()%30;
    cout<<"Number of elements: "<<n1<<endl;
    l4.create_random(n1);
    cout<<"List: "<<endl;
    l4.print();
    p1.create_random(30);
    cout<<"Adding element: "<<p1;
    l4.insert(p1);
    cout<<"List: \n";
    l4.print();
    p1.create_random(30);
    cout<<"Searching element: "<<p1<<endl;
     if(l4.search(p1)){
        cout<<"Element: "<<p1<<" exist"<<endl;
    }
    p1.create_random(30);
    p2.create_random(30);
    cout<<"Searching element that fits in range: "<<p1<<" "<<p2<<endl;
    l4.search_range(p1,p2);
    p1.create_random(30);
    cout<<"Deleting element: "<<p1<<endl;
    l4.del(p1);
    cout<<"Printing list\n";
    l4.print();

     cout<<"Creating random ordered list based on TwoTreeTree\n";
    n1=rand()%30;
    cout<<"Number of elements: "<<n1<<endl;
    l5.create_random(n1);
    cout<<"List: "<<endl;
    l5.print();
    p1.create_random(30);
    cout<<"Adding element: "<<p1;
    l5.insert(p1);
    cout<<"List: \n";
    l5.print();
    p1.create_random(30);
    cout<<"Searching element: "<<p1<<endl;
     if(l5.search(p1)){
        cout<<"Element: "<<p1<<" exist"<<endl;
    }
    p1.create_random(30);
    p2.create_random(30);
    cout<<"Searching element that fits in range: "<<p1<<" "<<p2<<endl;
    l5.traverse(p1,p2);
    p1.create_random(30);
    cout<<"Deleting element: "<<p1<<endl;
    l5.del(p1);
    cout<<"Printing list\n";
    l5.print();
}
void benchmark(){
const int N=30000000;
cout<<"Linked list"<<endl;
for(int n=10;n<N/50;n*=2){
cout<<"n:"<<n<<endl;
point p;
List l1;
clock_t t11=clock();
l1.create_random(n);
cout<<"Time of creating random list: "<<(clock()-t11)/1000.0<<endl;

p.create_random(n/2);
clock_t t21=clock();
l1.add_elem(p);
for(int i=0;i<n/10;i++){
    p.create_random(1000);
    l1.add_elem(p);
}
cout<<"Adding element: "<<(clock()-t21)/1000.0<<endl;
p.create_random(n/2);
clock_t t31=clock();
for(int i=0;i<n/10;i++){
    p.create_random(1000);
    l1.find_elem(p);
}

cout<<"Searching element: "<<(clock()-t31)/1000.0<<endl;
p.create_random(n/2);
clock_t t41=clock();
for(int i=0;i<n/10;i++){
    p.create_random(1000);
    l1.del(p);
}
cout<<"Deleting element: "<<(clock()-t41)/1000.0<<endl;
}
cout<<"ArrayList"<<endl;
for(int n=10;n<N;n*=2){
cout<<"n:"<<n<<endl;
point p;
ArrayList l2;
clock_t t12=clock();
l2.create_random(n);
cout<<"Time of creating random list: "<<(clock()-t12)/1000.0<<endl;

p.create_random(n/2);
clock_t t22=clock();
l2.add_elem(p);
for(int i=0;i<n/10;i++){
    p.create_random(1000);
    l2.add_elem(p);
}
cout<<"Adding element: "<<(clock()-t22)/1000.0<<endl;
p.create_random(n/2);
clock_t t32=clock();
for(int i=0;i<n/10;i++){
    p.create_random(1000);
    l2.find_elem(p);
}

cout<<"Searching element: "<<(clock()-t32)/1000.0<<endl;
p.create_random(n/2);
clock_t t42=clock();
for(int i=0;i<n/10;i++){
    p.create_random(n/2);
    l2.del(p);
}
cout<<"Deleting element: "<<(clock()-t42)/1000.0<<endl;

}
cout<<"BinarySearchTree"<<endl;
for(int n=10;n<N/10;n*=2){
cout<<"n:"<<n<<endl;
point p;
BinSearchTree l3;
clock_t t12=clock();
l3=random_create(n);
cout<<"Time of creating random list: "<<(clock()-t12)/1000.0<<endl;

p.create_random(n/2);
clock_t t22=clock();
l3.insert(l3.root,p);
for(int i=0;i<n/10;i++){
    p.create_random(n/2);
    l3.insert(l3.root,p);
}
cout<<"Adding element: "<<(clock()-t22)/1000.0<<endl;
p.create_random(n/2);
clock_t t32=clock();
for(int i=0;i<n/10;i++){
    p.create_random(n/2);
    l3.search(l3.root,p);
}

cout<<"Searching element: "<<(clock()-t32)/1000.0<<endl;
p.create_random(n/2);
clock_t t42=clock();
for(int i=0;i<n/10;i++){
    p.create_random(n/2);
    l3.del(p,l3.root);
}
cout<<"Deleting element: "<<(clock()-t42)/1000.0<<endl;

}
cout<<"AVL tree"<<endl;
for(int n=10;n<N/2;n*=2){
cout<<"n:"<<n<<endl;
point p;
AvlTree l4;
clock_t t12=clock();
l4.create_random(n);
cout<<"Time of creating random list: "<<(clock()-t12)/1000.0<<endl;

p.create_random(n/2);
clock_t t22=clock();
l4.insert(p);
for(int i=0;i<n/10;i++){
    p.create_random(1000);
    l4.insert(p);
}
cout<<"Adding element: "<<(clock()-t22)/1000.0<<endl;
p.create_random(n/2);
clock_t t32=clock();
for(int i=0;i<n/10;i++){
    p.create_random(1000);
    l4.search(p);
}

cout<<"Searching element: "<<(clock()-t32)/1000.0<<endl;
p.create_random(n/2);
clock_t t42=clock();
for(int i=0;i<n/10;i++){
    p.create_random(1000);
    l4.del(p);
}
cout<<"Deleting element: "<<(clock()-t42)/1000.0<<endl;

}
cout<<"2-3 tree"<<endl;
for(int n=10;n<N;n*=2){
cout<<"n:"<<n<<endl;
point p;
TwoThreeTree l5;
clock_t t12=clock();
l5.create_random(n);
cout<<"Time of creating random list: "<<(clock()-t12)/1000.0<<endl;

p.create_random(n/2);
clock_t t22=clock();
l5.insert(p);
for(int i=0;i<n/10;i++){
    p.create_random(1000);
    l5.insert(p);
}
cout<<"Adding element: "<<(clock()-t22)/1000.0<<endl;
p.create_random(n/2);
clock_t t32=clock();
for(int i=0;i<n/10;i++){
    p.create_random(1000);
    l5.search(p);
}

cout<<"Searching element: "<<(clock()-t32)/1000.0<<endl;
p.create_random(n/2);
clock_t t42=clock();
for(int i=0;i<n/10;i++){
    p.create_random(1000);
    l5.del(p);
}
cout<<"Deleting element: "<<(clock()-t42)/1000.0<<endl;

}
}
int main(){
srand(time(NULL));
demo();
}
