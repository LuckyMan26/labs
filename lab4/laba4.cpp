//Блок 0: Блок 1: 6 Блок 2: 7, 9 Блок 3: 14 Блок 4: 18 Блок 5:20 Блок 6: 22
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include <time.h>
using namespace std;
int statemenu;
struct node{
int data;
vector<node*> child;
node(){
data=-1;
}
node(int elem){
this->data=elem;
this->child={};
}
~node(){
    child.clear();
}
};
void print(node* root,int cur_level){
if(root==NULL){
    return;
}
else{
    cout<<cur_level<<","<<root->data<<" ";
    for(auto& n:root->child){
        print(n,cur_level+1);
    }
}
}
int num_of_child(node* n){
return n->child.size();
}

void setChild(int elem,node* root){
node* n=new node(elem);
root->child.push_back(n);
}

int height(node* root){
if(root==NULL){
    return 0;
}
else{
      int h=0;
        if (!root->child.empty()) {

            for (int i=0;i<root->child.size();i++) {
                h=max(h,height(root->child[i]));
                }
            return h + 1;

        }
        else{
              return h;
        }


}
}
void add(int elem,int min,int max,node* curr){
node* n=new node(elem);
node* temp=new node();
if(curr==NULL){
    curr=new node(elem);
    return;
}
if(num_of_child(curr)<min){
    curr->child.push_back(n);
}
else{
        if(curr->child.empty()){
            curr->child.push_back(new node(elem));
        }
        else{
        temp=curr->child[0];
    for(int i=0;i<curr->child.size();i++){
        if((num_of_child(temp))>(num_of_child(curr->child[i]))){
            temp=curr->child[i];
        }
    }
if(num_of_child(temp)<=max){
    delete n;
    add(elem,min,max,temp);
}
else if(num_of_child(curr)<=max){
    curr->child.push_back(n);
}
else{
    int len=temp->child.size();
    node* min=temp->child[0];
    for(int i=1;i<len;i++){
        if(height(min)>height(temp->child[i])){
            min=temp->child[i];
        }
    }
    setChild(elem,min);
}
}
}
}
void del(node* root,node* father,int elem){

if(root){
    if(root->data==elem){
         for(int i=0;i<father->child.size();i++){
            if(father->child[i]==root){
                father->child.erase(father->child.begin()+i);
            }
         }
        for(auto& n:root->child){
            father->child.push_back(n);
        }
      delete root;
      return;
    }
    else{
        for(auto& n:root->child){
          del(n,root,elem);
        }
    }
}
}

struct bin_node{
int data;
bin_node* left;
bin_node* right;
bin_node(){
data=-1;
this->left=nullptr;
this->right=nullptr;
}
bin_node(int elem){
this->data=elem;
this->left=nullptr;
this->right=nullptr;
}
};

