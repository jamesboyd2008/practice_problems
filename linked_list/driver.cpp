// Driver program for Linked List implementation as a grocery list.
#include "list_node.h"
using namespace std;

int main()
{
  ListNodePtr firstNode = new ListNode("flowers", 7);
  ListNodePtr secondNode = new ListNode("nails", 9);
  ListNodePtr thirdNode = new ListNode("\'nanners", 3);
  addNode(secondNode, firstNode);
  addNode(thirdNode, secondNode);

  printList(thirdNode);

  ListNodePtr searchResult = findItem(thirdNode, "nails");
  cout << "the result of your search: " << endl;
  cout << "item: " << searchResult->item << endl;
  cout << "quantity: " << searchResult->quantity << "\n\n";

  ListNodePtr fourthNode = new ListNode("paint juice", 1);
  insertNode(thirdNode, "nails", fourthNode);
  cout << "Your list, after inserting a node: \n";
  printList(thirdNode);

  cout << "Your list, after deleting a node: \n";
  deleteNode(thirdNode, "nails");
  printList(thirdNode);

  return 0;
}
