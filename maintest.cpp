#include "header/code_method.h"
#include <gtest/gtest.h>

TEST(Functest, Factorial){
  EXPECT_EQ(getFactorial(1), 1);
  EXPECT_EQ(getFactorial(3), 6);
  EXPECT_EQ(getFactorial(5), 120);
}

TEST(Functest, Prime){
  EXPECT_FALSE(is_prime(1));
  EXPECT_TRUE(is_prime(2));
  EXPECT_FALSE(is_prime(4));
}