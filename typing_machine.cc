// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
  this->pCursor = new Node('|');
  this->pHead = this->pCursor;
  this->pTail = this->pCursor;
  this->count = 0;
  return;
}

void TypingMachine::HomeKey() {
	if (this->pHead == this->pCursor)
		return;
	
	Node *nHead = this->pHead;
	Node *nPrev = this->pCursor->GetPreviousNode();
	
	if (this->pTail == this->pCursor) {
		if (this->pCursor->GetPreviousNode() != nullptr) {
			this->pTail = this->pCursor->GetPreviousNode();
		}
	}

	if (nPrev) {
		nPrev->EraseNextNode();	
	}

	Node *newCursor = nHead->InsertPreviousNode('|');
	this->pCursor = newCursor;
	this->pHead = this->pCursor;

    return;
}

void TypingMachine::EndKey() {
	if (this->pTail == this->pCursor)
		return;

	Node *nTail = this->pTail;
	Node *nPrev = this->pCursor->GetPreviousNode();

	if (this->pHead == this->pCursor) {
		if (this->pCursor->GetNextNode() != nullptr) {
			this->pHead = this->pCursor->GetNextNode();
		}
	}

	if (nPrev) {
		nPrev->EraseNextNode();
	}

	Node *newCursor = nTail->InsertNextNode('|');
	this->pCursor = newCursor;
	this->pTail = this->pCursor;
	return;
}

void TypingMachine::LeftKey() {

	if (this->pHead == this->pCursor)
		return;

	Node *pNode = this->pCursor->GetPreviousNode();
	if (this->pTail == this->pCursor)
		this->pTail = pNode;
	pNode->EraseNextNode();
	
	Node *newCursor = pNode->InsertPreviousNode ('|');
	this->pCursor = newCursor;

	if (pNode == this->pHead)
		this->pHead = newCursor;

	return;
}

void TypingMachine::RightKey() {
	if (this->pTail == this->pCursor)
		return;

	Node *pNode = this->pCursor->GetNextNode();
	if (this->pHead == this->pCursor)
		this->pHead = pNode;
	pNode->ErasePreviousNode();

	Node *newCursor = pNode->InsertNextNode('|');
	this->pCursor = newCursor;
	
	if (pNode == this->pTail)
		this->pTail = newCursor;

	return;
}

bool TypingMachine::TypeKey(char key) {

	if (this->count > 100 || (key < 0x20 || key > 0x7E))
		return false;	
	else {
		Node *node = this->pCursor->InsertPreviousNode(key);
		if (this->pCursor == this->pHead)
			this->pHead = node;
		this->count++;
		return true;
	}
}

bool TypingMachine::EraseKey() {
	
	Node *pNode = this->pCursor->GetPreviousNode();
	if (pNode) {
		this->pCursor->ErasePreviousNode();
		this->count--;
		if (pNode == this->pHead)
			this->pHead = this->pCursor;
		return true;
	}
	else
		return false;
}

std::string TypingMachine::Print(char separator) {
	Node *pTemp = this->pHead;
	std::string str;
	while (pTemp) {
		if (separator != '\0' ||  pTemp != this->pCursor )
			str = str + pTemp->GetData();
		if (pTemp->GetNextNode() != nullptr)
			pTemp = pTemp->GetNextNode();
		else
			break;
	}
	return str;
}
