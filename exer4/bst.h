#ifndef BST_H
#define BST_H

#include <iostream>

class Node {
private:
    int k;
    Node* lc;
    Node* rc;

public:
    Node() { lc = rc = NULL;}
    explicit Node(int k, Node* lc, Node* rc)
    {
    	 this->k = k;
		 this->lc = lc;
		 this->rc = rc;
	}
    ~Node() {}

    // Functions to set and return the key
    virtual int& getKey() { return k;}
    virtual void setKey(const int& k) { this->k = k;}
    virtual bool isLeaf() {  return (lc == NULL) && (rc == NULL); }

    // Functions to set and return the children
    virtual Node* left() const { return lc;}
    virtual void setLeft(Node* lc) { this->lc = lc;}
    virtual Node* right() const { return rc;}
    virtual void setRight(Node* rc) { this->rc = rc;}
};
class bst : public Node
{
	private:
		Node* root;
		int count;//节点数目 
		
		void clearHelp(Node*);
		Node* insertHelp(Node*, const int&);
		int findHelp(Node*, const int&) const;
	public:
		bst();
		~bst();
		
		void clear();
		void insert(const int&);
		void find(const int&) const;
};

#endif
