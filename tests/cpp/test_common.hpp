#ifndef TEST_COMMON_HPP
#define TEST_COMMON_HPP

#include <cassert>
#include <cstdlib>
#include <iostream>

// Simple CHECK macro for assertions in tests
#define CHECK(condition)                                                      \
    do                                                                        \
    {                                                                         \
        if (!(condition))                                                     \
        {                                                                     \
            std::cerr << "CHECK failed: " << #condition << std::endl;         \
            std::cerr << "  at " << __FILE__ << ":" << __LINE__ << std::endl; \
            std::exit(1);                                                     \
        }                                                                     \
    } while (0)

#define CHECK_EQ(actual, expected)                                                           \
    do                                                                                       \
    {                                                                                        \
        auto _actual = (actual);                                                             \
        auto _expected = (expected);                                                         \
        if (!(_actual == _expected))                                                         \
        {                                                                                    \
            std::cerr << "CHECK_EQ failed: " << #actual << " != " << #expected << std::endl; \
            std::cerr << "  at " << __FILE__ << ":" << __LINE__ << std::endl;                \
            std::exit(1);                                                                    \
        }                                                                                    \
    } while (0)

#endif // TEST_COMMON_HPP
