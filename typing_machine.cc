// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
  this->pCursor = new Node('|');
  this->pHead = this->pCursor;
  this->pLast = this->pCursor;
  this->count = 0;
  return;
}

void TypingMachine::HomeKey() {
	if (this->pHead == this->pCursor)
		return;
	
	if (this->pCursor->pPrev && this->pCursor->pNext) {
		this->pCursor->pPrev->pNext = this->pCursor->pNext;
		this->pCursor->pNext->pPrev = this->pCursor->pPrev;
	}
	else if (this->pCursor->pPrev==nullptr && this->pCursor->pNext) {
		this->pCursor->pNext->pPrev = nullptr;
	}
	else if (this->pCursor->pPrev && this->pCursor->pNext == nullptr) {
		this->pCursor->pPrev->pNext = nullptr;
	}
	if (this->pCursor->pPrev && this->pLast == this->pCursor)
		this->pLast = this->pCursor->pPrev;
	this->pCursor->pNext = this->pHead;
	this->pCursor->pPrev = nullptr;
	this->pHead = this->pCursor;
    return;
}

void TypingMachine::EndKey() {
	if (this->pLast == this->pCursor)
		return;

	if (this->pCursor->pPrev && this->pCursor->pNext) {
		this->pCursor->pPrev->pNext = this->pCursor->pNext;
		this->pCursor->pNext->pPrev = this->pCursor->pPrev;
	}
	else if (this->pCursor->pPrev == nullptr && this->pCursor->pNext) {
		this->pCursor->pNext->pPrev = nullptr;
	}
	else if (this->pCursor->pPrev && this->pCursor->pNext == nullptr) {
		this->pCursor->pPrev->pNext = nullptr;
	}

	if (this->pCursor->pNext && this->pHead == this->pCursor)
		this->pHead = this->pCursor->pNext;

	this->pLast->pNext = this->pCursor;
	this->pCursor->pPrev = this->pLast;
	this->pCursor->pNext = nullptr;
	this->pLast = this->pCursor;
	return;
}

void TypingMachine::LeftKey() {

	if (this->pHead == this->pCursor)
		return;

	Node *pNode = this->pCursor->GetPreviousNode();
	Node *ppNode = pNode->GetPreviousNode();
	if (ppNode) {
		ppNode->pNext = this->pCursor;
		this->pCursor->pPrev = ppNode;
	}
	else
	{
		this->pHead = this->pCursor;
	}
	if (pNode) {
		pNode->pPrev = this->pCursor;
		pNode->pNext = this->pCursor->pNext;
		this->pCursor->pNext = pNode;

		if (this->pLast == this->pCursor)
			this->pLast = pNode;
		
	}
	 
	return;
}

void TypingMachine::RightKey() {
	if (this->pLast == this->pCursor)
		return;

	Node *nNode = this->pCursor->GetNextNode();
	Node *nnNode = nNode->GetNextNode();
	Node *pNode = this->pCursor->GetPreviousNode();

	if (pNode && nNode) {
		pNode->pNext = nNode;
		nNode->pPrev = pNode;
	}
	
	if (nnNode) {
		nnNode->pPrev = this->pCursor;
		this->pCursor->pNext = nnNode;
	}
	else
	{
		this->pLast = this->pCursor;
		this->pCursor->pNext = nullptr;
	}
	if (nNode) {
		nNode->pNext = this->pCursor;
		nNode->pPrev = pNode;
		this->pCursor->pPrev = nNode;

		if (this->pHead == this->pCursor)
			this->pHead = nNode;
	}

	return;
}

bool TypingMachine::TypeKey(char key) {

	if (this->count > 100)
		return false;
	if (key < 0x20 || key > 0x7E)
		return false;
	// 100개 미만 처리 확인 필요
	else {
		Node *node = this->pCursor->InsertPreviousNode(key);
		if (this->pCursor == this->pHead)
			this->pHead = node;
		this->count++;
		return true;
	}
}

bool TypingMachine::EraseKey() {
	if (this->pCursor->pPrev) {
		this->pCursor->ErasePreviousNode();
		this->count--;
		return true;
	}
	else
		return false;
}

std::string TypingMachine::Print(char separator) {
	Node *pTemp = this->pHead;
	std::string str;
	while (pTemp) {
		str = str + pTemp->GetData();
		if (pTemp->pNext)
			pTemp = pTemp->pNext;
		else
			break;
	}
	return str;
}
