// This program deteremines whether a string is a pallindrome
#include <iostream>
#include <string>
#include "queue.cpp"
#include "stack.cpp"

/*
Prompt user to enter some text.
Normalize the input.
Pump it into a stack and a cue. Learn to spell queue.
Pop off pieces of each, one at a time, comparing them.
If any of the pieces don't match, print that it ain't a pallindrome.
If none of the pieces don't match, print that it's a pallindrome.
*/
int main()
{
    Stack stack;
    Queue queue;
    char next, ans;

    do
    {
      cout << "Enter a word: ";
      cin.get(next);
      while (next != '\n')
      {
        // downcase all letters, remove non-letters
        int ordinal = static_cast<int>(next);
        if (
          (ordinal >= 65 && ordinal <= 90) ||
          (ordinal >= 97 && ordinal <= 122)
        )
        {
          stack.push(static_cast<char>(tolower(next)));
          queue.add(static_cast<char>(tolower(next)));
        }
        cin.get(next);
      }

      // determine whether it's a pallindrome
      bool flag = true;
      while ( ! stack.empty() )
      {
        if (queue.remove() != stack.pop())
          flag = false;
      }

      cout << "It is " << (flag ? "" : "not ")
           << "a pallindrome." << "\n";

      cout << "Again?(y/n): ";
      cin >> ans;
      cin.ignore(10000, '\n');
    } while (ans != 'n' && ans != 'N');

    return 0;
}
