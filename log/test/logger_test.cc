#include <assert.h>
#include <iostream>

#include "log/logger.h"

using std::cout;
using std::endl;

#define MARK_RUNNING()                                                         \
  cout << "---------- Running " << __func__ << "----------" << endl
#define MARK_PASSED()                                                          \
  cout << "---------- Passed " << __func__ << "----------" << endl

namespace rlog {
namespace test {

//-----------------------------------------------------------------------------

class LoggerTest {
public:
    LoggerTest() = default;
    ~LoggerTest() = default;

    void InitTest();
};

//-----------------------------------------------------------------------------

void LoggerTest::InitTest() {
  MARK_RUNNING();

  auto logger1 = Logger::GetInstance();
  auto logger2 = Logger::GetInstance();
  assert(logger1 == logger2);
  cout << "Verified single logger getting created." << endl;
  
  MARK_PASSED();
}

//-----------------------------------------------------------------------------

} // namespace test
} // namespace rlog


int main() {
  rlog::test::LoggerTest test;
  test.InitTest();

  return 0;
}