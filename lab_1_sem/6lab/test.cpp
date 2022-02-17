#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

string Spaces(int n){
    string s = "";
    for(int i=0; i<n;i++) {
            s += " ";
    }
    return s;
}
string getLine(vector<string>& words, int start, int end, int letterCount, int maxWidth){
    string res = words[start];
    int spaces = maxWidth - letterCount;
    if(start == end){
        res += Spaces(spaces);
        return res;
    }
    int numOfSpace = spaces/(end-start);
    int extraOne = spaces%(end-start);
    string space0 = Spaces(numOfSpace);
    string space1 = space0 + " ";
    for(int i= 0; i< end-start; i++){
        res  = res + (i < extraOne? space1: space0) + words[start + 1 + i];
    }
    return res;
}

vector<string> justify(vector<string>& words, int maxWidth) {
    int N = words.size();
    int i = 0, j = 0;
    int counter = 0;
    vector<string> res;
    while(i<N && j<N){
        int len = words[j].length();
        counter += len;
        if(counter + j - i > maxWidth){
            counter -= len;
            res.push_back(getLine(words, i, j-1, counter, maxWidth));
            i = j;
            counter = 0;
        }else{
            j++;
        }
    }
    if(counter){
        string last = words[i];
        for(int x=i+1; x < j; x++) last = last + " " + words[x];
        last = last + Spaces(maxWidth - last.size());
        res.push_back(last);
    }

    return res;
}
vector<string> splitString(string str)
{
    vector<string> res;
    int start = 0;
    int end = str.find(" ");
    while (end != -1) {
        res.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(" ", start);
    }
    res.push_back(str.substr(start, end - start));
    return res;
}
int main(){
    ifstream fin;
    ofstream fout;
    fout.open("output.txt");
    char ch;
    fin.open("input.txt");
    string str;
    vector<string> words;
    vector<string> line;
    string s = "";
    string word="";
    vector<string> lines;
    while(!fin.eof()){
        str="";
        getline(fin,str);
        words=splitString(str);

        line=justify(words,50);
       // cout<<str<<endl;
        for(auto x:line){
        cout<<x<<"\n";
        }

    }
}
