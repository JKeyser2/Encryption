//Title: RailFence.cpp
//Author: Jackson Keyser
//Date: 4/20/2022
//Description: This is part of the Cipher Project in CMSC 202 @ UMBC
#include "RailFence.h"
#include <sstream>
using namespace std;

RailFence::RailFence(){}

RailFence::RailFence(string message, bool isEncrypted, int amountRails, bool startedDecrypted):Cipher(message, isEncrypted){
    m_rails = amountRails;
    m_startedDecrypted = startedDecrypted;
}

RailFence::~RailFence(){
 //   cout << "RailFence Destructor!" << endl;

}

void RailFence::Encrypt(){

    // Declares and intializes a string variable that will store the encrypted string that will be extended 1 character at a time
     string encryptedString = "";
     // Declares and initializes a char variable for each character that will be encrypted from original message
     char characterToManipulate = 'z';

    // Declares and initializes a int vairable for when the sequence repeats
    int sequenceRepeat = 0;

    // Delcares and intializes a int variable for the size of the message
    int sizeMessage = GetMessage().size();


  //  cout << "MESSAGE: " << GetMessage() << endl;
  //  cout << "m_rails: " << m_rails << endl;




    // Formula for when the sequence repeats
    sequenceRepeat = 2 * (m_rails - 1);


    if(m_startedDecrypted == false){
        // Loops once for each rail
        for(int i = 0; i < m_rails; i++){
            // If the amount of rails is odd
            if(m_rails % 2 == 1){

            //    cout << "ODD" << endl;

                // Sets the first quadrant to be 0
                m_arrayOfQuadrants[0] = 0;

                // If on the ends of the rail
                if(i == 0 || i == (m_rails-1)){

                    // Sets the quadrant + 1 to be 0
                    m_arrayOfQuadrants[i+1] = 0;

                    // Adds the previous quadrant to get the beginning index for the quadrant we are currently on
                    m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + m_arrayOfQuadrants[i];

                    // Loops through. 
                    for(int j = i; j < sizeMessage; j+=sequenceRepeat){
                        // If the first character in the loop
                        if(j == i){
                            // Gets the character
                            characterToManipulate = GetMessage().at(j);
                            // Adds character to encrypted string
                            encryptedString = encryptedString + characterToManipulate;
                            m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                        //    cout << "arrayOfQuadrant[i]: " << m_arrayOfQuadrants[i+1] << endl;
                        }else{
                            // If character  is less than the size of the message
                            // Would still be in bounds of the array
                            if( j < sizeMessage){
                                // Gets the character
                                characterToManipulate = GetMessage().at(j);
                                // Adds the character to encrypted string
                                encryptedString = encryptedString + characterToManipulate;
                                m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                           //     cout << "arrayOfQuadrant[i]: " << m_arrayOfQuadrants[i+1] << endl;
                            // If character out of bounds of the array
                            }else{
                                // The loop will exit
                                // No character added as you would be out of bounds of the array
                                j = j + sequenceRepeat;
                            }
                    }
                    }
                }
                // If the middle rail
                if(i == (m_rails/2)){

                    // Sets the quadrant + 1 to be 0
                    m_arrayOfQuadrants[i+1] = 0;

                    // Adds the previous quadrant to get the beginning index for the quadrant we are currently on
                    m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + m_arrayOfQuadrants[i];

                    // Divides the sequence repeat by 2
                    int newSequenceRepeat = sequenceRepeat/2;
                    // Loops through. 
                    for(int j = i; j < sizeMessage; j+=newSequenceRepeat){
                        // If the first character in the loop
                        if(j == i){
                            // Gets the character
                            characterToManipulate = GetMessage().at(j);
                            // Adds character to encrypted string
                            encryptedString = encryptedString + characterToManipulate;
                            m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                         //   cout << "arrayOfQuadrant[i]: " << m_arrayOfQuadrants[i+1] << endl;
                        // If not the first character in the loop
                        }else{
                            // If character is less than the size of the message
                            // Would still be in bounds of the array
                            if(j < sizeMessage){
                                // Gets the character
                                characterToManipulate = GetMessage().at(j);
                                // Adds the character to encrypted string
                                encryptedString = encryptedString + characterToManipulate;
                                m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                            //    cout << "arrayOfQuadrant[i]: " << m_arrayOfQuadrants[i+1] << endl;
                            // If character out of bounds of the array
                            }else{
                                // The loop will exit
                                // No character added as you would be out of bounds of the array
                                j = j + newSequenceRepeat;
                            }
                            }
                    }
                }
                // If It is less than halfway and is not the first rail
                if(i < (m_rails/2) && i != 0){

                    // Sets the quadrant + 1 to be 0
                    m_arrayOfQuadrants[i+1] = 0;

                    // Adds the previous quadrant to get the beginning index for the quadrant we are currently on
                    m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + m_arrayOfQuadrants[i];

                    // If rail 5: 8 - 2 = 6
                    // If rail 5: 8 - 6 = 2
                    int sequenceRepeatOne = sequenceRepeat - (2*i);
                    int sequenceRepeatTwo = sequenceRepeat - sequenceRepeatOne;

                    // Starts at sequenceRepeatOne
                    int currentSequenceRepeat = sequenceRepeatOne;


                    // Loops through. 
                    for(int j = i; j < sizeMessage; j+=currentSequenceRepeat){
                        // If the first character in the loop
                        if(j == i){
                            // Gets the character
                            characterToManipulate = GetMessage().at(j);
                            // Adds character to encrypted string
                            encryptedString = encryptedString + characterToManipulate;
                            m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                        //    cout << "arrayOfQuadrant[i]: " << m_arrayOfQuadrants[i+1] << endl;
                        }else{
                            // If character is less than the size of the message
                            // Would still be in bounds of the array
                            if(j < sizeMessage){
                                // Gets the character
                                characterToManipulate = GetMessage().at(j);
                                // Adds the character to encrypted string
                                encryptedString = encryptedString + characterToManipulate;
                                m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                            //    cout << "arrayOfQuadrant[i]: " << m_arrayOfQuadrants[i+1] << endl;

                                // Flips the sequence
                                if(currentSequenceRepeat == sequenceRepeatOne){
                                    currentSequenceRepeat = sequenceRepeatTwo;
                                }else{
                                    currentSequenceRepeat = sequenceRepeatOne;
                                }
                            // If character out of bounds of the array
                            }else{
                                // The loop will exit
                                // No character added as you would be out of bounds of the array
                                j = j + currentSequenceRepeat;
                            }
                            }
                    }
                }  
                // If It is more than halfway and is not the last rail
                if(i > (m_rails/2) && i != (m_rails-1)){
                    // Sets the quadrant + 1 to be 0
                    m_arrayOfQuadrants[i+1] = 0;

                    // Adds the previous quadrant to get the beginning index for the quadrant we are currently on
                    m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + m_arrayOfQuadrants[i];

                    // If rail 5: 8 - 6 = 2
                    // If rail 5: 8 - 2 = 6
                    int sequenceRepeatOne = sequenceRepeat - (2*i); //6
                    int sequenceRepeatTwo = sequenceRepeat - sequenceRepeatOne; //2

                    // Starts at sequenceRepeatOne
                    int currentSequenceRepeat = sequenceRepeatOne;

                    // Loops through. 
                    for(int j = i; j < sizeMessage; j+=currentSequenceRepeat){
                        // If the first character in the loop
                        if(j == i){
                            //cout << "j: " << j << endl;
                            // Gets the character
                            characterToManipulate = GetMessage().at(j);
                            // Adds character to encrypted string
                            encryptedString = encryptedString + characterToManipulate;
                            m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                          //  cout << "arrayOfQuadrant[i]: " << m_arrayOfQuadrants[i+1] << endl;
                            //cout << "CHARACTER: " << characterToManipulate << endl;
                        }else{ 
                            // If character + the sequenceRepeat is less than the size of the message
                            // Would still be in bounds of the array
                            if(j < sizeMessage){
                                // Gets the character
                                characterToManipulate = GetMessage().at(j);
                                // Adds the character to encrypted string
                                encryptedString = encryptedString + characterToManipulate;
                                m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                             //   cout << "arrayOfQuadrant[i]: " << m_arrayOfQuadrants[i+1] << endl;
                                //cout << "CHARACTER: " << characterToManipulate << endl;

                                // Flips the sequence
                                if(currentSequenceRepeat == sequenceRepeatOne){
                                    currentSequenceRepeat = sequenceRepeatTwo;
                                }else{
                                    currentSequenceRepeat = sequenceRepeatOne;
                                }
                            // If character out of bounds of the array
                            }else{
                                // The loop will exit
                                // No character added as you would be out of bounds of the array
                                j = j + currentSequenceRepeat;
                            }
                        }
                    }
                }  
            // If the amount of rails is even
            }else{  

              //  cout << "EVEN" << endl;

                // Sets the first quadrant to be 0
                m_arrayOfQuadrants[0] = 0;

                
                // If on the ends of the rail
                if(i == 0 || i == (m_rails-1)){

                    // Sets the quadrant + 1 to be 0
                    m_arrayOfQuadrants[i+1] = 0;

                    // Adds the previous quadrant to get the beginning index for the quadrant we are currently on
                    m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + m_arrayOfQuadrants[i];

                    // Loops through. 
                    for(int j = i; j < sizeMessage; j+=sequenceRepeat){
                        // If the first character in the loop
                        if(j == i){
                            // Gets the character
                            characterToManipulate = GetMessage().at(j);
                            // Adds character to encrypted string
                            encryptedString = encryptedString + characterToManipulate;
                            m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                        }else{
                            // If character  is less than the size of the message
                            // Would still be in bounds of the array
                            if( j < sizeMessage){
                                // Gets the character
                                characterToManipulate = GetMessage().at(j);
                                // Adds the character to encrypted string
                                encryptedString = encryptedString + characterToManipulate;
                                m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                            // If character out of bounds of the array
                            }else{
                                // The loop will exit
                                // No character added as you would be out of bounds of the array
                                j = j + sequenceRepeat;
                            }
                    }
                    }
                }
            
                // If It is less than halfway and is not the first rail
                if(i < (m_rails/2) && i != 0){

                    // Sets the quadrant + 1 to be 0
                    m_arrayOfQuadrants[i+1] = 0;

                    // Adds the previous quadrant to get the beginning index for the quadrant we are currently on
                    m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + m_arrayOfQuadrants[i];

                    // If rail 5: 8 - 2 = 6
                    // If rail 5: 8 - 6 = 2
                    int sequenceRepeatOne = sequenceRepeat - (2*i);
                    int sequenceRepeatTwo = sequenceRepeat - sequenceRepeatOne;

                    // Starts at sequenceRepeatOne
                    int currentSequenceRepeat = sequenceRepeatOne;


                    // Loops through. 
                    for(int j = i; j < sizeMessage; j+=currentSequenceRepeat){
                        // If the first character in the loop
                        if(j == i){
                            // Gets the character
                            characterToManipulate = GetMessage().at(j);
                            // Adds character to encrypted string
                            encryptedString = encryptedString + characterToManipulate;
                            m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                        }else{
                            // If character is less than the size of the message
                            // Would still be in bounds of the array
                            if(j < sizeMessage){
                                // Gets the character
                                characterToManipulate = GetMessage().at(j);
                                // Adds the character to encrypted string
                                encryptedString = encryptedString + characterToManipulate;
                                m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;

                                // Flips the sequence
                                if(currentSequenceRepeat == sequenceRepeatOne){
                                    currentSequenceRepeat = sequenceRepeatTwo;
                                }else{
                                    currentSequenceRepeat = sequenceRepeatOne;
                                }
                            // If character out of bounds of the array
                            }else{
                                // The loop will exit
                                // No character added as you would be out of bounds of the array
                                j = j + currentSequenceRepeat;
                            }
                            }
                    }
                }  
                // If It is more than halfway and is not the last rail
                if(i >= (m_rails/2) && i != (m_rails-1)){

                    // Sets the quadrant + 1 to be 0
                    m_arrayOfQuadrants[i+1] = 0;

                    // Adds the previous quadrant to get the beginning index for the quadrant we are currently on
                    m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + m_arrayOfQuadrants[i];

                    // If rail 5: 8 - 6 = 2
                    // If rail 5: 8 - 2 = 6
                    int sequenceRepeatOne = sequenceRepeat - (2*i); //6
                    int sequenceRepeatTwo = sequenceRepeat - sequenceRepeatOne; //2

                    // Starts at sequenceRepeatOne
                    int currentSequenceRepeat = sequenceRepeatOne;

                    // Loops through. 
                    for(int j = i; j < sizeMessage; j+=currentSequenceRepeat){
                        // If the first character in the loop
                        if(j == i){
                            //cout << "j: " << j << endl;
                            // Gets the character
                            characterToManipulate = GetMessage().at(j);
                            // Adds character to encrypted string
                            encryptedString = encryptedString + characterToManipulate;
                            m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                            //cout << "CHARACTER: " << characterToManipulate << endl;
                        }else{ 
                            // If character + the sequenceRepeat is less than the size of the message
                            // Would still be in bounds of the array
                            if(j < sizeMessage){
                                // Gets the character
                                characterToManipulate = GetMessage().at(j);
                                // Adds the character to encrypted string
                                encryptedString = encryptedString + characterToManipulate;
                                m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                                //cout << "CHARACTER: " << characterToManipulate << endl;

                                // Flips the sequence
                                if(currentSequenceRepeat == sequenceRepeatOne){
                                    currentSequenceRepeat = sequenceRepeatTwo;
                                }else{
                                    currentSequenceRepeat = sequenceRepeatOne;
                                }
                            // If character out of bounds of the array
                            }else{
                                // The loop will exit
                                // No character added as you would be out of bounds of the array
                                j = j + currentSequenceRepeat;
                            }
                        }
                    }
                }  
            }
        } // ENDS HERE
        
    SetMessage(encryptedString);
    ToggleEncrypted();
    // If the message started as decrypted
    }else{
       // Loops once for each rail
        for(int i = 0; i < m_rails; i++){
            // If the amount of rails is odd
            if(m_rails % 2 == 1){

             //   cout << "ODD" << endl;

                // Sets the first quadrant to be 0
                m_arrayOfQuadrants[0] = 0;

                // If on the ends of the rail
                if(i == 0 || i == (m_rails-1)){

                    // Sets the quadrant + 1 to be 0
                    m_arrayOfQuadrants[i+1] = 0;

                    // Adds the previous quadrant to get the beginning index for the quadrant we are currently on
                    m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + m_arrayOfQuadrants[i];

                    // Loops through. 
                    for(int j = i; j < sizeMessage; j+=sequenceRepeat){
                        // If the first character in the loop
                        if(j == i){
                            m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                         //   cout << "arrayOfQuadrant[i]: " << m_arrayOfQuadrants[i+1] << endl;
                        }else{
                            // If character  is less than the size of the message
                            // Would still be in bounds of the array
                            if( j < sizeMessage){
                                m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                            //    cout << "arrayOfQuadrant[i]: " << m_arrayOfQuadrants[i+1] << endl;
                            // If character out of bounds of the array
                            }else{
                                // The loop will exit
                                // No character added as you would be out of bounds of the array
                                j = j + sequenceRepeat;
                            }
                    }
                    }
                }
                // If the middle rail
                if(i == (m_rails/2)){

                    // Sets the quadrant + 1 to be 0
                    m_arrayOfQuadrants[i+1] = 0;

                    // Adds the previous quadrant to get the beginning index for the quadrant we are currently on
                    m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + m_arrayOfQuadrants[i];

                    // Divides the sequence repeat by 2
                    int newSequenceRepeat = sequenceRepeat/2;
                    // Loops through. 
                    for(int j = i; j < sizeMessage; j+=newSequenceRepeat){
                        // If the first character in the loop
                        if(j == i){
                            m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                        //    cout << "arrayOfQuadrant[i]: " << m_arrayOfQuadrants[i+1] << endl;
                        // If not the first character in the loop
                        }else{
                            // If character is less than the size of the message
                            // Would still be in bounds of the array
                            if(j < sizeMessage){
                                m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                            //    cout << "arrayOfQuadrant[i]: " << m_arrayOfQuadrants[i+1] << endl;
                            // If character out of bounds of the array
                            }else{
                                // The loop will exit
                                // No character added as you would be out of bounds of the array
                                j = j + newSequenceRepeat;
                            }
                            }
                    }
                }
                // If It is less than halfway and is not the first rail
                if(i < (m_rails/2) && i != 0){

                    // Sets the quadrant + 1 to be 0
                    m_arrayOfQuadrants[i+1] = 0;

                    // Adds the previous quadrant to get the beginning index for the quadrant we are currently on
                    m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + m_arrayOfQuadrants[i];

                    // If rail 5: 8 - 2 = 6
                    // If rail 5: 8 - 6 = 2
                    int sequenceRepeatOne = sequenceRepeat - (2*i);
                    int sequenceRepeatTwo = sequenceRepeat - sequenceRepeatOne;

                    // Starts at sequenceRepeatOne
                    int currentSequenceRepeat = sequenceRepeatOne;


                    // Loops through. 
                    for(int j = i; j < sizeMessage; j+=currentSequenceRepeat){
                        // If the first character in the loop
                        if(j == i){
                            m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                        //    cout << "arrayOfQuadrant[i]: " << m_arrayOfQuadrants[i+1] << endl;
                        }else{
                            // If character is less than the size of the message
                            // Would still be in bounds of the array
                            if(j < sizeMessage){
                                m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                            //    cout << "arrayOfQuadrant[i]: " << m_arrayOfQuadrants[i+1] << endl;

                                // Flips the sequence
                                if(currentSequenceRepeat == sequenceRepeatOne){
                                    currentSequenceRepeat = sequenceRepeatTwo;
                                }else{
                                    currentSequenceRepeat = sequenceRepeatOne;
                                }
                            // If character out of bounds of the array
                            }else{
                                // The loop will exit
                                // No character added as you would be out of bounds of the array
                                j = j + currentSequenceRepeat;
                            }
                            }
                    }
                }  
                // If It is more than halfway and is not the last rail
                if(i > (m_rails/2) && i != (m_rails-1)){
                    // Sets the quadrant + 1 to be 0
                    m_arrayOfQuadrants[i+1] = 0;

                    // Adds the previous quadrant to get the beginning index for the quadrant we are currently on
                    m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + m_arrayOfQuadrants[i];

                    // If rail 5: 8 - 6 = 2
                    // If rail 5: 8 - 2 = 6
                    int sequenceRepeatOne = sequenceRepeat - (2*i); //6
                    int sequenceRepeatTwo = sequenceRepeat - sequenceRepeatOne; //2

                    // Starts at sequenceRepeatOne
                    int currentSequenceRepeat = sequenceRepeatOne;

                    // Loops through. 
                    for(int j = i; j < sizeMessage; j+=currentSequenceRepeat){
                        // If the first character in the loop
                        if(j == i){
                            m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                        //    cout << "arrayOfQuadrant[i]: " << m_arrayOfQuadrants[i+1] << endl;
                            //cout << "CHARACTER: " << characterToManipulate << endl;
                        }else{ 
                            // If character + the sequenceRepeat is less than the size of the message
                            // Would still be in bounds of the array
                            if(j < sizeMessage){
                                m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                             //   cout << "arrayOfQuadrant[i]: " << m_arrayOfQuadrants[i+1] << endl;
                                //cout << "CHARACTER: " << characterToManipulate << endl;

                                // Flips the sequence
                                if(currentSequenceRepeat == sequenceRepeatOne){
                                    currentSequenceRepeat = sequenceRepeatTwo;
                                }else{
                                    currentSequenceRepeat = sequenceRepeatOne;
                                }
                            // If character out of bounds of the array
                            }else{
                                // The loop will exit
                                // No character added as you would be out of bounds of the array
                                j = j + currentSequenceRepeat;
                            }
                        }
                    }
                }  
            // If the amount of rails is even
            }else{  

             //   cout << "EVEN" << endl;

                // Sets the first quadrant to be 0
                m_arrayOfQuadrants[0] = 0;

                
                // If on the ends of the rail
                if(i == 0 || i == (m_rails-1)){

                    // Sets the quadrant + 1 to be 0
                    m_arrayOfQuadrants[i+1] = 0;

                    // Adds the previous quadrant to get the beginning index for the quadrant we are currently on
                    m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + m_arrayOfQuadrants[i];

                    // Loops through. 
                    for(int j = i; j < sizeMessage; j+=sequenceRepeat){
                        // If the first character in the loop
                        if(j == i){
                            m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                        }else{
                            // If character  is less than the size of the message
                            // Would still be in bounds of the array
                            if( j < sizeMessage){
                                m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                            // If character out of bounds of the array
                            }else{
                                // The loop will exit
                                // No character added as you would be out of bounds of the array
                                j = j + sequenceRepeat;
                            }
                    }
                    }
                }
            
                // If It is less than halfway and is not the first rail
                if(i < (m_rails/2) && i != 0){

                    // Sets the quadrant + 1 to be 0
                    m_arrayOfQuadrants[i+1] = 0;

                    // Adds the previous quadrant to get the beginning index for the quadrant we are currently on
                    m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + m_arrayOfQuadrants[i];

                    // If rail 5: 8 - 2 = 6
                    // If rail 5: 8 - 6 = 2
                    int sequenceRepeatOne = sequenceRepeat - (2*i);
                    int sequenceRepeatTwo = sequenceRepeat - sequenceRepeatOne;

                    // Starts at sequenceRepeatOne
                    int currentSequenceRepeat = sequenceRepeatOne;


                    // Loops through. 
                    for(int j = i; j < sizeMessage; j+=currentSequenceRepeat){
                        // If the first character in the loop
                        if(j == i){
                            m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                        }else{
                            // If character is less than the size of the message
                            // Would still be in bounds of the array
                            if(j < sizeMessage){
                                m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;

                                // Flips the sequence
                                if(currentSequenceRepeat == sequenceRepeatOne){
                                    currentSequenceRepeat = sequenceRepeatTwo;
                                }else{
                                    currentSequenceRepeat = sequenceRepeatOne;
                                }
                            // If character out of bounds of the array
                            }else{
                                // The loop will exit
                                // No character added as you would be out of bounds of the array
                                j = j + currentSequenceRepeat;
                            }
                            }
                    }
                }  
                // If It is more than halfway and is not the last rail
                if(i >= (m_rails/2) && i != (m_rails-1)){

                    // Sets the quadrant + 1 to be 0
                    m_arrayOfQuadrants[i+1] = 0;

                    // Adds the previous quadrant to get the beginning index for the quadrant we are currently on
                    m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + m_arrayOfQuadrants[i];

                    // If rail 5: 8 - 6 = 2
                    // If rail 5: 8 - 2 = 6
                    int sequenceRepeatOne = sequenceRepeat - (2*i); //6
                    int sequenceRepeatTwo = sequenceRepeat - sequenceRepeatOne; //2

                    // Starts at sequenceRepeatOne
                    int currentSequenceRepeat = sequenceRepeatOne;

                    // Loops through. 
                    for(int j = i; j < sizeMessage; j+=currentSequenceRepeat){
                        // If the first character in the loop
                        if(j == i){
                            m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                            //cout << "CHARACTER: " << characterToManipulate << endl;
                        }else{ 
                            // If character + the sequenceRepeat is less than the size of the message
                            // Would still be in bounds of the array
                            if(j < sizeMessage){
                                m_arrayOfQuadrants[i+1] = m_arrayOfQuadrants[i+1] + 1;
                                //cout << "CHARACTER: " << characterToManipulate << endl;

                                // Flips the sequence
                                if(currentSequenceRepeat == sequenceRepeatOne){
                                    currentSequenceRepeat = sequenceRepeatTwo;
                                }else{
                                    currentSequenceRepeat = sequenceRepeatOne;
                                }
                            // If character out of bounds of the array
                            }else{
                                // The loop will exit
                                // No character added as you would be out of bounds of the array
                                j = j + currentSequenceRepeat;
                            }
                        }
                    }
                }  
            }
        } // ENDS HERE 
        m_startedDecrypted = false;
    }



}

