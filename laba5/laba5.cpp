#include <iostream>
#include <time.h>
#include <vector>
#include <queue>
#include <algorithm>
#define INFINITY 10000
//(1,2) 7 11 14 17 19 21
int statemenu;
using namespace std;
bool is_in_vector(vector<pair<int,int>> v,pair<int,int> p){
for(int i=0;i<v.size();i++){
    if(v[i]==p){
        return true;
    }
}
return false;
}

struct ListAdj;
struct MatrixAdj;
struct edge{
int beg,end;
int weight;
bool operator <(edge& x){
if(this->weight<x.weight){
    return true;
}
else{
    return false;
}
}

};
bool is_in_vector(vector<edge> v,int beg,int end){
for(int i=0;i<v.size();i++){
    if((v[i].beg==beg)&&((v[i].beg==end))){
        return true;
    }
}
return false;
}
void print1(bool* v,int length){
for(int i=0;i<length;i++){
    cout<<v[i]<<" ";
}
cout<<endl;
}

struct node{
int data;
node* next;
int weight;
node(){
next=nullptr;
}
node(int d,int w=0){
data=d;
next=nullptr;
weight=w;
}
};

int minDist(int dist[],bool Tset[],int size){
 int minimum=INT_MAX,ind;

    for(int k=0;k<size;k++)
    {
        if(Tset[k]==false && dist[k]<=minimum)
        {
            minimum=dist[k];
            ind=k;
        }
    }
    return ind;
}
struct MatrixAdj{
int** arr;
int size;
bool is_directed=1;
ListAdj convert();
MatrixAdj(){
size=0;
is_directed=1;
arr=new int*[size];
for(int i=0;i<size;i++){
    arr[i]=new int[size];
}
for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
        arr[i][j]=0;
    }
}
}
MatrixAdj(int s,bool x=1){
size=s;
is_directed=x;
arr=new int*[size];
for(int i=0;i<size;i++){
    arr[i]=new int[size];
}
for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
        arr[i][j]=0;
    }
}
}
void add_edge(int beg,int end,int weight=0){
if(is_directed){
if(beg<size&&end<size){
        if(weight==0){
            arr[beg][end]=1;
        }
        else{
        arr[beg][end]=weight;
}
}
else{
    cout<<"Error\n";
    return;
}
}
else{
   if(beg<size&&end<size){
         if(weight==0){
            arr[beg][end]=1;
            arr[end][beg]=1;
        }
        else{
        arr[beg][end]=weight;
        arr[end][beg]=weight;
}
}
else{
    cout<<"Error\n";
    return;
}
}
}
void create_random(int vertixe,int edge){

this->size=vertixe;
int beg,end;
int weight;
for(int i=0;i<edge;i++){
    beg=rand()%vertixe;
    end=rand()%vertixe;
    while(arr[beg][end]==1||beg==end){
        beg=rand()%vertixe;
        end=rand()%vertixe;
    }
    weight=1+rand()%10;
    add_edge(beg,end,weight);
}


}

void print(){
for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
            if(arr[i][j]>0){
                    if(arr[i][j]==1){
                        cout<<i<<" "<<j<<" weight: 0"<<endl;
                    }
                    if(arr[i][j]>1){
                        cout<<i<<" "<<j<<" weight: "<<arr[i][j]<<endl;
                    }
            }
    }
}
}
bool foo(int index,bool* visited,int parent=-1){
visited[index]=true;

for (int i=0;i<size;i++)
	{
	    if(arr[index][i]){
		if (!visited[i])
			foo(i,visited,index);
		else if(i != parent)
		{
			return false;
		}
	    }
	}
	return true;
}

