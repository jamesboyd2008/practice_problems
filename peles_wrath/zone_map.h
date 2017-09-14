// This is the ZoneMap class
#include "zone.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class ZoneMap
{
  private:
    Zone zones[5][5];
    const string adjectives[20] = {
      "a beautiful",
      "an ugly",
      "a lovely",
      "an abominable",
      "a serene",
      "a dystopian",
      "a utopian",
      "a foul",
      "a heavenly",
      "a hellacious",
      "an enormous",
      "a tiny",
      "a gorgeous",
      "a dazzling",
      "an exquisite",
      "a bewitching",
      "a sublime",
      "an inferior",
      "a repulsive",
      "a drab"
    };
    const string nouns[20] = {
      "papaya farm",
      "jungle",
      "lava field",
      "tide pool",
      "coconut grove",
      "pineapple field",
      "taro field",
      "mountain",
      "cow pasture",
      "river",
      "warm pond",
      "mosquito hut",
      "beach",
      "lava tube",
      "rainforest",
      "black sand beach",
      "fish hatchery",
      "macadamia grove",
      "botanical garden",
      "cinder road"
    };
    const string questions[20] = {
      "Kilauea, a shield volcano on the island of Hawai'i, has been erupting continuously since 1983. t or f?",
      "There are only 8 islands in the Hawaiian archipelago. t or f?",
      "Kamehameha I conquered the Hawaiian Islands and established a unified monarchy across the archipelago. t or f?",
      "Many wonderful macaque monkeys inhabit the Hawaiian Islands. t or f?",
      "Hawaiian Monk Seals are endemic to the Hawaiian Islands. t or f?",
      "Hawai'i is farther south than the Florida Keys. t or f?",
      "Hawai'i is farther west than Alaska. t or f?",
      "You can swim with sea turtles in Hilo and spinner dolphins in Kona. t or f?",
      "There are only 12-13 letters in the Hawaiian alphabet. t or f?",
      "The wind generally blows west to east in Hawai'i. t or f?",
      "Moloka'i has the world's highest sea cliffs. t or f?",
      "No flora is endemic to Hawai'i. t or f?",
      "The biggest telescope in the world is on top of Mauna Kea. t or f?",
      "Lauwiliwilinukunukuʻoiʻoi is the name of a fish. t or f?",
      "Botswana is on the opposite side of thet world from the Big Island. t or f?",
      "In 1946, at 16+ meter tsunami hit Hilo. t or f?",
      "Hawai'i annually experiences more earthquakes than California. t or f?",
      "Hawai'i annually experiences more earthquakes than Alaska. t or f?",
      "More than one-third of the world's commercial supply of pineapples comes from Hawaii. t or f?",
      "The Hawaiian Archipelago consists of over 130 scattered points of land. t or f?"
    };
    string answers[20] = {
      "t",
      "f",
      "t",
      "f",
      "t",
      "t",
      "f",
      "t",
      "t",
      "f",
      "t",
      "f",
      "t",
      "t",
      "t",
      "t",
      "f",
      "f",
      "t",
      "t"
    };
  public:
    ZoneMap();
    string randomDescription();
    string * randomQuestion();
    Zone getZone(int row, int column);
};

/**
 *  a constructor, initialize a ZoneMap.
 *  @return ZoneMap
 */
ZoneMap::ZoneMap()
{
  unsigned seed;
  seed = time(0);
  srand(seed);

  // fill in the zones
  for (int i = 0; i < 5; i++) // rows
  {
    for (int j = 0; j < 5; j++) // columns
    {
      // Zone(string describeIt, string newQuestion, string rightAnswer);
      string *theQuestion;
      theQuestion = randomQuestion();
      zones[i][j] = Zone(randomDescription(), theQuestion[0], theQuestion[1]);
    }
  }
}

/**
 *  returns a string, a description of the environment.
 *  @return The description
 */
string ZoneMap::randomDescription()
{
  string description = adjectives[rand() % 20] + " "
                          + nouns[rand() % 20] + ".";
  return description;
}

/**
 *  returns a pointer pointing to an array of 2 strings,
 *  the question and the answer.
 *  @return The question and answer
 */
string * ZoneMap::randomQuestion()
{
  static string qNa[2];
  int questionNum = rand() % 20;
  qNa[0] = questions[questionNum];
  qNa[1] = answers[questionNum];
  return qNa;
}

/**
 *  takes two integer paramaters and returns the associated zone object.
 *  @param row
 *  @param column
 *  @return zone
 */
Zone ZoneMap::getZone(int row, int column)
{
  return zones[row][column];
}
