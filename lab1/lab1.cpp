#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <ctime>
using namespace std;
int statemenu;
bool is_number(string s){
    for(int i=0;i<s.length();i++){
if(!isdigit(s[i])){
        return false;
}
}
return true;
}
bool is_number_double(string s){
    for(int i=0;i<s.length();i++){
if(!isdigit(s[i])&&s[i]!='.'){
        return false;
}
}
return true;
}
struct Time{
int day;
int month;
int year;
void print(){
    cout<<day<<"."<<month<<"."<<year;
    cout<<endl;
}
void print_in_file(){
    ofstream fout;
    fout.open("lab1.txt",ios::app);
    fout<<day<<"."<<month<<"."<<year;
    fout<<endl;
    fout.close();
}
void input(){
    string day_s,month_s,year_s;
    cout<<"Enter day (number from 1 to 31)"<<endl;
    cin>>day_s;
    while(true){
        if((is_number(day_s)&&stoi(day_s)>0&&stoi(day_s)<31)){
        day=stoi(day_s);
        break;
    }
    cout<<"Enter correct value(number from 1 to 31)\n";
    cin>>day_s;

    }

    cout<<"Enter month (number from 1 to 12)"<<endl;
    cin>>month_s;
    while(true){
        if((is_number(month_s)&&stoi(month_s)>0&&stoi(month_s)<31)){
        month=stoi(month_s);
        break;
    }
    cout<<"Enter correct value(number from 1 to 12)\n";
    cin>>month_s;
    }
    cout<<"Enter year (any number)"<<endl;
    cin>>year_s;
    year=stoi(year_s);
     while(true){
        if((is_number(year_s)&&year>0)){
        year=stoi(year_s);
        break;
    }
    cout<<"Enter correct positive value\n";
    cin>>year_s;
    }

}
void random_creation(){
year=2000+rand()%23;
month=1+rand()%12;
day=1+rand()%31;
}
bool operator <=(const Time& t){
if(year<t.year){
    return true;
}
else if(year>t.year){
    return false;
}
else{
  if(month<t.month){
    return true;
}
else if(month>t.month){
    return false;
}
else{
    if(day<t.day){
    return true;
}
else if(day>t.day){
    return false;
}
return true;
}
}
}
};

