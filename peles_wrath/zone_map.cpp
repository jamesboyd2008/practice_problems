// This is the ZoneMap class
#include "zone.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class ZoneMap
{
  private:
    Zone zones[5][5];
    string adjectives[12] = { "a beautiful", "an ugly", "a lovely",
      "an abominable", "a serene", "a dystopian", "a utopian", "a foul",
      "a heavenly", "a hellacious", "an enormous", "a tiny"};
    string nouns[13] = { "papaya farm", "jungle", "lava field", "tide pool",
      "coconut grove", "pineapple field", "taro field", "mountain",
      "cow pasture", "river", "warm pond", "mosquito hut", "beach"};
    string questions[20] = {
      "",
      "There are only 8 islands in the Hawaiian archipelago. true/false",
      "Kamehameha I conquered the Hawaiian Islands and established a unified monarchy across the archipelago. true/false",
      "",
      "",
      "",
      "",
      "",
      "",
      "",
      "",
      "",
      "",
      "",
      "",
      "",
      "",
      "",
      "",
      ""
    };
    string answers[20] = {
      "",
      "false",
      "true",
      "",
      "",
      "",
      "",
      "",
      "",
      "",
      "",
      "",
      "",
      "",
      "",
      "",
      "",
      "",
      "",
      ""
    }
  public:
    Map();
    string randomDescription();
    string randomQuestion(); // returns an array of two strings, Q & A
}

/**
 *  a constructor, initialize a ZoneMap.
 *  @return ZoneMap
 */
// ZoneMap::ZoneMap()
// {
//   // fill in some zones
//   for (int i = 0; i < 5; i++) // rows
//   {
//     for (int j = 0; j < 5; j++) // columns
//     {
//       // Zone(string describeIt, string newQuestion, string rightAnswer);
//       string theQuestion[2] = randomQuestion();
//       zones[i][j] = Zone(randomDescription(), theQuestion[0], theQuestion[1]);
//     }
//   }
// }

/**
 *  returns a string, a description of the environment.
 *  @return The description
 */
string ZoneMap::randomDescription()
{
  string description = "You are in " + adjectives[rand() % 12] + " "
                                     + nouns[rand() % 13] + ".";
  return description;
}

/**
 *  returns an array of 2 strings, the question and the answer.
 *  @return The question and answer
 */
string ZoneMap::randomQuestion()
{

}
