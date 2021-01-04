#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;

using std::system;
using std::cin;

int main () {
    std::string str;
    cout << "Enter name of the video to upload: ";
    cin >> str;
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
    f << "<li><video src=\"" << str << "\" playsinline=true width=200 height=200 controls=true></video></li>" << endl << copyhalfcontents.rdbuf();
    std::string gitstring = "gitbashfile " + str;
    cout << gitstring;
    f.close();
    system(gitstring.c_str());
    //system("git commit -m 'Update to page'");
    //system("git push");
    copyhalfcontents.close();
    f.close();
    return 0;
}