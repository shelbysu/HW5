/*
Author: Shelby Sutter
 Program HW5
 Last modified December 12, 2021
 Problem: searching for a full name in the list and displaying said name if it is in the list
*/
#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>
#include "listtoolshb.h"
#include "listtoolshb.cpp"

struct Profile{
    string fullname;
    string state;
    bool operator==( Profile rhs)
    {if (fullname==rhs.fullname) return true; return false; }
    bool operator!=(Profile rhs)
    {if (fullname!=rhs.fullname) return true; return false; }
};
ostream& operator<< (ostream &out, Profile &user){
    out << user.fullname<<"--"<<user.state;
    return out;
}

int main() {
    Profile temp;
    string line;
    MyList<Profile> pMyList;
    ifstream file("C:\\Users\\Shelby\\CLionProjects\\HW5\\presidentsWstates.txt");
    if (file.is_open()){
        while (getline(file, line)){
            stringstream ss(line);
            getline(ss, temp.fullname, '\t');
            getline(ss, temp.state, '\t');
            pMyList.insertHead(temp);
        }
    }
    //pMyList.display();
    cout<< "\n_______________________________\n"<<endl;
    Profile p1;
    p1.fullname = "Gerald R. Ford";
    Profile target=p1;
   // pMyList.search(target);
    //pMyList.deleteHead();
    //pMyList.display();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
