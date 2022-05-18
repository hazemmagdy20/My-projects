#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctype.h>
#include <fstream>
#include <regex>
#include <conio.h>

using namespace std;

struct regester{
    int id;
    string username;
    string email;
    string phone;
    string password;
};

string pass(){
    cout << "Please enter the password according to the following instructions:" << endl;
    cout << "It is allowed to use : Lowercase Characters, Uppercase Characters, Numbers" << endl;
    cout << "It is NOT allowed to use any other symbols like !@#$%^" << endl;
    cout << "Enter PassWord : ";
    string password;
    string confirm;
    char ch;
    while (true){
        if (password.length()<=7){
            while ((ch = getch()) != '\r'){
                if (ch == '\b'){
                    cout << "\b \b";
                  password.pop_back();
                }else {
                cout << "*";
                password += ch;
                }
            }regex e("[0-9|a-z|A-Z]{8,}");
            bool match = regex_match(password,e);
            if (match == true){cout << "\nYour password is : " << password << endl;}
            else {cout << "\nNot valid." << endl;}
            cout << "Enter the password again : ";
        }else {break;}
    }while (confirm != password){
        cin >> confirm;
        if (confirm == password){cout << "Your password is accepted.";}
        else {cout << "Enter the right password : ";}
    }
    return password;
}

string e_mail(){
    string email;
    string e_mail1;
    cout<<"Enter your email : ";
    cin>> email ;
    regex r("[[:w:]]+@[[:w:]]+(.com)");
    bool work = regex_match(email,r);
    while (work != true){
           cout << "\nNot valid." << endl;
           cout << "Enter the Email again : ";
           cin>>e_mail1;
           bool work1 = regex_match(e_mail1,r);
           if (work1 == true){
                break;
           }
    }cout<<"The Email is accepted."<<endl;
    return email;

}

string the_phone(){
    string phone ;
    string phone1;
    cout<<"Enter your phone : ";
    cin>> phone;
    regex d("(01)?[0-9]{11}");
    bool truth = regex_match(phone,d);
    if (truth == false){
        while (truth != true){
            cout << "not valid." << endl;
            cout << "Enter the phone again : ";
            cin >> phone1;
            bool truth1 = regex_match(phone1, d);
            if (truth1 == true){
                break;
            }
        }
        return phone1;
    }
    else{
        cout << "The phone is accepted." << endl;
        return phone;
    }
}

string Encryption(string text)
{
    string cipher = "";
    for (int i = 0; i <= text.length(); i++)
    {
        if (isupper(text[i]))
        {
            if (text[i] >= 'V' && text[i] <= 'Z')
            {
                cipher += (char)(text[i] + 1 - 'Z' + 'A' - 1);
            }
            else if (text[i] >= 'A' && text[i] <= 'U')
            {
                cipher += (char)(text[i] + 1);
            }
            else
            {
                cipher += text[i];
            }
        }
        else
        {
            if (text[i] >= 'v' && text[i] <= 'z')
            {
                cipher += (char)(text[i] + 1 - 'z' + 'a' - 1);
            }
            else if (text[i] >= 'a' && text[i] <= 'u')
            {
                cipher += (char)(text[i] + 1);
            }
            else
            {
                cipher += text[i];
            }
        }
    }
    return cipher;
}

