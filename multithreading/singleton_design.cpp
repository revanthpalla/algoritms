#include <iostream>
#include <memory>
#include <mutex>
using namespace std;

class DBConnection {
private:
    DBConnection() {
        cout << "DBConnection() constructor ..." << endl;
    }
    /* Disable copy constructor and assignment operator */
    DBConnection(const DBConnection&) = delete;
    DBConnection& operator=(const DBConnection&) = delete;
    /* Disable move constructor and move assignment operator */
    DBConnection(DBConnection&&) = delete;
    DBConnection& operator=(DBConnection&&) = delete;
    /* Private static instance */
    static DBConnection* instance;
    static mutex mtx;
public:
    static DBConnection* getInstance() {
        std::lock_guard<std::mutex> lg(mtx);
        if (instance == nullptr) {
            instance = new DBConnection();
        }
        return instance;
    }
    void connect() {
        cout << "instance id: " << instance << " got connected" << endl;
    }
};
// Initialize static members outside the class definition
std::mutex DBConnection::mtx;
DBConnection* DBConnection::instance = nullptr;

int main() {
    DBConnection* db1 = DBConnection::getInstance();
    DBConnection* db2 = DBConnection::getInstance();
    db1->connect();
    db2->connect();
    return 0;
}