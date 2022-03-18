// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: Vignere Cipher.cpp
// Program Description: input to user a message and keyword ,then the message is encrypted  or decrypted by key according to switch 
// Last Modification Date: 17/3/2022
// Teaching Assistant: Eng------
// ID = 20210113
#include <iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int main()  
{
    cout<< "Ahlan ya user ya hapbibi."<<endl ;
    cout<< "1-Cipher a message"<<endl ;
    cout<<"2-Decipher a message"<<endl ;
    cout<<"3-end"<<endl ;
    string message;
    string key ;
    int input ;
    cin>>input ;
    switch (input){
        
    case 1 :
      
    { 
        cout<<"plz enter the message to cipher with capital letters:"<<endl ; //input the message
        cin.ignore();
        getline(cin,message) ;
        while(message.length() > 80) // the length of message should be less than or equal 80
        {
          cout<<"plz enter the message again and length of letters should be less than or equal 80 :"<<endl ;
          getline(cin,message) ;
        }
        cout<<"plz enter the key with capital letters :"<<endl ; // input the key
        getline(cin,key) ;
        while(key.length() > 8) //the length of key should be less than or equal 8
        {
          cout<<"plz enter the key again and lenth of it should be less than or equal 8 :"<<endl ;
          getline(cin,key) ;
        }
        while (message.length() > key.length()) // repeated key
        {    
          for (int j= 0; ; j++)
          {
             int p = message.length();
             if (p == j)
                j = 0;
             if (key.length() == message.length())
                break;
             key.push_back(key[j]);
          }
        }
        cout<<key<<endl; // Output repeated key
        for(int i = 0 ; i<message.length(); i++ ) // encrypted message
        {
          char c = message[i] ;
          char v = key[i] ;
          if (message[i]==' ') // if in message any space 
          {
             cout<<message[i] ;
             continue ;
          }
          if (not isalpha(message[i])) // if in message not alphabetic characters
          {
             cout<<message[i] ;
             continue ;
          }
          int x = message[i] + key[i] ;
          int encrytpted_message = x % 26 +'A' ;
          cout<<char(encrytpted_message) ; // Output encrypted message
        }
        cout<<endl ;
    }  
    break ;
    
    case 2 : 
    
    {    
        cout<<"plz enter the message to decipher with capital letters:"<<endl ; //input the encrypted message
        cin.ignore();
        getline(cin,message) ;
        while(message.length() > 80) // the length of encrypted message should be less than or equal 80
        {
          cout<<"plz enter the encrypted message again and length of letters should be less than or equal 80 :"<<endl ;
          getline(cin,message) ;
        }
        cout<<"plz enter the key with capital letters :"<<endl ; // input the key
        getline(cin,key) ;
        while(key.length() > 8) //the length of key should be less than or equal 8
        {
          cout<<"plz enter the key again and lenth of it should be less than or equal 8 :"<<endl ;
          getline(cin,key) ;
        }
        while (message.length() > key.length()) // repeated key
        {    
          for (int j= 0; ; j++)
          {
             int p = message.length();
             if (p == j)
                j = 0;
             if (key.length() == message.length())
                break;
             key.push_back(key[j]);
          }
        }
        cout<<key<<endl; //output repeated key
        for (int i = 0 ; i<message.length() ; i++) // decrypted message
        {
          char c = message[i] ;
          char v = key[i] ;
          if (message[i]==' ')   //if in  encrypted message any space
          {
             cout<<message[i] ;
             continue ;
          }
          if (not isalpha(message[i]))  // if in encrypted message not alphabetic characters
          {
             cout<<message[i] ;
             continue ;
          }
          int x = message[i] - key[i] + 26 ;
          int decrypted_message = x % 26 + 'A' ;
          cout<<char(decrypted_message) ; //output decrypted message
            
        }
    }
    break ;
    
    case 3 : // finish the program
      
       break ;
    
    }
    return 0 ;
    
}