#pragma once
class cBST
{
private:

	cNode* m_pRoot;
	cNode* m_pCurrent;

public:

	cBST() :
		m_pRoot(NULL),
		m_pCurrent(m_pRoot)

	{};
	~cBST() {};

	cNode* GetCurret(void) { return m_pCurrent; }

	void Insert(int key, int data);
	cNode* Find(int data);
	void Delete(int data);
	void Print();

	void PrintF(cNode* node);
	void PrintB(cNode* node);
	void PrintM(cNode* node);
};