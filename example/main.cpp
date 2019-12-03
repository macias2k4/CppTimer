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
