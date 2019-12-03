#pragma once

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// stl
#include <chrono>
#include <future>
#include <iostream>
#include <thread>
#include <memory>

namespace CppTimer {

class Timer {
public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    template<typename Function>
    Timer ( Function function, int intervalInMSec );
    ~Timer();

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // member functions
    inline void stop() {
        _active = false;
    }

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    std::unique_ptr<std::thread> _thread;
    bool _active{false};
    uint _intervalInMSec{100};

};

// ────────────────────────────────────────────────────────────────────────────────────────────── //
template <typename Function>
Timer::Timer ( Function function, int intervalInMSec ) {
    _active = true;
    _intervalInMSec = intervalInMSec;
    _thread = std::make_unique<std::thread> ( [ = ]() {
        while ( _active ) {
            std::this_thread::sleep_for ( std::chrono::milliseconds ( intervalInMSec ) );
            function();
        }
    } );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
Timer::~Timer() {
    stop();
    _thread->join();
}

} // CppTimer
