#include "log/log_record.h"

#include <assert.h>

using std::move;
using std::string;

namespace rlog {

//-----------------------------------------------------------------------------

LogRecord::LogRecord(string data, LogLevel level, string file_name,
                     int line_num, string time)
    : data_(move(data)), level_(level), file_name_(move(file_name)),
      line_num_(line_num), time_(move(time)) {
    // TODO: Convert '10000' to a constant.
    //
    // Limit the actual log size.
    assert(data_.size() < 10000);
}

//-----------------------------------------------------------------------------

string LogRecord::Format() {
  // Log format - <level> <time> <file_name>@<line_num>] <data>\n
  // Example:
  // INF 01:20.1234 log_record.cc@11] Log format line!
  string fmt_str;

  switch (level_) {
  case LogLevel::INFO:
    fmt_str += "INF ";
    break;

  case LogLevel::DEBUG:
    fmt_str += "DEB ";
    break;

  case LogLevel::WARNING:
    fmt_str += "WAR ";
    break;

  case LogLevel::ERROR:
    fmt_str += "ERR ";
    break;

  case LogLevel::FATAL:
    fmt_str += "FAT ";
    break;

  default:
    assert(false);
  }

  fmt_str += time_ + file_name_ + "@" + std::to_string(line_num_) + "] " +
             data_ + "\n";
  return fmt_str;
}

//-----------------------------------------------------------------------------

} // namespace rlog