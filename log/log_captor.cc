// LogCaptor class.
//
// This class helps capture the LogRecord and send it to Logger for logging.

#include "log/log_captor.h"

namespace rlog {

//-----------------------------------------------------------------------------

LogCaptor::LogCaptor(int line_num, std::string file_name)
    : line_num_(line_num), file_name_(move(file_name)) {}

//-----------------------------------------------------------------------------

LogCaptor::~LogCaptor() {
    // TODO: Build, format record and send to Logger.
}

//-----------------------------------------------------------------------------

} // namespace rlog