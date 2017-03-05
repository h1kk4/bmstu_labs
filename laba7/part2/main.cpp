#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Print(const vector<string> &V, int count, int numb, const string &word) {
    int k;
    int i;
    if (numb != 0) {
        k = 0;
        i = numb - 1;
        string str;
        cout << "From left side - ";
        while (true) {
            if (k == count || i < 0) break;
            str = V[i] + " " + str;
            k++;
            --i;
        }
        cout << str << " ";
    }
    if (numb != V.size() - 1) {
        k = 0;
        i = numb + 1;

        cout << "From the right side - ";
        while (true) {
            if (i == V.size() || k == count) break;
            cout << V[i] << " ";
            k++;
            i++;
        }
        cout << ';' << '\n';
    }
}

void toLow(string &word) {
    for (int i = 0; i < word.size(); i++) {
        word[i] = char(tolower(word[i]));
    }
}

int main() {
    ifstream File;
    File.open("/Users/alex/ClionProjects/Laba7_part2/File1.txt");
    string word;
    cout << "Enter your word" << '\n';
    getline(cin, word);
    toLow(word);
    int n(0);
    cout << "How many words to show?" << '\n';
    cin >> n;
    string buff;
    int count = 1;
    bool flag = true;
    while (!File.eof()) {
        getline(File, buff);
        string str;
        vector<string> Vector;
        for (int i = 0; i <= buff.length(); i++) {
            if (isalpha(buff[i])) {
                str.push_back(char(tolower(buff[i])));
            } else if (!str.empty()) {
                Vector.push_back(str);
                str = "";
            }
        }
        vector<int> Locations;
        for (int i = 0; i < Vector.size(); i++) {
            if (Vector[i] == word) {
                Locations.push_back(i);
            }
        }
        if (!Locations.empty()) {
            flag = false;
            for (int i = 0; i < Locations.size(); i++) {
                cout << "String #" << count << " ";
                Print(Vector, n, Locations[i], word);
            }
        } else {
            count++;
            continue;
        }
        count++;
    }
    if (flag)
        cout << "The word = " << word << " was not found in File" << '\n';

    File.close();
    return 0;
}