#ifndef TESTS_BASE_UT_H_
#define TESTS_BASE_UT_H_



#define UT_MSG_FAILED(msg) \
    do { \
        printf("%s: Failed\n", msg); \
    } while (0)

#define UT_MSG_OK(msg) \
    do { \
        printf("%s: Ok\n", msg); \
    } while (0)


#endif  // TESTS_BASE_UT_H_