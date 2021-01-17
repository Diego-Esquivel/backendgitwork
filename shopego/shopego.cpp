#include <iostream>
#include <fstream>
#include <string>
//#include "..\WindowsToolInstaller\git"

using std::cout;
using std::endl;

using std::system;
using std::cin;

int main () {
    //WindowsToolInstaller::git::main();implements later;
    std::string str;
    std::string price;
    cout << "Please be certain the item content is in the folder with the application.\nContent includes but is not limited to content image.\n";
    cout << "Enter name of the item image to upload: ";
    cin >> str;
    cout << "Enter name of the item price to upload: ";
    cin >> price;
    char * itemname = new char[str.length() - 3];
    for(int i = 0; i != str.length() - 4; i++){
        itemname[i] = str[i];
        cout << str[i];
    }
    itemname[str.length() - 4] = '\0';
    std::fstream f("shopego.html");
    std::fstream copyhalfcontents;
    copyhalfcontents.open("temp.txt", std::ios_base::out | std::ios_base::trunc);
    char character = ' ';
    bool foundU = false;
    bool foundL = false;
    bool foundSlash = false;
    int counter = 0;
    int pointertoenddiv = 0;
    while(!f.eof()) {
        f.read(&character, 1);
        if(character == '/')
            foundSlash = true;
        else if(foundSlash && character == 'u')
            foundU = true;
        else if(foundU && character == 'l') {
            foundL = true;
            pointertoenddiv = f.tellg();
        }
        else {
            foundSlash = false;
            foundL = false;
            foundU = false;
        }
    }
    f.close();
    f.open("shopego.html");
    f.seekg(pointertoenddiv - 14, std::ios::beg);
    f.seekp(pointertoenddiv - 14, std::ios::beg);
    f.read(&character, 1);
    while(!f.eof()) {
        copyhalfcontents << character;
        f.read(&character, 1);
    }
    copyhalfcontents.close();
    copyhalfcontents.open("temp.txt");
    f.close();
    f.open("shopego.html");
    f.seekg(pointertoenddiv - 14, std::ios::beg);
    f.seekp(pointertoenddiv - 14, std::ios::beg);
    f << "<li><image src=\"" << str << "\" width=200 height=200 ></br>Name: " << itemname << "</br>Cost: " << price << "</image></li>" << endl << copyhalfcontents.rdbuf();
    /*std::string gitstring = "gitbashfile " + str;
    cout << gitstring;
    f.close();
    system(gitstring.c_str());
    */
    //system("git commit -m 'Update to page'");
    //system("git push");
    copyhalfcontents.close();
    f.close();
    return 0;
}