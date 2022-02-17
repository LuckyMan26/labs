#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int leven_distance(string s1,string s2){
int array[s1.length()+1][s2.length()+1];
    array[0][0]=0;
    for(int i=0;i<=s1.length();i++){
        array[i][0]=i;
    }
    for(int i=0;i<=s2.length();i++){
        array[0][i]=i;
    }
    for(int i=1;i<=s1.length();i++){
        for(int j=1;j<=s2.length();j++){
         if((s1[i-1]==s2[j-1])){
            array[i][j]=array[i-1][j-1];

         }
         else{
            array[i][j]=min(min(array[i-1][j],array[i][j-1]),array[i-1][j-1])+1;
         }
        }
    }
    return array[s1.length()][s2.length()];
}
int main(){

string s1,s2;
cin>>s1>>s2;
cout<<leven_distance(s1,s2);
}
