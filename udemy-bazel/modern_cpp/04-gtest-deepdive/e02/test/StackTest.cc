#include "Stack.h"

#include "gtest/gtest.h"

class StackTestImpl : public testing::Test {
protected:
  void SetUp() override
  {
    stack = new Stack;
  }

  void TearDown() override
  {
    delete stack;
    stack = nullptr;
  }

  Stack *stack;
};

TEST_F(StackTestImpl, Constructor) {
  EXPECT_EQ(0, stack->size());
}

TEST_F(StackTestImpl, EmptyStack) {
  stack->push(10);
  stack->pop();
  EXPECT_EQ(0, stack->size());
}

TEST_F(StackTestImpl, PopEmptyStackKillsProgram) {
  EXPECT_EXIT(stack->pop(), testing::KilledBySignal(SIGSEGV), "");
}

TEST_F(StackTestImpl, SimplePushTest) {
  for (int i = 0; i < 10; ++i) {
    stack->push(i);
    EXPECT_EQ(i + 1, stack->size());
  }
}

TEST_F(StackTestImpl, DuplicateElementPushTest) {
  for (int i = 0; i < 10; ++i) {
    stack->push(1);
    EXPECT_EQ(i + 1, stack->size());
  }
}

TEST_F(StackTestImpl, SimplePopTest) {
  for (int i = 0; i < 10; ++i) {
    stack->push(i);
    EXPECT_EQ(i + 1, stack->size());
  }
  for (int i = 9; i >= 0; --i) {
    EXPECT_EQ(i, stack->pop());
    EXPECT_EQ(i, stack->size());
  }
}

TEST_F(StackTestImpl, DuplicateElementPopTest) {
  for (int i = 0; i < 10; ++i) {
    stack->push(1);
    EXPECT_EQ(i + 1, stack->size());
  }
  for (int i = 10; i > 0; --i) {
    EXPECT_EQ(1, stack->pop());
    EXPECT_EQ(i - 1, stack->size());
  }
}
