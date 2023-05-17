#include<iostream>
using namespace std;
#include"linkedlist.h"

int main(){
   linkedlist animals;
   node *p;
   p = new node();
   p->setdata("cat");
   animals.push(p);

   p = new node();
   p->setdata("dog");
   animals.push(p);

   p = new node();
   p->setdata("unicorn");
   animals.push(p);

   p = new node();
   p->setdata("horse");
   animals.append(p);

   p = new node();
   p->setdata("frog");
   animals.append(p);
   
   animals.print();

   cout << "The length of the linkedlist: " << animals.cal_length() << endl;
   cout << "dog is in the list (1 - True, 0 - False): " << animals.find("dog") << endl;
   cout << "ant is in the list (1 - True, 0 - False): " << animals.find("ant") << endl;
   string animal_name = animals.get(2);
   if (animal_name == "") {
      cout << "Invalid index or position" << endl;
   } else {
      cout << "The second animal in the list is " << animal_name << endl;
   }

   animals.clear();
   cout << "Length after clearing the list: " << animals.cal_length();

}