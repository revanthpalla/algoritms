#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <utility>
using namespace std;

int main() {
    int foo_count = 0, bar_count = 0;
    std::mutex foo_mtx, bar_mtx;
    int overall_count = 0;
    std::mutex done_mtx;
    bool done = false;

    auto increment = [](int& count, std::mutex& m, const char* desc) {
        for (int i = 0;i < 10;i++) {
            std::unique_lock<std::mutex> u_lock(m);
            ++count; //critical section
            cout << desc << ": " << count << '\n';
            u_lock.unlock();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        };

    thread foo_thread(increment, std::ref(foo_count), std::ref(foo_mtx), "FOO");
    thread bar_thread(increment, std::ref(bar_count), std::ref(bar_mtx), "BAR");

    thread consumer([&]() {
        done_mtx.lock();
        while (!done) {
            done_mtx.unlock();
            int result = std::try_lock(foo_mtx, bar_mtx);
            if (result == -1) {
                overall_count += foo_count + bar_count;
                foo_count = 0;
                bar_count = 0;
                cout << "overall_count: " << overall_count << endl;
                foo_mtx.unlock();
                bar_mtx.unlock();
            }
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        });

    // waiting states
    foo_thread.join();
    bar_thread.join();
    done_mtx.lock();
    done = true;
    done_mtx.unlock();
    consumer.join();

    // display results
    cout << "Done Processing ..... " << endl;
    cout << "foo counter: " << foo_count << endl;
    cout << "bar counter: " << bar_count << endl;
    cout << "overall counter: " << overall_count << endl;

    return 0;
}