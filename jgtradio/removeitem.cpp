#include <iostream>
#include <fstream>
#include <string>
//#include "..\WindowsToolInstaller\git"
/*
find line containing list entry for item name
find beginning of line with item name
find end of line with item name
copy contents of file before line with item name
copy contents of file before line with item name
replace file with copied contents
*/

using std::cout;
using std::endl;

using std::system;
using std::cin;

int main () {
    //WindowsToolInstaller::git::main();implements later;
    std::string str;
    cout << "Please be certain the item content is in the same as within the application.\nContent includes but is not limited to a song.\n";
    cout << "Enter name of the item remove: ";
    getline(cin,str);
    std::fstream f("index.html");
    std::fstream copylasthalfcontents;
    std::fstream copyfirsthalfcontents;
    copylasthalfcontents.open("lasttemp.txt", std::ios_base::out | std::ios_base::trunc);
    copyfirsthalfcontents.open("firsttemp.txt", std::ios_base::out | std::ios_base::trunc);
    char character = ' ';
    bool foundI = false;
    bool foundL = false;
    bool foundSlash = false;
    int counter = 0;
    int pointertoenddiv = 0;
    int pointertobegdiv = 0;
    //find line with item name
    while(!f.eof()) {
        f.read(&character, 1);
        if(character == str[counter])
            counter++;
        else {
            counter = 0;    
        }
        if(counter == str.length()){
            pointertoenddiv = f.tellg();
            break;
        }
    }
    counter = 0;
    f.close();
    f.open("shopego.html");
    f.seekg(pointertoenddiv, std::ios::beg);
    f.seekp(pointertoenddiv, std::ios::beg);
    //find beginning of line with item name
    while(f.tellg() != 0) {
        counter++;
        f.read(&character, 1);
        if(character == 'i')
            foundI = true;
        else if(foundI && character == 'l'){
            foundL = true;
            pointertobegdiv = f.tellg();
            pointertobegdiv--;
            break;
        }
        else {
            foundI = false;
            foundL = false;
        }
        f.seekg(pointertoenddiv - counter, std::ios::beg);
    }

    counter = 0;
    f.close();
    f.open("shopego.html");
    f.seekg(pointertoenddiv, std::ios::beg);
    f.seekp(pointertoenddiv, std::ios::beg);
    //find beginning of line with item name
    while(!f.eof()) {
        f.read(&character, 1);
        if(character == '/')
            foundSlash = true;
        else if(foundSlash && character == 'l')
            foundL = true;
        else if(foundL && character == 'i') {
            foundI = true;
            pointertoenddiv = f.tellg();
            pointertoenddiv += 3;
            break;
        }
        else {
            foundSlash = false;
            foundL = false;
            foundI = false;
        }
    }

    f.close();
    f.open("shopego.html");
    f.seekg(pointertoenddiv, std::ios::beg);
    f.seekp(pointertoenddiv, std::ios::beg);
    f.read(&character, 1);
    //copy contents after the item name location
    while(!f.eof()) {
        copylasthalfcontents << character;
        f.read(&character, 1);
    }
    copylasthalfcontents.close();
    f.close();
    f.open("shopego.html");
    f.read(&character, 1);
    //copy first half contents
    while(f.tellg() != pointertobegdiv) {
        copyfirsthalfcontents << character;
        f.read(&character, 1);
    }
    copyfirsthalfcontents.close();
    copylasthalfcontents.open("lasttemp.txt");
    copyfirsthalfcontents.open("firsttemp.txt");
    f.close();
    f.open("shopego.html", std::ios_base::out | std::ios_base::trunc);
    f << copyfirsthalfcontents.rdbuf() << copylasthalfcontents.rdbuf();
    /*std::string gitstring = "gitbashfile " + str;
    cout << gitstring;
    f.close();
    system(gitstring.c_str());
    */
    //system("git commit -m 'Update to page'");
    //system("git push");
    copyfirsthalfcontents.close();
    copylasthalfcontents.close();
    f.close();
    return 0;
}