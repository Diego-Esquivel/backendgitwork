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
            }
            teams[i] = _team;
            points[i] = 0;
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
        void print(){
            string output = "";
            for(int i = 0; i < 16; i++){
                output += to_string(i) + "\t" + teams[i].getName() + "\t" + to_string(points[i]) + "\n";
            }
            cout << output;
        }
};
#endif