#include "log/logger.h"

#include <iostream>

using std::cout;
using std::endl;
using std::string;

#define LOG_FLUSH_THRESHOLD 100

namespace rlog {

//-----------------------------------------------------------------------------

Logger *Logger::GetInstance() {
  static Logger logger;
  return &logger;
}

//-----------------------------------------------------------------------------

Logger::Logger() { cout << "Created Logger!" << endl; }

//-----------------------------------------------------------------------------

Logger::~Logger() { cout << "Destroyed Logger!" << endl; }

//-----------------------------------------------------------------------------

void Logger::Write(string logstr) {
  logs_.push_back(Format(logstr));

  if (logs_.size() >= LOG_FLUSH_THRESHOLD) {
    Flush();
  }
}

//-----------------------------------------------------------------------------

string Logger::Format(string str) {
  string ret = "INFO DATE " + str + "\n";
  return ret;
}

//-----------------------------------------------------------------------------

void Logger::Flush() {
    for (auto& str : logs_) {
        cout << str;
    }
    cout << std::flush;
    logs_.clear();
}

//-----------------------------------------------------------------------------

} // namespace rlog