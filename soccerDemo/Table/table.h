#ifndef TABLE_H
#define TABLE_H
#include ".\..\Team\Team.h"
using namespace std;

class Table{
    private:
        int counter = 1;
        Team teams[16];
        int points[16];
    public:
        Table(){
            for(auto i : teams){
                i = Team();
            }
            for(int i = 0; i < 16; i++){
                points[i] = 0;
            }
        } 
        Table(Team _teams[16]){
            for(int i = 0; i < 16; i++){
                teams[i] = _teams[i];
            }
            for(int i = 0; i < 16; i++){
                points[i] = 0;
            }
        }
        void addTeam(Team _team){
            int i = 0;
            while(teams[i].getName() != ""){
                i++;
                if(i >= 16)
                    break;
            }
            if(i >= 16)
                cout<<"league season full";
            else {
                teams[i] = _team;
                points[i] = 0;
            }
        }
        void addPoints(int index, int code){
            points[index] += code;
        }
        void dropTeam(int index){
            teams[index] = Team();
            points[index] = 0;
        }
        void dropPoints(int index, int code){
            points[index] -= code;
        }
        string to_print(){
            string output = "";
            for(int i = 0; i < 16; i++){
                output += to_string(i) + "\t" + teams[i].to_print() + "\t" + to_string(points[i]) + "\n";
            }//right now the for loop prints teams in order they were added. Need to change it to print in points order decending
            cout << output;
            return output;
        }
};
#endif