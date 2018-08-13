// Copyright 2018 Minkyu Jo

#ifndef TEST_H_
#define TEST_H_

#include <iostream>
#include <cstdlib>

// condition이 false이면 강제 종료
#define ASSERT_TRUE(condition) \
do { \
    if (!(condition)) { \
        std::cerr << "Condition not true: " << #condition; \
        std::cerr << " @ file " << __FILE__ << ", line " << __LINE__ << std::endl; \
        exit(0); \
    } \
} while (0);

// condition이 true라도 강제 종료되지 않고, 진행은 됨
#define EXPECT_TRUE(condition) \
do { \
    if (!(condition)) { \
        std::cerr << "Condition not true: " << #condition; \
        std::cerr << " @ file " << __FILE__ << ", line " << __LINE__ << std::endl; \
    } \
} while (0);


#define ASSERT_FALSE(condition) \
do { \
    if ((condition)) { \
        std::cerr << "Condition not false: " << #condition; \
        std::cerr << " @ file " << __FILE__ << ", line " << __LINE__ << std::endl; \
        exit(0); \
    } \
} while (0);

#define EXPECT_FALSE(condition) \
do { \
    if ((condition)) { \
        std::cerr << "Condition not false: " << #condition; \
        std::cerr << " @ file " << __FILE__ << ", line " << __LINE__ << std::endl; \
    } \
} while (0);

// 비교 후 값까지 출력
#define ASSERT_EQ(val1, val2) \
do { \
    auto v1 = (val1); \
    auto v2 = (val2); \
    if (!(v1 == v2)) { \
        std::cerr << "Values not equal: " << #val1 << " is " << v1; \
        std::cerr << ", but " << #val2 << " is " << v2; \
        std::cerr << " @ file " << __FILE__ << ", line " << __LINE__ << std::endl; \
        exit(0); \
    } \
} while (0);

#define EXPECT_EQ(val1, val2) \
do { \
    auto v1 = (val1); \
    auto v2 = (val2); \
    if (!(v1 == v2)) { \
        std::cerr << "Values not equal: " << #val1 << " is " << v1; \
        std::cerr << ", but " << #val2 << " is " << v2; \
        std::cerr << " @ file " << __FILE__ << ", line " << __LINE__ << std::endl; \
    } \
} while (0);


#define ASSERT_NE(val1, val2) \
do { \
    auto v1 = (val1); \
    auto v2 = (val2); \
    if (v1 == v2) { \
        std::cerr << "Values not different: " << #val1 << " and " << #val2; \
        std::cerr << " are both " << v1; \
        std::cerr << " @ file " << __FILE__ << ", line " << __LINE__ << std::endl; \
        exit(0); \
    } \
} while (0);

#define EXPECT_NE(val1, val2) \
do { \
    auto v1 = (val1); \
    auto v2 = (val2); \
    if (v1 == v2) { \
        std::cerr << "Values not different: " << #val1 << " and " << #val2; \
        std::cerr << " are both " << v1; \
        std::cerr << " @ file " << __FILE__ << ", line " << __LINE__ << std::endl; \
    } \
} while (0);

#endif  // TEST_H_
