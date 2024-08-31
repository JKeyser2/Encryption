//Title: Cipher.cpp
//Author: Jackson Keyser
//Date: 4/20/2022
//Description: This is part of the Cipher Project in CMSC 202 @ UMBC
#include "Cipher.h"

Cipher::Cipher(){
    m_message = "message";
    m_isEncrypted = false;
}

Cipher::Cipher(string message, bool isEncrypted){
    m_message = message;
    m_isEncrypted = isEncrypted;
}

Cipher::~Cipher(){
   // cout << "CIPHER DESTURCTOR!" << endl;
}

string Cipher::GetMessage(){
    return m_message;
}

bool Cipher::GetIsEncrypted(){
    return m_isEncrypted;
}

void Cipher::SetMessage(string message){
    m_message = message;
}

void Cipher::ToggleEncrypted(){
    // This will flip the boolean for whether or not the message is encrypted
    if(m_isEncrypted == true){
        m_isEncrypted = false;
    }else{
        m_isEncrypted = true;
    }
}

ostream &operator<<( ostream &output, Cipher &C){
    output << C.GetMessage() << endl;
    return output;
}