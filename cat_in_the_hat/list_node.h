// This file contains an implementation of a Linked List.
#include <iostream>
#include <cstddef>
#include <iomanip>
#include <string>
using namespace std;

struct ListNode {
  string name;
  int position;
  ListNode *next;
  ListNode *previous;
  ListNode
  (
    string newName,
    int newQuantity,
    ListNode *nextNode = nullptr,
    ListNode *previousNode = nullptr
  )
  {
    name = newName;
    position = newQuantity;
    next = nextNode;
    previous = previousNode;
  }
};

typedef ListNode* ListNodePtr;

// adds another node to the head of the linked list
void addNode(ListNodePtr nextNode, ListNodePtr head)
{
  nextNode->next = head;
  head->previous = nextNode;
}

// removes a node from the linked list
void deleteNode(ListNodePtr deleteMe)
{
  deleteMe->previous->next = deleteMe->next;
  deleteMe->next->previous = deleteMe->previous;
  delete deleteMe;
}