void RailFence::Decrypt(){
    // Declares and intializes a string variable that will store the decrypted string that will be extended 1 character at a time
     string decryptedString = "";
     // Declares and initializes a char variable for each character that will be decrypted from original message
     char characterToManipulate = 'z';


    // Delcares and intializes a int variable for the size of the message
    int sizeMessage = GetMessage().size();


    int numberRails = m_rails;


    int theDividor = 4;
    int theDividor2 = 0;

 
     // If more than 3 rails
    if(numberRails > 3){
        // Gets the amount of rails over 3
        numberRails = numberRails - 3;
        // Multiplies them by 2
        theDividor2 = numberRails * 2;
    }

    // Adds the dividors together
    theDividor = theDividor + theDividor2;


    // EXAMPLE 78 characters
    // numRails = 5
    // Rail 1: 1/8     0-9
    // Rail 2: 2/8     10-28
    // Rail 3: 2/8     29-47
    // Rail 4: 2/8     48-67
    // Rail 5: 1/8     68-77
    //
    // 1 -> 2 -> 3 -> 4 -> 5
    // 4 (1 less than rail max) -> 3 -> 2 -> 1 -> 0 -> 1 -> 2 -> 3 -> 4 -> 3 -> 2 -> 1 -> 0 -> 1 -> 2 -> 3 -> 4 -> 5



    int counter2 = 0;

    bool isDecrementing = true;

    // Loops through all characters in the message
    for(int i = 0; i < sizeMessage; i++){
        //characterToManipulate = GetMessage().at(i);

        // For first cycle, goes in order by quadrant
        if(i < m_rails){
            // Gets the first character in each quadrant
            characterToManipulate = GetMessage().at(m_arrayOfQuadrants[i]);
            decryptedString = decryptedString + characterToManipulate;
        // First character after the first cycle is 1 quadrant before the back-end rail
        }else if(i == m_rails){
            // Subtracts 2 from i. This is 1 before the back-end rail
            counter2 = i - 2;
            // Adds 1 to counter as this is the 2nd time in quadrant 3
            //counter = counter + 1;
            // 1 quadrant before end rail. Add counter to move 1 index up
            m_arrayOfQuadrants[counter2] = m_arrayOfQuadrants[counter2] + 1;
            characterToManipulate = GetMessage().at(m_arrayOfQuadrants[counter2]);
            decryptedString = decryptedString + characterToManipulate;
        }else{
            // If reached head of rails, will begin incrementing again
            if(counter2 == 0){
                isDecrementing = false;
            }
            // If reach tail of rails, will begin decrementing again
            if(counter2 == (m_rails-1)){
                isDecrementing = true;
            }
            // If decrementing
            if(isDecrementing == true){
                // Subtract 1
                counter2 = counter2 - 1;
            // If incrementing
            }else{
                // Add 1
                counter2 = counter2 + 1;
            }
            // Moves up 1 index in current quadrant
            m_arrayOfQuadrants[counter2] = m_arrayOfQuadrants[counter2] + 1;
            characterToManipulate = GetMessage().at(m_arrayOfQuadrants[counter2]);
            decryptedString = decryptedString + characterToManipulate;

        }
    }
    
    SetMessage(decryptedString);
    ToggleEncrypted();
}

string RailFence::ToString(){
    // Returns that it is a RailFence cipher
    return "(RailFence)";
}

string RailFence::FormatOutput(){
    // true is 1, false is 0

    stringstream ss;

    ss << 'r';
    ss << '|';
    if(GetIsEncrypted() == true){
        ss << 1;
    }else{
        ss << 0;
    }
    ss << '|';
    ss << GetMessage();
    ss << '|';
    ss << m_rails;
    ss << '\n';

    // Stores all info into stream
    string info = ss.str();

    return info;

}