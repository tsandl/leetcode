cmake_minimum_required(VERSION 3.16)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)


add_executable(listnode code/ListNode/listNode.cpp)
add_executable(doublelistnode code/ListNode/double_listnode.cpp)
add_executable(tree code/Tree/Tree.cpp)
add_executable(tree1 code/Tree/Tree1.cpp)
add_executable(tree3 code/Tree/Tree2.cpp)
add_executable(balance1 code/Tree/balance_Tree.cpp)
add_executable(search_Tree code/Tree/search_Tree.cpp code/Tree/search_Tree.h)
add_executable(classTest  code/Class/classTest.cpp)
add_executable(classTest11  code/Class/test.cpp)