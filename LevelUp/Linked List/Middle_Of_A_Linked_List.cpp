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

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/DevSpace/CPP space/Input.txt", "r", stdin);
    freopen("D:/DevSpace/CPP space/Output.txt", "w", stdout);
    freopen("D:/DevSpace/CPP space/Error.txt", "w" , stderr);
    #endif

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

    ListNode *head = midNode(dummy->next);
    
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}