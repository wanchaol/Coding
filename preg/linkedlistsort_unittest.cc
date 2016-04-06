//WhatsApp Coding Challenge by Wanchao Liang

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../catch.hpp"

//the new linkedlist data type
class LinkedList {
private:

	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int v): val(v), next(nullptr) {}
	};

	ListNode *head;
	ListNode *tail;
	int listlen = 0;

	//merge two sorted linked list
	ListNode *MergeTwoSortedLists(ListNode *A, ListNode *B) {
	
		ListNode *dummy = new ListNode(0);

		ListNode *cur = dummy;

		while(A && B) {
			if (A->val < B->val) {
				cur->next = A;
				A = A->next;
			}
			else {
				cur->next = B;
				B = B->next;
			}
			cur = cur->next;

		}

		if (A != nullptr) {
			cur->next = A;
		}
		else {
			cur->next = B;
		}

		cur = dummy->next;

		delete dummy;

		return dummy->next;
	}

	//begin the merge sort implementation
	ListNode *GetMiddle(ListNode *p) {
		if (p == nullptr) {
			return p;
		}

		ListNode *slow = p;
		ListNode *fast = p;

		while(fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}

		return slow;

	}

	//The underlying merge sort function
	ListNode *MergeSort(ListNode *left) {
		if (left == nullptr || left -> next == nullptr) {
			return left;
		}

		ListNode *middle = GetMiddle(left);
		//std::cout<<"middle value"<<middle->val<<std::endl;
		
		ListNode *right = middle->next;
		middle->next = nullptr;

		return MergeTwoSortedLists(MergeSort(left), MergeSort(right));
		
	}

public:

	LinkedList(): head(nullptr), tail(nullptr),listlen(0) {}

	~LinkedList() {
		ListNode *p;
		while(head) {
			p = head->next;
			delete head;
			head = p;
		}
	}

	int size() const { return listlen;}

	void push_back(int v) {
		ListNode *node = new ListNode(v);
		
		if (!head) {
			head = node;
			tail = head;
			
		}
		else {
			tail->next = node;
			tail = tail->next;
		}
		++ listlen;

	}

	void push_front(int v) {
		ListNode *node = new ListNode(v);
		node->next = head;
		head = node;
		++listlen;
	}
	
	std::string printList() const {
		ListNode *p = head;
		std::string str;

		if (head == nullptr) {
			return "";
		}

		while(p) {
			if (p!= tail) {
				str += std::to_string(p->val) + "->";
			}
			else {
				str += std::to_string(p->val);
			}

			p = p->next;
		}

		return str;

	}
	std::vector<int> getList() const {
		ListNode *p = head;
		std::vector<int> reslist;

		if (head == nullptr) {
			return reslist;
		}

		while(p) {
			if (p!= tail) {
				reslist.push_back(p->val);
			}
			else {
				reslist.push_back(p->val);
			}

			p = p->next;
		}

		return reslist;

	}
	
	void clear() {
		this->~LinkedList();
		listlen = 0;
	}

	//The wrapper sort function
	void merge_sort() {
		if (head == nullptr) {
			return;
		}

		head = MergeSort(head);
		//reset the tail
		ListNode *p = head;
		while(p->next) {
			p = p->next;
		}
		this->tail = p;
	}


};

TEST_CASE( "Reverse Linked List Order", "[linkedlisttest]" ) { //REQUIRE( Factorial(1) == 1 );

	LinkedList a;

	for (int i = 0; i < 20; ++i) {
		a.push_back(19-i);
	}

	a.merge_sort();
	std::vector<int> sorted = a.getList();
	for (int i = 0; i < 20; ++i) {
		REQUIRE(sorted[i] == i);
	}
}
