#pragma once

namespace rlog {

class Logger {
public:
  // Singleton method.
  static Logger *GetInstance();

  // Add API to delete singleton? For lifecycle management.
  
private:
  // Private constructor to prevent non singleton creation.
  Logger();
  ~Logger();

private:
  // Delete the copy and assignment constructors.
  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;
};

} // namespace rlog