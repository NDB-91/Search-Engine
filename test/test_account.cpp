#include <gtest/gtest.h>

#include "../source/account/StudentAccount.h"
#include "../source/account/LecturerAccount.h"
#include "../source/account/AccountFactory.h"
#include "../source/student/Student.h"
#include "../source/lecturer/Lecturer.h"

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

// Test Case 1.1: Verify Correct Password
TEST_F(StudentAccountTest, VerifyCorrectPassword) {
    EXPECT_TRUE(account->verifyPassword("password"));
}

// Test Case 1.2: Verify Incorrect Password
TEST_F(StudentAccountTest, VerifyIncorrectPassword) {
    EXPECT_FALSE(account->verifyPassword("wrongpassword"));
}

// Test Case 1.3: Retrieve Email
TEST_F(StudentAccountTest, RetrieveEmail) {
    EXPECT_EQ(account->email(), "example@student");
}

// Test Case 1.4: Retrieve Role
TEST_F(StudentAccountTest, RetrieveRole) {
    EXPECT_EQ(account->role(), Role::Student);
}

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

// Test Case 2.1: Verify Correct Password
TEST_F(LecturerAccountTest, VerifyCorrectPassword) {
    EXPECT_TRUE(account->verifyPassword("securepassword"));
}

// Test Case 2.2: Verify Incorrect Password
TEST_F(LecturerAccountTest, VerifyIncorrectPassword) {
    EXPECT_FALSE(account->verifyPassword("wrongpassword"));
}

// Test Case 2.3: Retrieve Email
TEST_F(LecturerAccountTest, RetrieveEmail) {
    EXPECT_EQ(account->email(), "example@lecturer");
}

// Test Case 2.4: Retrieve Role
TEST_F(LecturerAccountTest, RetrieveRole) {
    EXPECT_EQ(account->role(), Role::Lecturer);
}

// Test Suite: AccountFactoryTest
class AccountFactoryTest : public ::testing::Test {};

// Test Case 3.1: Create StudentAccount
TEST_F(AccountFactoryTest, CreateStudentAccount) {
    Student student("example@student", "Student Name", University::Name::HCMUS);
    auto account = AccountFactory::create(student, "password");

    ASSERT_NE(account, nullptr);
    EXPECT_EQ(account->email(), "example@student");
    EXPECT_EQ(account->role(), Role::Student);
    EXPECT_TRUE(account->verifyPassword("password"));
}

// Test Case 3.2: Create LecturerAccount
TEST_F(AccountFactoryTest, CreateLecturerAccount) {
    Lecturer lecturer("example@lecturer", "Lecturer Name", Department::INFORMATION_TECHNOLOGY, University::Name::HCMUS);
    auto account = AccountFactory::create(lecturer, "securepassword");

    ASSERT_NE(account, nullptr);
    EXPECT_EQ(account->email(), "example@lecturer");
    EXPECT_EQ(account->role(), Role::Lecturer);
    EXPECT_TRUE(account->verifyPassword("securepassword"));
}