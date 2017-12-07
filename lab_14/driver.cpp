// This was almost the driver program for the binaryTreeType class.

#include "binaryTreeType.h"
// #include "binarySearchTree.h"

using namespace std;

int main()
{
  binaryTreeType<int> tree1;
  binaryTreeType<int> tree2;

  nodeType<int> node1;
  nodeType<int> node2;
  nodeType<int> node3;
  nodeType<int> node4;
  nodeType<int> node5;
  nodeType<int> node6;

  node1.info = 42;
  node2.info = 20;
  node3.info = 19;
  node4.info = 21;
  node5.info = 52;
  node6.info = 90;

  node1.lLink = &node2;
  node1.rLink = &node5;

  node2.lLink = &node3;
  node2.rLink = &node4;

  node3.lLink = nullptr;
  node3.rLink = nullptr;

  node4.lLink = nullptr;
  node4.rLink = nullptr;

  node5.rLink = &node6;
  node5.lLink = nullptr;

  node6.lLink = nullptr;
  node6.rLink = nullptr;


  cout << "I really didn't complete this assignment.\n"
       << "I read over the functions, and I believe I mostly understand them.\n"
       << "I understand that trees will be coming up a lot next semester,\n"
       << "and that it will behoove me to understand them\n";
       << "and this assignment.\n";

  return 0;
}