char* sub(int beg,int len,char* str){
char* sub=new char[len+1];
for(int i=beg;i<beg+len;i++){
    sub[i-beg]=str[i];
}
sub[len]='\0';
return sub;
}
Time convert_to_time(string str){
int start=0;
Time t;
int final=str.find(".");
//cout<<start<<" "<<final<<endl;
t.day=stoi(str.substr(start,final-start));
//cout<<t.day<<endl;
start=final+1;

final=str.find(".",start);

t.month=stoi(str.substr(start,final-start));
t.year=stoi(str.substr(final+1));
return t;
}
struct monster{
vector<string> name_of_monsters={"Bogeyman","Vampire","Dybbuk","Banshee","Pontianak","Zombie","Hydra","Chimera","Yeti","Dragon","Unicorn","Basilisk","Phoenix","Griffin"};
int hp;
int attack;
double probability;
string name;
int type_of_attack;
int id;
Time time_of_appearance;
void create_monster(int *cur_id){
hp=rand()%50000;
attack=rand()%2000;
probability = (double)rand() / RAND_MAX;
name=name_of_monsters[rand()%14];
type_of_attack=rand()%4;//0-counterattck,1-critical attack,2-stun,3-heal
id=*(cur_id);
time_of_appearance.random_creation();
(*cur_id)++;
}
void print(){
cout<<"ID "<<id<<endl;
cout<<"Name "<<name<<endl;
cout<<"HP "<<hp<<endl;
cout<<"Attack "<<attack<<endl;
cout<<"Type of attack "<<type_of_attack<<endl;
cout<<"Probability "<<probability<<endl;
time_of_appearance.print();
cout<<"--------------------------"<<endl;
}
void create_monster_user(int *i){
string hp_s,attack_s,probability_s,type_of_attack_s;

cout<<"Enter hp number from 1 to 50000"<<endl;
cin>>hp_s;
    while(true){
        if((is_number(hp_s)&&stoi(hp_s)>0&&stoi(hp_s)<=50000)){
        hp=stoi(hp_s);
        break;
    }
    cout<<"Enter correct value(number from 1 to 50000)\n";
    cin>>hp_s;

    }
cout<<"Enter attack number from 1 to 2000"<<endl;
cin>>attack_s;
while(true){
        if((is_number(attack_s)&&stoi(attack_s)>0&&stoi(attack_s)<=2000)){
        attack=stoi(attack_s);
        break;
    }
    cout<<"Enter correct value(number from 1 to 2000)\n";
    cin>>attack_s;

    }
cout<<"Enter probability "<<endl;
cin>>probability_s;
while(true){
        if((is_number_double(probability_s)&&stod(probability_s)>=0&&stod(probability_s)<=1)){
        probability=stod(probability_s);
        break;
    }
    cout<<"Enter correct value(number from 0 to 1)\n";
    cin>>probability_s;

    }
cout<<"Enter type of attack "<<endl;
cin>>type_of_attack_s;
while(true){
    if(is_number(type_of_attack_s)&&stoi(type_of_attack_s)>=0&&stoi(type_of_attack_s)<=3){
        type_of_attack=stoi(type_of_attack_s);
        break;
    }
    cout<<"Enter correct value(number from 0 to 3)\n";
    cin>>type_of_attack_s;
}
cout<<"Enter monster`s name"<<endl;
cin>>name;
id=*i;
cout<<"Enter time of appearance"<<endl;
time_of_appearance.input();
(*i)++;
}

void print_in_file(){
ofstream fout;
fout.open("lab1.txt",ios::app);
fout<<id<<endl;
fout<<name<<endl;
fout<<hp<<endl;
fout<<attack<<endl;
fout<<type_of_attack<<endl;
fout<<probability<<endl;
time_of_appearance.print_in_file();
fout.close();
}
void print_binary(){
ofstream bin;
bin.open("lab11.txt",ios::binary|ios::app);
bin<<hp<<" "<<attack<<" "<<probability<<" "<<name<<" "<<type_of_attack<<" "<<id<<" "<<time_of_appearance.day<<" "<<time_of_appearance.month<<" "<<time_of_appearance.year<<endl;
bin.close();
}

};
void find_monster_by_string(vector<monster> v,int show_regime){
string str;
int len=v.size();
string s;
int count=0;
if(show_regime==0){
    str="Zombie";
    for(int i=0;i<len;i++){
    s=v[i].name;
    if(str.length()<=s.length()){
        if(s.substr(s.length()-str.length(),str.length())==str){
            //cout<<"Monster that was founded"<<endl;
            //v[i].print();
            count++;
        }
    }
}
  /*if(count==0){
    //cout<<"Nothing was founded\n";
}*/
}
else if(show_regime==1){
str="Zombie";
cout<<"String that was searched"<<endl;
cout<<str<<endl;
for(int i=0;i<len;i++){
    s=v[i].name;
    if(str.length()<=s.length()){
        if(s.substr(s.length()-str.length(),str.length())==str){
            cout<<"Monster that was founded"<<endl;
            v[i].print();
            count++;
        }
    }
}
if(count==0){
    cout<<"Nothing was founded\n";
}
}
else{
  cout<<"Enter string on which name should end\n";
  cin>>str;
  for(int i=0;i<len;i++){
    s=v[i].name;
    if(str.length()<=s.length()){
        if(s.substr(s.length()-str.length(),str.length())==str){
            cout<<"Monster that was founded"<<endl;
            v[i].print();
            count++;
        }
    }
}
if(count==0){
    cout<<"Nothing was founded\n";
}
}

}
void find_monster_probability(vector<monster> v,int show_regime){
int a;
double x,y;
string s1,s2;
int count=0;
int len=v.size();
if(show_regime==0){
x=0.63;
a=1;
for(int i=0;i<len;i++){
    y=v[i].probability;
    if(y>=x&&(v[i].type_of_attack==a)){
        //cout<<"Monster that was founded"<<endl;
        //v[i].print();
        count++;
    }
    /*if(count==0){
    //cout<<"Nothing was founded\n";
}*/
}
}
else if(show_regime==1){
    x=0.63;
    a=1;
    cout<<"Min probability: "<<x<<"\tType of attack: "<<a<<endl;
    for(int i=0;i<len;i++){
    y=v[i].probability;
    if(y>=x&&v[i].type_of_attack==a){
        cout<<"Monster that was founded"<<endl;
        v[i].print();
        count++;
    }
}
if(count==0){
    cout<<"Nothing was founded\n";
}
}
else{
    cout<<"Enter type of attack and min probability(from 0 to 1) respectively\nType of attack is one word. 0-counterattack,1-crit,2-heal,3-stun\n";
    cin>>s1>>s2;
    int temp;
    while(true){
    if((is_number(s1))&&stoi(s1)<=3&&stoi(s1)>=0){
        a=stoi(s1);
       break;
    }
    cout<<"Enter correct value between 0 and 3\n";
    cin>>s1;
    }
    while(true){
    if((is_number_double(s2))&&stod(s2)<=1&&stod(s2)>=0){
       x=stod(s2);
       break;
    }
    cout<<"Enter correct value between 0 and 1\n";
    cin>>s2;
    }
   for(int i=0;i<len;i++){
    y=v[i].probability;
    if(y>=x&&(v[i].type_of_attack==a)){
        cout<<"Monster that was founded"<<endl;
        v[i].print();
        count++;
    }
}
if(count==0){
    cout<<"Nothing was founded\n";
}
}
}

