#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

// std::mutex m;
// Example -1 Normal lock()
// int amount = 0;
// void deposit(int x) {
//     m.lock();
//     // critical section
//     amount += x;
//     m.unlock();
// }

// Example -2 try_lock()
// int counter = 0;
// void increaseTheCounter10000thTime() {
//     for (int i = 0;i < 10000;i++) {
//         if (m.try_lock()) {
//             ++counter;
//             m.unlock();
//         }
//     }
// }

// Example -3 (std::try_lock())
// int X = 0, Y = 0;
// std::mutex m1, m2;
// void delayForSeconds(int sec) {
//     std::this_thread::sleep_for(std::chrono::seconds(sec));
// }

// void incrementXorY(int& x_y, std::mutex& m, const char* desc) {
//     for (int i = 0;i < 5;i++) {
//         m.lock();
//         ++x_y;
//         cout << desc << x_y << endl;
//         m.unlock();
//         delayForSeconds(1);
//     }
// }

// void consumeXY() {
//     int count = 5;
//     int x_y = 0;
//     while (1) {
//         int lock_res = std::try_lock(m1, m2);
//         if (lock_res == -1) {
//             if (X != 0 and Y != 0) {
//                 count--;
//                 x_y += X + Y;
//                 // after consuming X=0 and Y=0
//                 X = 0;
//                 Y = 0;
//                 cout << "x+y = " << x_y << endl;
//             }
//             m1.unlock();
//             m2.unlock();
//             if (count == 0)
//                 break;
//         }
//     }
// }

// Example -4
// int amount = 0;
// std::timed_mutex m;
// void inc(int i) {
//     if (m.try_lock_for(std::chrono::seconds(1))) {
//         ++amount;
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         cout << "thread - " << i << "entered" << endl;
//         m.unlock();
//     } else {
//         cout << "thread - " << i << "couldn't acquire lock" << endl;
//     }
// }

// Example -5 (important concept recursive mutex)
// std::recursive_mutex m;
// int buffer = 0;
// void recursion_test(char c, int loop_counter) {
//     if (loop_counter < 0)
//         return;
//     m.lock();
//     cout << c << " " << ++buffer << endl;
//     recursion_test(c, --loop_counter);
//     m.unlock();
// }

// Example -6 std::lock_guard<mutex> lock(m1)
// It is a light weight wrapper fow owning a mutex in scope basics
// It acquires a mutex lock the moment you create a object of lock guard
// It automatically removes lock when it goes out of scope
// No need to explicitly unlock lock guard
// can't copy lock guard
// std::mutex m;
// int buffer = 0;
// void task(const char* thread_id, int loop_counter) {
//     std::lock_guard<mutex> lock(m);
//     for (int i = 0;i < loop_counter;i++) {
//         ++buffer;
//         cout << thread_id << buffer << endl;
//     }
// }

// Example -7 std::unique_lock<mutex> lock(m1)
// The class unique lock is a mutex ownership wrapper
// It allows different locking strategies like try_lock, try_lock_for(timed_mutex), recursive_locking
// transfer of lock ownership
// condition variables
// lock strategies
// defer_lock  - do not acuire ownership of mutex
// try_to_lock - try to acqure ownership of mutex without blockng
// adopt_block - assume calling thread has already owner ship of mutex
// std::mutex m;
// void task(const char* thread_id, int loop) {
//     std::unique_lock<mutex> u_lock(m, std::defer_lock); // doesn't lock mutex because of defer_lock
//     u_lock.lock(); // call it explicitly
//     for (int i = 0;i < loop;i++) {
//         cout << thread_id << i << endl;
//     }
//     // u_lock.unlock(); No need to unlock manually destructor of class unique lock called when its out of scope and unlocks it
// }

// Example -8 condition_variable (adv concept in multi threading)
// cv's 
// are used to notify other threads
// waiting for some conditions
// cv's allows running threads to wait on some conditions once those conditions are met the waiting thread is notified using
// - notify_one()
// - notify_all()
// you need mutex to use condition variable
// If some thread wants to wait on some condition then it has to do these things
// a - Acquire mutex lock using std::unique_lock<mutex> u_lock(m)
// b - Execute wait, wait_for or wait_until. The wait operations atomically release the mutex and suspend the execution of thread
// c - when condition variable is notified thread is awekened, mutex atomically reacquired. The thread should check the condition
//.    and resume waiting if wake up was spurious
// std::mutex m;
// std::condition_variable cv;
// long balance = 0;
// void deposit(int amount_) {
//     std::lock_guard<mutex> l(m);
//     balance += amount_;
//     cout << "Amount deposited Balance: " << balance << endl;
//     cv.notify_one();
// }

// void withdraw(int amount_) {
//     std::unique_lock<mutex> u_lock(m);
//     auto bl_check = []() {
//         if (balance > 0)
//             return true;
//         else
//             return false;
//         };
//     // wait on condition variable cv 
//     // first it unique lock, locks (m)
//     // if condition variable preciate is true, then it follows further steps
//     // else it will release lock and waits for someone to notify
//     // if someone notified then it tries to lock mutex, then check condition variable predicate again, then do further steps   
//     cv.wait(u_lock, bl_check);
//     if (balance >= amount_) {
//         balance -= amount_;
//         cout << "Amount withdrawn " << amount_ << " remaining balance is " << balance << endl;
//     } else {
//         cout << "No sufficent Funds to withdraw " << amount_ << endl;
//         cout << "Current Balance is " << balance << endl;
//     }
// }

int main() {
    // Example -1 start
    // thread t1(deposit, 5000);
    // thread t2(deposit, 6000);
    // if (t1.joinable())
    //     t1.join();
    // if (t2.joinable())
    //     t2.join();
    // cout << "Amount: " << amount << endl;
    // Example -1 end

    // Example -2 start
    // thread T1(increaseTheCounter10000thTime);
    // thread T2(increaseTheCounter10000thTime);
    // T1.join();
    // T2.join();
    // cout << "counter: " << counter << endl; // expecting ans = 20000 but came as 10004, every run it changes
    // Example -2 end

    // Example -3 start
    // thread T1(incrementXorY, std::ref(X), std::ref(m1), " x - bucket ");
    // thread T2(incrementXorY, std::ref(Y), std::ref(m2), " y - bucket ");
    // thread T3(consumeXY);
    // T1.join();
    // T2.join();
    // T3.join();
    // Example -3 end

    // Example -4 start
    // thread t1(inc, 1);
    // thread t2(inc, 2);
    // t1.join();
    // t2.join();
    // cout << "Amount - " << amount << endl;
    // Example -4 end

    // Example -5 start
    // thread t1(recursion_test, 'A', 10);
    // thread t2(recursion_test, 'B', 10);
    // t1.join();
    // t2.join();
    // Example -5 end

    // Example -6 start
    // thread t1(task, "A", 10);
    // thread t2(task, "B", 10);
    // t1.join();
    // t2.join();
    // Example -6 end

    // Example -7 start
    // thread t1(task, "A", 10);
    // thread t2(task, "B", 10);
    // t1.join();
    // t2.join();
    // Example -7 end

    // Example -8 start
    // thread t1(withdraw, 700);
    // thread t2(deposit, 600);
    // t1.join();
    // t2.join();
    // Example -8 end
    return 0;
}