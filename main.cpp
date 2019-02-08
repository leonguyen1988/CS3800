#include <iostream>
#include <vector>
#include <sstream>
#include <time.h> 
#include <stdio.h>
#include "Tree.hpp"
#include "file.hpp"
using namespace std;

const string USERDEFUALT = "user@LeoOS: ";

int main(){
    vector<string> words;
    root create;
    create.setName("root");
    Tree<root> tree{create};

    
    Tree<root>::Node* newRoot;
    Tree<root>::Node* temp;
    newRoot = tree.GetRoot();
    // // cout<<current->GetData().getName();

    create.setName("leo");
    tree.GetRoot()->AppendChild(create);
    create.setName("alo");
    tree.GetRoot()->AppendChild(create);
    create.setName("asdadsad");
    tree.GetRoot()->AppendChild(create);
    newRoot = tree.GetRoot()->GetFirstChild();
    cout<<newRoot->GetData().getName();
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
        // for(int i = 0; i<words.size(); i++)
        // {
        //     cout<< words[i]<<endl;;
        // }
        try{
            if(words[0] == "pwd")
            {
                if(newRoot == tree.GetRoot())
                {
                     cout << "/"<< tree.GetRoot()->GetData().getName()<<endl;
                }
                else
                {
                    tempRoot = newRoot;
                    while(tempRoot !== tree->GetRoot())
                    {
                        
                    }
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
                            cout<<"pass";
                        }
                        else
                        {
                            cout<<"Systax incorrect ";
                        }
                    }
                    else
                    {
                        cout<< newRoot->GetFirstChild()->GetData().getName() <<" ";
                        for(int i = 0; i< newRoot->GetChildCount()-1;i++)
                        {
                            cout<< newRoot->GetFirstChild()->GetNextSibling()->GetData().getName()<<" ";
                        }
                        cout<<endl;
                    }
                }else
                {
                    cout<<"Bad command"<<endl;
                }
                
                
               
            }
            // else if (words[0] == "mkdir")
            // {
            //     root tempFile;
            //     if(!tree.GetRoot()->HasChildren())
            //     {
            //         long size = rand() %1000 +1000000;
            //         tempFile.setName(word[1]);
            //         tempFile.setdate(time(0));
            //         tempFile.setFileSize(size);
            //         tempFile.setUser("student");
            //         tempFile.setIsFile(1);
            //         tree.GetRoot()->AppendChild(tempFile);
            //         newRoot = tree.GetRoot()->GetFirstChild();
            //     }
            //     else
            //     {

            //         long size = rand() %1000 +1000000;
            //         tempFile.setName(word[1]);
            //         tempFile.setdate(time(0));
            //         tempFile.setFileSize(size);
            //         tempFile.setUser("student");
            //         tempFile.setIsFile(1);
            //         for(int i = 0; )
            //     }   
            // }
            else if(words[0] == "quit" 
                    || words[0] =="exit")
            {
                break;
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