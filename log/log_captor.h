// LogCaptor class.
//
// This class helps capture the LogRecord and send it to Logger for logging.

#include <sstream>
#include <string>

namespace rlog {

class LogCaptor {
public:
  LogCaptor(int line_num, std::string file_name);
  ~LogCaptor();

  std::ostringstream& stream() { return oss_; }

private:
  const int line_num_;
  const std::string file_name_;
  std::ostringstream oss_;
};

} // namespace rlog