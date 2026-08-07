#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
for testfile in test_*.cpp; do
  exe="${testfile%.cpp}"
  clang++ -std=c++20 -Wall -Wextra -Werror -Wno-unused-function -DUNIT_TESTING "$testfile" -o "$exe"
done
