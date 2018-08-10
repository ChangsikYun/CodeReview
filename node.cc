// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
	this->data = data;
	this->pNext = nullptr;
	this->pPrev = nullptr;
	return;
}

char Node::GetData() {
	return this->data;
}

Node* Node::GetPreviousNode() {
	if (this->pPrev)
		return this->pPrev;
	else
		return nullptr;
}

Node* Node::GetNextNode() {
	if (this->pNext)
		return this->pNext;
	else
		return nullptr;
}

Node* Node::InsertPreviousNode(char data) {
	Node *node = new Node(data);
	Node *prev = this->pPrev;

	if (prev != nullptr) {
		prev->pNext = node;
		node->pPrev = prev;
	}	
	node->pNext = this;
	this->pPrev = node;
    
    return node;
}

Node* Node::InsertNextNode(char data) {
	Node *node = new Node(data);
	Node *next = this->pNext;

	if (next != nullptr) {
		next->pPrev = node;
		node->pNext = next;
	}
	node->pPrev = this;
	this->pNext = node;

	return node;
}

bool Node::ErasePreviousNode() {
	if (this->pPrev)
	{
		Node *node = this->pPrev;
		if (node->pPrev) {
			Node *prev = node->pPrev;
			prev->pNext = this;
			this->pPrev = prev;
		}
		else {
			this->pPrev = nullptr;
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
		if (node->pNext) {
			Node *next = node->pNext;
			next->pPrev = this;
			this->pNext = next;
		}
		else {
			this->pNext = nullptr;
		}
		delete node;
		return true;
	}
  return false;
}
