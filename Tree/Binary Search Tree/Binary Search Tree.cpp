#include "pch.h"
#include <iostream>
using namespace std;

class BST {
public:
	int veri;
	BST* pSol;
	BST* pSag;

	BST(int veri, BST* pSol = NULL, BST* pSag = NULL) {
		this->veri = veri;
	}

	void ekle(int item) {
		if (veri > item) {
			if (pSol)
				return pSol->ekle(item);
			BST* pYeni = new BST(item);
			pSol = pYeni;
		}
		else if (veri < item) {
			if (pSag)
				return pSag->ekle(item);
			BST* pYeni = new BST(item);
			pSag = pYeni;
		}
	}

	void cikar(int item, BST* ebeveyn) {
		if (veri > item) {
			if (pSol)
				pSol->cikar(item, this);
			else
				return;
		}
		else if (veri < item) {
			if (pSag)
				pSag->cikar(item, this);
			else
				return;
		}
		
		if ((pSag == NULL) && (pSol == NULL)) {
			if (ebeveyn->pSol == this)
				ebeveyn->pSol = NULL;
			else
				ebeveyn->pSag = NULL;
		}
		else if (pSag&&pSol) {
			veri = pSag->minGetir();
			return pSag->cikar(veri, this);
		}
		else if (pSag) {
			if (ebeveyn->pSol == this)
				ebeveyn->pSol = pSag;
			else
				ebeveyn->pSag = pSag;
		}
		else {
			if (ebeveyn->pSol == this)
				ebeveyn->pSol = pSol;
			else
				ebeveyn->pSag = pSol;
		}
		delete this;
	}

	BST* Ara(int item) {
		if (veri > item) {
			if (pSol)
				return pSol->Ara(item);
			else
				return NULL;
		}
		else if (veri < item) {
			if (pSag)
				return pSag->Ara(item);
			else
				return NULL;
		}
		return this;
	}

	int minGetir() {
		if (pSol)
			return pSol->minGetir();
		return veri;
	}

	void dolas(BST* tree) {
		if (tree == NULL)
			return;
		dolas(tree->pSol);
		cout << tree->veri << " ";
		dolas(tree->pSag);
	};

};

int main()
{
	BST* tree = new BST(1);

	tree->ekle(10);
	tree->ekle(20);
	tree->ekle(5);
	tree->dolas(BST* tree);
}