int main(){
    int process;
    cout << "Hello user.\n\nWhat do you want to do?\n\n1- Register.\n\n2- Login.\n\n3-Change Password.\n\n4-Exit." << endl
         << endl<< "=>";
    while (true){
        cin >> process;
        if (process == 1){
            regester order[1000];
            int increament = 0;

            cout << "Welcome...First we need to fill your information...Please enter the following :" << endl;

            fstream mainfile;
            mainfile.open("data.txt", ios::out|ios::app);

            cout << "Enter ID : ";
            cin >> order[increament].id;
            mainfile << order[increament].id << " ";

            cout << "Enter your name  : ";
            cin >> order[increament].username;
            mainfile << order[increament].username << " ";

            order[increament].email = e_mail();
            mainfile << order[increament].email << " ";

            order[increament].phone = the_phone();
            mainfile << order[increament].phone << " ";

            order[increament].password = pass();
            mainfile << order[increament].password << endl;

            cout << "Your information enter successfully." << endl;

            mainfile.close();
            increament += 1;

        }else if (process == 2){
            //static int incremant = 0;
            int id;
            static int trying = 0;
            while (trying != 3)
            {
                cout << "Enter the id:\n";
                cin >> id;
                cout << "Please enter the password:\n";
                char ch;
                static string password = "";
                ch = getch();
                while ((ch = getch()) != 'p')
                {
                    cout << "*";
                    password = password + ch;
                }
                bool ty = true;
                fstream search;
                search.open("data.txt", ios::in);
                int sure_id;
                string sure_password, sure_user_name;
                while (!search.eof())
                {
                    //cin.ignore();
                    //search.getline(sure_id, 20,' ');
                    //cin.ignore();
                    //search.getline(sure_password, 20,' ');
                    search >> sure_id;
                    search >> sure_user_name;
                    search >> sure_password;
                    if (sure_id == id)
                    {
                        if (Encryption(sure_password) == password)
                        {
                            cout << "Successful login, welcome xxx\n";
                            continue;
                        }
                        else
                        {
                            cout << "Please enter the true password\n";
                            ty = false;
                            break;
                        }
                    }
                    else
                    {
                        cout << "the id isn't found\n";
                        ty = false;
                        break;
                    }
                }

                /*bool ty = true;
                for (int i; i <= 100; i++)
                {
                    if (id == arrprof[i].id)
                    {
                        if (password == arrprof[i].password)
                        {
                            cout << "Successful login, welcome xxx\n";
                        }
                        else
                        {
                            cout << "Please enter the true password\n";
                            ty = false;
                            break;
                        }
                    }
                    else
                    {
                        cout << "the id isn't found\n";
                        ty = false;
                        break;
                    }
                }*/
                if (ty == false)
                {
                    trying++;
                    process = 2;
                }
                if (trying == 3)
                {
                    cout << "you are denied access to system with this information\n";
                    break;
                }
                continue;
            }
        }else if (process == 3)
        {
            fstream search;
            search.open("data.txt", ios::in);
            int id, sure_id;
            static string new_password, sure_password, sure_user_name;
            char ch2, ch3;
            cout << "Please enter the id and the old password:\n";
            cin >> id;
            char ch;
            //pass();
            static string password = "";
            ch = getch();
            while ((ch = getch()) != 'p')
            {
                cout << "*";
                password = password + ch;
            }
            while (search.eof())
            {
                search >> sure_id;
                search >> sure_user_name;
                search >> sure_password;
                if (sure_id == id)
                {
                    if (Encryption(sure_password) == password)
                    {
                        cout << "Enter the new password:\n";
                        ch2 = getch();
                        while ((ch2 = getch()) != 'p')
                        {
                            cout << "*";
                            new_password = new_password + ch2;
                        }
                        cout << "\nthe new password is " << new_password << endl;
                        if (new_password == password)
                        {
                            cout << "Please enter new password different from the old password :( \n";
                            break;
                        }
                        cout << "Enter the new password again :\n";
                        ch3 = getch();
                        while ((ch3 = getch()) != 'p')
                        {
                            cout << "*";
                            sure_password = sure_password + ch3;
                        }
                        if (sure_password == new_password)
                        {
                            cout << "Successful change password :) \n";
                            password = new_password;
                        }

                        else
                        {
                            cout << "Failed to change password :( \n";
                        }
                    }
                }
            }
            continue;
        }
        else if (process == 4){
            cout << "Thanks for using." << endl;
            break;
        }
    }
    return 0;
}
