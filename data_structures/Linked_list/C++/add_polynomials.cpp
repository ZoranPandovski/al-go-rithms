#include <iostream>
using namespace std;

class Node
{
private:
  int data;
  int pow;
  Node *next;
  friend class SLL;

public:
  Node(int data, int pow, Node *next = 0) : data(data), pow(pow), next(next) {}
};

class SLL
{
private:
  Node *head;
  Node *tail;

public:
  SLL() : head(0), tail(0) {}
  void insertAtHead(int, int);
  void display();
  SLL traverse(SLL &);
};

void SLL::insertAtHead(int data, int pow)
{
  Node *node = new Node(data, pow, head);
  head = node;
  if (!tail)
    tail = head;

  return;
}

void SLL::display()
{
  Node *curr = head;

  while (curr != 0)
  {
    cout << "  " << curr->data << "x^" << curr->pow;
    if (curr->next != 0)
      cout << " +";
    curr = curr->next;
  }

  return;
}

SLL SLL::traverse(SLL &obj)
{
  Node *currOne = head;
  Node *currTwo = obj.head;
  SLL polyThree;

  while (currOne != 0 && currTwo != 0)
  {
    while (currOne != 0 && currTwo != 0 && currOne->pow <= currTwo->pow)
    {
      if (currOne->pow == currTwo->pow)
      {
        polyThree.insertAtHead(currOne->data + currTwo->data, currOne->pow);
        currTwo = currTwo->next;
      }

      else
        polyThree.insertAtHead(currOne->data, currOne->pow);

      currOne = currOne->next;
    }

    while (currOne != 0 && currTwo != 0 && currOne->pow >= currTwo->pow)
    {
      if (currOne->pow == currTwo->pow)
      {
        polyThree.insertAtHead(currOne->data + currTwo->data, currOne->pow);
        currOne = currOne->next;
      }
      else
        polyThree.insertAtHead(currTwo->data, currTwo->pow);

      currTwo = currTwo->next;
    }
  }

  while (currOne != 0)
  {
    polyThree.insertAtHead(currOne->data, currOne->pow);
    currOne = currOne->next;
  }

  while (currTwo != 0)
  {
    polyThree.insertAtHead(currTwo->data, currTwo->pow);
    currTwo = currTwo->next;
  }

  return polyThree;
}

int main()
{
  SLL polyOne;
  int deg, coeff;

  cout << "\nEnter degree of first polynomial : ";
  cin >> deg;
  cout << "\npolynomial one : ";
  for (int i = deg; i >= 0; i--)
  {
    cout << "\nEnter " << i << "th degree's coeff : ";
    cin >> coeff;

    if (coeff != 0)
      polyOne.insertAtHead(coeff, i);
  }

  cout << "\npoly one :\n";
  polyOne.display();

  SLL polyTwo;

  cout << "\nEnter degree of second polynomial : ";
  cin >> deg;
  cout << "\npolynomial two : ";

  for (int i = deg; i >= 0; i--)
  {
    cout << "\nEnter " << i << "th degree's coeff : ";
    cin >> coeff;

    if (coeff != 0)
      polyTwo.insertAtHead(coeff, i);
  }

  cout << "\npoly two :\n";
  polyTwo.display();

  SLL polyThree = polyOne.traverse(polyTwo);
  cout << "\npoly three :\n";
  polyThree.display();
}