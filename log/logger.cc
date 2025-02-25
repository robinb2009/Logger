#include "log/logger.h"

#include <cassert>
#include <iostream>
#include <mutex>

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
  std::unique_lock<std::shared_mutex> ul(mutex_);
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
  assert(!mutex_.try_lock_shared());

  for (auto &str : logs_) {
    cout << str;
  }
  cout << std::flush;
  logs_.clear();
}

//-----------------------------------------------------------------------------

} // namespace rlog