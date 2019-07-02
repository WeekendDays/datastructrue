#include <iostream>
using namespace std;
#ifndef _List
#define _List

template <typename E> 
class Link
{
	public:
	E element;
	Link *next;
	Link(const E& elemval,Link* nextval =NULL){
		element=elemval;
		next=nextval;	
	}	
	Link(Link* nextval=NULL){
			next=nextval;
	}
};

template <typename E> 
class List
{
	private:
	    void operator =(const List&) {}
	    List(const List&) {}
	public:
		List() {}
		virtual ~List() {}
		virtual void clear() =0;
		virtual void insert(const E& item) =0;
		virtual void append(const E& item) =0;
		virtual E remove() =0;
		virtual void moveToStart() =0;
		virtual void moveToEnd() =0;
		virtual void prev() =0;
		virtual void next() =0;
		virtual int length() const =0;
		virtual int currPos() const =0;
		virtual void moveToPos(int pos) =0;
		virtual const E& getValue() const =0;			
};

template<typename E>
class LList:public List<E>
{
	private:
		Link<E>* head;
		Link<E>* tail;
		Link<E>* curr;
		int cnt;
		void init();
		void removeall();
	public:
		LList(int size);
		~LList();
		void print() const;
		void clear();
		void insert(const E& it); 
		void append(const E& it);
		E remove();
		void moveToStart();
		void moveToEnd();
		void prev();
		void next();
		int length() const;
		int currPos() const;
		void moveToPos(int pos);
		const E& getValue() const;	
};
#endif

