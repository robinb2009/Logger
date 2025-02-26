// Logger class. 
//
// Today logger class is independent of actual LogCaptor and LogRecord implementation.
// It just deals with strings. We may need to integrate in the future to indicate whether 
// to crash when receiving a FATAL log.


#pragma once

#include <shared_mutex>
#include <string>
#include <vector>

namespace rlog {

class Logger {
public:
  // Singleton method.
  static Logger *GetInstance();

  // Add API to delete singleton? For lifecycle management.

  /* APIs */

  // TODO: Consider converting to Write(LogRecord). 
  // We may want the ability to switch up how we format and persist data.
  void Write(std::string logstr);

private:
  // Private constructor to prevent non singleton creation.
  Logger();
  ~Logger();

  // Flush the logs that are in memory to disk.
  void Flush();

private:
  // Shared mutex to lock logs_.
  std::shared_mutex mutex_;

  // Logs stored in memory before flushing.
  std::vector<std::string> logs_;

private:
  // Delete the copy and assignment constructors.
  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;
};

} // namespace rlog