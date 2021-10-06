#include <string>
using namespace std;

class location{
    private:
        string name;
        string address;
        string photo;
    public:
        location(){
            name = "";
            address = "";
            photo = "";
        }
        location (string _name, string _address){
            name = _name;
            address = _address;
            photo = "";
        }
        location(string _name, string _address, string _photo){
            name = _name;
            address = _address;
            photo = _photo;
        }
        void setName(string _name){
            name = _name;
        }
        void setAddress(string _address){
            address = _address;
        }
        void setPhoto(string _photo){
            photo = _photo;
        }
        string getName(){
            return name;
        }
        string getAddress(){
            return address;
        }
        string getPhoto(){
            return photo;
        }
};