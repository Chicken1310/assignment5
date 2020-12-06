/* MY name : Mohamed saif aldeen
   Class : Second Year
   Department : Computer Engineering
*/

// git : https://github.com/Chicken1310/assignment5
// import the input output stream liberary
#include<iostream>
using namespace std ;
const int MAX_SIZE = 100 ;

class linkedList {
  struct Node
  {
      int item ;
      Node*next ;
  };
  Node*first ;
  Node*last ;
  int length ;
public :
  linkedList() {
    first = last = NULL ;
    length = 0 ;
  }
  bool isEmpty() {
    return length == 0 ;
   }

  void insertFirst(int &element)
  {
    Node*newNode = new Node ;
    newNode->item = element ;
    if(length ==0)
    {
      first = last = newNode ;
      newNode->next = NULL ;
    }
    else
    {
      newNode->next = first ;
      first = newNode ;
    }
    length++;
  }
  void insertLast (int element)
  {
    Node*newNode = new Node ;
    newNode->item = element ;
    if(length ==0)
    {
      first = last = newNode ;
      newNode->next = NULL ;
    }
    else
    {
      last->next = newNode ;
      newNode->next = NULL ;
      last = newNode ;
    }
    length++;
  }

  void insertAtPos(int pos, int element)
  {
    if(pos<0 || pos>length )
      std::cout << "Out Of Range " << '\n';
    else
    {
      Node*newNode = new Node ;
      newNode->item = element ;
      if (pos == 0)
        insertFirst(element) ;
      else if (pos == length)
        insertLast(element) ;
      else {
        Node * Cur = first ;
        for (int i = 1; i<pos; i++) {
          Cur = Cur->next ;
        }
        newNode->next = Cur->next ;
        Cur->next = newNode ;
        length++ ;
      }
    }
  }

  void removeFirst() {
    if (length == 0)
      std::cout << " Empty List Can't Remove" << '\n';
    else if (length == 1)
    {
      delete first ;
      last = first = NULL ;
      length--;
    }
    else
    {
      Node*current = first ;
      first = first->next ;
      delete current ;
      length--;
    }
  }
  void removeLast() {
    if (length == 0)
      std::cout << " Empty List Can't Remove" << '\n';
    else if (length == 1)
    {
      delete first ;
      last = first = NULL ;
      length--;
    }
    else
    {
      Node*curr = first->next ;
      Node*prev = first ;
      while(curr!=last) {
        prev = curr ;
        curr = curr->next ;
      }
      delete curr ;
      prev->next = NULL ;
      last = prev ;
      length-- ;
    }
  }
  void remove(int element)
  {
    if(isEmpty())
    {
      std::cout << "Empty List Can't Remove" << '\n';
      return ;
    }

    Node *curr, *prev ;
    if(first->item == element) {
      curr = first ;
      first = first->next ;
      delete curr ;
      if(length == 0)
        last = NULL;
    }
    else
    {
      curr = first->next ;
      prev = first ;
      while (curr != NULL) {
        if (curr->item == element)
          break ;
        prev = curr ;
        curr =curr->next ;
      }

      if(curr == NULL)
        std::cout << "the Element Not Found " << '\n';
      else
      {
        prev->next = curr->next ;
        if (last == curr)
          last = prev ;
        delete curr ;
        length--;
      }
    }

  }

  void print()
  {
    Node*cur = first ;
    std::cout << '\n';
    for (int i =0; i<length; i++) {
      std::cout<< cur->item<<" ";
      cur = cur->next;
    }
    std::cout << '\n';
  }
  void getLength() {
    std::cout << "\nLength is : "<<length << '\n';

  }



};
// to make the stack assign any kind of data type
class stack  {
  int top ;
  int item[MAX_SIZE] ;
public :
  stack() : top (-1) {}

  void push (int  Element)
  {
    // could make exception handling here
    if (top >= MAX_SIZE -1) {
      std::cout << " stack full on push " << '\n';
    }
    else
      item[++top] = Element ;
  }
  // to check if stack empty or not
  bool isEmpty()
  {
    return top<0 ;
  }
  void pop () {
    if (isEmpty())
      cout << "stack empty on pop" << '\n';
    else
      top--;
  }
  // overload if user want to get the value of pop before deleting
  void pop (int &Element) {
    if (isEmpty())
      cout << "stack empty on pop" << '\n';
    else
    {
      Element = item[top] ;
      top--;
    }
  }
  int getTop (int&stackTop) {
    if (isEmpty())
      cout << "stack empty on getTop" << '\n';
    else
    {
      stackTop = item[top] ;
      return stackTop ;
    }
  }

