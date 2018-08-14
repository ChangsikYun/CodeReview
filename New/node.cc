// Copyright 2018 Changsik Yun (changsik.yun@samsung.com)

#include "node.h"

Node::Node(char data) : data(data), pPrev(nullptr), pNext(nullptr){
	return;
}

char Node::GetData() {
	return this->data;
}

Node* Node::GetPreviousNode() {
	return this->pPrev;
}

Node* Node::GetNextNode() {
	return this->pNext;
}

Node* Node::InsertPreviousNode(char data) {
    	Node *node = new Node(data);
	if (node) {
		Node *prev = this->pPrev;

		if (prev != nullptr) {
			prev->pNext = node;
			node->pPrev = prev;
		}	
		node->pNext = this;
		this->pPrev = node;

		return node;
	}
	else
		return nullptr;
}

Node* Node::InsertNextNode(char data) {
	Node *node = new Node(data);
	if (node) {
		Node *next = this->pNext;

		if (next != nullptr) {
			next->pPrev = node;
			node->pNext = next;
		}
		node->pPrev = this;
		this->pNext = node;

		return node;
	}
	else
		return nullptr;
}

bool Node::ErasePreviousNode() {
	if (this->pPrev)
	{
		Node *node = this->pPrev;
		Node *prev = node->pPrev;
		this->pPrev = prev;
		if (node->pPrev) {
			prev->pNext = this;
		}
		delete node;
		return true;
	}
	return false;
}

bool Node::EraseNextNode() {
	if (this->pNext)
	{
		Node *node = this->pNext;
		Node *next = node->pNext;
		this->pNext = next;
		if (node->pNext) {
			next->pPrev = this;
		}
		delete node;
		return true;
	}
  return false;
}
