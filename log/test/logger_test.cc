#include <assert.h>
#include <iostream>
#include <string>

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
  void WriteTest();
};

//-----------------------------------------------------------------------------

void LoggerTest::InitTest() {
  MARK_RUNNING();

  auto *logger1 = Logger::GetInstance();
  auto *logger2 = Logger::GetInstance();
  assert(logger1 == logger2);

  MARK_PASSED();
}

//-----------------------------------------------------------------------------

void LoggerTest::WriteTest() {
  auto *logger = Logger::GetInstance();
  for (int i = 0; i < 1000; ++i) {
    logger->Write("Logline" + std::to_string(i));
  }
}

//-----------------------------------------------------------------------------

} // namespace test
} // namespace rlog

int main() {
  rlog::test::LoggerTest test;
  test.InitTest();
  test.WriteTest();
  
  return 0;
}