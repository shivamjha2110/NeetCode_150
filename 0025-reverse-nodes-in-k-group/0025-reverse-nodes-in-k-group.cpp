class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        ListNode *dummy = new ListNode(0, head); // Dummy node with value 0 pointing to the initial head of the given LL
        ListNode *currNode = dummy, *nextNode = dummy, *prevNode = dummy;
        
        // Calculate length of LL
        int count = -1; // The initial value of count is taken as -1 because the dummy node shouldn't be counted
        while(currNode){
            count++;
            currNode = currNode->next;
        }
        
        // Iterating till we have groups of size >= k
        while(count >= k){
            // For every group of size k, we need to make sure that currNode is 1st node and nextNode is 2nd node
            currNode = prevNode->next; // prevNode is the previous node of the previous group and points to the first node of the new group
            nextNode = currNode->next;
            
            // Reverse k - 1 nodes
            for(int i = 1; i < k; i++){
                currNode->next = nextNode->next; // currNode keeps track of where we can shift nextNode after a single reversal
                nextNode->next = prevNode->next; // Reversing the link
                prevNode->next = nextNode; // prevNode->next stores the address where we can shift currNode (current nextNode is going to be our next currNode)
                nextNode = currNode->next; // currNode->next indicates the new address of nextNode (nextNode->next cannot be used as it has been reversed)
            }
            prevNode = currNode; // prevNode should stand at the last node of the previous reversed group of size k
            count -= k; // Reversal has been successful for k nodes, so we reduce k from count
        }
        return dummy->next; // dummy->next points to the last node of the first reversed group of size k
    }
};