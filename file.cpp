#include <cstdlib>
#include <string>
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

void root::setdate()
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


string root::convertcCharToBin(char digit)
{
   int number = digit - '0';
   string permission[3] = {"R","W","X"};
   string finalWord;
   for(int element = 0; element < 3;element++)
   {
       if(number >= 0)
       {
           if(number % 2 ==0)
           {
               permission[element] = "-";
           }
           number  = number / 2;
       }
   }

    for(int element =2 ; element >=0;element--)
    {
        finalWord +=permission[element];
    }
    return finalWord;
} 

