//Title: Ong.cpp
//Author: Jackson Keyser
//Date: 4/20/2022
//Description: This is part of the Cipher Project in CMSC 202 @ UMBC
#include "Ong.h"

Ong::Ong(){}

Ong::Ong(string message, bool isEncrypted):Cipher(message, isEncrypted){}

Ong::~Ong(){
  //  cout << "ONG DESTRUCTOR!" << endl;
}

bool Ong::IsVowel(char singleCharacter){
    // If character is a vowel
    if(singleCharacter == 'a' || singleCharacter == 'e' || singleCharacter == 'i' || singleCharacter == 'o'
       || singleCharacter == 'u' || singleCharacter == 'A' || singleCharacter == 'E' || singleCharacter == 'I'
       || singleCharacter == 'O' || singleCharacter == 'U'){

           // Return true
           return true;
       // If character is a consonant
       }else{
           // Return false
           return false;
       }
}

void Ong::Encrypt(){
    // Declares and intializes a string variable that will store the encrypted string that will be extended 1 character at a time
     string encryptedString = "";
     // Declares and initializes a char variable for each character that will be encrypted from original message
     char characterToManipulate = 'z';

    // Declares and initializes a string variable for the ong that will be added onto every consonant
     string ongString = "ong";
     // Declares and initializes a string variable for checking whether or not next character is an empty space
     // This will be used to check if it is the end of a word
     string spaceCheck = "";
     // Declares and initializes a char variable for a hyphen
     // Will be added to end of each letter in the word
     char addHyphen = '-';
     // Only used to check if the current character is not a space
     string stringVersionCharacterToManipulate = "";
     // Declares and initializes a boolean variable for storing whether or not we are on the last character
     bool lastCharacter = false;
    // Declares and initializes a boolean variable for whether or not it is a vowel
     bool checkVowel = false;
     int messageSize = GetMessage().size();

    // Loops through every character in the message
     for(int i = 0; i < messageSize; i++){

         // Stores the character from the message at said index
         characterToManipulate = GetMessage().at(i);
         // Only used to check if the current character is not a space
         stringVersionCharacterToManipulate =  GetMessage().at(i);

         // If not the last character
         if(i < (messageSize-1)){
             // Gets the next character, stores it in variable
             spaceCheck = GetMessage().at(i+1);
        // If the last character
         }else{
             // Sets boolean to true
             lastCharacter = true;
         }

        // Checks to see if the character is a letter
         if((characterToManipulate >= 'a' && characterToManipulate <= 'z') || 
           (characterToManipulate >= 'A' && characterToManipulate <= 'Z')){
            // Using function to check if character is a vowel, stores it in boolean variable
            checkVowel = IsVowel(characterToManipulate);

            // If character is a consonant
            if(checkVowel == false){
                // Adds charcter to the encrypted string
                encryptedString = encryptedString + characterToManipulate;
                // Adds ong string afterwards, as it is a consonant
                encryptedString = encryptedString + ongString;
                // If next character is not a space
                if(spaceCheck != " "){
                    // Adds a hyphen
                    encryptedString = encryptedString + addHyphen;
                }
            // If character is a vowel
            }else{
                // Adds just the vowel onto the encrypted string
                encryptedString = encryptedString + characterToManipulate;
                // If next character is not a space
                if(spaceCheck != " "){
                    // Adds a hyphen
                    encryptedString = encryptedString + addHyphen;
                }
            }
        // If character is not a letter
        }else{
            // Simply adds the character onto the new, encrypted string
            encryptedString = encryptedString + characterToManipulate;
            // If the current character is not a space and this is not the last character
            if(stringVersionCharacterToManipulate != " " && lastCharacter != true){
            // If the next character is not a space
            if(spaceCheck != " "){
                // Adds a hyphen
                encryptedString = encryptedString + addHyphen;
                }   
            }
        }
    }
    SetMessage(encryptedString);
    ToggleEncrypted();
}

