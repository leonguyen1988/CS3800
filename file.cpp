#include <cstdlib>
#include "file.hpp"

using namespace std;

root::root(){
    name="";
    date = time(0);
    size = 0;
    user = "";
}

void root::setName(string selectedName)
{
    name = selectedName;
}

void root::setdate(time_t now)
{
    date = now;
}

void root::setFileSize(long sizeFile)
{
    size = sizeFile;
}

void root::setUser(string userName)
{
    user = userName;
}

void root::setIsFile(bool fileOrFolder)
{
    isFile  = fileOrFolder;
}
string root::getName()
{
    return name;
} 

time_t root::getDate()
{
    return date;
}

long root::getSize()
{
    return size;
}

string root::getUser()
{
    return user;
}

bool root::getIsFile()
{
    return isFile;
}