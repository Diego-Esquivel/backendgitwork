#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
using namespace std;

class Player {
    private:
        string name;
        int goals;
        int assists;
    public:
        Player(){
            name = "";
            goals = 0;
            assists = 0;
        };
        Player(string _name){
            name = _name;
            goals = 0;
            assists = 0;
        };
        void setName(string _name){
            name = _name;
        };
        string getName(){
            return name;
        };
        void setGoals(){
            goals += 1;
        };
        int getGoals(){
            return goals;
        };
        void setAssists(){
            assists += 1;
        };
        int getAssists(){
            return assists;
        };
        string to_print() {
            string output = "<div id=\"" + getName() + "\">" + getName() + "\t" + "Goals : " + to_string(getGoals()) + "\t" + "Assists : " + to_string(getAssists()) + "<\\div>";
            return output;
        };

};
#endif