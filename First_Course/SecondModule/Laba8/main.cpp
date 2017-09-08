#include <iostream>
#include <vector>
template <typename IT>
void sort(IT beg, IT end){

    for(IT i=beg;i!=end;++i){
        for (IT j=i;j<end-1;++j){
            if(*j<*(j-1))
                std::swap(*j,*(j-1));
        }
    }
}
template <typename IT>
void print(IT beg, IT end){

    for(IT i=beg;i!=end;++i){
        std::cout<<*i<<" ";
    }
    std::cout<<std::endl;
}
int main()
{
    int arr [] = {123, 3, 0, 13212, -100};
    sort(&arr[0], &arr[3]);// arr: 0, 3, 123, 13212, -100
    print(&arr[0],&arr[5]);
    sort(&arr[2], &arr[5]); // arr: 0, 3, -100, 123, 13212
    print(&arr[0],&arr[5]);
    std::vector<double> vec = {123.0, 3.0, 0.0, 13212.0, -100.0};
    sort(vec.begin(), vec.end()); // vec: -100.0, 0.0, 3.0, 123.0, 13212.0
    print(vec.begin(), vec.end());
    return 0;
}