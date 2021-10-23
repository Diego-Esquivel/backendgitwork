#ifndef SEASON_H
#define SEASON_H
#include ".\..\Table\table.h"
#include ".\..\Location\location.h"
using namespace std;

class season{
    private: 
        Table table;
    public:
        season() {
            table = Table();
        }
        season(Table _table) {
            table = _table;
        }

        void setTable(Table _table) {
            table = _table;
        }

        Table getTable() {
            return table;
        }

        void addTeam(Team _team){
            table.addTeam(_team);
        }
        void dropTeam(int index) {
            table.dropTeam(index);
        }

        void addPoints(int index, int points) {
            table.addPoints(index, points);
        }
        void dropPoints(int index, int points) {
            table.addPoints(index, points);
        }

        string to_print() {
            
        }

};
#endif