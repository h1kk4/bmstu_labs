#include <iostream>
#include <string>

using namespace std;

int main() {
    while (true) {
        string buff;
        getline(cin, buff);
        if (buff.empty()) {
            cout << "Error!" << '\n';
        }
        if (buff=="exit"){
            exit(1);
        }
        string rev;
        for (int i=0; i<buff.length(); ++i){
            rev.push_back(buff[i]);
        };
        reverse(rev.begin(),rev.end());
        if (buff==rev){
            cout<<"Palindrom"<<'\n';
        }
        else{
            cout<<"It's not a palindrom"<<'\n';
        }

    }

}