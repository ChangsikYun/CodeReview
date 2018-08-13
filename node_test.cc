// Copyright 2018 Minkyu Jo


bool ErasePreviousNode();
bool EraseNextNode();


#include "node.h"
#include "node_test.h"
#include "test.h"

class NodeConstructorTestSuite
{
private:
  static void SingleNodeTest() {
    Node *node = new Node('A');
    ASSERT_EQ(node->GetData(), 'A');
    delete node;
  }

  static void DoubleNodeTest() {
	  Node *node1 = new Node('A');
	  ASSERT_EQ(node1->GetData(), 'A');
	  delete node1;

	  Node *node2 = new Node('A');
	  ASSERT_EQ(node2->GetData(), 'A');
	  delete node2;
  }

public:
  static void RunTest() {
    SingleNodeTest();
	DoubleNodeTest();
  }
};

class SomeOtherTestSuite
{
private:
	static void InsertPreviousNodeTest() {
		Node *node = new Node('A');
		node->InsertPreviousNode('B');

		Node *temp = node->GetPreviousNode();
		ASSERT_EQ(temp->GetData(), 'B');
		delete node;
		delete temp;
	}
	static void InsertNextNodeTest() {
		Node *node = new Node('A');
		node->InsertNextNode('B');

		Node *temp = node->GetNextNode();
		ASSERT_EQ(temp->GetData(), 'B');
		delete node;
		delete temp;
	}
	static void ErasePreviousSingleNodeTest() {
		bool result;
		Node *node = new Node('A');
		result = node->ErasePreviousNode();
		ASSERT_EQ(result, false);
		delete node;
	}

	static void ErasePreviousMultiNodeTest() {
		bool result;

		Node *node = new Node('A');
		node->InsertPreviousNode('B');
		node->InsertPreviousNode('C');

		result = node->ErasePreviousNode();
		ASSERT_EQ(result, true);

		Node *temp = node->GetPreviousNode();
		ASSERT_EQ(temp->GetData(), 'B');

		delete node;
		delete temp;

	}

	static void EraseNextSingleNodeTest() {
		bool result;
		Node *node = new Node('A');
		result = node->EraseNextNode();
		ASSERT_EQ(result, false);
		delete node;
	}

	static void EraseNextMultiNodeTest() {
		bool result;

		Node *node = new Node('A');
		node->InsertNextNode('B');
		node->InsertNextNode('C');

		result = node->EraseNextNode();
		ASSERT_EQ(result, true);

		Node *temp = node->GetNextNode();
		ASSERT_EQ(temp->GetData(), 'B');

		delete node;
		delete temp;

	}
public:
  static void RunTest() {
	  InsertPreviousNodeTest();
	  InsertNextNodeTest();
	  ErasePreviousSingleNodeTest();
	  ErasePreviousMultiNodeTest();
	  EraseNextSingleNodeTest();
	  EraseNextMultiNodeTest();
    // add more..
  }
};

void NodeTest() {
  NodeConstructorTestSuite::RunTest();
  SomeOtherTestSuite::RunTest();
  // add more..
}