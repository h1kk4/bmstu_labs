#include <iostream>
#include "PC.h"
#include <string>
int main() {
    int n(0), freaquence(0);
    std::string title;
    std::cout << "Enter the number of PC's" << std::endl;
    std::cin>>n;
    PC *list = new PC[n];
    for (int i=0;i<n;i++){
        std::cin>>title;
        std::cin>>freaquence;
        list[i].SetDate(title,freaquence);
    }
    PC temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (list[j].GetDate() < list[j + 1].GetDate()) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
    for (int i=0;i<n;i++){
        list[i].Print();
    }
    delete[] list;
    return 0;
}