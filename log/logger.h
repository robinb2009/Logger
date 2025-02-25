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
  void Write(std::string logstr);

private:
  // Private constructor to prevent non singleton creation.
  Logger();
  ~Logger();

  // Format the string.
  std::string Format(std::string str);

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