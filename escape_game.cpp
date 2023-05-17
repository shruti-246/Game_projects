//Name - Shruti Debnath
//Section - 08
//Assignment - 05
#include<iostream>

using namespace std;

void printinstruction();
string direction;
int TreasureRoom();
int PearlRoom();
int FireRoom();
int MonsterRoom();
int OxygenRoom();
int GoldRoom();
int ThiefRoom();
int playerlocation;
struct player {
    int hp = 500;
    int diamond;
    int gold;
    int pearl;
    int oxygen ;

};
player p1;

void printinstruction(){
    cout << endl;
    cout << "Room 01" << endl;
    cout << "Room 02" << endl;
    cout << "Room 03" << endl;
    cout << "Room 04" << endl;
    cout << "Room 05" << endl;
    cout << "Room 06" << endl;
    cout << "Room 07" << endl;
    cout << "Exit (0)" << endl;
    cout << "Enter your choice: ";
    cin  >> playerlocation;
}

int main(){
    printinstruction();
    //string direction;
    int room;
    while (playerlocation < 8){
        switch (playerlocation)
        {
            case 0 : cout << "Thanks for playing the game!!!!!!!!!" << endl;
            break;
            case 1 : cout << " A door made of cheese appear before you, unable to resisit you eat your way into the dungeon " << endl;
            room = TreasureRoom();
            cout << "remaining health: " << p1.hp << endl;
            cout << "You are in room number " << room << endl;
            cout << "Now there are two doors which one you want to choose (Left or Straight) type 'left' or 'straight': ";
            cin >> direction;
            if (direction == "left"){playerlocation = 2;}
            else if (direction == "straight"){playerlocation = 7;}
        //break;

            case 2 : cout << " a picture " << endl;
            room = PearlRoom();
            cout << "remaining health: " << p1.hp << endl;
            cout << "You are in room number " << room << endl;
            cout << "Now there are four doors which one you want to choose (Left or Straight or Back) type 'left', 'straight' or 'back': ";
            cin >> direction;
            if (direction == "left"){playerlocation = 3;}
            else if (direction == "back"){playerlocation = 7;}
            else if (direction == "straight"){playerlocation = 4;}
            else if (direction == "right"){playerlocation = 8;}
        //break;

            case 3: cout << " a basketball " << endl;
            room = FireRoom();
            cout << "remaining health: " << p1.hp << endl;
            cout << "You are in room number " << room << endl;
            cout << "Now there are three doors which one you want to choose (Exit or Left or straight) type 'exit', 'left' or 'straight': ";
            cin >> direction;
            if (direction == "exit"){break;}
            else if (direction == "left"){playerlocation = 7;}
            else if (direction == "straight"){playerlocation = 8;}
        //break;
        
            case 4: cout << " A net " << endl;
            room = MonsterRoom();
            cout << "remaining health: " << p1.hp << endl;
            cout << "You are in room number " << room << endl;
            cout << "Now there are four doors which one you want to choose (Left, Right, Back or Straight) type 'left', 'back', 'straight' or 'right': ";
            cin >> direction;
            if (direction == "left"){playerlocation = 3;}
            else if (direction == "straight"){playerlocation = 6;}
            else if (direction == "right"){playerlocation = 5;}
            else if (direction == "back"){playerlocation = 1;}
        //break;

            case 5: cout << " A drawing " << endl;
            room = OxygenRoom();
            cout << "remaining health: " << p1.hp << endl;
            cout << "You are in room number " << room << endl;
            cout << "Now there are four doors which one you want to choose (Left back or Right back or right or exit) type 'left back', 'right back', 'right' or 'straight': ";
            cin >> direction;
            if (direction == "left back"){playerlocation = 3;}
            else if (direction == "right back"){playerlocation = 6;}
            else if (direction == "right"){playerlocation = 8;}
            else if (direction == "exit"){break;}
        //break;
        
            case 6: cout << " A shoe " << endl;
            room = GoldRoom();
            cout << "remaining health: " << p1.hp << endl;
            cout << "You are in room number " << room << endl;
            cout << "Now there are two doors which one you want to choose (Right or Straight) type 'right' or 'straight': ";
            cin >> direction;
            if (direction == "right"){playerlocation = 1;}
            else if (direction == "straight"){playerlocation = 3;}
        //break;

            case 7: cout << " A flower " << endl;
            room = ThiefRoom();
            cout << "remaining health: " << p1.hp << endl;
            cout << "You are in room number " << room << endl;
            cout << "Now there are three doors which one you want to choose (Left or Straight) type 'left' or 'straight': ";
            cin >> direction;
            if (direction == "left"){playerlocation = 2;}
            else if (direction == "straight"){playerlocation = 7;}
            else if (direction == "exit"){break;}
            
            default:
            if (direction == "exit"){
                break;
            }

        //break;
        }if (p1.hp <= 5) break;
        if (direction == "exit"){
                break;
    }
}
    cout << "You have gold " << p1.gold << ", pearl " << p1.pearl << ", diamond " << p1.diamond << endl;
    return 0;
}
int TreasureRoom(){
    int room_num = 01;
    static int diamond = 200;
    int d;
    cout << "There are some stone like things which reflasing lights and there are some paintings of diamond." << endl;
    do {
        cout << diamond << " diamond is in the room, how much do you take? ";
        cin >> d;
        if (d > diamond){ cout << " too much!! greed is bad \n"; break;}
        if (d < 0){ cout << " you should't give back to the dungeon \n";break;}

    } while (d > diamond || d < 0);
  
    diamond -= d;
    p1.diamond += d;
    return room_num;
}
int PearlRoom(){
    int room_num = 05;
    static int pearl = 300;
    int p;
    cout << "there are some white pearl under the bed and a snake over the bed." << endl;
    do {
        cout << pearl << " pearl is in the room, how much do you take? ";
        cin >> p;
        if (p > pearl){ cout << " too much!! greed is bad \n";break;}
        if (p < 0){ cout << " you should't give back to the dungeon \n";break;}

    } while (p > pearl || p < 0);
  
    pearl -= p;
    p1.pearl += p;
    return room_num;
}
int FireRoom(){
    int room_num = 03;
    cout << "everything is burning because of the fire. There no such a thing to collect." << endl;
    if (p1.hp >= 100){p1.hp -= 50;}
    else if ((p1.gold < 100) || (p1.gold >= 50)){p1.hp -= 20;}
    else if ((p1.hp > 10) || (p1.hp < 50)){p1.hp -= 10;}
    if (p1.pearl > 50){p1.pearl -= 20;}
    else if ((p1.pearl < 50) || (p1.pearl > 10)){p1.pearl -= 10;}
    else if ((p1.pearl > 0) || (p1.pearl < 10)){p1.pearl -= 2;}
    return room_num;
}
int MonsterRoom(){
    int room_num = 06;
    cout << "There is a huge size monster. you have to fight with him." << endl;
    if (p1.hp >= 100){p1.hp -= 50;}
    else if ((p1.gold < 100) || (p1.gold >= 50)){p1.hp -= 20;}
    else if ((p1.hp > 10) || (p1.hp < 50)){p1.hp -= 10;}
    if (p1.diamond > 50){p1.diamond -= 20;}
    else if ((p1.diamond < 50) || (p1.diamond > 10)){p1.diamond -= 10;}
    else if ((p1.diamond > 0) || (p1.diamond < 10)){p1.diamond -= 2;}
    return room_num;
}
int OxygenRoom(){
    int room_num = 04;
    static int oxygen = 200;
    int oxy;
    cout << "you can take oxygen from here only if your health condition under 100. " << endl;
    if (p1.hp < 100){
        do {
            cout << oxygen << " oxygen is in the room, how much do you take? ";
            cin >> oxy;
            if (oxy > oxygen){ 
                cout << " too much!! greed is bad \n";
                break;
            }
            if (oxy < 0){ 
                cout << " you should't give back to the dungeon \n";
                break;
            }

        } while (oxy > oxygen || oxy < 0);
        p1.oxygen += oxy;
        p1.hp += 50;
    }
    return room_num;
}
int GoldRoom(){
    int room_num = 02;
    static int gold = 200;
    int g;
    cout << "Don't be so greedy but you can collect some gold from here." << endl;
    do {
        cout << gold << " Gold is in the room, how much do you take? ";
        cin >> g;
        if (g > gold){ cout << " too much!! greed is bad \n";break;}
        if (g < 0){ cout << " you should't give back to the dungeon \n";break;}

    } while (g > gold || g < 0);
  
    gold -= g;
    p1.gold += g;
    return room_num;
}
int ThiefRoom(){
    int room_num = 07;
    cout << "You gonna lose your collections." << endl; 
    if (p1.gold >= 10){p1.gold -= 10;}
    else if ((p1.gold < 10) || (p1.gold >= 5)){p1.gold -= 5;}
    else if ((p1.gold > 0)||(p1.gold < 5)){p1.gold -= 2;}
    return room_num;
}






