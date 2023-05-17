
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
class pet{
   private:
     int hunger;           // private data member
     string pet_name;      // private data member
     int happy;            // private data member
     int money_get;
   public:
     pet();                // constructor
     void interact();      // public member function
     void play();          // public member function
     void feed();          // public member function
     void print();         // public member function
     int check_health();   // public member function
     string find_name();   // a public member function to find out the name of the pet
     void every_pet();     // to have acess with every pet
     void give_name(string new_name);   // to set name of the pets.
     void pet_show();
     void event();
};

/* Constructor, creates a new pet with starting values. */
pet::pet(){
     hunger = 50;
     happy = 50;
     money_get = 50;
     cout << "Pet name: ";
     cin >> pet_name;
}

/* Member function interact(), allows player to interact with a pet. */
void pet::interact(){
    print();
    int choice;
    cout << "What would you like to do with your pet?\n";
    cout << " Play (1) \n Feed (2) \n";
    cin >> choice;
    switch(choice){
       case 1:
          play();
          break;
       case 2:
          feed();
          break;
    }
}

/* Member function play(), allows playing with a pet. */
void pet::play(){
    int choice = 0;
    cout << "What should we play?\n";
    cout << " Fetch (1) \n Roll over (2) \n";
    cin >> choice;
    switch(choice){
    case(1):
         happy += 15;
         hunger += 3;
         break;
    case(2):
         happy += 4;
         hunger += 1;
         break;
    default:
         cout << "Not a valid choice." << endl;
   }
}

void pet::feed(){
    cout << "\nMMM, Yummy!\n";
    hunger -= 5;
}

void pet::print(){
    cout << "\nYour pet " << pet_name << " is:\n ";
    cout << "Happy: " << happy << endl;
    cout << "Hungry: " << hunger << endl;
    cout << "Money: " << money_get << endl;
}

int pet::check_health(){
    if(hunger >= 100){
         cout << "\nYour pet has starved.\n";
         return 1;
     }
     if(happy <= 0){
         cout << "\nYour pet has died of a broken heart.\n";
         return 1;
     }
     if (money_get <= 0)
    {
     cout << "No moneey to take care of your cat" << endl;
     return 1;
    }
    return 0;
}
void pet::pet_show(){
     srand(time(NULL));
     int max_rate;
     cout << "Highest rate of this cat could be ";
     cin >> max_rate;
     int stars = rand() % max_rate +1;
     cout << "You cat has earned " << stars << " stars" << endl;
     int ExtraMoney = 0;
     if ((stars + 10) > max_rate){
          int ExtraMoney = stars/2;
     }else if ((stars + 5) > max_rate){
          int ExtraMoney = stars + 5;
     }else if ((stars + 5) < max_rate){
          int ExtraMoney = stars - 2;
     }else{
          int ExtraMoney = stars*2;
     }
     cout << "You earned " << ExtraMoney << " money" << endl;
     money_get += ExtraMoney;
     hunger -= 10;
     happy += stars*2;
}

void pet::event(){
     string events[] = {"gets lose", "Find a Treat", "Learn a trick", "dogs up buried treasure"};
     int choose_event = rand() % 5 - 1;
     if (choose_event != -1)
     {
          cout << "Your pet " << events[choose_event] << endl;
          if (choose_event == 0){
               happy -= 5;
               money_get -= 5;
          }else if (choose_event == 1){
               happy += 5;
               hunger -= 5;
               money_get -= 5;
          }else if (choose_event == 2){
               happy += 5;
               money_get -= 5;
          }else{
               hunger += 5;
               happy += 5;
               money_get -= 5;
          }
     }
}

string pet::find_name(){
     return pet_name;
}
void pet::every_pet(){
     hunger += 2;
     happy -= 2;
}
void pet::give_name(string new_name){
   pet_name = new_name;
}