void DFS(int index,bool* visited,bool regime,int version=1){
if(regime){
if(version==1){
visited[index]=true;
cout<<index<<" ";
for(int i=0;i<size;i++){
    if(arr[index][i]){
    if(!visited[i]){
        DFS(i,visited,regime);

    }
    }

}
}
if(version==0){
visited[index]=true;
cout<<index<<" ";
vector<int> v;
for(int i=0;i<size;i++){
        if(arr[index][i]){
           v.push_back(i);
        }
    }
if(v.size()!=0){
    for(int i=0;i<v.size()-1;i++){
    for(int j=0;j<v.size()-i-1;j++){
        if(arr[index][v[j]]>arr[index][v[j+1]]){
            swap(v[j],v[j+1]);
        }
    }
}
for(int i=0;i<v.size();i++){
    if(!visited[v[i]]){
        DFS(v[i],visited,0);
    }
}
}
}
}
else{
    if(version==1){
visited[index]=true;
//cout<<index<<" ";
for(int i=0;i<size;i++){
    if(arr[index][i]){
    if(!visited[i]){
        DFS(i,visited,regime);

    }
    }

}
}
if(version==0){
visited[index]=true;
//cout<<index<<" ";
vector<int> v;
for(int i=0;i<size;i++){
        if(arr[index][i]){
           v.push_back(i);
        }
    }
if(v.size()!=0){
    for(int i=0;i<v.size()-1;i++){
    for(int j=0;j<v.size()-i-1;j++){
        if(arr[index][v[j]]>arr[index][v[j+1]]){
            swap(v[j],v[j+1]);
        }
    }
}
for(int i=0;i<v.size();i++){
    if(!visited[v[i]]){
        DFS(v[i],visited,0);
    }
}
}
}
}
}
void dist(int start,int* distance){
bool* visited=new bool[size];
for(int i=0;i<size;i++){
    distance[i]=INFINITY;
    visited[i]=false;
}

distance[start]=0;
for(int i=0;i<size-1;i++){
    int m=minDist(distance,visited,size);
    visited[m]=true;
    for(int j=0;j<size;j++){
        while(!visited[j]&&arr[m][j]&&distance[m]!=INFINITY&&distance[m]+arr[m][j]<distance[j]){
            distance[j]=distance[m]+arr[m][j];
        }
    }
}
}
void Kahn(bool regime){
if(regime){
vector<int> v(size,0);
for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
        if(arr[i][j]){
        v[j]++;
        }
    }
}
int count=0;
queue<int> q;

for(int i=0;i<size;i++){
    if(v[i]==0){
        q.push(i);
    }
}

vector<int> top_order;

    while (!q.empty()) {

        int u = q.front();
        q.pop();
        top_order.push_back(u);

        for(int i=0;i<size;i++){
                if(arr[u][i]){
            if(--v[i]==0){
                q.push(i);
            }
        }
        }
        count++;


    }
    if (count != size) {
        cout << "There exists a cycle in the graph\n";
        return;
    }

    for (int i = 0; i < top_order.size(); i++)
        cout << top_order[i] << " ";
    cout << endl;
}
else{
    vector<int> v(size,0);
for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
        if(arr[i][j]){
        v[j]++;
        }
    }
}
int count=0;
queue<int> q;

for(int i=0;i<size;i++){
    if(v[i]==0){
        q.push(i);
    }
}

vector<int> top_order;

    while (!q.empty()) {

        int u = q.front();
        q.pop();
        top_order.push_back(u);

        for(int i=0;i<size;i++){
                if(arr[u][i]){
            if(--v[i]==0){
                q.push(i);
            }
        }
        }
        count++;


    }
    if (count != size) {
        cout << "There exists a cycle in the graph\n";
        return;
    }

    for (int i = 0; i < top_order.size(); i++){}
        //cout << top_order[i] << " ";
    //cout << endl;
}
}
bool is_acyclic(){
if(is_directed){
vector<int> v(size,0);
for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
        if(arr[i][j]){
        v[j]++;
        }
    }
}
int count=0;
queue<int> q;

for(int i=0;i<size;i++){
    if(v[i]==0){
        q.push(i);
    }
}

vector<int> top_order;

    while (!q.empty()) {

        int u = q.front();
        q.pop();
        top_order.push_back(u);

        for(int i=0;i<size;i++){
                if(arr[u][i]){
            if(--v[i]==0){
                q.push(i);
            }
        }
        }
        count++;

    }
    if (count != size) {
        cout << "There exists a cycle in the graph\n";
        return false;
    }
return true;

}
else{
bool* visited=new bool[size];
for(int i=0;i<size;i++){
    if(!foo(i,visited)){
        return false;
    }
    for(int j=0;j<size;j++){
        visited[j]=false;
    }
}
return true;
}
}
void Spanning_tree(MatrixAdj res,int index,bool* visited){
visited[index]=true;
for(int i=0;i<size;i++){
    if(arr[index][i]){
    if(!visited[i]){
        res.add_edge(index,i,arr[index][i]);
        Spanning_tree(res,i,visited);

    }
    }
}

}
MatrixAdj SpTr(){
MatrixAdj res(size,0);
bool* visited=new bool[size];
for(int i=0;i<size;i++){
    if(!visited[i]){
        Spanning_tree(res,i,visited);
    }
}
return res;
}
void delete_edge(int beg,int end){
if(is_directed){
    arr[beg][end]=0;
}
else{
        arr[beg][end]=0;
        arr[end][beg]=0;

}
}
MatrixAdj Kruskal(){
vector<edge> v;
for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
        if(arr[i][j]>0&&(!is_in_vector(v,i,j)&&(!is_in_vector(v,j,i)))){
        v.push_back({i,j,arr[i][j]});
    }
    }
}

