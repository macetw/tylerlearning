#include<iostream>

#include <gtest/gtest.h>

using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;
using ::testing::Test;
using ::testing::TestCase;
using ::testing::TestEventListeners;
using ::testing::TestInfo;
using ::testing::TestPartResult;
using ::testing::UnitTest;

using std::cout;
using std::endl;

class LifecycleListener : public EmptyTestEventListener {
   
  void OnTestProgramStart(const UnitTest& unitTest) override {
      cout << "OnTestProgramStart : BEFORE any test runs." << endl;
  }

  void OnTestProgramEnd(const UnitTest& unitTest) override {
    cout << "OnTestProgramEnd : AFTER all tests" << endl;
  }

  
  void OnTestStart(const TestInfo& testInfo) override {
    cout << "OnTestStart : BEFORE " << testInfo.test_case_name()
     << "." << testInfo.name() << endl;
  }

  void OnTestEnd(const TestInfo& testInfo) override {
    cout << "OnTestEnd : AFTER " << testInfo.test_case_name()
     << "." << testInfo.name() << endl;
  }

  void OnTestPartResult(const TestPartResult& testPartResult) override {
    cout << "OnTestPartResult : " 
        << (testPartResult.failed() ? "FAILURE" : "SUCCESS") << endl
        << testPartResult.summary() << endl;
  }
};

int
main(int argc, char **argv)
{
    InitGoogleTest(&argc, argv);
    TestEventListeners& listeners = UnitTest::GetInstance()->listeners();
    delete listeners.Release(listeners.default_result_printer());
    listeners.Append(new LifecycleListener);
    return RUN_ALL_TESTS();
}
