#include<iostream>
using namespace std;

template<typename T>
struct ListNode
{
	T info;
	ListNode<T> * next;

	ListNode(T ninfo,ListNode<T> * node=NULL)
	:info{ninfo},next{node}
	{}

};

template<typename T>
void print(ListNode<T> * node)
{
	while(node!=NULL)
	{
		cout<<node->info;
		node=node->next;
	}
	cout<<endl;
}

template<typename T>
ListNode<T> * reverse(ListNode<T> * node)
{
	ListNode<T>* newnode;
	while(node!=NULL)
	{
		newnode=new ListNode<T>(node->info,newnode);
		node=node->next;
	}
	return newnode;
}

template<typename T>
bool is_palindrome(ListNode<T> * node)
{
	bool state=false;
	ListNode<T> * newnode=reverse<T>(node);		
	while(node!=NULL)
	{
		state=(node->info==newnode->info);
		node=node->next;
		newnode=newnode->next;
	}
	return state;
}


int main()
{
	


};

