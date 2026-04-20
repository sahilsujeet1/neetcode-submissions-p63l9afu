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
private:
    ListNode* merge(ListNode* h1, ListNode* h2) {
        ListNode temp;
        ListNode* tail = &temp;

        while(h1 && h2) {
            if(h1->val < h2->val) {
                tail->next = h1;
                h1 = h1->next;
            } else {
                tail->next = h2;
                h2 = h2->next;
            }
            tail = tail->next;
        }

        if(h1) {
            tail->next = h1;
        }

        if(h2) {
            tail->next = h2;
        }
        return temp.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;

        while(lists.size() > 1) {
            vector<ListNode*> mergedLists;

            for(int i=0; i<lists.size(); i+=2) {
                ListNode* n1 = lists[i];
                ListNode* n2 = i+1 < lists.size() ? lists[i+1] : NULL;

                ListNode* mergedList = merge(n1, n2);
                mergedLists.push_back(mergedList);
            }
            lists = mergedLists;
        }
        return lists[0];
    }

};
