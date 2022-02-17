#include <iostream>
#include <ctime>
using namespace std;
int num=0;
class grid{

private:
  /*int arr[9][9]= {
    {5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,0,9}
    };*/
   int arr[9][9]={
    {1,2,3,4,5,6,7,8,9},
    {4,5,6,7,8,9,1,2,3},
    {7,8,9,1,2,3,4,5,6},
    {2,3,4,5,6,7,8,9,1},
    {5,6,7,8,9,1,2,3,4},
    {8,9,1,2,3,4,5,6,7},
    {3,4,5,6,7,8,9,1,2},
    {6,7,8,9,1,2,3,4,5},
    {9,1,2,3,4,5,6,7,8}
};
    int sudoku[9][9];
    int sudoku_copy[9][9];

public:
    void createGrid();
    void transpose();
    void print();
    void printSol();
    void solve();
    bool correctness();
    void swap_rows();
    void swap_columns();
    void swap_big_columns();
    void swap_big_rows();
    void shuffle();
    bool possible(int x,int y,int n);
    bool isPresentInCol(int col, int num);
    bool isPresentInRow(int row, int num);
    bool isPresentInBox(int boxStartRow, int boxStartCol, int num);
    void sudokuGrid();
    bool findEmptyPlace(int &row, int &col);
    bool isValidPlace(int row, int col, int num);
    void solveSudoku();
    void deleteElement();
    void cmp();
};
    int getRand(int Max){
    return rand()%Max;
    }
    void grid::transpose(){
    for(int i=0;i<9;i++){
        for(int j=i+1;j<9;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    }
     void grid::swap_rows(){
    int area=getRand(2);
    int line1=getRand(2);
    int line2=getRand(2);

    for(int i=0;i<9;i++){
        swap(arr[3*area+line1][i],arr[3*area+line2][i]);
        }
    }
    void grid::swap_columns(){
        transpose();
        swap_rows();
        transpose();

    }
     void grid::swap_big_rows(){
     int area1=rand()%2;
     int area2=rand()%2;
        for(int i=0;i<3;i++){
        for(int j=0;j<9;j++){
            swap(arr[j][3*area1+i],arr[j][3*area2+i]);
        }
    }
    }
     void grid::swap_big_columns(){
     int area1=getRand(2);
     int area2=getRand(2);
        for(int i=0;i<3;i++){
        for(int j=0;j<9;j++){
            swap(arr[3*area1+i][j],arr[3*area2+i][j]);
        }
    }
    }

    void grid::createGrid(){

        int id=1+getRand(5);
        for(int i=0;i<10;i++){
        id=1+getRand(5);
        if(id==1) {
        transpose();
        }
        if(id==2){
            swap_rows();
        }
        if(id==3){
            swap_columns();
        }
        if(id==4){
            swap_big_rows();
        }
        if(id==5){
            swap_big_columns();
        }
        }
    }
    void  grid::print(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    }
   void  grid::printSol(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
    }
    bool grid::isPresentInCol(int col, int num) {

   for (int row = 0; row < 9; row++)
      if (sudoku_copy[row][col] == num)
         return true;

   return false;
}



bool grid::isPresentInRow(int row, int num) {

   for (int col = 0; col < 9; col++)
      if (sudoku_copy[row][col] == num)
         return true;
   return false;
}



bool grid::isPresentInBox(int boxStartRow, int boxStartCol, int num) {

   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         if (sudoku_copy[row+boxStartRow][col+boxStartCol] == num)
            return true;
   return false;
}
bool grid::possible(int x,int y,int n){
    if(!isPresentInBox((x/3)*3,(y/3)*3,n)&&(!isPresentInRow(x,n))&&(!isPresentInCol(y,n))){
       return true;
       }
       return false;
    }



void grid::sudokuGrid() {
   for (int row = 0; row < 9; row++) {
      cout<<"[ ";
      for (int col = 0; col < 9; col++) {

         cout << sudoku[row][col] <<" ";
      }
      cout<<"]"<<endl;

      }
      cout << endl;

}
bool grid::findEmptyPlace(int &row, int &col) {
   for (row = 0; row < 9; row++)
      for (col = 0; col < 9; col++)
         if (sudoku_copy[row][col] == 0)
            return true;
   return false;
}

bool grid::isValidPlace(int row, int col, int num) {
   return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row%3 , col - col%3, num);
}
void grid::cmp(){
for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            sudoku_copy[i][j]=sudoku[i][j];
        }
    }
}


void grid::solveSudoku() {
   int row, col;
   for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
        if(sudoku_copy[i][j]==0){
            for(int k=1;k<10;k++){
                if(possible(i,j,k)){
                    sudoku_copy[i][j]=k;
                    solveSudoku();
                    sudoku_copy[i][j]=0;
                }
            }
            return;
        }
    }
   }
    num++;

}

bool grid::correctness(){
if(num==1){
        num=0;
    return true;
}
num=0;
return false;
}
void grid::deleteElement(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            sudoku[i][j]=arr[i][j];
        }
    }
    int n=10+getRand(60);
for(int i=0;i<n;i++){
    int x=getRand(8);
    int y=getRand(8);
    sudoku[x][y]=0;
}
cmp();
solveSudoku();

while(num!=1){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            sudoku[i][j]=arr[i][j];
        }
    }
    int n=10+getRand(60);
for(int i=0;i<n;i++){
    int x=getRand(8);
    int y=getRand(8);
    sudoku[x][y]=0;
}
cmp();
num=0;
solveSudoku();
}
if(num==1){
    printSol();
    cout<<"yes"<<endl;
    return;
}
}
int main(){
    int number=0;
    srand(time(NULL));
    grid Grid;
    int arr[9][9]={
    {5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}
    };
    int n=0;
    Grid.createGrid();
    Grid.deleteElement();
    cout<<endl;
    Grid.solveSudoku();
}
