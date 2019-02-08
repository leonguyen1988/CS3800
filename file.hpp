#ifndef FILE_H
#define FILE_H
#include <ctime>
#include <string>
#include "Tree.hpp"

using namespace std;

class root
{
    private:
        string name;
        time_t date;
        long size;
        string user;
        bool isFile;
    public:
        root();
        void setName(string name);
        void setdate(time_t now);
        void setFileSize(long size);
        void setUser(string userName);
        void setIsFile(bool fileOrFolder);
        string getName();
        time_t getDate();
        long getSize();
        string getUser();
        bool getIsFile();

};

#endif
