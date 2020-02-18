#include <ctime>

#include "gtest/gtest.h"

#include "Stack.h"

class TimedTest : public testing::Test {
protected:
  void SetUp() override
  {
    start_time = time(nullptr);
  }

  void TearDown() override
  {
    time_t end_time = time(nullptr);
    EXPECT_LT(end_time - start_time, 1) << "Test not quick enough. Consider revising your unit test";

  }

  time_t start_time;
};

class InheritedStackTest : public TimedTest {
protected:
  void SetUp() override
  {
    TimedTest::SetUp();
    stack = new Stack;
  }

  void TearDown() override
  {
    delete stack;
    stack = nullptr;
    TimedTest::TearDown();
  }

  Stack *stack;
};

TEST_F(InheritedStackTest, Constructor) {
  EXPECT_EQ(0, stack->size());
}

TEST_F(InheritedStackTest, EmptyStack) {
  stack->push(10);
  stack->pop();
  EXPECT_EQ(0, stack->size());
}

TEST_F(InheritedStackTest, PopEmptyStackKillsProgram) {
  EXPECT_EXIT(stack->pop(), testing::KilledBySignal(SIGSEGV), "");
}

TEST_F(InheritedStackTest, SimplePushTest) {
  for (int i = 0; i < 10; ++i) {
    stack->push(i);
    EXPECT_EQ(i + 1, stack->size());
  }
}

TEST_F(InheritedStackTest, DuplicateElementPushTest) {
  for (int i = 0; i < 10; ++i) {
    stack->push(1);
    EXPECT_EQ(i + 1, stack->size());
  }
}

TEST_F(InheritedStackTest, SimplePopTest) {
  for (int i = 0; i < 10; ++i) {
    stack->push(i);
    EXPECT_EQ(i + 1, stack->size());
  }
  for (int i = 9; i >= 0; --i) {
    EXPECT_EQ(i, stack->pop());
    EXPECT_EQ(i, stack->size());
  }
}

TEST_F(InheritedStackTest, DuplicateElementPopTest) {
  for (int i = 0; i < 10; ++i) {
    stack->push(1);
    EXPECT_EQ(i + 1, stack->size());
  }
  for (int i = 10; i > 0; --i) {
    EXPECT_EQ(1, stack->pop());
    EXPECT_EQ(i - 1, stack->size());
  }
}
