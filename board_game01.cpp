/*Name - Shruti Debnath
Section - 08
Extra credit Assignment 04
Date - 10 february 2023*/
// --------------------------------NIM GAME--------------------------
 #include<iostream>     
 #include<cstdlib>
 using namespace std;
 int main()             
 {
   // ---------------- Variable declarations ---------------------
   int num_objects;
   int current_player = 1; 
   int move;
   int min = 1;
   int max = 5;
   bool flag = true;
   char var;
   //-----------------description----------------
   cout << "Game rule: " << endl;
   cout << "User can choose how many objects they wants to add\n";
   cout << "Then player 1 (user) will choose a number between 1 and 5\n";
   cout << "program will remove that number from the objects\n";
   cout << "then the round will be for the computer\n";
   cout << "the that removes the last object will lose the game.\n";
   // ----------- Beginning of the main game loop ----------------
   while (flag){
      cout << "How many objects you want to add: ";
      cin >> num_objects;
      do {                                      
         if (current_player == 1) {    
               cout << "Player 1 enter your move (1-5): ";  
               cin >> move;                 
               while (move < min || move > max || move > num_objects){
                  if (move < min || move > max){
                     cout << "Illegal move. \nEnter a new move (1-5): ";
                     cin >> move;
                  }else if (move > num_objects){
                     cout << "we do not enough objects \nEnter a new move between 1 and " << num_objects << " : ";
                     cin >> move;
                  }
               }
         } else{                                     
                do{
                    //if (num_objects > max){                                  
                        move =  1+ rand() % max;
                    // }else{
                    //     move = num_objects;
                    // }             
                }while (move < min || move > max || move > num_objects);
                cout << "Computer removed " << move << endl;
         }
         num_objects = num_objects - move;  
         cout << (num_objects) << " objects remaining.\n";
         if ((num_objects < 15) && (num_objects > 10)){
            cout << "A lot of objects remain. Anbody can be the winner." << endl;
         }else if((num_objects < 10) && (num_objects > 6)){
            cout << "Some objects are left. The game is getting interesting." << endl;
         }else if ((num_objects < 6) && (num_objects > 4)){
            cout << "A few objects are remain. Let's guess the winner." << endl;
         }else if ((num_objects <= 3) && (num_objects >=1)){
            cout << "The game is going to end. Let's see the winner of the day." << endl;
         }

         for (int i = 1; i <= num_objects; i++){
            cout << "#";
         }
            cout << endl;
      current_player = (current_player + 1) % 2;  // switch players
      } while (num_objects > 0);                    
      // ------------  end of the game loop --------------------------
      cout << "Player " << current_player << " wins!!!\n";
      cout << "Do you want to play again? if yes type 'y'otherwise type 'n' "<< endl;
      cin >> var;
      if (var == 'y'){
         flag = true;
      }else{
         cout << "Thanks for participating" << endl;
         flag = false;
      }
   }
   return 0;
}