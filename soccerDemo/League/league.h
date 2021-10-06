#ifndef LEAGUE_H
#define LEAGUE_H
#include <string>
#include ".\..\Season\season.h"

using namespace std;

class League {
    private:
    string name;
    season league_seasons[31];
    public:
    League(string _name) {
        name = _name;
    }
};
#endif