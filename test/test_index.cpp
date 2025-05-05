#include <gtest/gtest.h>
#include <memory>
#include "../source/indexer/InvertedIndex.h"
#include "../source/document/Document.h"
#include "../source/department/Department.h"

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

// Test Suite: InvertedIndexTest
class InvertedIndexTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Initialize the InvertedIndex object
        index = std::make_shared<InvertedIndex>();
    }

    std::shared_ptr<InvertedIndex> index;
};

// Test Case 1.1: Index a Document
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

// Test Case 1.2: Query Indexed Terms
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

// Test Case 1.3: Remove Indexed Document
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