  void print() {
    std::cout << "[";
    for (int i = top ; i >= 0; i--) {
      std::cout << item[i] << " ";
    }
    std::cout << "]" << '\n';
  }

};
class queue {
  int front = 0  ;
  int rear = MAX_SIZE-1 ;
  int item[MAX_SIZE] ;
  int count = 0 ;

public :
  bool isEmpty() {
    return count == 0 ;
   }
  bool isFull() {
    return count == MAX_SIZE ;
   }
  void enqueue(int a) {
    if(isFull())
      std::cout << "Queue is Full " << '\n';
    else {
      rear = (rear+1)%MAX_SIZE ;
      item[rear] = a ;
      count++;
    }
   }
  void dequeue() {
    if(isEmpty()) {
      std::cout << "Queue is Empty " << '\n';
    }
    else {
      front = (front+1)%MAX_SIZE ;
    }
    count--;
  }
  void getFront() {
      std::cout << "front is: "<<item[front] << '\n';
  }
  void getRear() {
    std::cout << "rear is: " <<item[rear]<< '\n';
  }
  void getSize() {
    std::cout << "size of queue is: "<< count << '\n';
  }
  void print() {
    std::cout << "[";
    for (int i = front ; i <= rear; i++) {
      std::cout << item[i] << " ";
    }
    std::cout << "]" << '\n';
  }
};
// Linkedlist function to initilaze the Linkedlist and prepare the user to work with it propaply
void Linkedlist()
{
  linkedList l ;
  std::cout << "What do you want: " << '\n';
  std::cout << "1/add\n2/remove\n3/length of linkedList" << '\n';
  std::cout << "if you want to exit press 0 " << '\n';
  int n ;
  cin>>n ;
  while (n !=0) {
    if (n==1) {
        std::cout << "1/add from frist\n2/add from last\n3/add from anywhere" << '\n';
        int n ;
        cin>>n ;
        if(n==1) {
            std::cout << "Enter the element you want to add: " << '\n';
            int q ;
            cin>>q ;
            l.insertFirst(q) ;
            l.print() ;
        }
        if(n==2) {
            std::cout << "Enter the element you want to add: " << '\n';
            int q ;
            cin>>q ;
            l.insertLast(q) ;
            l.print() ;
        }
        if(n==3) {
            std::cout << "Enter the element(first input) and the position(second input) you want to add: " << '\n';
            int q, pos ;
            cin>>q>>pos ;
            l.insertAtPos(pos,q) ;
            l.print() ;
        }

    }
    else if (n == 2) {
        std::cout << "1/remove frist\n2/remove last\n3/remove from anywhere" << '\n';
        int n ;
        cin>>n ;
        if(n==1) {
            l.removeFirst() ;
            l.print() ;
        }
        if(n==2) {
            l.removeLast() ;
            l.print() ;
        }
        if(n==3) {
              std::cout << "Enter the element  you want to remove: " << '\n';
            int q ;
            cin>>q;
            l.remove(q) ;
            l.print() ;
        }
    }
    else if (n== 3) {
        l.getLength() ;
    }
    else if (n== 0) {
        break ;
    }
    std::cout << "What do you want: " << '\n';
    std::cout << "1/add\n2/remove\n3/length of linkedList" << '\n';
    std::cout << "if you want to exit press 0 " << '\n';
    cin>>n ;
  }
}

// stack function to initilaze the stack and prepare the user to work with it propaply
void Stack() {
  stack stk ;
  std::cout << "What do you want: " << '\n';
  std::cout << "1/add\n2/remove\n3/print the element" << '\n';
  int n ;
  cin>>n ;
  while (n !=0) {
    if (n==1) {
      std::cout << "Enter the element you want to add" << '\n';
      int e ;
      cin>>e ;
      stk.push(e) ;
    }
    if (n==2) {
      stk.pop() ;
    }
    if (n==3) {
      stk.print() ;
    }
    std::cout << "What do you want: " << '\n';
    std::cout << "1/add\n2/remove\n3/print the element" << '\n';
    cin>>n;
  }
}
//Queu function to initilaze the Queu and prepare the user to work with it propaply
void Queu() {
  queue que ;
  std::cout << "What do you want: " << '\n';
  std::cout << "1/add\n2/remove\n3/print the element" << '\n';
  int n ;
  cin>>n ;
  while (n !=0) {
    if (n==1) {
      std::cout << "Enter the element you want to add" << '\n';
      int e ;
      cin>>e ;
      que.enqueue(e) ;
    }
    if (n==2) {
      que.dequeue() ;
    }
    if (n==3) {
      que.print() ;
    }
    std::cout << "What do you want: " << '\n';
    std::cout << "1/add\n2/remove\n3/print the element" << '\n';
    cin>>n;
  }
}
int main() {


  std::cout << "Choose the Data structure you Want to use : " << '\n';
  std::cout << "1/LinkedList\n2/Stack\n3/Queue " << '\n';
  std::cout << "If You Want to Exit press 0" << '\n';
  int n ;
  cin>>n ;
  // while loop make the proccess always run until the user press 0 .
  while (n!=0)

    if (n==1) {
      Linkedlist();
      break;
    }
    else if (n==2) {
      Stack() ;
      break;
    }
    else if (n==3) {
      Queu() ;
      break;
    }

  return 0 ;
}
