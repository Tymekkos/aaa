#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string dopisz(string text, char c){
    return text + c;
}

string zmien(string text, char c){
    text[text.size()-1] = c;
    return text;
}

string usun(string text){
    text.pop_back();
    return text;
}

string przesun(string text, char c){
    int t = text.find(c);
    if(t!=-1){
        if(c=='Z'){
            c='A';
        }else{
            c++;
        }
        text[t] = c;
    }
    return text;
}

int main()
{
    ifstream file("instrukcje.txt");
	string napis = "";
	if (!file){
        cout << "blad obslugi pliku" << endl;
	}
	string s;
	bool isCommand= true;
	int command == -1;
	while(file >> s){
        if(isCommand){
            if(s == "DOPISZ"){
                command = 0;
            }else if(s == "ZMIEN"){
                command = 1;
            }else if(s == "USUN"){
                command = 2;
            }else if(s == "PRZENIES"){
                command = 3;
            }
            isCommand=false;
        }else{
            current = s[0];
            switch(command){
            case 0:
                napis = dopisz(napis, current);
                break;
            case 1:
                napis = zmien(napis, current);
                break;
            case 2:
                napis = usun(napis);
                break;
            case 3:
                napis = przenies(napis, current);
                break;
            }
            isCommand = true;
        }
	}
	file.close();
	cout << napis;

    return 0;
}
