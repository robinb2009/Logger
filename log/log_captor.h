// LogCaptor class.
//
// This class helps capture the LogRecord and send it to Logger for logging.

#include <sstream>
#include <string>

#include "log/log_record.h"

namespace rlog {

class LogCaptor {
public:
  LogCaptor(int line_num, std::string file_name, LogLevel level);
  ~LogCaptor();

  std::ostringstream& stream() { return oss_; }

private:
  const int line_num_;
  const std::string file_name_;
  LogLevel level_;
  std::ostringstream oss_;
};

} // namespace rlog