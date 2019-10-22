// This is a basic tutorial to how implement threads in C++ using std::threads


#include <iostream>
#include <thread>
static const int num_threads = 10;

// This is our function that will run in different threads
void call_from_thread(int a, int b) {
    std::cout << "Launched by thread " << a <<" "<<b<< std::endl;
}


int main() {
    std::thread t[num_threads]; // This is our thread vector containing our threads
    for (int i = 0; i < num_threads; ++i) {
        int b = i+1;
        t[i] = std::thread(call_from_thread, i, b); // Here we instantiate our threads
    }
    std::cout << "Launched from the main\n";
    for (int i = 0; i < num_threads; ++i) {
        t[i].join(); // Here we call our threads by joining then to the main thread. By doing this we ensure that each one will run until the end.
    }
    return 0;
}
