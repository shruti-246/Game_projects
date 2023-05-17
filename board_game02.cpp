#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;

// Declaration of the square class
class square{
  private:
    int move;
    string message;
    char symbol;
    int score;
  public:
    square();
    void print();
    int action();
    void set(int, char, int, string);
    int print_score();
};

// Function Prototypes
void print_board(square[], int, int);
void read_board(square[]);
void check_position(int&);

// Global variables
const int board_length = 20;
int player1_score = 0;
int player2_score = 0;

int main(){
  int current_player = 1, roll;
  int player1_position = 0, player2_position = 0;
  square the_board[board_length]; // declare an array of squares
  srand(time(NULL));
  read_board(the_board);

  // Introduction
  cout << "Welcome to Treasure Hunt!\n";
  cout << "The goal of the game is to reach the treasure before your opponent.\n";
  cout << "Roll the dice and move your character on the board to find the treasure!\n\n";
  cout << "Player 01 will be 'Shruti'\n";
  cout << "Player 02 will be 'Raiyan'\n";
  // Print initial board
  print_board(the_board, player1_position, 1);
  print_board(the_board, player2_position, 2);

  // Game loop
  do{
    cout << "Player " << current_player << ", press enter to roll the dice.\n";
    cin.ignore();

    // Roll the dice
    roll = 1 + (rand() % 6);
    cout << "Player " << current_player << " rolled a " << roll << ".\n";

    // Update player position and score
    if (current_player == 1){
         player1_position += roll;
         check_position(player1_position);
         player1_position += the_board[player1_position].action();
         check_position(player1_position);
         player1_score += the_board[player1_position].print_score();
     }
     else{
        player2_position += roll;
        check_position(player2_position);
        player2_position += the_board[player2_position].action();
        check_position(player2_position);
        player2_score += the_board[player2_position].print_score();
     }
     print_board(the_board,player1_position,1);
     print_board(the_board,player2_position,2);
     current_player = (current_player % 2) + 1;
  }while((player1_position<board_length-1) && (player2_position<board_length-1));
current_player = (current_player % 2) + 1;
cout << "\nPlayer " << current_player << " Wins!!!\n"; //=============================================
  cin.ignore();
  return 0;
}


void read_board(square b[]){
    ifstream infile;
    infile.open("game.txt");
    int square_number, square_move, square_score;
    string square_message;
    char square_symbol;
    while(!infile.eof()){
        infile >> square_number >> square_move >> square_symbol >> square_score;
        getline(infile,square_message);
        if(square_number < board_length){
            b[square_number].set(square_move,square_symbol, square_score, square_message);
        }
     }
}
void print_board(square b[], int player_position, int player_number){
    string player_name;
    for(int i = 0; i < board_length; i++){
        if(i != player_position){
            b[i].print();
        }
        else{
            if (player_number == 1){
                player_name = "Shruti";
            }else{
                player_name = "Raiyan";
            }
            cout << " " << player_name;
        }
    }
    cout << " Goal\n"; //======================================
    for(int i = 0; i < board_length*2; i++)
         cout << "-"; //==========================================
    cout << "\n"; //====================================================
}
void check_position(int &p){
    if(p < 0)
         p = 0;
    if(p >= board_length)
         p = board_length-1;
}
                           // Functions of the class square
square::square(){
     symbol = ' ';
     move = 0;
     message = "";
     score = 0;
}
int square::action(){
     cout << message << "\n" << endl;
     cout << " " << endl;
     return move;
}
void square::print(){
     cout << " " << symbol;
}
void square::set(int m, char s, int s1, string a_message){
     move = m;
     symbol = s;
     message = a_message;
     score = s1;
}
int square::print_score(){
     return score;
}