void find_monster_time(vector<monster> v,int show_regime){
int len=v.size();
Time x,y,z;
int count=0;
if(show_regime==0){
x={10,12,2010};
y={5,6,2022};
for(int i=0;i<len;i++){
    z=v[i].time_of_appearance;
    if((x<=z)&&(z<=y)){
        //v[i].print();
        count++;
    }
    /*if(count==0){
    //cout<<"Nothing was founded\n";
    }*/
}
}
else if(show_regime==1){
x={10,12,2010};
y={5,6,2022};
cout<<"Intervals when monster was spawned\n";
x.print();
y.print();
for(int i=0;i<len;i++){
    z=v[i].time_of_appearance;
    if((x<=z)&&(z<=y)){
        v[i].print();
        count++;
    }

}
if(count==0){
    cout<<"Nothing was founded\n";
    }
}
else {
    cout<<"Enter time of appearance min and max respectively\n";
    x.input();
    y.input();
    while(true){
        if(x<=y){
            break;
        }
        cout<<"First date should be less then the second one";
        x.input();
        y.input();
    }
    for(int i=0;i<len;i++){
    z=v[i].time_of_appearance;
    if((x<=z)&&(z<=y)){
        v[i].print();
        count++;
    }
}
if(count==0){
    cout<<"Nothing was founded\n";
}
}
}
void menu(){

cout<<"Menu"<<endl;
cout<<"-----------------"<<endl;
cout<<"To generate monsters randomly enter 1"<<endl;
cout<<"You can find some monsters. To find them by their name enter 2. To find them by type and probability of attack type 3. To find by time of appearance type 4."<<endl;
cout<<"If you want to add monster by your own type 5"<<endl;
cout<<"If you want to delete monster enter 6"<<endl;
cout<<"If you want to end program enter 0"<<endl;
cin>>statemenu;
}

vector<monster> pass_file(){
ifstream fin;
fin.open("lab11.txt",ios::binary);
vector<monster> vec;
monster m;
while(fin>>m.hp>>m.attack>>m.probability>>m.name>>m.type_of_attack>>m.id>>m.time_of_appearance.day>>m.time_of_appearance.month>>m.time_of_appearance.year){
    vec.push_back(m);
}
fin.close();
return vec;
}
vector<monster> pass_txt_file(){
ifstream fin;
monster m;
fin.open("lab1.txt");
string str;
int count=0;
vector<monster> v;
while(!fin.eof()){
str="";
getline(fin,str);
if(count==0&&str!=""){
    m.id=stoi(str);
    count=1;
    getline(fin,str);
}
if(count==1&&str!=""){
    m.name=str;
    count=2;
    getline(fin,str);
}
if(count==2&&str!=""){
    m.hp=stoi(str);
    count=3;
    getline(fin,str);
}
if(count==3&&str!=""){
    m.attack=stoi(str);
    count=4;
    getline(fin,str);
}
 if(count==4&&str!=""){
    m.type_of_attack=stoi(str);
    count=5;
    getline(fin,str);
}
 if(count==5&&str!=""){
    m.probability=stod(str);
    count=6;
    getline(fin,str);
}
 if(count==6&&str!=""){
    m.time_of_appearance=convert_to_time(str);
    count=0;
}
v.push_back(m);
}
return v;
}

