#ifndef FILE_H
#define FILE_H
#include <ctime>
#include <string>
#include <map>
#include "Tree.hpp"

using namespace std;

const map<int,string> MONTHS ={
    { 1 , "January"},
    { 2 , "February"},
    { 3 , "March"},
    { 4 , "April"},
    { 5 , "May"},
    { 6 , "June"},
    { 7 , "July"},
    { 8, "August"},
    { 9,"September"},
    {10,"October"},
    {11, "November"},
    {12, "December"}
};

class root
{
    private:
        string name;
        string date;
        long size;
        string user;
        bool isFile;
        string Owner;
        string Group;
        string Public;
        string convertcCharToBin( char digit);

    public:
        root();
        void setName(string name);
        void setdate(time_t now);
        void setFileSize(long size);
        void setUser(string userName);
        void setIsFile(bool fileOrFolder);
        void setOwner(char digit);
        void setGroup(char digit);
        void setPublic(char digit);
        string getOwner(){ return Owner;}
        string getGroup(){ return Group;}
        string getPublic(){ return Public;}
        string getName();
        string getDate();
        long getSize();
        string getUser();
        bool getIsFile();

};

#endif
