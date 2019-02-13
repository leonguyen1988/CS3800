#include <cstdlib>
#include <string>
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include "systemOS.hpp"
#include <stdio.h>
using namespace std;


void systemOS::setName(string selectedName)
{
    name = selectedName;
}

void systemOS::setdate()
{
    
    date = UpdateDate();
}

void systemOS::setFileSize(long sizeFile)
{
size = sizeFile;
}

void systemOS::setUser(string userName)
{
    user = userName;
}

void systemOS::setIsFolder(bool fileOrFolder)
{
    isFile = fileOrFolder;
}


string systemOS::convertcCharToBin(char digit)
{
   int number = digit - '0';
   string permission[3] = {"X","W","R"};
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

/**
 * get digit from user input and convert it to sequence of string
 * to describe the permision of Owner.
 * PRE: digit param must be a character
 * POST: return the sequence of string like"RWX"
 * which:
 *      W is writing permission
 *      R is reading permision
 *      X is excution permission
*/
void systemOS::setOwner(char digit)
{
    Owner = convertcCharToBin(digit);
}

/**
 * get digit from user input and convert it to sequence of string
 * to describe the permision of Group.
 * PRE: digit param must be a character
 * POST: return the sequence of string like"RWX"
 * which:
 *      W is writing permission
 *      R is reading permision
 *      X is excution permission
*/
void systemOS::setGroup(char digit)
{
    Group =  convertcCharToBin(digit);
}

/**
 * get digit from user input and convert it to sequence of string
 * to describe the permision of Public.
 * PRE: digit param must be a character
 * POST: return the sequence of string like"RWX"
 * which:
 *      W is writing permission
 *      R is reading permision
 *      X is excution permission
*/
void systemOS::setPublic(char digit)
{
    Public = convertcCharToBin(digit);
}


/*
* Print full of the current directory
*/
void systemOS::printFullDirectory(Tree<systemOS>::Node* Directory)
{
    string isFile = (Directory->GetData().getIsFolder())?"d":"-";
    cout<<isFile<<Directory->GetData().getOwner();
    cout<<Directory->GetData().getGroup();
    cout<<Directory->GetData().getPublic();
    cout<<" "<<Directory->GetChildCount() + 1<<" pbg ";
    cout<<Directory->GetData().getUser();
    cout<<"  "<<Directory->GetData().getSize();
    cout<<"  "<<Directory->GetData().getDate();
    cout<<" "<<Directory->GetData().getName();
    cout<<(Directory->GetData().getIsFolder()?"/":" ")<<endl;
}

/**
 * Update the date for changing permission of file or folder
*/
string systemOS::UpdateDate()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    char iyear[50],imonth[50],iday[50],ihour[50],imin[50],isec[50];
    sprintf(iyear, "%d",1900 + ltm->tm_year );
    sprintf(imonth, "%02d", 1 + ltm->tm_mon);
    sprintf(iday, "%02d", ltm->tm_mday -1);
    sprintf(ihour, "%02d", (ltm->tm_hour) );
    sprintf(imin, "%02d",  ltm->tm_min);
    sprintf(isec, "%02d",  ltm->tm_sec);

    vector<string> sDate{imonth,iday,iyear};
    vector<string> sTime{ihour, imin, isec};
    string myDate = boost::algorithm::join(sDate, "-") ;
    string myTime = boost::algorithm::join(sTime, ":") ;
    vector<string> sDateTime{myDate, myTime};
    string myDateTime = boost::algorithm::join(sDateTime, " ") ;
    return myDateTime;
}


Tree<systemOS>::Node* systemOS::UpdatePermission( Tree<systemOS>::Node* node,string permissionDetail)
{
    node->GetData().setOwner(permissionDetail[0]);
    node->GetData().setGroup(permissionDetail[1]);
    node->GetData().setPublic(permissionDetail[2]);
    node->GetData().setdate();
    return node;
    
}

void systemOS::printError()
{
    printf("%s\n","Comand not found");
}

Tree<systemOS>::Node* systemOS::Delete(Tree<systemOS>::Node* root, string name)
{
    Tree<systemOS>::Node* temp;
    temp = root->GetFirstChild();
    for(int i =0 ; i < root->GetChildCount();i++)
    {
        if(temp->GetData().getName() == name)
        {
            temp->DeleteFromTree();
        }
        else
        {
            temp = temp->GetNextSibling();     
        }
        
    }
    return root;
    
}

systemOS systemOS::addNode(string name, int isFile)
{
    systemOS tempFile;
    tempFile.setName(name);
    tempFile.setIsFolder(isFile);
    return tempFile;
}

bool systemOS::isExist(Tree<systemOS>::Node* root, string name)
{
    Tree<systemOS>::Node* temp;
    temp = root->GetFirstChild();
    for(int i =0 ; i < root->GetChildCount();i++)
    {
        if(temp->GetData().getName() == name)
        {
            temp->GetData().setdate();
            return true;
        }
        else
        {
            temp = temp->GetNextSibling();     
        }
        
    }
    return false;
}

bool systemOS::isFolder(Tree<systemOS>::Node* root, string name)
{
    Tree<systemOS>::Node* temp;
    temp = root->GetFirstChild();
    for(int i =0 ; i < root->GetChildCount();i++)
    {
        if(temp->GetData().getName() == name)
        {
            if(temp->GetData().getIsFolder() == true)
            {
                return true;
            }

        }
        else
        {
            temp = temp->GetNextSibling();     
        }
        
    }
    return false;
}