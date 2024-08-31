//Title: CipherTool.cpp
//Author: Jackson Keyser
//Date: 4/20/2022
//Description: This is part of the Cipher Project in CMSC 202 @ UMBC
#include "CipherTool.h"

#include <iostream>
#include <fstream>


// REMOVE AT END
#include "Caesar.cpp"
#include "Cipher.cpp"
#include "Ong.cpp"
#include "RailFence.cpp"




// Seperates each part of the information on the line from the txt file
const char DELIMETER = '|';
// "c" in txt file stands for Caesar cipher
const string CAESARCIPHER = "c";
// "o" in txt file stands for Ong cipher
const string ONGCIPHER = "o";
// "r" in txt file stands for RailFence cipher
const string RAILFENCECIPHER = "r";

CipherTool::CipherTool(string fileName){
    m_filename = fileName;
}

CipherTool::~CipherTool(){
    //cout << "CIPHERTOOL DESTRUCTOR!" << endl;

    for(unsigned int i = 0; i < m_ciphers.size(); i++){
        delete m_ciphers.at(i);
        m_ciphers.at(i) = nullptr;
    }
}

void CipherTool::LoadFile(){
    // Retrieves the file
    ifstream infile(m_filename);

    // If file is opened
    if(infile.is_open()){

        // Declare and initialize string variables for storing data that will be parsed from the given text file
        string cipherType = "";
        string isEncrypted = "";
        string message = "";
        string amountRotatesOrRails = "";

        // Declares and intializes int variable for translating the string to int after the file is read in
        int intAmountRotatesOrRails = 0;

        // Declares and initializes a bool variable for storing whether the file is encrypted
        bool boolIsEncrypted = false;

        // Reads through all the lines of the txt file, storing into appropriate variables
        while(getline(infile, cipherType, DELIMETER) && getline(infile, isEncrypted, DELIMETER) &&
        getline(infile, message, DELIMETER) && getline(infile, amountRotatesOrRails)){

            // If empty string, is a ong cipher which would break if next line of code were to run
            if(amountRotatesOrRails != ""){
                // Transforms variable from string to int
                intAmountRotatesOrRails = stoi(amountRotatesOrRails);
            }

            // If 1, is true. Else, false.
            boolIsEncrypted = StringToBoolean(isEncrypted);

            if(boolIsEncrypted == false){
                //cout << "nice" << endl;
            }



            // If the cipher is supposed to be Caesar
            if(cipherType == CAESARCIPHER){
                // Dynamically creates a new Ceasar cipher object
                Cipher* newCipher = new Caesar(message, boolIsEncrypted, intAmountRotatesOrRails);
                // Stores the object in a vector
                m_ciphers.push_back(newCipher);
            }
            // If the cipher is supposed to be Ong
            else if(cipherType == ONGCIPHER){
                // Dynamically creates a new Ong cipher object
                Cipher* newCipher = new Ong(message, boolIsEncrypted);
                // Stores the object in a vector
                m_ciphers.push_back(newCipher);
            }
            else if(cipherType == RAILFENCECIPHER){
                // Dyncamically creates a new RailFence cipher object
                Cipher* newCipher = new RailFence(message, boolIsEncrypted, intAmountRotatesOrRails, boolIsEncrypted);
                if(boolIsEncrypted == true){
                    newCipher->Encrypt();
                }
                // Stores the object in a vector
                m_ciphers.push_back(newCipher);
            }
        }
        // Closes the file
        infile.close();
    // If file cannot be opened
    }else{
        cout << "This file was unable to be opened!" << endl;
    }

}

bool CipherTool::StringToBoolean(string input){
    // If 1, is true. Else, false.
    if(input == "1"){
        return true;
    }else{
        return false;
    }
}

void CipherTool::DisplayCiphers(){

    // Loops through ciphers
    for(int i = 0; i < int(m_ciphers.size()); i++){
        // Prints them out
        cout << i+1 << "." << m_ciphers.at(i)->GetMessage() << " " << m_ciphers.at(i)->ToString() << endl;
        cout << endl;

        //cout << i+1 << ". " << *m_ciphers.at(i) << endl;
    }

}

void CipherTool::EncryptDecrypt(bool isEncrypted){
    //cout << "Encrypt Decrypt" << endl;

    int counter = 0;

    // If we are encrypting
    if(isEncrypted == true){
        //cout << "sweet" << endl;
        // Loops through all ciphers
        for(int i = 0; i < int(m_ciphers.size()); i++){
            // If the cipher is encrypted already
            if(m_ciphers.at(i)->GetIsEncrypted() == true){
               // cout << "bruh" << endl;
                // Do nothing
            // If the cypher is encrypted
            }else{
                // Encrypts the cipher
                m_ciphers.at(i)->Encrypt();
                counter = counter + 1;
            }
        }
        cout << counter << " ciphers Encrypted" << endl;
    // If we are decrypting
    }else{
        // Loops through all ciphers
        for(int i = 0; i < int(m_ciphers.size()); i++){
            // If the cipher is decrypted already
            if(m_ciphers.at(i)->GetIsEncrypted() == false){
                // Do nothing
            }else{
                // Encrypts the cipher
                m_ciphers.at(i)->Decrypt();
                counter = counter + 1;
            }
        }
        cout << counter << " ciphers Decrypted" << endl;
    }
}

void CipherTool::Export(){
   // cout << "Export" << endl;

    string theOutput = "";

    string nameFile = "";

    cout << "Enter the name you want to name the file (followed by .txt): " << endl;
    cin >> nameFile;

    ofstream myfile;
    myfile.open (nameFile);

    for(int i = 0; i < int(m_ciphers.size()); i++){
        theOutput = m_ciphers.at(i)->FormatOutput();
        myfile << theOutput;
    }
    //myfile << "Writing this to a file.\n";
    myfile.close();

}

int CipherTool::Menu(){
    // Declares and intializes an int variable for storing user choice
    int userInput = 0;

    // Gives the user all of their choices
    cout << "What would you like to do?" << endl;
    cout << "1. Display All Ciphers" << endl;
    cout << "2. Encrypt All Ciphers" << endl;
    cout << "3. Decrypt All Ciphers" << endl;
    cout << "4. Export All Ciphers" << endl;
    cout << "5. Quit" << endl;
    cin >> userInput;

    // If user gives a choice that is not within the list given
    while(userInput > 5 || userInput < 1){
        cout << "That is not a possible choice. (1-5)" << endl;
        cout << "1. Display All Ciphers" << endl;
        cout << "2. Encrypt All Ciphers" << endl;
        cout << "3. Decrypt All Ciphers" << endl;
        cout << "4. Export All Ciphers" << endl;
        cout << "5. Quit" << endl;
        cin >> userInput;
        }

        return userInput;
}

void CipherTool::Start(){
    // Declares and initializes an integer variable for storing user choice
    int userChoice = 0;
    // Declares and initializes a boolean variable for storing whether or not the user wants to exit the program
    bool exitCipher = false;

    // Uses function to load the file in and store the objects into the vector
    LoadFile();

    // Loop runs until the user selects 5
    do{
        // Gets user choice from menu of options
        userChoice = Menu();

        if(userChoice == 1){
            DisplayCiphers();
        }
        if(userChoice == 2){
            EncryptDecrypt(true);
        }
        if(userChoice == 3){
            EncryptDecrypt(false);
        }
        if(userChoice == 4){
            Export();
            exitCipher = true;
        }
        if(userChoice == 5){
            exitCipher = true;
        }
    // While user has not selected choice number 5
    }while(exitCipher != true);

}