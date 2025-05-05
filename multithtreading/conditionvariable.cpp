#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

std::condition_variable cv;
std::mutex m;
long balance = 0;

void addMoney(int money) {
	std::lock_guard<mutex>lg(m);
	balance += money;
	cout << "Amount added current balance: " << balance << endl;
	cv.notify_one();
}

void withdrawMoney(int money) {
	std::unique_lock<mutex> ul(m);
	//if balance if zero the condition becomes false and the mutex will wait and lock goes to another thread.
	cv.wait(ul, [] { return { balance != 0 } ? true : false;});
	if (balance >= money) {
		balance -= money;
		cout << "Amount deducted: " << money << endl;
	}
	else {
		cout << "Amount cant be deducted , current balance is less than" << money << endl;
	}
	cout << "Current balance is: " << balance << endl;
}

int main() {
	std::thread t1(withdrawMoney, 500);
	std::thread t2(addMoney, 500);
	t1.join();
	t2.join();
	return 0;
}