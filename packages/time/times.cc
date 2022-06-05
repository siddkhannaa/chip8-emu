#include <iostream>
#include <chrono>
// #include <ctime>

#include <emojicode/runtime/Runtime.h>

// extern "C" runtime::Integer getEpoch() {
extern "C" runtime::Integer getTime(runtime::ClassInfo*) {

    // auto time = std::chrono::system_clock::now(); boblov

    uint64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    runtime::Integer output = (runtime::Integer)ms;

    return output;
    // std::cout << "yo" << std::endl;
}