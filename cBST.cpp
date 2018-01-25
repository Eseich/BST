#include "stdafx.h"
#include "cBST.h"

void cBST::Insert(int key, int data)
{
	cNode* temp = new cNode;

	if (m_pCurrent == NULL)
	{
		m_pRoot = temp;
		m_pRoot->m_nData = data;
		m_pCurrent = m_pRoot;
		return;
	}

	if (data < m_pCurrent->m_nData)
	{
		if (m_pCurrent->m_pSmall == NULL)
		{
			temp->m_pPrev = m_pCurrent;
			temp->m_nData = data;

			m_pCurrent->m_pSmall = temp;
			m_pCurrent = m_pRoot;
		}
		else
		{
			m_pCurrent = m_pCurrent->m_pSmall;
			Insert(m_pCurrent->m_nData, data);
		}
	}
	else if (data > m_pCurrent->m_nData)
	{
		if (m_pCurrent->m_pLarge == NULL)
		{
			temp->m_pPrev = m_pCurrent;
			temp->m_nData = data;

			m_pCurrent->m_pLarge = temp;
			m_pCurrent = m_pRoot;
		}
		else
		{
			m_pCurrent = m_pCurrent->m_pLarge;
			Insert(m_pCurrent->m_nData, data);
		}
	}
	else return;
}

cNode* cBST::Find(int data)
{
	if (m_pCurrent->m_nData == data)
	{
		cNode* temp = new cNode;
		temp = m_pCurrent;
		m_pCurrent = m_pRoot;

		//cout << "Success to Search" << endl;
		return temp;
	}
	else if (data < m_pCurrent->m_nData)
	{
		if (m_pCurrent->m_pSmall == NULL)
		{
			cout << "Fail to Search" << endl;
			m_pCurrent = m_pRoot;
			return nullptr;
		}
		m_pCurrent = m_pCurrent->m_pSmall;
		Find(data);
	}
	else if (data > m_pCurrent->m_nData)
	{
		if (m_pCurrent->m_pLarge == NULL)
		{
			cout << "Fail to Search" << endl;
			m_pCurrent = m_pRoot;
			return nullptr;
		}
		m_pCurrent = m_pCurrent->m_pLarge;
		Find(data);
	}
}

void cBST::Delete(int data)
{
	cNode* deletedNode;
	//
	deletedNode = Find(data);

	if (deletedNode == NULL)
	{
		cout << "Fail to Delete" << endl;
		return;
	}
	// none Next
	if (deletedNode->m_pSmall == NULL && deletedNode->m_pLarge == NULL)
	{
		// from Parent Smaller
		if (deletedNode->m_pPrev->m_pSmall && deletedNode->m_pPrev->m_pSmall->m_nData == data)
		{
			deletedNode->m_pPrev->m_pSmall = nullptr;
		}
		// from Parent Lager
		else if (deletedNode->m_pPrev->m_pLarge && deletedNode->m_pPrev->m_pLarge->m_nData == data)
		{
			deletedNode->m_pPrev->m_pLarge = nullptr;
		}
	}
	// single Child
	//// smaller
	else if (deletedNode->m_pSmall != NULL && deletedNode->m_pLarge == NULL)
	{
		// from Parent Smaller
		if (deletedNode->m_pPrev->m_pSmall && deletedNode->m_pPrev->m_pSmall->m_nData == data)
		{
			deletedNode->m_pSmall->m_pPrev = deletedNode->m_pPrev;
			deletedNode->m_pPrev->m_pSmall = deletedNode->m_pSmall;
		}
		// from Parent Lager
		else if (deletedNode->m_pPrev->m_pLarge && deletedNode->m_pPrev->m_pLarge->m_nData == data)
		{
			deletedNode->m_pSmall->m_pPrev = deletedNode->m_pPrev;
			deletedNode->m_pPrev->m_pLarge = deletedNode->m_pSmall;
		}
	}
	//// lager
	else if (deletedNode->m_pSmall == NULL && deletedNode->m_pLarge != NULL)
	{
		// from Parent Smaller
		if (deletedNode->m_pPrev->m_pSmall && deletedNode->m_pPrev->m_pSmall->m_nData == data)
		{
			deletedNode->m_pLarge->m_pPrev = deletedNode->m_pPrev;
			deletedNode->m_pPrev->m_pSmall = deletedNode->m_pLarge;
		}
		// from Parent Lager
		else if (deletedNode->m_pPrev->m_pLarge && deletedNode->m_pPrev->m_pLarge->m_nData == data)
		{
			deletedNode->m_pLarge->m_pPrev = deletedNode->m_pPrev;
			deletedNode->m_pPrev->m_pLarge = deletedNode->m_pLarge;
		}
	}

	// has Children	
	else if (deletedNode->m_pSmall != NULL && deletedNode->m_pLarge != NULL)
	{
		cNode* saveNode; saveNode = new cNode;
		saveNode = deletedNode;

		deletedNode = deletedNode->m_pSmall;

		while (deletedNode->m_pLarge != nullptr)
		{
			deletedNode = deletedNode->m_pLarge;
		}

		// disconnect to Leaf's Parent
		deletedNode->m_pPrev->m_pLarge = nullptr;

		// change Value
		saveNode->m_nData = deletedNode->m_nData;
	}
}

void cBST::Print()
{
	m_pCurrent->Print();
}

void cBST::PrintF(cNode* node)
{
	if (node)
	{
		PrintF(node->m_pSmall);
		cout << node->m_nData << endl;
		PrintF(node->m_pLarge);
	}
}

void cBST::PrintB(cNode* node)
{
	if (node)
	{
		PrintB(node->m_pSmall);
		PrintB(node->m_pLarge);
		cout << node->m_nData << endl;
	}
}

void cBST::PrintM(cNode* node)
{
	if (node)
	{
		cout << node->m_nData << endl;
		PrintM(node->m_pSmall);
		PrintM(node->m_pLarge);
	}
}