#ifndef TEAM_H
#define TEAM_H
#include ".\..\Player\player.h"

class Team {
    private:
        string name;
        Player players[31];
    public:
        Team(){
            name = "";
            for(auto i :  players){
                i = Player();
            }
        };
        Team(string _name){
            name = _name;
            for(auto i :  players){
                i = Player();
            }
        };
        void setName(string _name){
            name = _name;
        };
        string getName(){
            return name;
        };
        void addPlayer(Player _player){
            int i = 0;
            while(players[i].getName() != ""){
                i++;
            }
            players[i].setName(_player.getName());
            for(int d = _player.getGoals(); d > 0; d--){
                players[i].setGoals();
            }
            for(int d = _player.getAssists(); d > 0; d--){
                players[i].setAssists();
            }
        };
        Player getPlayer(int index){
            if(index < 31)
                return players[index];
            return players[30];
        };
        void removePlayer(int index){
            if(index > 31)
                players[30] = Player();
            else
                players[index] = Player();
        };
        string to_print(){
            string output = "<div id=\"" + getName() + "\">" + "<div id=\"team_name\">" + getName() + "<\\div>\n";
            int i = 0;
            while ( i < 31 && getPlayer(i).getName() != "" ){
                output += getPlayer(i).to_print() + "\n";
                i++;
            }
            output += "<\\div>";
            cout << output;
            return output;
        };
};
#endif