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

bool is_winner(){
  bool winner = false;
  //rows
  if(board[0] == board[1] && board[1] == board[2] && board[0] != " "){
    winner = true;
  }
  else  if( board[3]==board[4] && board[4] == board[5] && board[3] != " "){
    winner = true;
  }
  else  if( board[6]==board[7] && board[7] == board[8] && board[6] != " "){
    winner = true;
  }

  //columns
  else if( board[0]==board[3] && board[3] == board[6] && board[0] != " "){
    winner = true;
  }
  else  if( board[1]==board[4] && board[4] == board[7] && board[1] != " "){
    winner = true;
  }
  else  if( board[2]==board[5] && board[5] == board[8] && board[2] != " "){
    winner = true;
  }

  //diagonals
  else  if( board[0]==board[4] && board[4] == board[8] && board[0] != " "){
    winner = true;
  }
  else  if( board[2]==board[4] && board[4] == board[6] && board[2] != " "){
    winner = true;
  }
  return winner;
}
bool filled_up(){
  bool filled = true;
  for (int i = 0; i < 9; i++){
    if(board[i]== " "){
      filled = false;
    }
  }
  return filled;
}

void draw(){
  cout<<  "     |     |      \n";
  cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
  cout << "_____|_____|_____ \n";
  cout << "     |     |      \n";
  cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
  cout << "_____|_____|_____ \n";
  cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
  cout << "     |     |      \n";
  cout << "\n";

}
//prompt the user to enter position
void set_position(){
  cout << "Player " << player <<" enter (1-9): ";
  while(!(cin>>position)){
    cout << "Please enter a valid number between (1-9): " << endl;
    cin.clear();//flushes the buffer
    cin.ignore();//ignore whatever is in the buffer, remove whatever is the error value
    cout << endl;
  }
  while(board[position - 1] != " "){
    cout << "Oops that position is already filled\n Try again\n";
    cout << "Player " << player << "'s turn (Enter 1-9): ";
    cin >> position;
  } 
}
//placing a character on the board
void update_board(){
  if(player %2 == 1){
    board[position - 1] = "X";
  }else{
    board[position - 1] = "O";
  }
}

//change players
//player 1 plays their position then player 2 continues
void change_players(){
  if(player == 1){
    player++;
  }
  else{
    player--;
  }
}
//taking turns when player 1 is done player 2 plays then continues
//when the board is not filled
//when the is winner function is false
//invoking the functions
void take_turns(){
  while(!is_winner && !filled_up()){
    set_position();
    update_board();
    change_players();
    draw();
  }
}
//updating the game, the game ended on a draw or winning note
void end_game(){
  if(is_winner()){
    cout << "There is a winner!\n";
  }else if(filled_up()){
    cout << "There is a tie.";
  }
}/*
int main() {
    introduction();
    
  set_position();
        take_turns();

    
    end_game();
    return 0;
}*/
/*
int main(){

    introduction();
     //set_position();
    // update_board();
      take_turns();
    end_game();
   
    return 0;
}*/
