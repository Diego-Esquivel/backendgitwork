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
    cout << "Please be certain the item content is in the folder with the application.\nContent includes but is not limited to a song.\n";
    cout << "Enter name of the item song to upload: ";
    getline(cin,str);
    cout << "Enter name of the song title to upload: ";
    cin >> price;
    std::fstream f("index.html");
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
    f.open("index.html");
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
    f.open("index.html");
    f.seekg(pointertoenddiv - 14, std::ios::beg);
    f.seekp(pointertoenddiv - 14, std::ios::beg);
    f << "<li><audio controls><source src=\"" << str << "\" type=\"audio/mpeg\">Your browser does not support the audio element.</audio><br/>" << price << "</li>" << endl << copyhalfcontents.rdbuf();
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