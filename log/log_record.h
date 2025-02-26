// LogRecord class.
//
// This class represents a log record.

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

// Build using LogRecordBuilder.
//
// TODO: How to enforce usage of builder? Make it a friend and privatise
// constructor?

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

//-----------------------------------------------------------------------------

class LogRecordBuilder {
public:
  LogRecordBuilder() = default;
  ~LogRecordBuilder() = default;

  LogRecord build() const;

  /* Builder Methods */
  //
  // Callers are recommended to move input arguments to these methods.

  LogRecordBuilder &set_data(std::string data);
  LogRecordBuilder &set_level(LogLevel level);
  LogRecordBuilder &set_file_name(std::string file_name);
  LogRecordBuilder &set_line_num(int line_num);
  LogRecordBuilder &set_time(std::string time);

private:
  std::string data_;
  LogLevel level_ = LogLevel::INFO;
  std::string file_name_;
  int line_num_ = -1;
  std::string time_;
};

} // namespace rlog