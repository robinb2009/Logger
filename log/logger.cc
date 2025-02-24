#include "log/logger.h"

#include <iostream>

using std::cout;
using std::endl;

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

} // namespace rlog