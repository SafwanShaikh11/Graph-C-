#include<iostream>
#include <thread>
#include<chrono>

using namespace std;

void func(){
    cout << "Hello from the thread!" << endl;
}

int main(){

    thread t(&func);

    t.joinable();
    t.join();
    cout << " the thread is running" <<endl;
    return 0;

}