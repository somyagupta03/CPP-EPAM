#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mtx1;
std::mutex mtx2;

void threadA() {
    std::lock_guard<std::mutex> lock1(mtx1);
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // simulate work
    std::cout << "Thread A locked mtx1, trying to lock mtx2...\n";

    std::lock_guard<std::mutex> lock2(mtx2);  // waits for mtx2
    std::cout << "Thread A acquired both locks.\n";
}

void threadB() {
    std::lock_guard<std::mutex> lock2(mtx2);
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // simulate work
    std::cout << "Thread B locked mtx2, trying to lock mtx1...\n";

    std::lock_guard<std::mutex> lock1(mtx1);  // waits for mtx1
    std::cout << "Thread B acquired both locks.\n";
}

int main() {
    std::thread t1(threadA);
    std::thread t2(threadB);

    t1.join();
    t2.join();

    std::cout << "Done.\n";
    return 0;
}
