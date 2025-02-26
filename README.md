# Logger
Simple logger repo.

# Setup
c++ 20
bazel 7.2.1

bazel test //log/test:logger_test


Left to implement -
1. Signal handling for SIGABRT -> Flush logs.
2. Support assertions in library -> They should be logged and then abort.
3. Ability for clients to add signal handling functors.