void Ong::Decrypt(){

    // Declares and intializes a string variable that will store the decrypted string that will be extended 1 character at a time
     string decryptedString = "";
     // Declares and initializes a char variable for each character that will be decrypted from original message
     char characterToManipulate = 'z';

     // Declares and initializes a boolean variable for whether or not it is a vowel
     bool checkVowel = false;
    

     // Declares and initializes a string variable for checking whether or not the next character is a space
     string spaceCheck = "";
     // Declares and initializes a boolean variable for checking whether or not the next character is a space
     bool nextCharacterIsSpace = false;

     // Following 2 variables only used for special characters
     // Declares and initializes a string variable for checking whether or not the next character is a hyphen
     string hyphenCheck = "";
     // Declares and initializes a boolean variable for checking whether or not the next character is a hyphen
     bool nextCharacterIsHyphen = false;
     int messageSize = GetMessage().size();

    // Loops through the message, getting 1 character at a time
    for(int i = 0; i < messageSize; i++){
        // Gets the charcter at current index
        characterToManipulate = GetMessage().at(i);

        // If at the last character
        if(i == (messageSize-1)){
            // Adds onto decrypted string
            decryptedString = decryptedString + characterToManipulate;
        // If not on last character
        }else{

        

        // Checks to see if the character is a letter
         if((characterToManipulate >= 'a' && characterToManipulate <= 'z') || 
           (characterToManipulate >= 'A' && characterToManipulate <= 'Z')){

            // Using function to check if character is a vowel, stores it in boolean variable
            checkVowel = IsVowel(characterToManipulate);

            // If character is a vowel
            if(checkVowel == true){
                // Checks if there is a space following. This would make it the end of the word
                spaceCheck = GetMessage().at(i+1);
                if(spaceCheck == " "){
                    nextCharacterIsSpace = true;
                }else{
                    nextCharacterIsSpace = false;
                }
            // If character is a consonant
            }else{
                // Checks if there is a space following the ong. This would make it the end of the word
                spaceCheck = GetMessage().at(i+4);
                if(spaceCheck == " "){
                    nextCharacterIsSpace = true;
                }else{
                    nextCharacterIsSpace = false;
                }
            }

            // If the character is a vowel and the next character is not a space
            if(checkVowel == true && nextCharacterIsSpace == false){
                // Adds the character to the decrypted string
                decryptedString = decryptedString + characterToManipulate;
                // Since there is a hyphen following the vowel, we will add 2
                // 1 for the vowel and 1 for the hyphen
                i = i + 2;
            // If the character is a consonant and the next character is not a space
            }else if(checkVowel == false && nextCharacterIsSpace == false){
                // Adds the character to the decrypted string
                decryptedString = decryptedString + characterToManipulate;
                // Since there is a ong and a hyphen following the consonant, we will add 5
                // 1 for the consonant, 3 for the ong and 1 for the hyphen
                i = i + 5;
            // If the character is a vowel and the next character is a space
            }else if(checkVowel == true && nextCharacterIsSpace == true){
                // Adds the character to the decrypted string
                decryptedString = decryptedString + characterToManipulate;
                // Nothing following the vowel, add 1
                i = i + 1;
            // If the character is a consonant and the enxt character is a space
            }else if(checkVowel == false && nextCharacterIsSpace == true){
                decryptedString = decryptedString + characterToManipulate;
                // 1 for the consonant, 3 for the ong
                i = i + 4;
            }
    // If character is not a letter
    }else{
         // Checks if there is a hyphen following. Skip if there is
        hyphenCheck = GetMessage().at(i+1);
        if(hyphenCheck == "-"){
            nextCharacterIsHyphen = true;
        }else{
            nextCharacterIsHyphen = false;
        }

        // If next character is a hyphen
        if(nextCharacterIsHyphen == true){
            // Adds the character to the decrypted string
            decryptedString = decryptedString + characterToManipulate;
            // Adds 2 to skip the hyphen
            i = i + 2;
        // If next character is not a hyphen
        }else{
            // Adds the character to the decrypted string
            decryptedString = decryptedString + characterToManipulate;
            // Just adds 1 
            i = i + 1;
        }
    }
    // For loop adds 1 every time it runs. This is to negate it
    i = i - 1;
    }
    }
    // Changes the message to the decrypted string
    SetMessage(decryptedString);
    ToggleEncrypted();
}

string Ong::ToString(){
    // Returns that it is a Ong cipher
    return "(Ong)";
}

string Ong::FormatOutput(){
    // true is 1, false is 0

    stringstream ss;

    ss << 'o';
    ss << '|';
    if(GetIsEncrypted() == true){
        ss << 1;
    }else{
        ss << 0;
    }
    ss << '|';
    ss << GetMessage();
    ss << '|';
    ss << '\n';

    // Stores all info into stream
    string info = ss.str();

    return info;
}