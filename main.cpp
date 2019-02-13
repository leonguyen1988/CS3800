#include <iostream>
#include <vector>
#include <sstream>
#include <time.h> 
#include <cstdio>
#include "Tree.hpp"
#include "systemOS.hpp"
using namespace std;

const std::string USERDEFUALT = "user@LeoOS: ";

int main(){
    vector<string> words;
    systemOS Linuxsystem;
    Linuxsystem.setName("~");
    Tree<systemOS> tree{Linuxsystem};
    Tree<systemOS>::Node* newRoot;
    Tree<systemOS>::Node* temp;
    Tree<systemOS>::Node* parent;
    newRoot = tree.GetRoot();
    parent = NULL;
    Linuxsystem.setName("Linux");
    newRoot->AppendChild(Linuxsystem);
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
                    vector<systemOS> getDirection;
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
                            temp = NULL;
                            temp = newRoot->GetFirstChild();
                            for(int child = 0;child < newRoot->GetChildCount();child++)
                            {  
                                Linuxsystem.printFullDirectory(temp);
                                temp = temp->GetNextSibling();
                            }
                            
                        }
                        else
                        {
                            Linuxsystem.printError();
                        }
                    }
                    else
                    {
                        temp = newRoot->GetFirstChild();
                        for(int i = 0; i< newRoot->GetChildCount();i++)
                        {
                            cout<< temp->GetData().getName();
                            if(temp->GetData().getIsFolder() == true)
                            {
                                cout<<"/ ";
                            }
                            else
                            {
                                cout<<" ";
                            }
                            temp = temp->GetNextSibling();
                        }
                        cout<<endl;
                    }
                }
               
            }
            else if (words[0] == "mkdir" and words[1].length() !=0 )
            {
                newRoot->AppendChild(Linuxsystem.addNode(words[1],1));
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
                    if(!Linuxsystem.isFolder(newRoot,words[1]))
                    {
                        cout<<"No such file or directory"<<endl;
                    }
                    else
                    {
                      temp = newRoot->GetFirstChild();
                        for(int i =0; i < newRoot->GetChildCount(); i++)
                        {
                            if(temp->GetData().getName() == words[1])
                            {
                                if(!temp->GetData().getIsFolder())
                                {
                                    cout<<" Bad command!!"<<endl;
                                    break;
                                }
                                else
                                    {
                                        parent = newRoot;
                                        newRoot = NULL;
                                        newRoot = temp;
                                        temp = NULL;
                                    }
                            }
                            else
                            {
                                temp = temp->GetNextSibling();
                            }                     
                        }   
                    }
                       
                }
            }
            else if(words[0] == "chmod")
            {
                if(words[1].length()==3)
                {
                    string selectedName = words[2];
                    bool found = false;
                    if(newRoot->HasChildren())
                    {
                        temp = newRoot->GetFirstChild();
                        for(int child = 0;child < newRoot->GetChildCount();child++)
                        {
                            if(temp->GetData().getName() == selectedName)
                            {

                                temp = Linuxsystem.UpdatePermission(temp,words[1]);
                                found = true;
                                break;
                            }
                            else
                            {
                                temp = temp->GetNextSibling();
                            }

                        }
                    }
                }
                else
                {
                    Linuxsystem.printError();
                }
            }
            else if(words[0] == "rmdir")
            {
                if(Linuxsystem.isFolder(newRoot,words[1]))
                {
                    newRoot = Linuxsystem.Delete(newRoot,words[1]);
                }
                else
                {
                    cout<<"Bad command"<<endl;
                 }
                
            } 
            else if(words[0] == "touch")
            {
                if (!Linuxsystem.isExist(newRoot,words[1]))
                {
                     newRoot->AppendChild(Linuxsystem.addNode(words[1],0));
                }
            }
            else if(words[0] == "rm")
            {
                if(!Linuxsystem.isFolder(newRoot,words[1]))
                {
                    newRoot= Linuxsystem.Delete(newRoot,words[1]);
                }
                else
                {
                    cout<<"Bad Command!!"<<endl;
                }
            }
            else
            {
               Linuxsystem.printError();
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