void print_binary(vector<monster> v){
ofstream bin;
bin.open("lab11.txt",ios::binary|ios::app);
for(int i=0;i<v.size();i++){
    bin<<v[i].hp<<" "<<v[i].attack<<" "<<v[i].probability<<" "<<v[i].name<<" "<<v[i].type_of_attack<<" "<<v[i].id<<" "<<v[i].time_of_appearance.day<<" "<<v[i].time_of_appearance.month<<" "<<v[i].time_of_appearance.year<<endl;
}
bin.close();
}
void clear_file(){
ofstream fout;
ofstream bin;
fout.open("lab1.txt");
bin.open("lab11.txt");
fout<<"";
bin<<"";
fout.close();
bin.close();
}
void demo(){
vector<monster> v;
monster m;
int n=100;
v=pass_file();
cout<<"Number of monsters that were spawned\n";
int cur_ind=v[v.size()-1].id+1;

for(int i=0;i<n;i++){
m.create_monster(&cur_ind);
m.print_in_file();
v.push_back(m);
}
print_binary(v);
v.clear();
v=pass_file();
find_monster_by_string(v,1);
cout<<endl;
find_monster_probability(v,1);
cout<<endl;
find_monster_time(v,1);
cout<<endl;
}
int fileSizeBin(string file) {
	ifstream mySource;
	mySource.open(file, ios_base::binary);
	mySource.seekg(0, ios_base::end);
	int size = mySource.tellg();
	mySource.close();
	return size;
}

void benchmark(){
vector<monster> v;
monster *m=new monster;
int n=819200;
int cur_ind=1;
for(int i=0;i<n;i++){
(*m).create_monster(&cur_ind);
v.push_back((*m));
//(*m).print_in_file();//to print in txt file
}
cout<<clock()/1000.0<<endl;
print_binary(v); //to print in binary file
cout<<clock()/1000.0<<endl;
v.clear();
//v=pass_txt_file(); // to pass txt file and fill vector
v=pass_file(); //to pass binary file and fill vector
cout<<clock()/1000.0<<endl;
delete m;
find_monster_by_string(v,0);
cout<<clock()/1000.0<<endl;
find_monster_probability(v,0);
cout<<clock()/1000.0<<endl;
find_monster_time(v,0);
cout<<clock()/1000.0<<endl;
cout<<fileSizeBin("lab11.txt"); //size of bin file
//cout<<fileSizeBin("lab1.txt"); //size of txt file
}
void interactive(){
vector<monster> v;
v=pass_file();
int cur_ind=v.size()>0 ? (v[v.size()-1].id+1): 1;
monster *m=new monster;
int n;
menu();
v=pass_file();
while(statemenu!=0){
if(statemenu==1){
v=pass_file();
cout<<"Cur ind "<<cur_ind<<endl;
for(int i=0;i<5;i++){
(*m).create_monster(&cur_ind);
(*m).print_in_file();
v.push_back(*m);
(*m).print_binary();
}
}
if(statemenu==2){
find_monster_by_string(v,2);
}
if(statemenu==3){
find_monster_probability(v,2);
}
if(statemenu==4){
find_monster_time(v,2);
}
if(statemenu==5){
    v=pass_file();
    int cur_ind=v.size()>0 ? (v[v.size()-1].id+1): 1;
    (*m).create_monster_user(&cur_ind);
    v.push_back(*m);
    (*m).print_in_file();
    (*m).print();
    (*m).print_binary();

}
if(statemenu==6){
    v=pass_file();
    int index;
    bool cond=false;
    cout<<"Enter index to delete\n";
    cin>>index;
    for(int i=0;i<v.size();i++){
        if(v[i].id==index){
            index=i;
            cond=true;
        }
    }
    if(!cond){
        cout<<"No such index exist. Enter valid one\n";
    }
    else{
    v.erase(v.begin()+index);
    clear_file();
for(int i=0;i<v.size();i++){
        v[i].print();
        v[i].print_in_file();
        v[i].print_binary();
    }

}
}
menu();
}
}
int main(){

srand(time(NULL));
interactive();
clear_file();
}
