#include <iostream>
#include <thread>
#include <chrono>
#include <utility>
#include <shared_mutex>
#include <mutex>
#include <vector>
using namespace std;
/* Multi reader and single writer
reader perspective
However, in scenarios involving multiple readers and a single writer,
there is a high probability of multiple readers accessing the critical section concurrently.
Since readers do not modify the data in the critical section, their simultaneous access does not cause a data race.
We do not need to synchronize shared data access in this case.
writer perspective
When a writer thread needs to access the critical section, it is essential to block access for all other reader and writer threads.
This ensures the shared data in the critical section remains consistent and is not modified until the writer thread completes its work.
*/

/* shared mutex has 2 options
exclusive lock
- No other thread may acquire a lock.
- No other thread can enter a critical section.
std::lock_guard<std::shared_mutex>
std::unique_lock<std::shared_mutex>

shared lock
- Other threads may acquire a shared lock.
- They can execute critical section concurrently.
std::shared_lock<std::shared_mutex>

shared_mutex in this compiler is renamed as shared_timed_mutex
*/

std::shared_timed_mutex sm;
int x = 0; // shared variable

void reader() {
    cout << "reader" << endl;
    std::shared_lock<std::shared_timed_mutex> lg(sm);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void writer() {
    cout << "writer" << endl;
    std::lock_guard<std::shared_timed_mutex> lg(sm);
    // critical section
    ++x;
}

int main() {
    vector<std::thread> v;
    auto start = std::chrono::steady_clock::now();
    // 20 readers 
    for (int i = 0;i < 20;i++) {
        v.push_back(std::thread(reader));
    }
    // 2 writers
    v.push_back(std::thread(writer));
    v.push_back(std::thread(writer));
    // 20 readers
    for (int i = 0;i < 20;i++) {
        v.push_back(std::thread(reader));
    }
    for (auto& t : v) {
        t.join();
    }
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << "ms" << endl;
    return 0;
}

/* with above approach with normal mutex and lock_guard
40 readers - 40 * 100ms = 4000ms
2 writers
so total time roughly ~4000ms
with shared_mutex - writers have exclusive lock and readers have shared_lock
readers access concurrently
write access exclusive lock
40 readers -  all take 100ms
2 writers
so total time rougly ~100ms
*/