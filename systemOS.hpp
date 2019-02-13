#ifndef SYSTEM_OS
#define SYSTEM_OS
#include <ctime>
#include <string>
#include <map>
#include "Tree.hpp"
using namespace std;

class systemOS
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
        string UpdateDate();
    public:
        // Default Construtor
        systemOS()
        {
            setdate();
            size = rand() %1000 +1000000;
            setOwner('6');
            setGroup('7');
            setPublic('1');
            setUser("Student");
        }
        void setName(string name);
        void setdate();
        void setFileSize(long size);
        void setUser(string userName);
        void setIsFolder(bool fileOrFolder);
        void setOwner(char digit);
        void setGroup(char digit);
        void setPublic(char digit);
        string getOwner() { return Owner;}
        string getGroup() { return Group;}
        string getPublic() { return Public;}
        string getName() { return name;}
        string getDate() { return date;}
        long getSize()  {return size;}
        string getUser() {return user;}
        bool getIsFolder() {return isFile;}
        void printFullDirectory(Tree<systemOS>::Node* directory);
        Tree<systemOS>::Node* UpdatePermission(Tree<systemOS>::Node* node, string permissionDetail);
        void printError();
        Tree<systemOS>::Node* Delete(Tree<systemOS>::Node* root, string name);
        systemOS addNode(string name,int isFile);
        bool isExist(Tree<systemOS>::Node* root,string name);
        bool isFolder(Tree<systemOS>::Node* root,string name);
};

#endif
