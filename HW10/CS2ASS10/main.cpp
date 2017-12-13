//====================================================
//  main.cpp                                        //
//  Class: (Data Structures)                        //
//  Professor: Dr. Singhal                          //
//  Assignment#: 10                                 //
//  Operating Systems Used: MacOS(Xcode)            //
//  Last successful run: 11/22/17                   //
//  Created by: Kirby James on 11/19/17.            //
//  Due Date: 12/11/17                              //
//  Copyright � 2017 oc. All rights reserved.      //
//====================================================

#include "WordList.hpp"

int main()
{
    /*-- Declaration of Variables -- */
    /* -------------------------------- *
     * (string) currentLine = reads the current line from file input
     * (string) currentToken = disintegrates a single line
     * (int) currentNumLine = current line from file input
     * (string) fileInput = input file
     * (string) fileOuput = output file
     * -------------------------------- */
    ifstream fin;
    ofstream fout;
    string currentLine, currentToken, fileInput, fileOutput;
    int currentNumLine = 0;
    
    BinarySearchTree<WordList> B;
    SinglyLinkedList<int> S;
    
    // Prompt user for file input
    cout << "Please enter the name of input file: ";
    cin >> fileInput;
    
    fin.open(fileInput);
    
    while (fin.peek() != EOF)
    {
        currentNumLine++;
        getline(fin, currentLine);
        
        // on each current line convert to lower case
        currentToken = ConvertToLower(getToken(currentLine));
        
        while (currentToken != "")
        {
            if (currentToken.length() != 1)
            {
                // Create temporary WordList
                WordList wordListTemp;
                
                wordListTemp.setWord(currentToken);
                
                // if it already exist, grab it and remove it
                if (B.contains(wordListTemp))
                {
                    wordListTemp = B.get(wordListTemp)->contents;
                    B.remove(wordListTemp);
                }
                
                // obtain the LineNumList then add it from the current line and update the word list
                // lastly add it to the BinarySearchTree then proceed to next word and close input file
                S = wordListTemp.getList();
                S.addRear(currentNumLine);
                wordListTemp.setList(S);
                
                B.add(wordListTemp);
            }
            currentToken = ConvertToLower(getToken(currentLine));
        }
        
    }
    fin.close();
    
    // Prompt user the name of the output file. Start of output section
    cout << "Please enter the name of output file: ";
    cin >> fileOutput;
    
    // open the output file
    fout.open(fileOutput);
    // print this first on the top portion of the output file
    fout << "The line numbers are printed out after the words.\n" << endl;
    
    // Prints Binary Search Tree in-order. and close output file
    B.printInorder(fout);
    fout.close();

        bool done = false;
        while (done != true)
        {
            WordList WL;
            string wordSearch;
            cout << "Enter a word to be searched in the tree: " << flush;
            cin >> wordSearch;
            
            WL.setWord(ConvertToLower(wordSearch));
            // if it already exist, grab it and remove it
            if (B.contains(WL))
            {
                WL = B.get(WL)->contents;
                cout << WL;
            }
            else
            {
                cout << "Word not found" << endl;
            }
            
            cout << "Enter 0 to continue searching 1 to exit" << endl;
            cin >> done;
        }
    
    cin.get();
    return 0;
} // end of main