sort(v.begin(),v.end());

MatrixAdj res(size,0);

while(!v.empty()){
    res.add_edge(v[0].beg,v[0].end,v[0].weight);
    //res.print();
    if(!res.is_acyclic()){
        res.delete_edge(v[0].beg,v[0].end);
    }
    v.erase(v.begin());
}
return res;
}
int weight(){
int res;
for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
        if(arr[i][j]){
            res+=arr[i][j];
        }
    }
}
return (res/2);
}
};
struct ListAdj{
int size;
node** arr;
bool is_directed;
ListAdj(){
size=0;
is_directed=1;
arr=new node*[size];
for(int i=0;i<size;i++){
    arr[i]=nullptr;
}
}
ListAdj(int s,bool x=1){
size=s;
is_directed=x;
arr=new node*[size];
for(int i=0;i<size;i++){
    arr[i]=nullptr;
}
}

void add_edge(int beg,int end,int weight=0){
node* temp=new node();
if(is_directed){
if(beg<size&&end<size){
    temp=arr[beg];
    if(temp){
    while(temp->next){
       temp=temp->next;
    }
    node* tmp=new node(end,weight);
    temp->next=tmp;
    }
    else{
            arr[beg]=new node(end,weight);
    }
}
}
else{
    if(beg<size&&end<size){
    temp=arr[beg];
    if(temp){
    while(temp->next){
       temp=temp->next;
    }
    node* tmp=new node(end,weight);
    temp->next=tmp;
    }
    else{
            arr[beg]=new node(end,weight);
    }
      temp=arr[end];
      if(temp){
    while(temp->next){
       temp=temp->next;
    }
    node* tmp=new node(beg,weight);
    temp->next=tmp;
    }
    else{
            arr[end]=new node(beg,weight);
    }
}
}
}
void print(){
node* temp=new node();
for(int i=0;i<size;i++){
    temp=arr[i];
    while(temp){
        cout<<i<<" "<<temp->data<<" weight: "<<temp->weight<<endl;
        temp=temp->next;
    }
}
}
MatrixAdj convert(){
MatrixAdj g(this->size,this->is_directed);
node* temp=new node();
for(int i=0;i<size;i++){
    if(arr[i]){
        temp=arr[i];
        while(temp){
            g.arr[i][temp->data]=temp->weight+1;
            temp=temp->next;
        }
    }
}
return g;
}
void random_creation(int vertixes,int edge){
this->size=vertixes;
int beg,end;
vector<pair<int,int>> v;
if(is_directed){
for(int i=0;i<edge;i++){
    beg=rand()%vertixes;
    end=rand()%vertixes;
    while(is_in_vector(v,{beg,end})&&(beg==end)){
        beg=rand()%vertixes;
        end=rand()%vertixes;
    }
    v.push_back({beg,end});
}
}
else{
    for(int i=0;i<edge;i++){
    beg=rand()%vertixes;
    end=rand()%vertixes;
    while(is_in_vector(v,{beg,end})||(is_in_vector(v,{end,beg}))||(beg==end)){
        beg=rand()%vertixes;
        end=rand()%vertixes;
    }
    v.push_back({beg,end});
}
}

node* temp=new node();
int weight;
for(int i=0;i<v.size();i++){
        weight=1+rand()%10;
    this->add_edge(v[i].first,v[i].second,weight);
}
}
void DFS(int index,bool* visited,bool regime,int version=1){
if(regime){
if(version==1){
node* temp=new node();
temp=arr[index];
visited[index]=true;
cout<<index<<" ";
while(temp){
    if(!visited[temp->data]){
        DFS(temp->data,visited,true,1);

    }
        temp=temp->next;
}
}
if(version==0){
node* temp=new node();
temp=arr[index];
visited[index]=true;
vector<node*> v;
cout<<index<<" ";
while(temp){
        v.push_back(temp);
        temp=temp->next;
}
if(v.size()!=0){
    for (int i=0;i<v.size()-1;i++){
    for (int j=0;j<v.size()-i-1;j++){
            if ((v[j]->weight)>(v[j+1]->weight)){
                swap(v[j],v[j+1]);
            }
}
}
for(int i=0;i<v.size();i++){
    if(!visited[v[i]->data]){
        DFS(v[i]->data,visited,true,0);
    }
}
}

}
}
if(!regime){
if(version==1){
node* temp=new node();
temp=arr[index];
visited[index]=true;
//cout<<index<<" ";
while(temp){
    if(!visited[temp->data]){
        DFS(temp->data,visited,false,1);

    }
        temp=temp->next;
}
}
if(version==0){
node* temp=new node();
temp=arr[index];
visited[index]=true;
vector<node*> v;
//cout<<index<<" ";
while(temp){
        v.push_back(temp);
        temp=temp->next;
}
if(v.size()!=0){
    for (int i=0;i<v.size()-1;i++){
    for (int j=0;j<v.size()-i-1;j++){
            if ((v[j]->weight)>(v[j+1]->weight)){
                swap(v[j],v[j+1]);
            }
}
}
for(int i=0;i<v.size();i++){
    if(!visited[v[i]->data]){
        DFS(v[i]->data,visited,false,0);
    }
}
}

}
}
}
void dist(int start,int* distance){

bool* visited=new bool[size];
for(int i=0;i<size;i++){
    distance[i]=INFINITY;
    visited[i]=false;
}
node* temp=new node();
distance[start]=0;
for(int i=0;i<size-1;i++){
    int m=minDist(distance,visited,size);
    visited[m]=true;
    temp=arr[m];

    while(temp){
        while(!visited[temp->data]&&distance[m]!=INFINITY&&(distance[m]+temp->data+temp->weight<distance[temp->data])){
                if(temp->weight>0){
            distance[temp->data]=distance[m]+temp->weight;
                }
                else{
                    distance[temp->data]=distance[m]+1;

                }
        }
        temp=temp->next;
    }
}

}
void Kahn(bool regime){
if(regime){
vector<int> v(size,0);
node* temp=new node();
for(int i=0;i<size;i++){
    temp=arr[i];
    while(temp){
        v[temp->data]++;
        temp=temp->next;
    }
}

int count=0;
queue<int> q;
for(int i=0;i<size;i++){
    if(v[i]==0){
        q.push(i);
    }
}
vector<int> top_order;

    while (!q.empty()) {

        int u = q.front();
        q.pop();
        top_order.push_back(u);
        temp=arr[u];

        while(temp){
            if(--v[temp->data]==0){
                q.push(temp->data);
            }
        temp=temp->next;
        }
        count++;


    }
    if (count != size) {
        cout << "There exists a cycle in the graph\n";
        return;
    }

    for (int i = 0; i < top_order.size(); i++)
        cout << top_order[i] << " ";
    cout << endl;
}
else{
    vector<int> v(size,0);
node* temp=new node();
for(int i=0;i<size;i++){
    temp=arr[i];
    while(temp){
        v[temp->data]++;
        temp=temp->next;
    }
}

int count=0;
queue<int> q;
for(int i=0;i<size;i++){
    if(v[i]==0){
        q.push(i);
    }
}
vector<int> top_order;

    while (!q.empty()) {

        int u = q.front();
        q.pop();
        top_order.push_back(u);
        temp=arr[u];

        while(temp){
            if(--v[temp->data]==0){
                q.push(temp->data);
            }
        temp=temp->next;
        }
        count++;


    }
    if (count != size) {
        cout << "There exists a cycle in the graph\n";
        return;
    }

    for (int i = 0; i < top_order.size(); i++){
        //cout << top_order[i] << " ";
    }
   // cout << endl;
}
}
bool isCyclicUtil(int v, bool visited[], int parent)
{
    visited[v] = true;

    node* temp=new node();
    temp=arr[v];
    while(temp)
    {

        if (!visited[temp->data])
        {
           if (isCyclicUtil(temp->data, visited, v))
              return true;
        }

        else if (temp->data != parent)
           return true;
        temp=temp->next;
    }
    return false;
}
bool is_acyclic(){
if(is_directed){
vector<int> v(size,0);
node* temp=new node();
for(int i=0;i<size;i++){
    temp=arr[i];
    while(temp){
        v[temp->data]++;
        temp=temp->next;
    }
}

int count=0;
queue<int> q;
for(int i=0;i<size;i++){
    if(v[i]==0){
        q.push(i);
    }
}

    while (!q.empty()) {

        int u = q.front();
        q.pop();
        temp=arr[u];

        while(temp){
            if(--v[temp->data]==0){
                q.push(temp->data);
            }
        temp=temp->next;
        }
        count++;


    }
    if (count != size) {
        return false;
    }

    return true;
}
else{
    bool *visited = new bool[size];
    for (int i = 0; i < size; i++)
        visited[i] = false;

        for (int i = 0; i<size; i++)
    {
        if (!visited[i])
          if (isCyclicUtil(i, visited, -1))
             return false;
    }
    return true;
}
}
void Spanning_tree(ListAdj res,int index,bool* visited){
node* temp=new node();
temp=arr[index];
visited[index]=true;
while(temp){
    if(!visited[temp->data]){
        //cout<<temp->data<<" ";
        res.add_edge(index,temp->data,temp->weight);
        Spanning_tree(res,temp->data,visited);

    }
        temp=temp->next;

}
}
ListAdj SpTr(){
    ListAdj res(size,0);
bool* visited=new bool[size];
for(int i=0;i<size;i++){
    if(!visited[i]){
        Spanning_tree(res,i,visited);
    }
}
return res;
}
void delete_edge(int beg,int end){
node* temp=new node();
node* prev=new node();
temp=arr[beg];
while(temp->data!=end){
    prev=temp;
    temp=temp->next;
}
if(temp->next){
    prev->next=temp->next;
    delete temp;
}
else{
    prev->next=nullptr;
}
}
ListAdj Kruskal(){

node* temp=new node();

vector<edge> v;

for(int i=0;i<size;i++){
    temp=arr[i];
    while(temp){
        if((!is_in_vector(v,i,temp->data))&&((!is_in_vector(v,temp->data,i)))){
        v.push_back({i,temp->data,temp->weight});
    }
    temp=temp->next;


}
}

sort(v.begin(),v.end());

ListAdj res(size,0);

while(!v.empty()){
    res.add_edge(v[0].beg,v[0].end,v[0].weight);
    if(!res.is_acyclic()){
        res.delete_edge(v[0].beg,v[0].end);
    }
    v.erase(v.begin());
}
return res;
}
int weight(){
node* temp=new node();
vector<edge> v;
for(int i=0;i<size;i++){
    temp=arr[i];
    while(temp){
        v.push_back({i,temp->data,temp->weight});
        temp=temp->next;
    }
}

for(int i=0;i<v.size();i++){
    for(int j=i+1;j<v.size();j++){
        if((v[i].beg==v[j].end)&&(v[i].end==v[j].beg)){
            v.erase(v.begin()+j);
        }
    }
}
int sum=0;
for(int i=0;i<v.size();i++){
    sum+=v[i].weight;
}
return sum;
}
};
ListAdj MatrixAdj::convert(){
node* temp=new node();
node* tmp=new node();
ListAdj g(this->size,this->is_directed);
for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
       temp=g.arr[i];
        if(arr[i][j]){
        if(temp){
         while(temp->next){
            temp=temp->next;
         }
         tmp=new node(j,arr[i][j]);
         temp->next=tmp;
        }
        else{

            g.arr[i]=new node(j,arr[i][j]);
        }

        }
    }
}
return g;
}
void interactive(){

int v,e;
int x;
bool is_directed;


    cout<<"Enter number of vertexes in graph built using list of adjacency\n";
    cin>>v;
    cout<<"Enter number of edges in graph\n";
    cin>>e;
    cout<<"Enter whether graph is directed\n";
    cin>>is_directed;
    ListAdj g(v,is_directed);
    g.random_creation(v,e);
    cout<<"Graph is created\n";


    cout<<"Enter number of vertexes in graph built using matrix of adjacency\n";
    cin>>v;
    cout<<"Enter number of edges in graph\n";
    cin>>e;
    cout<<"Enter whether graph is directed\n";
    cin>>is_directed;
    MatrixAdj g1(v,is_directed);
    g1.create_random(v,e);
    cout<<"Graph is created\n";


while(statemenu!=-1){
cout<<"1 Convert list of adjacency to matrix of adjacency\n";
cout<<"2 Convert matrix of adjacency to list of adjacency\n";
cout<<"3 Adding edge to the graph\n";
cout<<"4 Print graph\n";
cout<<"5 Checking if graph is cyclic\n";
cout<<"6 DFS\n";
cout<<"7 Finding minimal path\n";
cout<<"8 Kahn algorithm\n";
cout<<"9 Building Spanning tree\n";
cout<<"10 Building Minimal Spanning tree\n";
cin>>statemenu;

 if(statemenu==1){
    g1=g.convert();

}
else if(statemenu==2){
    g=g1.convert();

}
else if(statemenu==3){
    cout<<"1 To add edge to graph built using adjacency list\n";
    cout<<"2 To add edge to graph built using matrix of adjacency\n";
    cin>>x;
    if(x==1){
            if(g.is_directed){
        int start;
        cout<<"Enter start vertex\n";
        cin>>start;
        int end;
        cout<<"Enter end vertex\n";
        cin>>end;
        int w;
        cout<<"Enter weight of the edge\n";
        cin>>w;
        g.add_edge(start,end,w);
    }
    else{
        int start;
        cout<<"Enter start vertex\n";
        cin>>start;
        int end;
        cout<<"Enter end vertex\n";
        cin>>end;
        g.add_edge(start,end);
    }
    }
    else if(x==2){
            if(g1.is_directed){
        int start;
        cout<<"Enter start vertex\n";
        cin>>start;
        int end;
        cout<<"Enter end vertex\n";
        cin>>end;
        int w;
        cout<<"Enter weight of the edge\n";
        cin>>w;
        g1.add_edge(start,end,w);
    }
    else{
        int start;
        cout<<"Enter start vertex\n";
        cin>>start;
        int end;
        cout<<"Enter end vertex\n";
        cin>>end;
        g1.add_edge(start,end);
    }
    }
}
else if(statemenu==4){
    cout<<"1 To print graph based on matrix of adjacency\n";
    cout<<"2 To print graph based on list of adjacency\n";
    cin>>x;
    if(x==1){

        g1.print();
    }
    else{
        g.print();
    }
}
else if(statemenu==5){
    cout<<"1 To check wether graph based on matrix of adjacency\n";
    cout<<"2 To check wether graph based on list of adjacency\n";
    cin>>x;
    if(x==1){
        if(g1.is_acyclic()){
            cout<<"It is acyclic\n";
        }
        else{
            cout<<"Graph contains cycle\n";
        }
    }
    else{
        if(g.is_acyclic()){
            cout<<"It is acyclic\n";
        }
        else{
            cout<<"Graph contains cycle\n";
        }
    }
}
else if(statemenu==6){
    cout<<"1 To do DFS in the graph based on matrix of adjacency\n";
    cout<<"2 To do DFS in the graph based on list of adjacency\n";
    cin>>x;
    if(x==1){
        int s;
        cout<<"Enter start vertex\n";
        cin>>s;
        int verse;
        cout<<"Enter in which order edges should be traversed(1 to be traversed in any order,0 to be traversed in order f increasing weights\n";
        cin>>verse;
        bool* visited=new bool[g1.size];
        g1.DFS(s,visited,verse);
    }
    else{
        int s;
        cout<<"Enter start vertex\n";
        cin>>s;
        int verse;
        cout<<"Enter in which order edges should be traversed(1 to be traversed in any order,0 to be traversed in order f increasing weights\n";
        cin>>verse;
        bool* visited=new bool[g.size];
        g.DFS(s,visited,verse);
    }
}
else if(statemenu==7){
    int* distance=new int[g1.size];
    cout<<"1 To find minimal path in the graph based on matrix of adjacency\n";
    cout<<"2 To find minimal path in the graph based on list of adjacency\n";
    cin>>x;
    if(x==1){
        int y,z;
        int temp;
        cout<<"1 To find minimal path between two vertexes\n";
        cout<<"2 To find minimal path between fixed vertex and all others\n";
        cout<<"3 To find minimal path between any two vertexes\n";
        cin>>temp;
        if(temp==1){
        cout<<"Enter first\n";
        cin>>y;
        cout<<"Enter second\n";
        cin>>z;
        g1.dist(y,distance);
        cout<<"Distance: "<<distance[z];
        }
        else if(temp==2){
        cout<<"Enter first\n";
        cin>>y;

        g1.dist(y,distance);
        for(int i=0;i<g1.size;i++){
            cout<<"Distance between "<<y<<" and "<<i<<" = "<<distance[i]<<endl;
        }
        }
        else if(temp==3){

        for(int i=0;i<g1.size;i++){
        g1.dist(y,distance);
        for(int j=0;j<g1.size;j++){
            cout<<"Distance between "<<i<<" and "<<j<<" = "<<distance[i]<<endl;
        }
        }
        }
    }

}
else if(statemenu==8){
    int x;
    cout<<"1 To do Kahn algorithm in the graph based on matrix of adjacency\n";
    cout<<"2 To do Kahn algorithm in the graph based on list of adjacency\n";
    cin>>x;
    if(x==1){
            if(!g1.is_directed){
                cout<<"It can`t be topologically sorted\n";
            }
            else{
                 g1.Kahn(true);
            }

    }
    if(x==2){
            if(!g.is_directed){
                cout<<"It can`t be topologically sorted\n";
            }
    else{
        g.Kahn(true);
    }

    }
}
else if(statemenu==9){
    int x;
    cout<<"1 To build spanning tree in the graph based on matrix of adjacency\n";
    cout<<"2 To build spanning tree in the graph based on list of adjacency\n";
    cin>>x;
    if(x==1){
       if(g1.is_directed){
        cout<<"Can`t build spanning tree,because graph is directed\n";
       }
       else{
        MatrixAdj res(g1.size,0);
        res=g1.SpTr();
       cout<<"Result: \n";
       res.print();
       cout<<"Weight of Spanning tree: "<<res.weight()<<endl;
       }
    }
    if(x==2){
        if(g.is_directed){
        cout<<"Can`t build spanning tree, because graph is directed\n";
       }
    else{
        ListAdj res(g.size,0);
        res=g.SpTr();
       cout<<"Result: \n";
       res.print();
       cout<<"Weight of Spanning tree: "<<res.weight();
    }
    }
}
else if(statemenu==10){
     int x;
    cout<<"1 To build minimal spanning tree using Kruskal`s in the graph based on matrix of adjacency\n";
    cout<<"2 To build minimal spanning tree using Kruskal`s in the graph based on list of adjacency\n";
    cin>>x;
    if(x==1){
       if(g1.is_directed){
            cout<<"Can`t build spanning tree, because graph is directed\n";
            }
       else{

        MatrixAdj res1(g1.size,0);
        res1=g1.Kruskal();
       cout<<"Result: \n";
       res1.print();
       cout<<"Weight of Spanning tree: "<<res1.weight();
       }
    }
    if(x==2){
        if(g.is_directed){
        cout<<"Can`t build spanning tree, because graph is directed\n";
       }
    else{
       ListAdj res2(g.size,0);
       res2=g.Kruskal();
       cout<<"Result: \n";
       res2.print();
       cout<<"Weight of Spanning tree: "<<res2.weight();
    }
    }
}
}
}
void demo(){

int size1,size2;
size1=1+rand()%20;
size2=1+rand()%20;

bool* visited1=new bool[size1];
bool* visited2=new bool[size2];
bool x1,x2,x3,x4;
int edges1,edges2;
x1=rand()%2;
x2=rand()%2;
edges1=1+rand()%(size1);
edges2=1+rand()%(size2);
if(edges1>(size1)*(size1-1)/2){
    edges1=(size1)*(size1-1)/2;
}
if(edges2>(size2)*(size2-1)/2){
    edges2=(size2)*(size2-1)/2;
}
cout<<"Number of vertexes in adjacency list: "<<size1<<" Is directed: "<<x1<<" Number of edges: "<<edges1<<endl;
cout<<"Number of vertexes in adjacency matrix: "<<size2<<" Is directed: "<<x2<<" Number of edges: "<<edges2<<endl;

ListAdj g(size1,x1);
MatrixAdj g1(size2,x2);
g.random_creation(size1,edges1);
g1.create_random(size2,edges2);
cout<<"Graph build using adjacency list: "<<endl;
g.print();
cout<<endl;
cout<<"Graph build using matrix of adjacency: "<<endl;
g1.print();
cout<<endl;
int start1,start2;
start1=rand()%size1;
start2=rand()%size2;
x3=rand()%2;
x4=rand()%2;
cout<<"Checking if graph build using list of adjacency is acyclic: \n";
if(g.is_acyclic()){
    cout<<"It is acyclic\n";
}
else{
        cout<<"It contains cycles\n";

}
cout<<"Checking if graph build using matrix of adjacency is acyclic: \n";
if(g1.is_acyclic()){
    cout<<"It is acyclic\n";
}
else{
        cout<<"It contains cycles\n";

}
cout<<"DFS: \n";
cout<<"Start of the DFS in graph build using list of adjacency : "<<start1<<endl;
cout<<"Order of traversing vertexes(0 increasing weight of edges,1 random order): "<<x3<<endl;
g.DFS(start1,visited1,x3);
cout<<endl;
cout<<"Start of the DFS in graph build using matrix of adjacency: "<<start2<<endl;
cout<<"Order of traversing vertexes(0 increasing weight of edges,1 random order): "<<x4<<endl;
g1.DFS(start2,visited2,x4);
int s1,s2,e1,e2;
s1=rand()%size1;
s2=rand()%size2;
e1=rand()%size1;
e2=rand()%size2;
cout<<"Distance between two vertexes in graph 1: "<<s1<<" "<<e1<<" = ";
int* d1=new int[size1];
int* d2=new int[size2];
g.dist(s1,d1);
cout<<d1[e1]<<endl;
cout<<"Distance between two vertexes in graph 2: "<<s2<<" "<<e2<<" = ";

g1.dist(s2,d2);
cout<<d2[e2]<<endl;
cout<<"Kahn`s algorithm for graph1: \n";
g.Kahn(true);
cout<<"Kahn`s algorithm for graph2: \n";
g1.Kahn(true);
ListAdj res1(size1,0);
MatrixAdj res2(size2,0);

if(!g.is_directed){
    res1=g.SpTr();
    cout<<"Result: \n";
    res1.print();
    cout<<"Weight: "<<res1.weight()<<endl;
}
else if(g.is_directed){
    cout<<"Graph g1 is directed. Can`t build spanning tree\n";
}
if(!g1.is_directed){
    res2=g1.SpTr();
    cout<<"Result: \n";
    res2.print();
    cout<<"Weight: "<<res2.weight()<<endl;
}
else if(g1.is_directed){
    cout<<"Graph g2 is directed. Can`t build spanning tree\n";
}
cout<<"Minimal spanning tree using Kruskal`s algorithm\n";
ListAdj r1(size1,0);
MatrixAdj r2(size2,0);
if(!g.is_directed){
    r1=g.Kruskal();
    r1.print();
}
else{
        cout<<"Graph is directed. Can`t build spanning tree\n";

}
if(!g1.is_directed){
    r2=g1.Kruskal();
    r2.print();
}
else{
        cout<<"Graph is directed. Can`t build spanning tree\n";

}

}
void benchmark(){
int n=1000;
int edges=rand()%n;
MatrixAdj g(n,0);
MatrixAdj g1(n,1);
ListAdj G(n,0);
ListAdj G1(n,1);
g.create_random(n,edges);
g1.create_random(n,edges);
G.random_creation(n,edges);
G1.random_creation(n,edges);
clock_t t1=clock();
g.is_acyclic();
cout<<(clock()-t1)/1000.0<<endl;
clock_t t2=clock();
G.is_acyclic();
cout<<(clock()-t2)/1000.0<<endl;
clock_t t3=clock();
int index;
index=rand()%n;
bool* visited1=new bool[n];
g.DFS(index,visited1,false);
cout<<(clock()-t3)/1000.0<<endl;
clock_t t4=clock();
bool* visited2=new bool[n];
G.DFS(index,visited2,false);
cout<<(clock()-t4)/1000.0<<endl;
int* d1=new int[n];
int* d2=new int[n];
clock_t t5=clock();
g.dist(index,d1);
cout<<(clock()-t5)/1000.0<<endl;
clock_t t6=clock();
G.dist(index,d2);
cout<<(clock()-t6)/1000.0<<endl;
clock_t t7=clock();
g1.Kahn(false);
cout<<(clock()-t7)/1000.0<<endl;
clock_t t8=clock();
G1.Kahn(false);
cout<<(clock()-t8)/1000.0<<endl;
clock_t t9=clock();
g1.SpTr();
cout<<(clock()-t9)/1000.0<<endl;
clock_t t10=clock();
G1.SpTr();
cout<<(clock()-t10)/1000.0<<endl;
clock_t t11=clock();
//g.Kruskal();
//cout<<(clock()-t11)/1000.0<<endl;
clock_t t12=clock();
G.Kruskal();
cout<<(clock()-t12)/1000.0<<endl;
}
int main(){
srand(time(NULL));
demo();
}
