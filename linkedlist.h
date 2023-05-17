// First Define a node class, then define a linked list class
class node{
   private:
     node *next;
     string name;
   public:
     void setnext(node *n){next = n;} // inline function
     void setdata(string n){name = n;}  // inline function
     void print(); // defined below
     void clear();
     string get_name() { return name; }
     node* get_next() { return next; }
     bool find(string n); // defined below
};

void node::clear(){
   if(next != NULL)
      next -> clear();
   delete this;
}

void node::print(){
   cout << name << endl;
   if(next != NULL)
      next -> print();
}

bool node::find(string n){
   if (name == n) {
      return true;
   } else if (next == NULL) {
      return false;
   } else {
      return next->find(n);
   }
}

// Definition of the linked list class

class linkedlist{
   private:
     node *head;
     int len;
   public:
     linkedlist();
     void push(node *);
     void print();
     void clear();
     int cal_length();
     int append(node *);
     bool find(string n);
     string get(int n);
};

linkedlist::linkedlist(){ // constructor
   head = NULL;
   len = 0;
}

void linkedlist::push(node *n){
  n->setnext(head);
  head = n;
  len = len + 1;
}

int linkedlist::cal_length() {
    return len;
}

bool linkedlist::find(string name) {
   if (head == NULL) {
      return false;
   } else {
      return head->find(name);
   }
}

string linkedlist::get(int num) {
   if (num >= len) {
      return "";
   } else {
      node *cur = head;
      for (int i = 0; i < num; i++) {
         cur = cur->get_next();
      }
      return cur->get_name();
   }
}

int linkedlist::append(node *n){
   if (head == NULL) {
      head = n;
   } else {
      node *cur = head;
      while (cur->get_next() != NULL) {
         cur = cur->get_next();
      }
      cur->setnext(n);
   }
   len++;
   return len;
}

void linkedlist::print(){
  if(head != NULL){
     head -> print();
  }
}

void linkedlist::clear(){
  if(head != NULL){
     head-> clear();
  }
  head = NULL;
  len = 0;
}
