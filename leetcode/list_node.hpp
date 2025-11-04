#pragma once
#include "tracker.hpp"
#include <ranges>

struct ListNode : public Tracker<ListNode> {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *ToList(const std::vector<int> &vec) {
    ListNode *head{nullptr};
    for (const auto &val : vec | std::views::reverse) {
        ListNode *n{new ListNode(val, head)};
        head = n;
    }
    return head;
}

std::vector<int> FromList(const ListNode *head) {
    std::vector<int> vec;
    while (head != nullptr) {
        vec.push_back(head->val);
        head = head->next;
    }
    return vec;
}
