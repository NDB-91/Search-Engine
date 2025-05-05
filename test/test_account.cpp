/**
 * @file test_account.cpp
 * @brief Unit tests for the StudentAccount, LecturerAccount, and AccountFactory classes using Google Test.
 *
 * This file contains unit tests for the StudentAccount, LecturerAccount, and AccountFactory classes.
 * The tests verify password validation, email retrieval, role retrieval, and account creation functionality.
 */

#include <gtest/gtest.h>

#include "../source/account/StudentAccount.h"
#include "../source/account/LecturerAccount.h"
#include "../source/account/AccountFactory.h"
#include "../source/student/Student.h"
#include "../source/lecturer/Lecturer.h"

/**
 * @brief Test Plan
 *
 * **Objective**:
 * To verify the functionality of the StudentAccount, LecturerAccount, and AccountFactory classes,
 * ensuring they meet the requirements for account creation, password verification, and role-based behavior.
 *
 * **Scope**:
 * The tests cover:
 * - Password verification for StudentAccount and LecturerAccount.
 * - Role and email retrieval for both account types.
 * - Account creation using AccountFactory.
 *
 * **Test Environment**:
 * - Language: C++ (with Google Test framework).
 * - Dependencies: gtest, gtest_main, and the provided source files.
 * - Compiler: g++ with C++17 support.
 *
 * **Test Items**:
 * - StudentAccount
 * - LecturerAccount
 * - AccountFactory
 *
 * **Test Approach**:
 * - Unit tests are written for each class.
 * - Mock objects are used for dependencies like Student and Lecturer where necessary.
 *
 * **Entry Criteria**:
 * - Code compiles without errors.
 * - All dependencies are available.
 *
 * **Exit Criteria**:
 * - All test cases pass successfully.
 * - No critical defects remain unresolved.
 */

/**
 * @class StudentAccountTest
 * @brief Test suite for the StudentAccount class.
 *
 * The StudentAccountTest class provides unit tests for the following functionalities:
 * - Password verification.
 * - Email retrieval.
 * - Role retrieval.
 */

// Test Suite: StudentAccountTest
class StudentAccountTest : public ::testing::Test {
protected:
    void SetUp() override {
        student = Student("example@student", "Student Name", University::Name::HCMUS);
        account = std::make_shared<StudentAccount>(student, "password");
    }

    Student student;
    std::shared_ptr<StudentAccount> account;
};

/**
 * @brief Test Case 1.1: Verify Correct Password
 *
 * This test verifies that the correct password is accepted for a StudentAccount.
 */
TEST_F(StudentAccountTest, VerifyCorrectPassword) {
    EXPECT_TRUE(account->verifyPassword("password"));
}

/**
 * @brief Test Case 1.2: Verify Incorrect Password
 *
 * This test verifies that an incorrect password is rejected for a StudentAccount.
 */
TEST_F(StudentAccountTest, VerifyIncorrectPassword) {
    EXPECT_FALSE(account->verifyPassword("wrongpassword"));
}

/**
 * @brief Test Case 1.3: Retrieve Email
 *
 * This test verifies that the email is correctly retrieved for a StudentAccount.
 */
TEST_F(StudentAccountTest, RetrieveEmail) {
    EXPECT_EQ(account->email(), "example@student");
}

/**
 * @brief Test Case 1.4: Retrieve Role
 *
 * This test verifies that the role is correctly retrieved for a StudentAccount.
 */
TEST_F(StudentAccountTest, RetrieveRole) {
    EXPECT_EQ(account->role(), Role::Student);
}

/**
 * @class LecturerAccountTest
 * @brief Test suite for the LecturerAccount class.
 *
 * The LecturerAccountTest class provides unit tests for the following functionalities:
 * - Password verification.
 * - Email retrieval.
 * - Role retrieval.
 */

// Test Suite: LecturerAccountTest
class LecturerAccountTest : public ::testing::Test {
protected:
    void SetUp() override {
        lecturer = Lecturer("example@lecturer", "Lecturer Name", Department::INFORMATION_TECHNOLOGY, University::Name::HCMUS);
        account = std::make_shared<LecturerAccount>(lecturer, "securepassword");
    }

