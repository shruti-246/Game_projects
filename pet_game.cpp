
#include <iostream> 
#include <string>
#include <fstream>
#include "pet_game.h"
using namespace std; // declaration of the pet class 

int main() {
   // Ask the user how many pets they want 
   int num_pet;
   pet arr_pet[num_pet];
   cout << "How many pets you want: ";
   cin >> num_pet;
   ofstream names_file;
   string filename;
   cout << "Give a filename ";
   getline(cin >> ws, filename);
   names_file.open(filename);
   for (int i = 0; i < num_pet; i++) {
      names_file << arr_pet[i].find_name() << endl;
   }
   names_file.close();

   int num = 0;
   int choose;
   while(num >= 0 && num <= num_pet){
      cout << "To exit press 0" << endl;
      cout << "0) exit.\n";
      cout << "Or play another round.\n";
      cout << "Which pet will you choose?\n";
      for (int i = 0; i < num_pet; i++){
         cout << i+1 << ") " << arr_pet[i].find_name() << endl;
      }
      cin >> choose;
      if (choose == 0){
         cout << "Thanks for playing. We will wait for you to play again." << endl;
         break;
      }else{
         arr_pet[choose-1].interact();
      }
      for (int i = 0; i < num_pet; i++){
         arr_pet[i].every_pet();
      }
      for (int i = 0; i < num_pet; i++){
         arr_pet[i].print();
      }
      int l = rand() % num_pet;
      arr_pet[l].event();
      arr_pet[l].pet_show();
      
      for (int i = 0; i < num_pet; i++){
         if (arr_pet[i].check_health() == 1){
            cout << arr_pet[i].check_health() << endl;
            cout << "One of your pets name " << arr_pet[i].find_name() << " died" << endl;
            cout << "Game has completed" << endl;
            break;
         }
      }
      num++;
   }
   cout << "Press enter to exit." << endl;
   cin.ignore();
   return 0;
}