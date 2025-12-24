/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) {
            return nullptr;
        }
        int k = lists.size();
        for(int i=1; i<k; i++) {
            lists[i] = mergeLists(lists[i-1], lists[i]);
        }
        return lists[k-1];
    }

private: 
    ListNode* mergeLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0, nullptr);
        ListNode* node = dummy;
        while(list1!=nullptr && list2!=nullptr) {
            if(list1->val<list2->val) {
                node->next = list1;
                list1 =list1->next;
                node = node->next;
            }
            else {
                node->next = list2;
                list2 = list2->next;
                node = node->next;
            }
        }
        if(list1!=nullptr) {
            node->next = list1;
        }
        else {
            node->next = list2;
        }
        return dummy->next;
    }
};