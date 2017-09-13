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
      "Kilauea, a shield volcano on the island of Hawai'i, has been erupting continuously since 1983. true or false?",
      "There are only 8 islands in the Hawaiian archipelago. true or false?",
      "Kamehameha I conquered the Hawaiian Islands and established a unified monarchy across the archipelago. true or false?",
      "Many wonderful macaque monkeys inhabit the Hawaiian Islands. true or false?",
      "Hawaiian Monk Seals are endemic to the Hawaiian Islands. true or false?",
      "Hawai'i is farther south than the Florida Keys. true or false?",
      "Hawai'i is farther west than Alaska. true or false?",
      "You can swim with sea turtles in Hilo and spinner dolphins in Kona. true or false?",
      "There are only 12-13 letters in the Hawaiian alphabet. true or false?",
      "The wind generally blows west to east in Hawai'i. true or false?",
      "Moloka'i has the world's highest sea cliffs. true or false?",
      "No flora is endemic to Hawai'i. true or false?",
      "The biggest telescope in the world is on top of Mauna Kea. true or false?",
      "Lauwiliwilinukunukuʻoiʻoi is the name of a fish. true or false?",
      "Botswana is on the opposite side of thet world from the Big Island. true or false?",
      "In 1946, at 16+ meter tsunami hit Hilo. true or false?",
      "Hawai'i has more earthquakes than California. true or false?",
      "Hawai'i has more earthquakes than Alaska. true or false?",
      "More than one-third of the world's commercial supply of pineapples comes from Hawaii. true or false?",
      "The Hawaiian Archipelago consists of over 130 scattered points of land. true or false?"
    };
    string answers[20] = {
      "true",
      "false",
      "true",
      "false",
      "true",
      "true",
      "false",
      "true",
      "true",
      "false",
      "true",
      "false",
      "true",
      "true",
      "true",
      "false",
      "false",
      "true",
      "true"
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
 *  returns a pointer pointing to an array of 2 strings,
 *  the question and the answer.
 *  @return The question and answer
 */
string * ZoneMap::randomQuestion()
{
  string qNa[2];
  int questionNum = rand() % 20;
  qNa[0] = questions[questionNum];
  qNa[1] = answers[questionNum];
  return qNa;
}
