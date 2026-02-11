class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return new TreeNode(head->val);
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev_slow = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            prev_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode *root = new TreeNode(slow->val);
        prev_slow->next = nullptr;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};