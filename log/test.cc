#include <iostream>
#include <string>

using namespace std;

// We meed a class that pretends to be a stream operator and stores the data for a single logline. (Like Logger)
// Abuse the fact that destructor will get called after all the '<<' operators are called. 
// It's the only way to detect end of logline.
// We don't need to use macros? --> Necessary only for filename and linenumber.

class Logger {
public:
    Logger(string name) : name_(move(name)) {
        cout << "Logger " << name_ << endl;
    }

private:
    string name_;
};

Logger& operator<<(Logger& lg, const int& x) {
    cout << x << endl;
    return lg;
}

class Dummy {
public:
    Dummy() { cout << "Dummy created" << endl; }
    ~Dummy() { cout << "Dummy destroyed" << endl; }
};

int main() {
    Dummy();
    auto log = Logger("Log1234");
    log << 5 << 4 << 3;
    return 0;
}