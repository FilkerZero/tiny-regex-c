#include <gtest/gtest.h>
#include <tests_defs.hpp>
#include <re.h>

extern char *test_vector[68][4];
extern regex_tuple_t re_pattern;

TEST(regex, compile)
{
    EXPECT_EQ(re_compile("\\\x01[^\\\xff][^", &re_pattern), nullptr);
    EXPECT_EQ(re_compile("\\\x01[^\\\xff][\\", &re_pattern), nullptr);
}

TEST(regex, test1)
{
    char* text;
    char* pattern;
    int should_fail;
    unsigned int length;
    int correctlen;
    size_t ntests = sizeof(test_vector) / sizeof(*test_vector);
    size_t nfailed = 0;
    size_t i;

    for (i = 0; i < ntests; ++i)
    {
        pattern = test_vector[i][1];
        text = test_vector[i][2];
        should_fail = (test_vector[i][0] == NOK);
        correctlen = (int)(test_vector[i][3]);

        re_compile(pattern, &re_pattern);
        int m = re_matchp(&re_pattern, text, &length);

        if (should_fail)
        {
            EXPECT_EQ(m, -1) 
            << '[' << (i+1) << '/' << ntests << ']'
            << "pattern " << pattern << " matched " << text << " unexpectedly, matched " << length << "chars. \n";
        }
        else
        {
            EXPECT_NE(m, -1)
            << '[' << (i+1) << '/' << ntests << ']'
            << "pattern " << pattern << " didn't match " << text << " as expected. \n";
            
            EXPECT_EQ(length, correctlen)
            << '[' << (i+1) << '/' << ntests << ']'
            << "pattern " << pattern << " matched " << length << " chars of " << text << "; expected " << correctlen << ". \n";
        }
    }
}