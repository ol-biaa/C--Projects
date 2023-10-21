#include <iostream>
#include "dec.h"
//#include "main.cpp"
using namespace std;

string board[9]= {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int player = 1;
int position = 0;

void introduction(){ 
    cout << "Press ENTER to begin";
    getchar();//stop the screen until a key is pressed(haults the screen) 
    cout << endl;

    cout << "******** TIC TAC TOE *********\n"; 
    cout << "*******************************\n";

     cout<<"\nPlayer 1) X\n";
     cout<<"Player 2) O\n\n";
  
  cout<<"The 3x3 grid is shown below:\n\n";
  
  cout << "     |     |      \n";
  cout << "  1  |  2  |  3   \n";
  cout << "_____|_____|_____ \n";
  cout << "     |     |      \n";
  cout << "  4  |  5  |  6   \n";
  cout << "_____|_____|_____ \n";
  cout << "     |     |      \n";
  cout << "  7  |  8  |  9   \n";
  cout << "     |     |      \n\n";
}
int main(){
 
introduction();





return 0;
}