# CppTimer
C++ Timer

It's a simple C++ Timer implementation (C++14). Everything You need is to include Timer.hpp file.

To use it just create a Timer class object (with providing a function. It can be lambda or another function pointer) and he will start working immediately. When the lifetime of the Timer class object is ending timer is stopping automatically.

Example of use:

```
// ────────────────────────────────────────────────────────────────────────────────────────────── //
// CppTimer
#include "../src/Timer.hpp"

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// stl
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void calledByTimer(){
    cout << "Timer called function" << endl;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
int main() {
    CppTimer::Timer timer ( &calledByTimer, 2000 );
    for ( int i = 0; i < 10; i++ ) {
        this_thread::sleep_for ( chrono::seconds ( 1 ) );
        cout << "Main thread step" << endl;
    }
    cout << "Example is stopping" << endl;
    return 0;
}
```

To compile a provided example use:
```
g++ main.cpp -std=c++14 -pthread -o example
```
