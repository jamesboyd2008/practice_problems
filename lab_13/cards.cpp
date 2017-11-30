/*
This program outputs card suites.
*/

#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <list>
#include <random>
#include <string>
#include <vector>
#include "Card.h"


using namespace std;

int main()
{
  vector <Card> deck;
  vector <string> suits = { "spades", "hearts", "diamonds", "clubs" };
  vector <string> values =
    { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
  vector <int> points =
    {  2,   3,   4,   5,   6,   7,   8,   9,   10,  11,  12,  13,  14, };

  // build deck
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 13; j++)
    {
      Card card(suits[i], values[j], points[j]);
      deck.push_back(card);
    }
  }

  // ensure proper build
  // for (Card x: deck) cout << x << endl;

  unsigned seed = chrono::system_clock::now().time_since_epoch().count();

  // shuffle deck
  shuffle (deck.begin(), deck.end(), default_random_engine(seed));

  // ensure shuffle
  // for (Card x: deck) cout << x << endl;

  list <Card> left_hand;
  list <Card> right_hand;

  // deal cards
  for (int i = 0; i < 5; i++)
  {
    left_hand.push_back(deck.back());
    deck.pop_back();
    right_hand.push_back(deck.back());
    deck.pop_back();
  }

  list <Card>:: iterator itercard;

  // output first hand
  cout << "\nfirst hand:\n";
  for (itercard = left_hand.begin(); itercard != left_hand.end(); itercard++)
  {
    cout << *itercard << endl;
  }

  // output second hand
  cout << "\nsecond hand:\n";
  for (itercard = right_hand.begin(); itercard != right_hand.end(); itercard++)
  {
    cout << *itercard << endl;
  }

  cout << "\n";

  // play war
  int player_1_score, player_2_score;
  player_1_score=player_2_score=0;

  for (int i = 0; i < 5; i++)
  {
    Card left = left_hand.back();
    Card right = right_hand.back();
    left_hand.pop_back();
    right_hand.pop_back();

    cout << "\nround " << (i + 1) << ":\n";
    cout << left << endl;
    cout << right << endl;

    if (left.get_points() > right.get_points())
      player_1_score++;
    else if (right.get_points() > left.get_points())
      player_2_score++;
  }

  cout << "\nPlayer one points: " << player_1_score << endl;
  cout << "Player two points: " << player_2_score << endl << endl;

  if (player_1_score > player_2_score)
    cout << "Player one wins.\n\n";
  else if (player_2_score > player_1_score)
    cout << "Player two wins.\n\n";
  else
    cout << "Nobody wins.\n\n";

  return 0;
}
