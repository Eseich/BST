#pragma once
class cNode
{
public:
	cNode();
	~cNode();
	cNode(int data, cNode* pNext = NULL);

	int		m_nData;
	cNode*	m_pPrev;
	cNode*	m_pNext;
	cNode*	m_pSmall;
	cNode*	m_pLarge;

	cNode* Find(int data);

	void Print();
	void Delete(int data, cNode** ppThis);
	void Insert(int data);

	int GetValue() { return m_nData; }
	void SetValue(int data) { m_nData = data; }
	cNode* GetNext() { return m_pNext; }
	void SetNext(cNode* next) { m_pNext = next; }

};