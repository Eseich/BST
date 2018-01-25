#include "stdafx.h"
#include "cNode.h"

using namespace std;

cNode::cNode()
{
}


cNode::~cNode()
{
}

cNode::cNode(int data, cNode * pNext)
	: m_nData(data), m_pNext(pNext), m_pSmall(NULL), m_pLarge(NULL), m_pPrev(NULL)
{
}

cNode* cNode::Find(int data)
{
	if (m_nData == data)
	{
		return this;
	}
	else if (m_pNext)
	{
		m_pNext->Find(data);
	}

	return nullptr;
}

void cNode::Print()
{
	std::cout << m_nData << std::endl;

	//kms
	//abd
	//if (m_pLarge)
	//{
	//	m_pLarge->Print();
	//}

	if (m_pSmall)
	{
		m_pSmall->Print();
	}

	//if (m_pNext)
	//{
	//	m_pNext->Print();
	//}
}

void cNode::Delete(int data, cNode ** ppThis)
{
	if (m_nData == data)
	{
		(*ppThis) = m_pNext;
		delete this;
	}
	else if (m_pNext)
	{
		m_pNext->Delete(data, &m_pNext);
	}
}

//void cNode::Insert(int data)
//{
//	cNode* pNode = new cNode(data, NULL);
//
//}
