/*
This program outputs the unique items from a list.

from https://open.kattis.com/problems/icpcawards

ICPC Awards
The ACM International Collegiate Programming Contest has been held in Vietnam for more than 10 years. The contest is a great chance for the students to meet new friends, broaden their knowledge and of course, win prizes.

Every years, universities can send one or multiple teams to the contest and all universities hope to win prizes. The organizers want to define a rule to award the excellent contestants.

The contest director decided to follow the World Finals policy by having 4 first prizes, 4 second prizes and 4 third prizes. 12 winners out of more than a hundred teams is also a good proportion to recognize the best students.

Since universities can send multiple teams, we don’t want one university to swept all the awards. Thus, only the top team from a university can be awarded. It seems harsh for the second best team from one university but do not worry, they will still receive relevant certificates.

Given the final scoreboard of the contest, your task is to determine which 12 teams should be awarded prizes.

Input
The input starts with the number of teams N (12≤N≤200).

The i-th line of the next N lines contains information about the team that ranks i: the university name and the team name separated by a single space. Both names consist of digits and lowercase and uppercase English alphabet letters only. Both names do not exceed 20 letters in length.

It is guaranteed that there are at least 12 different universities.

Output
The output should contain 12 lines describing 12 winners. In each line, you should print the university name and the team name separated by a single space. The winners should be listed in the same order as the input.

***************************************
Sample Input 1
***************************************
30
Seoul ACGTeam
VNU LINUX
SJTU Mjolnir
VNU WINDOWS
NTU PECaveros
HUST BKJuniors
HCMUS HCMUSSerendipity
VNU UBUNTU
SJTU Metis
HUST BKDeepMind
HUST BKTornado
HCMUS HCMUSLattis
NUS Tourism
VNU DOS
HCMUS HCMUSTheCows
VNU ANDROID
HCMUS HCMUSPacman
HCMUS HCMUSGeomecry
UIndonesia DioramaBintang
VNU SOLARIS
UIndonesia UIChan
FPT ACceptable
HUST BKIT
PTIT Miners
PSA PSA
DaNangUT BDTTNeverGiveUp
VNU UNIXBSD
CanTho CTUA2LTT
Soongsil Team10deung
Soongsil BezzerBeater

***************************************
Sample Output 1
***************************************
Seoul ACGTeam
VNU LINUX
SJTU Mjolnir
NTU PECaveros
HUST BKJuniors
HCMUS HCMUSSerendipity
NUS Tourism
UIndonesia DioramaBintang
FPT ACceptable
PTIT Miners
PSA PSA
DaNangUT BDTTNeverGiveUp
*/

#include "iostream"
#include "vector"

using namespace std;

int main()
{
  vector<string> teams, schools;
  int num_schools;
  cin >> num_schools;
  string team, go_us;

  cin >> go_us >> team;
  schools.push_back(go_us);
  teams.push_back(team);
  for (int i = 0; i < num_schools - 1; i++)
  {
    bool is_dup = false;
    cin >> go_us >> team;
    for (int j = 0; j < schools.size(); j++)
    {
      if (schools[j] == go_us)
      {
        is_dup = true;
        break;
      }
    }

    if (!is_dup)
    {
      schools.push_back(go_us);
      teams.push_back(team);
    }
  }

  for (int i = 0; i < 12; i++)
  {
    cout << schools[i] << " " << teams[i] << endl;
  }

  return 0;
}
