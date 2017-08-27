/*
______________ Assumptions _____________
1. LinkedList contains int or char
2. LinkedList size >= 1
3. Function throws invalid input Exception if input is 
	1. NULL
	2. ListNode elements is not of type int or char
4. Function Returns bool 





____________ Examples ________________
1. input=nursesrun return true
2. input=lol return true
3. input=microsoft return false
4. input=1 return true
5. input=NULL throw invalid input Exception 


*/
#include<iostream>
#include<string>
#include <assert.h>     
#include <ctype.h>

using namespace std;

class InvalidInputException: public exception
{
	virtual const char * what() const throw() 
	{
		return "InvalidInputException";
	}
}
;



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


ListNode<char> * inputToListNode(string input)
{
	ListNode<char> * node=NULL;
	for(char c:input)	
	{
		c=(char)tolower(c);
		node=new ListNode<char>(c,node);
	}
	return node;
}

template<typename T>
bool isValidIput(T input) throw(InvalidInputException)
{


}

int main()
{	
	//_____________ Test ______________
	//std::to_string
	
	//Testing Single Characters 
    ListNode<char> * letter= new ListNode<char>('a');
	assert(is_palindrome<char>(letter)==true);	
	
	
	//Testing strings (Multiple Characters)
	ListNode<char> * apple=inputToListNode("apple");
	assert(is_palindrome<char>(apple)==false);

	ListNode<char> * redder=inputToListNode("redder");
	assert(is_palindrome<char>(redder)==true);

	//Testing Upper and Lower case strings (NOTE lower and upper case is handled by the inputToListNode function) 
	ListNode<char> * ReDder=inputToListNode("ReDder");
	assert(is_palindrome<char>(ReDder)==true);


	//Testing int
    ListNode<int> * number=new ListNode<int>(9);
    assert(is_palindrome<int>(number)==true);

    ListNode<int> *number1= new ListNode<int>(1,new ListNode<int>(0,new ListNode<int>(1))); //101
    assert(is_palindrome<int>(number1)==true);

    ListNode<int> *number2= new ListNode<int>(0,new ListNode<int>(0,new ListNode<int>(1))); //001
    assert(is_palindrome<int>(number2)==false);


	//Testing Large inputs
    ListNode<char> * longSentence=inputToListNode("EvacanIseebeesinacave");
	print(longSentence);	
    assert(is_palindrome<char>(longSentence)==true);

	return 0;
};