void print(bin_node* root,int cur_level){
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
void insert(bin_node* root,int elem){
bin_node* n=new bin_node(elem);
if(root->data<elem){
    if(root->right){
        insert(root->right,elem);
    }
    else{
        root->right=n;
        return;
    }
}
else{
    if(root->left){
        insert(root->left,elem);
    }
    else{
        root->left=n;
        return;
    }
}
}
struct th{
int data;
th* left;
th* right;
bool l,r;
};
th* suc(th* p){
th* q=new th();
q=p->right;
if(p->r){
    while(q->l){
        q=q->left;
    }
}
return q;
}
void print(th* t){
while (t->l) {
t=t->left;
}
while (t) {
cout << t->data << ", "; t = suc(t);
}
}
th* buildo(bin_node* root,th* sl,th* sr){
th* t=new th;

t->data=root->data;
if((t->l)=(root->left!=NULL)){
    t->left=buildo(root->left,sl,t);
}
else{
    t->left=sl;
}
if((t->r)=(root->right!=NULL)){
    t->right=buildo((root->right),t,sr);
}
else{
  t->right=sr;
}
return t;
}
th* buildh(bin_node* root){
return(root?buildo(root,NULL,NULL):NULL);
}

void print_brackets(node* root){

		cout<<root->data;
		if (root->child.empty()) {  return; }
		cout<<"(";
		for(size_t i = 0; i<root->child.size(); i++) {
			if (!root->child[i]) {break;}
			print_brackets(root->child[i]);
			cout<<" ";
		}
		cout<<")";

}
void print_brackets(bin_node* root){

		std::cout<<root->data;
		if (!root->left && !root->right) { return; }
		std::cout<<"(";
		if(root->left){
            print_brackets(root->left);
            cout<<" ";
		}
		if(root->right){
            print_brackets(root->right);
            cout<<" ";
		}
		std::cout<<")";

}
struct calculator_node{
string data;
calculator_node* left;
calculator_node* right;
calculator_node(){
this->data="";
this->left=nullptr;
this->right=nullptr;
}
calculator_node(string s){
this->data=s;
this->left=nullptr;
this->right=nullptr;
}
calculator_node(string str,calculator_node* l,calculator_node* r){
this->data=str;
this->left=l;
this->right=r;
}
};
bool rightness(string a){
	bool rightness = true;
	if (a[0] == '+'||a[0] == '*'||a[0] == '/'){
        return false;
	}
	else if (a[a.length()-1]=='+'||a[a.length()-1]=='-'||a[a.length()-1]=='*'||a[a.length()-1]=='/'){
		return false;
	}
	else {
		for (int i = 0; (i < a.length()); i++) {
			if ((a[i] == '+'||a[i] == '-'||a[i] == '*'||a[i] == '/'||a[i]=='(')&&(a[i+1] == '+'||a[i+1] == '*'||a[i+1] == '/'||a[i+1]==')')){
				return false;
				}
			if((a[i] == '/')&&(a[i+1] == '0')){
				return false;
			}
		}
	}
	stack <double> stack;
	char left = '(', right = ')';
	int err = 0;
	for (int i = 0; i < a.size() && !err; ++i) {
		if (a[i] == left) stack.push(i);
		else if (a[i] == right) {
			if (stack.size() > 0) stack.pop();
			else return false;
		}
	}
	if (!err && stack.size() > 0) {
            return false;
           }

	return rightness;
}
int prior(string c){
if(c=="("){
    return 0;
   }
if(c=="+"){
    return 3;
}
if(c=="*"){
    return 2;
}
if(c=="-"){
    return 3;
}
if(c=="/"){
    return 2;
}
if(c=="^"){
    return 1;
}
return -1;
}
struct Value{
	string variable;
	int value;
};

struct Values{
	Value* values;
	std::size_t size;
	Values(std::size_t size) {
		this->size = size;
		this->values = new Value[size];
	}

};

bool IsOperator(string c)
{
if(c == "+" || c == "-" || c == "*" || c == "/" || c == "^" )
return true;
return false;
}

bool IsOperand(char c)
{
if( c >= 'A' && c <= 'Z')
return true;
if (c >= 'a' && c <= 'z')
return true;
if(c >= '0' && c <= '9')
return true;
return false;
}
string ConvertToInt(string str,int& beg){
string res="";
while(IsOperand(str[beg])){
    res+=str[beg];
    beg++;
}
beg--;
return res;
}
int precedence(char op)
{
if(op == '+' || op == '-')
return 1;
if (op == '*' || op == '/')
return 2;
if(op == '^')
return 3;
return 0;
}
bool eqlOrhigher (char op1, char op2)
{
int p1 = precedence(op1);
int p2 = precedence(op2);
if (p1 == p2)
{
if (op1 == '^' )
return false;
return true;
}
return  (p1>p2 ? true : false);
}
string postfix(string str){
stack <char> S;
string postfix ="";
char ch;
S.push( '(' );
str += ')';
string temp;
for(int i = 0; i<str.length(); i++)
{

ch = str[i];
temp=(1,ch);
if(ch == ' ')
continue;
else if(ch == '(')
S.push(ch);
else if(IsOperand(ch)){
postfix+=ConvertToInt(str,i)+" ";
}
else if(IsOperator(temp))
{
while(!S.empty() && eqlOrhigher(S.top(), ch))
{
postfix +=S.top();
postfix+=" ";
S.pop();
}
S.push(ch);
}
else if(ch == ')')
{
while(!S.empty() && S.top() != '(')
{
postfix +=S.top();
postfix+=" ";
S.pop();
}
S.pop();
}
}
return postfix;
}
vector<string> split(string str){
vector<string> s;
int beg=0;
int end=0;
for(int i=0;i<str.length();i++){
    if(str[i]==' '){
        end=i;
        s.push_back(str.substr(beg,end-beg));
        beg=i+1;
        end+=1;
        i++;
    }
}
return s;
}
calculator_node* ConvertToBinTree(string str){
stack<calculator_node*> res;
vector<string> s=split(str);

int length=s.size();
 if (str.length() == 0) {
        return nullptr;
    }
 else{
    for(int i=0;i<s.size();i++){
        if(IsOperator(s[i])){
            calculator_node* x=res.top();
            res.pop();
            calculator_node* y=res.top();
            res.pop();
            calculator_node* n= new calculator_node(s[i], y, x);
            res.push(n);
        }
        else{
            res.push(new calculator_node(s[i]));
        }
    }
 }
return res.top();
}
void print(calculator_node* root,int cur_level){
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
bool isNumber(string str)
{
    std::string::const_iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it)) ++it;
    return !str.empty() && it == str.end();
}
bool isVariale(string str){
for(int i=0;i<str.length();i++){
    if(('a'<=str[i])&&(str[i]<='z')||('A'<=str[i])&&(str[i]<='Z')){
        return true;
    }
}
return false;
}
int toInt(string s)
{

int num = 0;
if(s[0]!='-'){
    for (int i=0; i<s.length(); i++){
        num = num*10 + (int(s[i])-48);
    }
}
    else
    {
      for (int i=1; i<s.length(); i++)
        num = num*10 + (int(s[i])-48);
      num = (-1)*num;
    }
return num;
}


