#include<iostream>
#include<vector>
#include<list> //It's a doubly linked list 
using namespace std;


void print(){
    string name="this is walter";
    string *pname=&name;
    cout << *pname << endl;
}
int main(){
        print();
    std::cout << "This is my first c++ program";
    return 0;
}
