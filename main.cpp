#include <iostream>
#include <vector>
#include <sstream>
#include <time.h> 
#include <stdio.h>
#include "Tree.hpp"
#include "file.hpp"
using namespace std;

const string USERDEFUALT = "user@LeoOS: ";
void printError()
{
    printf("%s","Incorrect Syntax");
}
int main(){
    vector<string> words;
    root create;
    create.setName("~");
    Tree<root> tree{create};

    
    Tree<root>::Node* newRoot;
    Tree<root>::Node* temp;
    Tree<root>::Node* parent;
    // // cout<<current->GetData().getName();

    // create.setName("leo");
    // tree.GetRoot()->AppendChild(create);
    // newRoot = tree.GetRoot()->GetFirstChild();
    // cout<< newRoot->GetParent()->GetData().getName()<<endl; 
    // create.setName("alo");
    // newRoot = tree.GetRoot()->GetFirstChild()->AppendChild(create);
    // cout<< newRoot->GetParent()->GetData().getName();
    // create.setName("asdadsad");
    // tree.GetRoot()->AppendChild(create);
    newRoot = tree.GetRoot();
    parent = NULL;
    // cout<<newRoot->GetData().getName();
    bool quit = false;

    string command;
    while(!quit)
    {
        cout << USERDEFUALT;
        getline(cin,command);
        istringstream iss(command);
        string word;
        while(iss >> word)
        {
            words.push_back(word);
        }
        try{
            /*
            * pwd to print out the current directory with full path from root
            */
            if(words[0] == "pwd")
            {
                /*
                * if the current directory it will print out the '~' character
                */
                if(newRoot == tree.GetRoot())
                {
                     cout << tree.GetRoot()->GetData().getName()<<endl;
                }
                /*
                *   if the current directory is not the root, it will traverse 
                *  back to the root and push to the vector getDirection,
                *  when hit the root, it will print out the full path which is stored
                *  in the vector getDirection
                * */
                else
                {
                    vector<root> getDirection;
                    temp = newRoot;
                    while(temp != tree.GetRoot())
                    {
                        
                        getDirection.push_back(temp->GetData());  
                        temp = temp->GetParent();
                    
                    }
                    printf("%s","~");
                    for(int i =getDirection.size()-1 ; i!=-1 ; i--)
                    {
                        cout<<"/"<<getDirection[i].getName();
                    }
                    cout<<endl;
                }
            }
            else if( words[0] == "ls")
            {
                if(newRoot->HasChildren())
                {
                    if(words.size() >= 2)
                    {
                        if(words[1] == "-l")
                        {
                            printf("%s \n","pass");
                        }
                        else
                        {
                            printError();
                        }
                    }
                    else
                    {
                        temp = NULL;
                        temp = newRoot->GetFirstChild();
                        cout<< temp->GetData().getName();
                        for(int i = 0; i< newRoot->GetChildCount()-1;i++)
                        {
                            temp = temp->GetNextSibling();
                            if(temp->GetData().getIsFile() == true)
                            {
                                cout<<"/ ";
                            }
                            else
                            {
                                cout<<" ";
                            }
                            
                            cout<< temp->GetData().getName();
                        }
                        if(temp->GetData().getIsFile() == true)
                        {
                            cout<<"/\n";
                        }
                        else
                        {
                            cout<<endl;
                        }
                        temp = NULL;
                    }
                }
               
            }
            else if (words[0] == "mkdir")
            {
                root tempFile;
                long size = rand() %1000 +1000000;
                tempFile.setName(words[1]);
                tempFile.setdate(time(0));
                tempFile.setFileSize(size);
                tempFile.setUser("student");
                tempFile.setIsFile(1);
                newRoot->AppendChild(tempFile);   
            }
            else if(words[0] == "quit" 
                    || words[0] =="exit")
            {
                temp = NULL;
                newRoot = NULL;
                parent = NULL;
                delete temp;
                delete newRoot;
                delete parent;
                break;
            }
            else if(words[0] == "cd")
            {
                if(words[1] == ".." || words[1] == "../")
                {
                    if(newRoot == tree.GetRoot())
                    {
                        cout<<"No Exist directtory"<<endl;
                    }
                    else
                    {      
                        newRoot = newRoot->GetParent();   
                    }
                }
                else
                {
                    temp = newRoot->GetFirstChild();
                    for(int i =0; i < newRoot->GetChildCount(); i++)
                    {
                       if(temp->GetData().getName() == words[1])
                       {
                           parent = newRoot;
                           newRoot = NULL;
                           newRoot = temp;
                           temp = NULL;
                       }
                       else
                       {
                           temp = temp->GetNextSibling();
                       }                     
                    }
                    cout<<newRoot->GetData().getName()<<endl;
                }
            } 
        }catch (string param)
        {
            cout<<param;
        }
        words.clear();
    }
    cout<< "Thanks for using the most user-friendly Linux OS !!! " << endl;;

    return 0;
}

