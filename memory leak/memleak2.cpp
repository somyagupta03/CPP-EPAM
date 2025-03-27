#include <iostream>
#include <crtdbg.h>  // Include the CRT header for memory leak detection

void createMemoryLeak() {
    int* leakyArray = new int[100];  // Dynamically allocate memory
    std::cout << "Memory allocated for leakyArray\n";
    
    // Memory is not deallocated, causing a memory leak
}

int main() {
    // Enable memory leak detection
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // Create variables to store checkpoint memory states
    _CrtMemState checkpointBefore;
    _CrtMemState checkpointAfter;
    _CrtMemState memDiff;

    // Insert a checkpoint before memory allocation
    _CrtMemCheckpoint(&checkpointBefore);

    createMemoryLeak();  // Call the function where memory leak happens
    
    // Insert a checkpoint after memory allocation (before program exits)
    _CrtMemCheckpoint(&checkpointAfter);

    std::cout << "Exiting program...\n";
    
    // Compare memory checkpoints
    if (_CrtMemDifference(&memDiff, &checkpointBefore, &checkpointAfter)) {
        std::cout << "Memory Leak Detected!\n";
    } else {
        std::cout << "No memory leaks detected.\n";
    }

    return 0;
}
