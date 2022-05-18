#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;

int displayMenu(){
    int choice;
    cout << "\n\nPlease enter process you want: " << endl;
    cout << "1. Add new text to the end of the file." << endl;
    cout << "2. Display the content of the file." << endl;
    cout << "3. Empty the file." << endl;
    cout << "4. Encrypt the file content." << endl;
    cout << "5. Decrypt the file content." << endl;
    cout << "6. Merge another file." << endl;
    cout << "7. Count the number of words in the file." << endl;
    cout << "8. Count the number of characters in the file." << endl;
    cout << "9. Count the number of lines in the file" << endl;
    cout << "10. Search for a word in the file" << endl;
    cout << "11. Count the number of times a word exists in the file" << endl;
    cout << "12. Turn the file content to upper case." << endl;
    cout << "13. Turn the file content to lower case." << endl;
    cout << "14. Turn file content to 1st caps (1st char of each word is capital)" << endl;
    cout << "15. Save" << endl;
    cout << "16. Exit\n" << endl;
    cin >> choice;
    return choice;
}

void loadfile (vector<string>& text, ifstream& mainfile){
    char name[101]; char line[100];
    cout << "Please enter file name: ";
    cin >> name;
    mainfile.open(name);
    if (mainfile){
        cout << "File was opened successfully.";
        while (!(mainfile.eof())){
            mainfile.getline(line,100,'\n');
            text.push_back(string(line));
        }
    }else {
        cout << "This file could not be opened.";
    }
}

void numword(ifstream& mainfile){
    int counter = 0;
    char c;
    mainfile.seekg(0,ios::beg);
    while (!mainfile.eof()){
        mainfile.get(c);
        if (isspace(int(c))){
                counter += 1;
        }
    }
    cout << "The number of words is " << counter;
}

void numcharacter(ifstream& mainfile){
    int counter = 0;
    char c;
    mainfile.seekg(0,ios::beg);
    while (!mainfile.eof()){
        mainfile.get(c);
        if (isalpha(int(c))){
            counter += 1;
        }
    }
    cout << "The number of characters is " << counter;
}

int main()
{
    cout << "Welcome to TextEditor program." << endl;
    bool run = true;
    ifstream mainfile;
    vector<string> text;
    loadfile (text, mainfile);

    while (run){
        int choice;
        choice = displayMenu();
        switch (choice){
            case 1:
               {
                string name1;
                cout<<"Enter the file name again: ";
                cin>>name1;
                string text = "" ;
                cout<<"Enter text to write to file: "<<endl ;
                cin>>text;
                ofstream mainfile ;
                mainfile.open(name1);
                mainfile << text ;
                mainfile.close();
                }

                break;
            case 2:
                {
                    string name2;
                    cout<<"Enter file name again :";
                    cin>>name2;
                    ifstream mainfile ;
                    mainfile.open(name2,ios::in);
                    if(!mainfile)
                    {
                        cout<<"file does not exist!\n";
                        exit(0);
                    }
                    else
                    {
                        cout<<"contant of file....:\n";
                        while(mainfile.eof()==0) //read data from file
                        {
                            char line[100];
                            mainfile.getline(line,sizeof(line));
                            cout<<line<<"\n";
                        }

                    }
                    mainfile.close();
                }
                break;
            case 3:
                {
                    string name7;
                    cout<<"Enter file name again: ";
                    cin>>name7;
                    fstream mainfile;
                    mainfile.open(name7, ios::out);
                    mainfile.close();
                }

                break;
            case 4:
            {
             string name3;
             string name4;
             cout<<"Enter file name again :";
             cin>>name3;
             cout<<"Enter file name that encrypted data will put it: ";
             cin>>name4;
            ifstream mainfile(name3);
            ofstream mainfile1(name4);
            string string1 ;
            while(getline(mainfile,string1))
            {
                cout <<string1<<endl ;
                string encrypt1;
           for(int i = 0 ; i<string1.size();i++)
           {
            if (isupper(string1[i]))
            {
                if (string1[i] >= 'V' && string1[i] <= 'Z')
               {
                encrypt1 += (char)(string1[i] + 5 - 'Z' + 'A' - 1);
              }
             else if (string1[i] >= 'A' && string1[i] <= 'U')
             {
                encrypt1 += (char)(string1[i] + 5);
             }
            else
            {
                encrypt1 += string1[i];
            }
            }
        else
        {
            if (string1[i] >= 'v' && string1[i] <= 'z')
            {
                encrypt1 += (char)(string1[i] + 5 - 'z' + 'a' - 1);
            }
            else if (string1[i] >= 'a' && string1[i] <= 'u')
            {
                encrypt1 += (char)(string1[i] + 5);
            }
            else
            {
                encrypt1 += string1[i];
            }
        }

            }
                    mainfile1 << encrypt1 << endl;
                    }
                    mainfile.close();
                    mainfile1.close();
                }
                break;
            case 5:
                {
                    string name5;
                    string name6;
                    cout<<"Enter file name which consist of encrypted data: ";
                    cin>>name5;
                    cout<<"Enter file name that decode this encrypted data will put it;";
                    cin>>name6;
                    ofstream mainfile(name6);
                    ifstream mainfile1(name5);
                    string encrypt1;
                    while(getline(mainfile1,encrypt1))
                    {
                        cout<<encrypt1<<endl;
                        string decode ;
                        for(int i =0 ; i<encrypt1.size();i++)
                        {
                if (isupper(encrypt1[i])){
                if (encrypt1[i]>='A' && encrypt1[i]<='E'){
                    decode += (char)(encrypt1[i] - 5 + 'Z' - 'A' + 1);
                }else if (encrypt1[i]>='F' && encrypt1[i]<='Z'){
                    decode += (char)(encrypt1[i]-5);
                }else {
                    decode += encrypt1[i];
                }
            }else{
                if (encrypt1[i]>='a' && encrypt1[i]<='e'){
                    decode += (char)(encrypt1[i] - 5 + 'z' - 'a' + 1);
                }else if (encrypt1[i]>='f' && encrypt1[i]<='z'){
                    decode += (char)(encrypt1[i]-5);
                }else {
                    decode += encrypt1[i];
                }
            }
                        }
                    mainfile << decode << endl;
                    }
                 mainfile.close();
                 mainfile1.close();
                }
                break;
            case 6:
                break;
            case 7: numword(mainfile);
                break;
            case 8: numcharacter(mainfile);
                break;
            case 9: cout << "Number of lines: " << text.size();
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            case 13:
                break;
            case 14:
                break;
            case 15:
                break;
            case 16:
                cout << "Thanks for using TextEditor program.";
                run = false;
                break;
        }
    }
    return 0;
}