    Lecturer lecturer;
    std::shared_ptr<LecturerAccount> account;
};

/**
 * @brief Test Case 2.1: Verify Correct Password
 *
 * This test verifies that the correct password is accepted for a LecturerAccount.
 */
TEST_F(LecturerAccountTest, VerifyCorrectPassword) {
    EXPECT_TRUE(account->verifyPassword("securepassword"));
}

/**
 * @brief Test Case 2.2: Verify Incorrect Password
 *
 * This test verifies that an incorrect password is rejected for a LecturerAccount.
 */
TEST_F(LecturerAccountTest, VerifyIncorrectPassword) {
    EXPECT_FALSE(account->verifyPassword("wrongpassword"));
}

/**
 * @brief Test Case 2.3: Retrieve Email
 *
 * This test verifies that the email is correctly retrieved for a LecturerAccount.
 */
TEST_F(LecturerAccountTest, RetrieveEmail) {
    EXPECT_EQ(account->email(), "example@lecturer");
}

/**
 * @brief Test Case 2.4: Retrieve Role
 *
 * This test verifies that the role is correctly retrieved for a LecturerAccount.
 */
TEST_F(LecturerAccountTest, RetrieveRole) {
    EXPECT_EQ(account->role(), Role::Lecturer);
}

/**
 * @class AccountFactoryTest
 * @brief Test suite for the AccountFactory class.
 *
 * The AccountFactoryTest class provides unit tests for the following functionalities:
 * - Creating StudentAccount objects.
 * - Creating LecturerAccount objects.
 */

// Test Suite: AccountFactoryTest
class AccountFactoryTest : public ::testing::Test {};

/**
 * @brief Test Case 3.1: Create StudentAccount
 *
 * This test verifies that a StudentAccount is created correctly using AccountFactory.
 */
TEST_F(AccountFactoryTest, CreateStudentAccount) {
    Student student("example@student", "Student Name", University::Name::HCMUS);
    auto account = AccountFactory::create(student, "password");

    ASSERT_NE(account, nullptr);
    EXPECT_EQ(account->email(), "example@student");
    EXPECT_EQ(account->role(), Role::Student);
    EXPECT_TRUE(account->verifyPassword("password"));
}

/**
 * @brief Test Case 3.2: Create LecturerAccount
 *
 * This test verifies that a LecturerAccount is created correctly using AccountFactory.
 */
TEST_F(AccountFactoryTest, CreateLecturerAccount) {
    Lecturer lecturer("example@lecturer", "Lecturer Name", Department::INFORMATION_TECHNOLOGY, University::Name::HCMUS);
    auto account = AccountFactory::create(lecturer, "securepassword");

    ASSERT_NE(account, nullptr);
    EXPECT_EQ(account->email(), "example@lecturer");
    EXPECT_EQ(account->role(), Role::Lecturer);
    EXPECT_TRUE(account->verifyPassword("securepassword"));
}

/**
 * @brief Test Report
 *
 * **Summary**:
 * | Test Case ID | Test Description                     | Status  | Remarks              |
 * |--------------|--------------------------------------|---------|----------------------|
 * | TC1.1        | Verify Correct Password (Student)    | Passed  | Password verified successfully. |
 * | TC1.2        | Verify Incorrect Password (Student)  | Passed  | Incorrect password rejected. |
 * | TC1.3        | Retrieve Email (Student)             | Passed  | Email retrieved successfully. |
 * | TC1.4        | Retrieve Role (Student)              | Passed  | Role retrieved successfully. |
 * | TC2.1        | Verify Correct Password (Lecturer)   | Passed  | Password verified successfully. |
 * | TC2.2        | Verify Incorrect Password (Lecturer) | Passed  | Incorrect password rejected. |
 * | TC2.3        | Retrieve Email (Lecturer)            | Passed  | Email retrieved successfully. |
 * | TC2.4        | Retrieve Role (Lecturer)             | Passed  | Role retrieved successfully. |
 * | TC3.1        | Create StudentAccount                | Passed  | StudentAccount created successfully. |
 * | TC3.2        | Create LecturerAccount               | Passed  | LecturerAccount created successfully. |
 *
 * **Defects**:
 * No defects identified during testing.
 */