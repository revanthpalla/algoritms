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
    static std::shared_ptr<DBConnection> instance;
    static std::mutex mtx;
public:
    static shared_ptr<DBConnection> getInstance() {
        std::lock_guard<std::mutex> lg(mtx);
        if (DBConnection::instance == nullptr) {
            std::shared_ptr<DBConnection> instance1(new DBConnection());
            //DBConnection::instance = std::make_shared<DBConnection>();
            instance1.swap(instance);
        }
        return DBConnection::instance;
    }
    void connect() {
        cout << "instance id: " << instance << " got connected" << endl;
    }
};
// Initialize static members outside the class definition
std::mutex DBConnection::mtx;
std::shared_ptr<DBConnection> DBConnection::instance = nullptr;

int main() {
    std::shared_ptr<DBConnection> db1 = DBConnection::getInstance();
    std::shared_ptr<DBConnection> db2 = DBConnection::getInstance();
    db1->connect();
    db2->connect();
    return 0;
}