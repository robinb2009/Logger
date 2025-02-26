// LogCaptor class.
//
// This class helps capture the LogRecord and send it to Logger for logging.

#include "log/log_captor.h"
#include "log/logger.h"

using std::string;

namespace rlog {

//-----------------------------------------------------------------------------

LogCaptor::LogCaptor(int line_num, std::string file_name, LogLevel level)
    : line_num_(line_num), file_name_(move(file_name)), level_(level) {}

//-----------------------------------------------------------------------------

LogCaptor::~LogCaptor() {
  // TODO: Implent time! Consider moving all the data here?
  string time = "01:12.1234";
  auto log = LogRecordBuilder()
                 .set_data(oss_.str())
                 .set_level(level_)
                 .set_file_name(file_name_)
                 .set_line_num(line_num_)
                 .set_time(time);

  auto log_str = record.Format();

  Logger::GetInstance()->Write(move(log_str));
}

//-----------------------------------------------------------------------------

} // namespace rlog