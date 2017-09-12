// This is the Zone class
#ifndef _ZONE_H
#define _ZONE_H
#include <ctime>
#include <cstdlib>
#include <sstream>
using namespace std;

class Zone
{
  private:
    string description;
    string question;
    string correctResponse;
    int ttl; // time to live
  public:
    Zone(string describeIt, string newQuestion, string rightAnswer);
    void setDescription(string describeIt);
    string getDescription();
    void setQuestion(string newQuestion);
    string getQuestion();
    void setResponse(string rightAnswer);
    bool getResponse();
};

/**
 *  a contructor function, taking three string arguments.
 *  @return Zone
 */
Zone::Zone(string describeIt, string newQuestion, string rightAnswer)
{
  description = "You are " + describeIt;
  question = newQuestion;
  correctResponse = rightAnswer;
  ttl = (rand() % 30) + 30;
}

/**
 *  a mutator function that sets the zone's description,
 *  taking a string argument.
 *  @param describeIt
 */
void Zone::setDescription(string describeIt)
{
  description = "You are " + describeIt;
}

/**
 *  an accessor function that returns a string, the description of the zone.
 *  @return description
 */
string Zone::getDescription()
{
  ostringstream ostr;
  ostr << "You must answer this question in " << ttl << " seconds or "
       << "you will be engulfed in lava.\n" << description;
  return ostr.str();
}

/**
 *  a mutator function that sets the question to be asked within the zone,
 *  taking a string argument.
 *  @param newQuestion
 */
void Zone::setQuestion(string newQuestion)
{
  question = newQuestion;
}

/**
 *  an accessor function that returns a string, the zone's description.
 *  @return description
 */
string Zone::getQuestion()
{
  return question;
}

/**
 *  a mutator function that sets a string, the correct response to the question,
 *  taking a string as an argument.
 *  @param rightAnswer
 */
void Zone::setResponse(string rightAnswer)
{
  correctResponse = rightAnswer;
}

/**
 *  prompts a user for a response, prints the accuracy of the users response,
 *  then returns a boolean, the accuracy of the user's response.
 *  @return accuracy
 */
bool Zone::getResponse()
{
  bool result = true;
  string response;
  cout << "What say you? ";
  cin >> response;
  if (correctResponse != response)
  {
    cout << "\nIncorrect\n\n";
    result = false;
  }
  else
  {
    cout << "\nCorrect\n\n";
  }
  cout << "The correct answer was " << correctResponse << endl;
  cout << "You responded -------> " << response << endl;

  return result;
}
#endif
