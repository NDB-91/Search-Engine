/**
 * @file test_index.cpp
 * @brief Unit tests for the InvertedIndex class using Google Test.
 *
 * This file contains unit tests for the InvertedIndex class, which is responsible
 * for indexing documents, querying indexed terms, and removing indexed documents.
 * The tests use a mock Document class to simulate document behavior.
 */

#include <gtest/gtest.h>
#include <memory>

#include "../source/indexer/InvertedIndex.h"
#include "../source/document/Document.h"
#include "../source/department/Department.h"

/**
 * @class MockDocument
 * @brief Mock implementation of the Document class for testing purposes.
 *
 * The MockDocument class is used to simulate the behavior of the Document class
 * during unit testing. It provides a constructor to initialize document attributes
 * and overrides the content() method to return the document's content.
 */

// Mock Document class for testing
class MockDocument : public Document {
public:
    MockDocument(const std::string& id, const Department& department, const std::string& title, const std::string& author, const std::string& content)
        : Document(id, department, title, author), _content(content) {}

    std::string content() const override {
        return _content;
    }
private:
    std::string _content;
};

/**
 * @class InvertedIndexTest
 * @brief Test suite for the InvertedIndex class.
 *
 * The InvertedIndexTest class provides unit tests for the following functionalities:
 * - Indexing a document.
 * - Querying indexed terms.
 * - Removing indexed documents.
 */

/**
 * @brief Test Plan
 *
 * **Objective**:
 * To verify the functionality of the InvertedIndex class, ensuring it meets the
 * requirements for indexing, querying, and removing documents.
 *
 * **Scope**:
 * The tests cover:
 * - Document indexing.
 * - Querying indexed terms.
 * - Removing indexed documents.
 *
 * **Test Environment**:
 * - Language: C++ (with Google Test framework).
 * - Dependencies: gtest, gtest_main, and the provided source files.
 * - Compiler: g++ with C++17 support.
 *
 * **Test Items**:
 * - InvertedIndex
 *
 * **Test Approach**:
 * - Unit tests are written for each functionality of the InvertedIndex class.
 * - Mock objects are used for dependencies like Document.
 *
 * **Entry Criteria**:
 * - Code compiles without errors.
 * - All dependencies are available.
 *
 * **Exit Criteria**:
 * - All test cases pass successfully.
 * - No critical defects remain unresolved.
 */

class InvertedIndexTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Initialize the InvertedIndex object
        index = std::make_shared<InvertedIndex>();
    }

    std::shared_ptr<InvertedIndex> index;
};

/**
 * @brief Test Case 1.1: Index a Document
 *
 * This test verifies that a document is correctly indexed by the InvertedIndex class.
 */
TEST_F(InvertedIndexTest, IndexDocument) {
    MockDocument doc("1", Department::INFORMATION_TECHNOLOGY, "Test Title", "Author1", "hello world");
    index->indexDocument(doc);

    auto results = index->search("hello");
    EXPECT_EQ(results.size(), 1);
    EXPECT_EQ(results[0], "1");

    results = index->search("world");
    EXPECT_EQ(results.size(), 1);
    EXPECT_EQ(results[0], "1");
}

/**
 * @brief Test Case 1.2: Query Indexed Terms
 *
 * This test verifies that querying indexed terms returns the correct document IDs.
 */
TEST_F(InvertedIndexTest, QueryIndexedTerms) {
    MockDocument doc1("1", Department::INFORMATION_TECHNOLOGY, "Title1", "Author1", "hello world");
    MockDocument doc2("2", Department::INFORMATION_TECHNOLOGY, "Title2", "Author2", "hello universe");
    index->indexDocument(doc1);
    index->indexDocument(doc2);

    auto results = index->search("hello");
    EXPECT_EQ(results.size(), 2);
    EXPECT_NE(std::find(results.begin(), results.end(), "1"), results.end());
    EXPECT_NE(std::find(results.begin(), results.end(), "2"), results.end());
}

/**
 * @brief Test Case 1.3: Remove Indexed Document
 *
 * This test verifies that a document is removed from the index and its terms
 * are no longer searchable.
 */
TEST_F(InvertedIndexTest, RemoveIndexedDocument) {
    MockDocument doc1("1", Department::INFORMATION_TECHNOLOGY, "Title1", "Author1", "hello world");
    MockDocument doc2("2", Department::INFORMATION_TECHNOLOGY, "Title2", "Author2", "hello universe");
    index->indexDocument(doc1);
    index->indexDocument(doc2);

    index->removeIndex(doc1);

    auto results = index->search("hello");
    EXPECT_EQ(results.size(), 1);
    EXPECT_EQ(results[0], "2");

    results = index->search("world");
    EXPECT_TRUE(results.empty());
}

/**
 * @brief Test Report
 *
 * **Summary**:
 * | Test Case ID | Test Description                     | Status  | Remarks              |
 * |--------------|--------------------------------------|---------|----------------------|
 * | TC1.1        | Index a Document                    | Passed  | Document indexed successfully. |
 * | TC1.2        | Query Indexed Terms                 | Passed  | Query returned correct results. |
 * | TC1.3        | Remove Indexed Document             | Passed  | Document removed successfully. |
 *
 * **Defects**:
 * No defects identified during testing.
 */