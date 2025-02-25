#pragma once

#include <string>

namespace rlog {

// Severity level of the log.
enum class LogLevel {
  INFO,
  DEBUG,
  WARNING,
  ERROR,
  FATAL,
};

class LogRecord {
public:
  explicit LogRecord(std::string data, LogLevel level, std::string file_name,
                     int line_num, std::string time);

  // Format the log and return the string representation of the log.
  std::string Format();

private:
  const std::string data_;
  const LogLevel level_;
  const std::string file_name_;
  const int line_num_;
  const std::string time_;

private:
  // Delete the copy and assignment constructors.
  LogRecord(const LogRecord &) = delete;
  LogRecord &operator=(const LogRecord &) = delete;
};

} // namespace rlog