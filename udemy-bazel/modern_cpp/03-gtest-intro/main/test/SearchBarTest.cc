#include <limits>

#include "gtest/gtest.h"

#include "searchbar/SearchBar.h"

TEST(SearchBar, AdditionTest) {
  SearchBar searchBar;
  EXPECT_EQ(searchBar.process(1, 2, 0), "1 + 2 = 3");
  EXPECT_EQ(searchBar.process(1, 2, 1), "1 - 2 = -1");
  EXPECT_EQ(searchBar.process(1, 2, 2), "1 * 2 = 2");
  EXPECT_EQ(searchBar.process(1, 2, 3), "1 / 2 = 0.5");
  // For those comparing C style strings, use EXPECT_STREQ instead of EXPECT_EQ
  // const char *expected = "1 / 2 = 0.5";
  // const char *actual = searchBar.process(1, 2, 3).c_str();
  // EXPECT_STREQ(actual, expected);
}

TEST(SearchBar, InvalidOp) {
  SearchBar searchBar;
  EXPECT_DEATH(searchBar.process(0, 0, -1), "Assertion .* failed.");
  EXPECT_DEATH(searchBar.process(0, 0, 4), "Assertion .* failed.");
}