double eval(calculator_node* root,Values* vars=nullptr){

if (root->data=="+"){
    return eval(root->left,vars)+eval(root->right,vars);
}

else if (root->data=="-"){
    return eval(root->left,vars)-eval(root->right,vars);
}

else if (root->data=="*"){
        double left_value=eval(root->left,vars);
        if(left_value==0){
                    return 0;
        }
        else{
             return left_value*eval(root->right,vars);
        }
}
else if(root->data=="/"){
       int right_value = eval(root->right,vars);
        if(right_value==0){
            cout<<"Error.Division by 0\n";
            exit(0);
        }
        return eval(root->left,vars) / right_value;
}
else if(root->data=="^"){
       double right_value = eval(root->right,vars);
        if(right_value == 0){
        return 1;
        }
        else{
            return pow(eval(root->left,vars),right_value);
        }
}
else{
    if(vars){
        for (size_t i = 0; i < vars->size; i++) {
					Value val = vars->values[i];
					if(val.variable == root->data) {
						return val.value;
					}
				}
			}
			double value = toInt(root->data);
			return value;
		}
    }


	bool is_associative(calculator_node* root) {
		if (root->data == "+") {
			return true;
		} else if (root->data  == "-") {
			return false;
		} else if (root->data  == "*") {
			return true;
		} else if (root->data  == "/") {
			return false;
		}
		else if (root->data  == "^") {
			return false;
		}else {
			return true;
		}
	}
    string pretty_print(calculator_node* root);
	string optional_parentheses(calculator_node* root,calculator_node* child) {
		bool parents = false;
		if (prior(child->data)>prior(root->data)) {
			parents = true;
		} else if(prior(child->data)==prior(root->data)) {
			if (is_associative(child)&&(is_associative(root))) {
				parents = false;
			} else {
				parents = true;
			}
		} else {
			parents = false;
		}
		if (parents) {
			return "(" + pretty_print(child) + ")";
		} else {
			return pretty_print(child);
		}

	}
string pretty_print(calculator_node* root) {
		if (!IsOperator(root->data)>0) {
			return root->data;
		}
		return optional_parentheses(root,root->left) + root->data + optional_parentheses(root,root->right);
	}
