// This file contains an implementation of a Linked List.
#include <iostream>
#include <cstddef>
#include <iomanip>
#include <string>
using namespace std;

struct ListNode {
  string item;
  int quantity;
  ListNode *next;
  // constructor
  ListNode(string newItem, int newQuantity, ListNode *nextNode = nullptr)
  {
    item = newItem;
    quantity = newQuantity;
    next = nextNode;
  }
};

typedef ListNode* ListNodePtr;

// adds another node to the head of the linked list
void addNode(ListNodePtr nextNode, ListNodePtr head)
{
  nextNode->next = head;
}

// prints the linked list to the console
void printList(ListNodePtr head)
{
  cout << "Quantity" << setw(13) << "Item" << endl;

  ListNodePtr focus = head;
  while(focus)
  {
    cout << focus->quantity << setw(20) << focus->item << "\n";
    focus = focus->next;
  }
  cout << endl;
}

// finds a node within the linked list returning a ListNode,
// taking a ListNode pointer, hopefully pointing to the head of a list,
// and a string as arguments.
ListNodePtr findItem(ListNodePtr list, string value)
{
  ListNodePtr focus = list;
  while(focus)
  {
    if (value.compare(focus->item) == 0)
    {
      return focus;
    }
    focus = focus->next;
  }

  ListNodePtr absentNode = new ListNode("not on list", 0);
  return absentNode;
}

// inserts a node in the linked list,
// taking a string argument of the item after which the new item is
// to be insterted.
// Takes a ListNodePtr of the item to be inserted.
// Takes a ListNodePtr representing the list to which the new node is to
// be added.
void insertNode(ListNodePtr head, string preceedingValue, ListNodePtr newNode)
{
  ListNodePtr searchResult = findItem(head, preceedingValue);
  addNode(newNode, searchResult->next);
  searchResult->next = newNode;
}

// removes a node from the linked list, taking a string as an argument,
// being the item to be deleted.
// Takes a ListNode argument, being the head of the list containing the
// item to be deleted.
void deleteNode(ListNodePtr head, string valueOfDeletion)
{
  ListNodePtr itemOfDeletion = findItem(head, valueOfDeletion);
  ListNodePtr previousNode = nullptr;
  ListNodePtr currentNode = head;

  while (currentNode->next)
  {
    if (currentNode->item.compare(valueOfDeletion) == 0)
    {
      if (previousNode)
      {
        // it's not the head
        previousNode->next = currentNode->next;
        delete currentNode;
      }
      else {
        // it's the head
        delete currentNode;
      }
      break;
    }
    previousNode = currentNode;
    currentNode = currentNode->next;
  }
}
