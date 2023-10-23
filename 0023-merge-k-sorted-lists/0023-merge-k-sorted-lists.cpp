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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        //min heap based on Node value, the minimum value will be at the top in priority queue
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for (ListNode* listHead : lists) 
        {
            if (listHead != NULL) pq.push({listHead->val, listHead});
        }
        //=================================================================================
        ListNode* newHead = new ListNode(-1); //dummy node for the new Linked List
        ListNode* newTail = newHead;
        while(!pq.empty())
        {
            int minVal = pq.top().first;
            ListNode* minNode = pq.top().second;
            pq.pop();
            if (minNode->next != NULL) 
                pq.push({minNode->next->val, minNode->next});
            
            newTail->next = minNode;  //append the min Node to the new Linked List
            newTail = minNode; //make the minNode as the new tail of new Linked List
        }
        //=======================================================================================
        return newHead->next;
        
    }
};