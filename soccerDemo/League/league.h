#ifndef LEAGUE_H
#define LEAGUE_H
#include <string>
#include ".\..\Season\season.h"

using namespace std;

class League {
    private:
    string name;
    season league_seasons[31];
    int length_weeks;
    public:
    League(string _name) {
        name = _name;
        length_weeks = 0;
    }
    League(string _name, int _length_weeks) {
        name = _name;
        length_weeks = _length_weeks;
    }
    
    void setLength(int _length_weeks) {
        length_weeks = _length_weeks;
    }

    int getLength ( ) {
        return length_weeks;
    }
};
#endif