bool is_in_vector(vector<char> v,char x){
for(int i=0;i<v.size();i++){
    if(v[i]==x){
        return true;
    }
}
return false;
}
void interactive(){
node* root=new node();
bin_node* r=new bin_node();
th* t=new th();
while(statemenu!=-1){
    cout<<"1 Create tree\n";
    cout<<"2 Add element(6 option)\n";
    cout<<"3 Print tree\n";
    cout<<"4 Delete element\n";
    cout<<"5 Create binary tree\n";
    cout<<"6 Add element to binary tree\n";
    cout<<"7 Stitched tree built using symmetrical order\n";
    cout<<"8 Print stitched tree\n";
    cout<<"9 Print binary tree\n";
    cout<<"10 Calculating mathematical expression\n";
    cout<<"-1 To exit programm\n";
    cin>>statemenu;
    if(statemenu==1){
        root->data=-2;
        for(int i=0;i<3;i++){
            root->child.push_back(new node(i));
        }
        for(int i=0;i<3;i++){
            root->child[i]->child.push_back(new node(i+3));
        }
        cout<<"Tree: \n";
        print_brackets(root);
        cout<<endl;
    }
    if(statemenu==2){

        int elem,min,max;
        cout<<"Enter element to add\n";
        cin>>elem;
        cout<<"Enter minimum number of children\n";
        cin>>min;
        cout<<"Enter maximum number of children\n";
        cin>>max;
        add(elem,min,max,root);
    }
    if(statemenu==3){
        int x;
        cout<<"1 To print tree using level form\n";
        cout<<"2 To print tree using brackets form\n";
        cin>>x;
        if(x==1){
            print(root,0);
            cout<<endl;
        }
        else{

            print_brackets(root);
            cout<<endl;
        }
    }
    if(statemenu==4){
        cout<<"Enter element to delete\n";
        int elem;
        cin>>elem;
        del(root,NULL,elem);
    }
    if(statemenu==5){
        r->data=-2;
        r->left=new bin_node(0);
        r->right=new bin_node(1);
        r->left->left=new bin_node(2);
        r->left->right=new bin_node(3);
        r->right->left=new bin_node(4);
        r->right->right=new bin_node(5);
        cout<<"Binary tree\n";
        print_brackets(r);
        cout<<endl;
    }
    if(statemenu==6){
        int elem;
        cout<<"Enter element to add\n";
        cin>>elem;
        insert(r,elem);
    }
    if(statemenu==7){
        th* t=new th();
        t=buildh(r);
    }
    if(statemenu==8){
        print(t);
    }
    if(statemenu==9){
        int x;
        cout<<"1 To print using level form\n";
        cout<<"2 To print using brackets form\n";
        cin>>x;
        if(x==1){
            print(r,0);
            cout<<endl;
        }
        if(x==2){
            print_brackets(r);
            cout<<endl;
        }
    }
    if(statemenu==10){
        string str;
        cout<<"Enter expression\n";
    cin>>str;
    while(!rightness(str)){
        cout<<"Incorrect expression. Try Again\n";
        cin>>str;
    }
    if(rightness(str)){
        int count=0;
        int x;
        vector<char> v;
        for(int i=0;i<str.length();i++){
         if(!isdigit(str[i])&&(IsOperand(str[i]))&&(!is_in_vector(v,str[i]))){
            count++;
         v.push_back(str[i]);
    }
    }
    Values* vars=new Values(count);
    for(int i=0;i<count;i++){
        cout<<"Enter value of: "<<v[i]<<endl;
        cin>>x;
        vars->values[i]={string(1,v[i]),x};
    }


        calculator_node* n=new calculator_node();
        n=ConvertToBinTree(postfix(str));
        cout<<"Expression tree: \n";
        print(n,0);
        cout<<endl;
        cout<<pretty_print(n)<<" = ";
        cout<<eval(n,vars)<<endl;

    }
    }

}
}
void demo(){
node* root=new node();
 for(int i=0;i<5;i++){
            root->child.push_back(new node(i));
        }
        for(int i=0;i<5;i++){
            root->child[i]->child.push_back(new node(i+3));
        }
        cout<<"Tree: \n";
        print_brackets(root);
        cout<<endl;
cout<<"Adding element 10, minimum number of children 0, maximum number of children 2\n";
add(10,0,2,root);
print_brackets(root);
cout<<endl;
int elem;
elem=rand()%10;
cout<<"Deleting element "<<elem<<endl;
del(root,NULL,elem);
print_brackets(root);
cout<<endl;
bin_node* r=new bin_node();
r->data=-2;
r->left=new bin_node(0);
r->right=new bin_node(1);
r->left->left=new bin_node(2);
r->left->right=new bin_node(3);
r->right->left=new bin_node(4);
r->right->right=new bin_node(5);
cout<<"Printing binary tree\n";
print_brackets(r);
cout<<endl;
int x;
x=rand()%10;
cout<<"Inserting element "<<x<<endl;
insert(r,x);
print_brackets(r);
cout<<endl;
cout<<"Building stitched tree\n";
th* t=new th();
t=buildh(r);
print(t);
cout<<endl;
cout<<"Print tree using level form and brackets form\n";
cout<<"Bracket form of binary tree\n";
print_brackets(r);
cout<<endl;
cout<<"Level form of binary tree\n";
print(r,0);
cout<<endl;
cout<<"Bracket form of tree\n";
print_brackets(root);
cout<<endl;
cout<<"Level form of tree\n";
print(root,0);
cout<<endl;
string str;
str="(x*y-5)*x+(x+y)/2";
cout<<"Expression to calculate: "<<str<<endl;

Values* vars = new Values(2);
vars->values[0] = {"x", 3};
vars->values[1] = {"y", 5};
cout<<"Value of x: 3\n";
cout<<"Value of y: 5\n";
calculator_node* n=new calculator_node();
n=ConvertToBinTree(postfix(str));
cout<<"Expression tree: \n";
print(n,0);
cout<<endl;
cout<<pretty_print(n)<<" = ";
cout<<eval(n,vars)<<endl;
}
int main(){
srand(time(0));
demo();
}
