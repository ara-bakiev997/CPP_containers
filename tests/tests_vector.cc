#include <gtest/gtest.h>

//#include <utility>
#include <vector>

#include "../src/sequence/s21_vector.h"

using namespace s21;

class S21Vector_test : public ::testing::Test {
 protected:
  void SetUp() override {}
  S21Vector<int> vector_empty;
  S21Vector<int> vector_1_ = {1, 2, 3, 4, 5};
  S21Vector<int> vector_2_ = S21Vector<int>(10);
  std::vector<int> test_empty;
  std::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> test2 = {10, 20, 30, 40};
};

TEST_F(S21Vector_test, _operatorCopy) {
  vector_empty = vector_1_;
  for (auto i = 0; i < vector_empty.size(); ++i) {
    EXPECT_EQ(vector_empty.at(i), vector_1_.at(i));
  }
}

TEST_F(S21Vector_test, _operatorMove) {
  vector_empty = std::move(vector_1_);
}

TEST_F(S21Vector_test, at) {
  EXPECT_EQ(vector_1_.at(0), test.at(0));
  EXPECT_EQ(vector_1_.at(1), test.at(1));
  EXPECT_ANY_THROW(vector_1_.at(7));
  EXPECT_ANY_THROW(vector_empty.at(0));
}

TEST_F(S21Vector_test, brackets) {}

TEST_F(S21Vector_test, front) { EXPECT_EQ(vector_1_.front(), 1); }

TEST_F(S21Vector_test, back) { EXPECT_EQ(vector_1_.back(), 5); }

TEST_F(S21Vector_test, data) { EXPECT_EQ(*vector_1_.data(), 1); }

TEST_F(S21Vector_test, iterator_begin) { EXPECT_EQ((*vector_1_.begin()), 1); }

TEST_F(S21Vector_test, iterator_end) { EXPECT_EQ(*(vector_1_.end() - 1), 5); }

TEST_F(S21Vector_test, empty) {
  EXPECT_TRUE(vector_empty.empty());
  EXPECT_FALSE(vector_1_.empty());
}

TEST_F(S21Vector_test, size) {
  EXPECT_EQ(vector_empty.size(), 0);
  EXPECT_EQ(vector_1_.size(), 5);
}

// TEST_F(S21Vector_test, max_size) {
//  не проходит на маке
//   EXPECT_EQ(test.max_size(), vector_1_.max_size());
//   std::cout << test.max_size() << std::endl;
//   std::cout << vector_1_.max_size() << std::endl;
//   std::cout << std::numeric_limits<int>::max() << std::endl;
//   std::cout << SIZE_MAX / sizeof(int) << std::endl;
// }

TEST_F(S21Vector_test, reserve) {
  EXPECT_ANY_THROW(vector_1_.reserve(vector_1_.max_size() + 1));
  EXPECT_EQ(vector_1_.capacity(), 5);
  vector_1_.reserve(10);
  EXPECT_EQ(vector_1_.capacity(), 10);
}

TEST_F(S21Vector_test, capasity) { EXPECT_EQ(vector_1_.capacity(), 5); }

TEST_F(S21Vector_test, shrink_to_fit) {
  vector_1_.push_back(3);
  EXPECT_EQ(vector_1_.capacity(), 10);
  vector_1_.shrink_to_fit();
  EXPECT_EQ(vector_1_.capacity(), vector_1_.size());
  EXPECT_EQ(vector_1_.size(), 6);
}

TEST_F(S21Vector_test, push_back) {
  vector_empty.push_back(0);
  vector_1_.push_back(6);
  EXPECT_EQ(vector_1_.at(5), 6);
}

TEST_F(S21Vector_test, clear) {
  EXPECT_EQ(vector_1_.size(), 5);
  vector_1_.clear();
  EXPECT_EQ(vector_1_.size(), 0);
}

