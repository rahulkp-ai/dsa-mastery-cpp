#ifndef TEST_COMMON_HPP
#define TEST_COMMON_HPP

#include <iostream>
#include <cassert>

// Simple CHECK macro for assertions in tests
#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            std::cerr << "CHECK failed: " << #condition << std::endl; \
            std::cerr << "  at " << __FILE__ << ":" << __LINE__ << std::endl; \
            exit(1); \
        } \
    } while (0)

#endif // TEST_COMMON_HPP
