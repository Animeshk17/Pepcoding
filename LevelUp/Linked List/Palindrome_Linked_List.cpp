#include <iostream>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

ListNode *reverse(ListNode *head)
{
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* next = head->next;

    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;

}

ListNode *midNode(ListNode *head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){

        fast = fast->next->next;
        slow = slow->next;
        
    }

    return slow;
}

bool isPalindrome(ListNode *head)
{   
    if(head == NULL || head->next == NULL) return true;

    ListNode* mid = midNode(head);
    ListNode* newHead = reverse(mid);

    bool isPalindrome = false;

    while(head && newHead){
        if(head->val != newHead->val) return false;
        head = head->next;
        newHead = newHead->next;
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
   
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
   
    while (n-- > 0)
    {
 
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
 
    }

    cout << (boolalpha) << isPalindrome(dummy->next) << endl;

    return 0;
}