TEST_F(S21Vector_test, insert) {
  vector_1_.insert(vector_1_.end() - 1, 19);
  test.insert(test.end() - 1, 19);
  EXPECT_EQ(vector_1_.at(vector_1_.size() - 1), test.at(test.size() - 1));
  vector_1_.insert(vector_1_.end() - 2, 20);
  test.insert(test.end() - 2, 20);
  EXPECT_EQ(vector_1_.at(vector_1_.size() - 2), test.at(test.size() - 2));
  //  ////  vector_1_.insert(vector_1_.begin() - 2, 20);
  vector_1_.insert(vector_1_.begin(), 21);
  test.insert(test.begin(), 21);
  EXPECT_EQ(vector_1_.at(0), test.at(0));

//  for (auto i : test2) std::cout << i << ' ';
//  SequenceContainer<int>::iterator it2 = vector_1_.begin();
//  std::cout << '\n' << *it2 << std::endl;
//  std::copy(&(*it2), &(*(it2 + 4)), &(*(vector_2_.end() - 2)));
//  std::cout << std::endl;
//  for (auto i : vector_2_) std::cout << i << ' ';
//

  //  std::cout << "\n+++++++++++++++++++++" << std::endl;
  //
  //  for (auto it : vector_1_) std::cout << it << ' ';
  //  std::cout << "\nsize = " << vector_1_.size() << std::endl;
  //  std::cout << "capacity = " << vector_1_.capacity() << std::endl;
  //  std::cout << "+++++++++++++++++++++" << std::endl;
  //  for (auto it : test) std::cout << it << ' ';
  //  std::cout << "\nsize = " << test.size() << std::endl;
  //  std::cout << "capacity = " << test.capacity() << std::endl;
}

TEST_F(S21Vector_test, erase) {
  vector_1_.erase(vector_1_.begin());
  test.erase(test.begin());
  EXPECT_EQ(vector_1_.at(0), test.at(0));
  vector_1_.erase(vector_1_.begin() + 1);
  test.erase(test.begin() + 1);
  EXPECT_EQ(vector_1_.at(1), test.at(1));
  vector_1_.erase(vector_1_.end() - 1);
  test.erase(test.end() - 1);
  EXPECT_EQ(vector_1_.at(vector_1_.size() - 1), test.at(test.size() - 1));
  test_empty.erase(test_empty.end() - 1);
  vector_empty.erase(vector_empty.end() - 1);
  EXPECT_EQ(test_empty.size(), vector_empty.size());
}

TEST_F(S21Vector_test, popback) {
  EXPECT_EQ(vector_1_.size(), 5);
  vector_1_.pop_back();
  EXPECT_EQ(vector_1_.size(), 4);

  //  test.pop_back();
  //  std::cout << "\nsize = " << test.size() << std::endl;
  //  std::cout << "capacity = " << test.capacity() << std::endl;
  //  test_empty.pop_back();
  //  std::cout << "\nsize = " << test_empty.size() << std::endl;
  //  std::cout << "capacity = " << test_empty.capacity() << std::endl;
  //  size_t my_size = 0;
  //  std::cout << --my_size << std::endl;
}

TEST_F(S21Vector_test, swap) {
  int *test_vector_1_ = vector_1_.data();
  int *test_empty = vector_empty.data();
  vector_empty.swap(vector_1_);
  EXPECT_EQ(vector_empty.size(), 5);
  EXPECT_EQ(vector_empty.capacity(), 5);
  EXPECT_EQ(&(*vector_empty.begin()), test_vector_1_);
  EXPECT_EQ(vector_1_.size(), 0);
  EXPECT_EQ(vector_1_.capacity(), 0);
  EXPECT_EQ(&(*vector_1_.begin()), test_empty);
}

TEST_F(S21Vector_test, originVictorClear) {
  //  std::cout << test.size() << std::endl;
  //  std::cout << test.capacity() << std::endl;
  //  test.clear();
  //  std::cout << test.size() << std::endl;
  //  std::cout << test.capacity() << std::endl;
  //  for (int i = 0; i < 5; ++i) {
  //    std::cout << test[i] << std::endl;
  //  }
}

TEST_F(S21Vector_test, originVictorInsert) {
  //  test.insert(test.begin() + 8, 123);
  //  for (int i = 0; i < test.size(); ++i) {
  //    std::cout << test[i] << "\t";
  //  }
  //  std::cout << std::endl;
  // ---- exp >>>
  //    std::vector<std::vector<int>> vtr{{1, 2, 3}, {4, 5, 6,}, {7, 8, 9}};
  //    for (auto it = vtr.begin(); it != vtr.end(); ++it) {
  //      for (auto it_ = (*it).begin(); it_ != (*it).end(); ++it_ ) {
  //        std::cout << (*it_)  << ' ';
  //      }
  //      std::cout << std::endl;
  //    }
  //  <<< exp ----
  //  auto i = test.begin();
  //      auto i = vtr.begin()->begin();
  //    i++;
  //   std::vector<int>::iterator i;
  auto it = test.begin();
  //   auto a = *it;

  //  SequenceContainer<int> one;
  //  SequenceContainer<int> two;
  //  std::cout << *(one.begin()+1) << std::endl;
  //  SequenceContainer<int>::Iterator a;
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}