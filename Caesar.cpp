//Title: Caesar.cpp
//Author: Jackson Keyser
//Date: 4/20/2022
//Description: This is part of the Cipher Project in CMSC 202 @ UMBC
#include "Caesar.h"

Caesar::Caesar(){
    m_shift = 3;
}

 Caesar::Caesar(string message, bool isEncrypted, int shift):Cipher(message, isEncrypted){
     m_shift = shift;
 }

 Caesar::~Caesar(){
   //  cout << "CAESAR DESTRUCTOR!" << endl;
 }

 void Caesar::Encrypt(){
     // Declares and intializes a string variable that will store the encrypted string that will be extended 1 character at a time
     string encryptedString = "";
     // Declares and initializes a char variable for each character that will be encrypted from original message
     char characterToManipulate = 'z';

    // Only 26 letters in the alphabet. If m_shift is any more, would cycle again
     m_shift = m_shift % 26;

    // Loops through every character in the message
     for(int i = 0; i < int(GetMessage().size()); i++){

        // Counter variable for keeping track of current shift
         int counter = 0;

         // Stores the character from the message at said index
         characterToManipulate = GetMessage().at(i);

        // Shifts once at a time
        while(counter < m_shift){
            // If the character is between A and Z
            if(characterToManipulate >= 'A' && characterToManipulate <= 'Z'){
                 // Shifts the character by 1
                characterToManipulate = characterToManipulate + 1;
                // Increments counter by 1
                counter++;

                // If the character goes past Z
                if(characterToManipulate > 'Z'){
                    // Sets the character back to A
                    characterToManipulate = 'A';
                }
            }

            // If the character is between a and z
            else if(characterToManipulate >= 'a' && characterToManipulate <= 'z'){
                // Shifts the character by 1
                characterToManipulate = characterToManipulate + 1;
                // Increments counter by 1
                counter++;

                // If the character goes past z
                if(characterToManipulate > 'z'){
                    // Sets the character back to a
                    characterToManipulate = 'a';
                }
         }
            // If any other character, nothing is changed
            else{
                counter++;
            }
     }
     // Adds the encrypted character onto the string
     encryptedString = encryptedString + characterToManipulate;
    }
    SetMessage(encryptedString);
    ToggleEncrypted();
 }

 void Caesar::Decrypt(){
     // Declares and intializes a string variable that will store the decrypted string that will be extended 1 character at a time
     string decryptedString = "";
     // Declares and initializes a char variable for each character that will be decrypted from original message
     char characterToManipulate = 'z';

    // Only 26 letters in the alphabet. If m_shift is any more, would cycle again
     m_shift = m_shift % 26;

    // Loops through every character in the message
     for(int i = 0; i < int(GetMessage().size()); i++){

        // Counter variable for keeping track of current shift
         int counter = 0;

         // Stores the character from the message at said index
         characterToManipulate = GetMessage().at(i);

        // Shifts once at a time
        while(counter < m_shift){
            // If the character is between A and Z
            if(characterToManipulate >= 'A' && characterToManipulate <= 'Z'){
                 // Shifts the character by 1
                characterToManipulate = characterToManipulate - 1;
                // Increments counter by 1
                counter++;

                // If the character goes past A
                if(characterToManipulate < 'A'){
                    // Sets the character back to Z
                    characterToManipulate = 'Z';
                }
            }

            // If the character is between a and z
            else if(characterToManipulate >= 'a' && characterToManipulate <= 'z'){
                // Shifts the character by 1
                characterToManipulate = characterToManipulate - 1;
                // Increments counter by 1
                counter++;

                // If the character goes past a
                if(characterToManipulate < 'a'){
                    // Sets the character back to z
                    characterToManipulate = 'z';
                }
         }
            // If any other character, nothing is changed
            else{
                counter++;
            }
     }
     // Adds the decrypted character onto the string
     decryptedString = decryptedString + characterToManipulate;
    }
    SetMessage(decryptedString);
    ToggleEncrypted();
 }

 string Caesar::ToString(){
     // Returns that it is a Caesar cipher
     return "(Caesar)";
 }

 string Caesar::FormatOutput(){
     // true is 1, false is 0

    stringstream ss;

    ss << 'c';
    ss << '|';
    if(GetIsEncrypted() == true){
        ss << 1;
    }else{
        ss << 0;
    }
    ss << '|';
    ss << GetMessage();
    ss << '|';
    ss << m_shift;
    ss << '\n';

    // Stores all info into stream
    string info = ss.str();

    return info;
 }
