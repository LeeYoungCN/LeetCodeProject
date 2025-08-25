#pragma once

#ifndef LEETCODE_UTILS_LIST_HPP
#define LEETCODE_UTILS_LIST_HPP
#include <cstdint>
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    friend std::ostream &operator<<(std::ostream &os, const ListNode &node)
    {
        os << "{" << node.val;
        const ListNode *nodePtr = node.next;
        while (nodePtr != nullptr) {
            os << " -> " << nodePtr->val;
            nodePtr = nodePtr->next;
        }
        os << "}";
        return os;
    };
};

bool operator==(const ListNode &lhs, const ListNode &rhs);

bool operator!=(const ListNode &lhs, const ListNode &rhs);

ListNode *CreateList(const std::string &valStr);
ListNode *CreateList(const std::vector<int32_t> &valList);
void FreeList(ListNode *node);
std::string ToString(const ListNode *node);
void RegisterList(ListNode *node);

#endif  // LEETCODE_UTILS_LIST_HPP
