#include <iostream>
#include <SFML/Graphics.hpp>
#include<fstream>
#include<cassert>
#define RED_COEF 0.2126
#define GREEN_COEF 0.7152
#define BLUE_COEF 0.0722

using namespace std;
using namespace sf;

void print(int intensity,ofstream &fout){
switch(intensity) {
case 0:
 fout << " ";
 break;
case 1:
 fout << ".";
 break;
case 2:
 fout << "'";
 break;
case 3:
 fout << "`";
 break;
case 4:
 fout << "\\";
 break;
case 5:
 fout << "^";
 break;
case 6:
 fout << "\"";
 break;
case 7:
 fout << ",";
 break;
case 8:
 fout << ":";
 break;
case 9:
 fout << ";";
 break;
case 10:
 fout << "I";
 break;
case 11:
 fout << "l";
 break;
case 12:
 fout << "!";
 break;
case 13:
 fout << "i";
 break;
case 14:
 fout << ">";
 break;
case 15:
 fout << "<";
 break;
case 16:
 fout << "~";
 break;
case 17:
 fout << "+";
 break;
case 18:
 fout << "_";
 break;
case 19:
 fout << "-";
 break;
case 20:
 fout << "?";
 break;
case 21:
 fout << "]";
 break;
case 22:
 fout << "[";
 break;
case 23:
 fout << "}";
 break;
case 24:
 fout << "{";
 break;
case 25:
 fout << "1";
 break;
case 26:
 fout << ")";
 break;
case 27:
 fout << "(";
 break;
case 28:
 fout << "|";
 break;
case 29:
 fout << "\\";
 break;
case 30:
 fout << "/";
 break;
case 31:
 fout << "t";
 break;
case 32:
 fout << "f";
 break;
case 33:
 fout << "j";
 break;
case 34:
 fout << "r";
 break;
case 35:
 fout << "x";
 break;
case 36:
 fout << "n";
 break;
case 37:
 fout << "u";
 break;
case 38:
 fout << "v";
 break;
case 39:
 fout << "c";
 break;
case 40:
 fout << "z";
 break;
case 41:
 fout << "X";
 break;
case 42:
 fout << "Y";
 break;
case 43:
 fout << "U";
 break;
case 44:
 fout << "J";
 break;
case 45:
 fout << "C";
 break;
case 46:
 fout << "L";
 break;
case 47:
 fout << "Q";
 break;
case 48:
 fout << "0";
 break;
case 49:
 fout << "O";
 break;
case 50:
 fout << "Z";
 break;
case 51:
 fout << "m";
 break;
case 52:
 fout << "w";
 break;
case 53:
 fout << "q";
 break;
case 54:
 fout << "p";
 break;
case 55:
 fout << "d";
 break;
case 56:
 fout << "b";
 break;
case 57:
 fout << "k";
 break;
case 58:
 fout << "h";
 break;
case 59:
 fout << "a";
 break;
case 60:
 fout << "o";
 break;
case 61:
 fout << "*";
 break;
case 62:
 fout << "#";
 break;
case 63:
 fout << "M";
 break;
case 64:
 fout << "W";
 break;
case 65:
 fout << "&";
 break;
case 66:
 fout << "8";
 break;
case 67:
 fout << "%";
 break;
case 68:
 fout << "B";
 break;
case 69:
 fout << "@";
 break;
case 70:
 fout << "$";
 break;
    }
}
void print1(int i,ofstream& fout){
string str=" .,:;ox%#@";
fout<<str[(255-i)*10/256];
}
int main()
{
ofstream fout;
ofstream fout1;
fout.open("test.txt");
fout1.open("test1.txt");
Image img;
Image bw;
cout<<"Enter full path of the image(for example:E:\\image.jpg): "<<endl;
string str;
cin>>str;
if(img.loadFromFile(str)){

}
else{
    cout<<"Can`t open"<<endl;
}
bw=img;
int size_x=img.getSize().x;
int size_y=img.getSize().y;
for(int i=0;i<size_x;i++){
    for(int j=0;j<size_y;j++){
        bw.setPixel(i,j,Color(img.getPixel(i,j).r*RED_COEF+img.getPixel(i,j).g*GREEN_COEF+img.getPixel(i,j).b*BLUE_COEF,
                                     img.getPixel(i,j).r*RED_COEF+img.getPixel(i,j).g*GREEN_COEF+img.getPixel(i,j).b*BLUE_COEF,
                                     img.getPixel(i,j).r*RED_COEF+img.getPixel(i,j).g*GREEN_COEF+img.getPixel(i,j).b*BLUE_COEF));
    }
}
Color temp;
int intensity;
int XResolution=size_x/300;
int YResolution=2*XResolution;
int grey=0;
Image res=img;
Color tmp;
int cl;
for(int i=0;i<size_x-XResolution;i+=XResolution){
    for(int j=0;j<size_y-YResolution;j+=YResolution){
        for(int x=0;x<XResolution;x++){
            for(int y=0;y<YResolution;y++){
                cl=bw.getPixel(x+i,y+j).r;
                grey+=cl;
            }
        }
        grey/=XResolution*YResolution+1;
        for(int x=0;x<XResolution;x++){
            for(int y=0;y<YResolution;y++){
                assert(i+x<size_x);
                assert(j+y<size_y);
                res.setPixel(i+x,j+y,Color(grey,grey,grey));
            }

        }
    }
}
int y=res.getSize().y;
int x=res.getSize().x;
string ASCII;
for(int j=0;j<y;j+=YResolution){
    for(int i=0;i<x;i+=XResolution){
        intensity = res.getPixel(i,j).r % 71;
        print(intensity,fout);
        print1(intensity,fout1);
}
fout<<endl;
fout1<<endl;
}
fout.close();
fout1.close();

return 0;
}
