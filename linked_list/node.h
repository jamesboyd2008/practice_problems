// This file contains an implementation of a Linked List as a grocery list.
#include <iostream>
using namespace std;

struct ListNode {
  string item;
  int quantity;
  ListNode *Link;
}

typedef *ListNode ListNodePtr;
