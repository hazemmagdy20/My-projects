#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <string.h>

using namespace std;

int displayMenu(fstream& mainfile, string name){
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
    if (choice == 1||choice == 6||choice == 12||choice == 13||choice == 14){
        mainfile.open(name,ios::app);
    }else if(choice == 2||choice == 4||choice == 5||choice == 7||choice == 8||choice == 9||choice == 10||choice == 11){
        mainfile.open(name,ios::in);
    }
    return choice;
}

void loadfile (vector<string>& text, fstream& mainfile){
    char line[100];
    mainfile.open(name);
    if (mainfile){
        cout << "File was opened successfully.";
        while (!(mainfile.eof())){
            mainfile.getline(line,100,'\n');
            text.push_back(string(line));
        }
    }else {
        mainfile.open(name,ios::out);
        cout << "This is a new file. I created it for you.";
    }
    mainfile.close();
}

void addtext(fstream &mainfile){
    string text = "" ;
    cout << "Enter text to write to file: "<<endl ;
    cin >> text;
    mainfile << text << " ";
    mainfile.close();
}

void showfile(fstream &mainfile){
    cout<<"contant of file....:\n";
    while(mainfile.eof()==0){
    char line[100];
    mainfile.getline(line,sizeof(line));
    cout<<line<<"\n";
    }
    mainfile.close();
}

void emptyfile(fstream& mainfile, string name){
    mainfile.open(name, ios::out | ios::trunc);
    mainfile.close();
}

void encryptfile(fstream& mainfile){
    string name4;
    cout<<"Enter file name that encrypted data will put it: ";
    cin>>name4;
    ofstream mainfile1(name4, ios::out);
    string string1 ;
    while(getline(mainfile,string1)){
        cout <<string1<<endl ;
        string encrypt1;
        for(int i = 0 ; i<string1.size();i++){
            if (isupper(string1[i])){
                if (string1[i] >= 'V' && string1[i] <= 'Z'){
                    encrypt1 += (char)(string1[i] + 1 - 'Z' + 'A' - 1);
                    }
                    else if (string1[i] >= 'A' && string1[i] <= 'U'){
                        encrypt1 += (char)(string1[i] + 1);
                    }
                    else{
                        encrypt1 += string1[i];
                    }
            }
            else{
                if (string1[i] >= 'v' && string1[i] <= 'z'){
                    encrypt1 += (char)(string1[i] + 1 - 'z' + 'a' - 1);
                }
                else if (string1[i] >= 'a' && string1[i] <= 'u'){
                    encrypt1 += (char)(string1[i] + 1);
                }
                else{
                    encrypt1 += string1[i];
                }
            }
        }
        mainfile1 << encrypt1 << endl;
    }
    mainfile.close();
    mainfile1.close();
}

void Decryptfile(fstream& mainfile){
    string name6;
    cout<<"Enter file name that decode this encrypted data will put it;";
    cin>>name6;
    ofstream mainfile1(name6, ios::out);
    string encrypt1;
    while(getline(mainfile, encrypt1)){
        cout << encrypt1 << endl;
        string decode ;
        for(int i =0 ; i<encrypt1.size();i++){
            if (isupper(encrypt1[i])){
                if (encrypt1[i]>='A' && encrypt1[i]<='E'){
                    decode += (char)(encrypt1[i] - 1 + 'Z' - 'A' + 1);
                }else if (encrypt1[i]>='F' && encrypt1[i]<='Z'){
                    decode += (char)(encrypt1[i]-1);
                }else {
                    decode += encrypt1[i];
                }
            }else{
                if (encrypt1[i]>='a' && encrypt1[i]<='e'){
                    decode += (char)(encrypt1[i] - 1 + 'z' - 'a' + 1);
                }else if (encrypt1[i]>='f' && encrypt1[i]<='z'){
                    decode += (char)(encrypt1[i]-1);
                }else {
                    decode += encrypt1[i];
                }
            }
        }
        mainfile1 << decode << endl;
    }
    mainfile.close();
    mainfile1.close();
}

void mergeingfiles (fstream& mainfile){
	cout << "Enter the name of the second file : ";
    ifstream mergefile;
    char name1[31];
    char text;
    cin >> name1;
    mergefile.open(name1,ios::in);
    if((mergefile.fail())||(mainfile.fail())){
    	cout << "Error";
	}else{
	    while (!mergefile.eof()){
            mergefile >> noskipws >> text;
            mainfile << noskipws << text;
        }cout << "Done." << endl;
    }mainfile.close();
    mergefile.close();
}

void numword(fstream& mainfile){
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
    mainfile.close();
}

void numcharacter(fstream& mainfile){
    int noc = 0;
    char c;
    mainfile.seekg(0,ios::beg);
    while (!mainfile.fail()){
        mainfile.get(c);
        if (isalpha(int(c)) or isspace(int(c)) or ispunct(c) or isdigit(int(c))){
            noc += 1;
        }
    }
    cout << "The number of characters is " << noc;
    mainfile.close();
}

void searchword(fstream& mainfile){
    string word;
    cout << "Enter the word to find : ";
    cin >> word;
    string l = "";
    while (getline(mainfile, l)){
        if (l.find(word, 0) != string::npos){
            cout << "Word was found in the file." << endl;
            break;
        }else {
            cout << "Word was not found in the file." << endl;
        }
    }mainfile.close();
}

void countertimes(fstream& mainfile){
    string iWord, f_word;
    int incremant = 0, len_word;
    cout << "enter the word \n";
    cin >> iWord;
    len_word = sizeof(iWord);
    while (!mainfile.eof()){
        mainfile >> f_word;
        if (f_word == iWord){
            incremant++;
        }
    }
    cout << "the word times is " << incremant;
}

void turnlower(fstream& mainfile,string name,vector<string>& text){
    for (int i =0; i < text.size();i++){
        for (int j =0; j < text[i].size(); j++){
            text[i][j] = tolower(text[i][j]);
        }
    }mainfile.close();
    mainfile.open(name,ios::out | ios::trunc);
    for (auto e:text){
        mainfile << e;
    }
}

int main()
{
    cout << "Welcome to TextEditor program." << endl;
    bool run = true;
    fstream mainfile;
    vector<string> text;
    string name;
    cout << "Please enter file name: ";
    cin >> name;
    loadfile (text, mainfile);

    while (run){
        int choice;
        choice = displayMenu(mainfile,name);
        switch (choice){
	    case 1: addtext(mainfile);
		break;
            case 2: showfile(mainfile);
                break;
            case 3: emptyfile(mainfile, name);
                break;
            case 4: encryptfile(mainfile); 
                break;
            case 5: Decryptfile(mainfile);
                break;
            case 6: mergeingfiles(mainfile);
                break;
            case 7: numword(mainfile);
                break;
            case 8: numcharacter(mainfile);
                break;
            case 9: cout << "Number of lines: " << text.size();
                break;
            case 10: searchword(mainfile);
                break;
            case 11: countertimes(mainfile);
                break;
            case 12:
                break;
            case 13: turnlower(mainfile,name,text);
                break;
            case 14:
                break;
            case 15: cout << "Saved Successfully" << endl;
                break;
            case 16:
                cout << "Thanks for using TextEditor program.";
                run = false;
                break;
        }
    }
    return 0;
}
