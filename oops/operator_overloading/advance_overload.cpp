#include <iostream>
#include <string>
#include <vector>
using namespace std;

class youtube {
private:
    string channel_name;
    int subcribers_count;
public:
    youtube() :channel_name(""), subcribers_count(0) {}
    youtube(string channel, int count) {
        channel_name = channel;
        subcribers_count = count;
    }
    // getter and setter
    string getname() {
        return this->channel_name;
    }
    int getsubscribers() {
        return this->subcribers_count;
    }
    // find algorithm requires overloading of == operator
    bool operator==(const youtube& y) {
        return this->channel_name == y.channel_name;
    }
    // global function defined as a friend function class
    friend ostream& operator<<(ostream&, youtube&);
};

ostream& operator<<(ostream& out, youtube& yt) {
    out << yt.channel_name << "\t" << yt.subcribers_count << '\n';
    return out;
}

class collection_yt {
private:
    vector<youtube> channel_list;
public:
    // pushin collection
    void operator+=(youtube& yt) {
        this->channel_list.push_back(yt);
    }
    // popin collection
    void operator-=(youtube& yt) {
        auto find_pos = find(channel_list.begin(), channel_list.end(), yt);
        this->channel_list.erase(find_pos);
    }
    // print
    void print() {
        for (auto x : channel_list) {
            cout << x.getname() << "\t" << x.getsubscribers() << '\n';
        }
    }
};

int main() {
    youtube yt = youtube("Revanth-channel", 250);
    youtube yt1 = youtube("Rads-channel", 300);
    //cout << yt << yt1;
    collection_yt lst;
    lst += yt;
    lst += yt1;
    lst.print();
    lst -= yt1;
    lst.print();
    return 0;
}