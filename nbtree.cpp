#include "nbtree.h"

void nbCreate(nbTree *x)
{//Membuat tree kosong (X.root=NULL)
	Root(*x) = NULL;
}

nbAddr nbCNode(nbType X)
{//Alokasi untuk membuat node baru
	nbAddr newNode;
	newNode = (nbAddr) malloc(sizeof(nbTreeNode));
	if (newNode != NULL){
		FS(newNode)=NULL;
		Info(newNode)=X;
		NB(newNode)=NULL;
		Parent(newNode)=NULL;
	}
	return newNode;
}

void nbDNode(nbAddr *Node)
{
	FS(*Node)=NULL;
	NB(*Node)=NULL;
	Parent(*Node)=NULL;
	free(*Node);
}

void nbInsert(nbTree *tRoot, nbAddr parent, nbType X){
	nbAddr newNode, temp;
	newNode=nbCNode(X);
	if (newNode !=NULL){ //Jika pengalokasian node baru berhasil
		if (parent==NULL) //JIka belum terdapat root
			Root(*tRoot)=newNode;
		else{
			temp=parent;
			if (FS(temp) != NULL){
				temp=FS(temp);
				while(NB(temp)!=NULL)
					temp=NB(temp);
				NB(temp)=newNode;
			}else
				FS(temp) = newNode;
			Parent(newNode) = parent;
		}
	}
	else
	{
		printf("Alokasi gagal");
	}
}

nbAddr nbSearch(nbAddr root, nbType src){
	nbAddr nSrc;
	if (root!=NULL){
		if (Info(root)==src)
			return root;
		else{
			nSrc=nbSearch(FS(root),src);
			if (nSrc==NULL)
				return nbSearch(NB(root),src);
			else
				return nSrc;
		}
	}
	return NULL;
}

void nbUpgrade(nbAddr *root){
	nbAddr temp;
	temp= NB(*root);
	if (FS(*root)==NULL)
		FS(*root)=temp;
	while(temp!=NULL){
		Parent(temp)= *root;
		temp=NB(temp);
	}
}

void nbDelete(nbAddr *pDel, nbTree *pTree){
	nbAddr pCur;
	pCur=*pDel;
	
	if(Root(*pTree) == NULL) //kondisi ketika root kosong
	{
		printf("Tree Kosong");
		return;
	}
	if (pCur==Root(*pTree) && FS(pCur)==NULL) //kondisi ketika root memiliki 1 elemen
	{
		Root(*pTree)=NULL;
		return;
	}
	
	//kondisi node merupakan leaf dan jika merupakan first son maka next brothernya menjadi first son
	if(FS(pCur) == NULL)
	{
		if(FS(Parent(pCur)) == pCur) //kondisi ketika node merupakan anak pertama dari parent
		{
			if(NB(pCur) != NULL) //ketika first son memiliki sibling
				FS(Parent(pCur)) = NB(pCur);
			else
				FS(Parent(pCur)) = NULL;
			nbDNode(&(*pDel));
		}else //kondisi ketika node bukan merupakan anak pertama
		{
			pCur = FS(Parent(pCur)); //pCur ditunjuk ke anak pertama 
			while(NB(pCur) != *pDel) //pencarian node sebelum pDel
				pCur = NB(pCur);
			if(NB(*pDel) == NULL) //kondisi ketika pDel merupakan last son
			{
				NB(pCur) = NULL;
				nbDNode(&(*pDel));
			}
			else //kondisi ketika pDel bukan merupakan last son
			{
				NB(pCur) = NB(*pDel);
				nbDNode(&(*pDel));
			}
		}
		return;	
	}
	else //kondisi node memiliki child
	{
		while( FS(pCur)!=NULL )
			pCur = FS(pCur); // pcur diisi dengan First son sampai null
		while (pCur != *pDel){
			nbUpgrade(&pCur);
			if (Parent(pCur)!=NULL)
				NB(pCur)=NB(Parent(pCur));
			else
				NB(pCur)=NULL;
			pCur= Parent(pCur);
		}
		
		pCur = *pDel;
		if(Parent(pCur) != NULL ) // ketika node memiliki parent 
		{
			if(FS(Parent(pCur)) == *pDel) //kondisi node merupakan first son dari parentnya
			{
				FS(Parent(pCur))=FS(pCur);
				Parent(FS(pCur)) = Parent(pCur);
				nbDNode(&(*pDel));
			}else //kondisi node bukan merupakan first son (masih error)
			{
				pCur = FS(Parent(*pDel));
				while(NB(pCur) != *pDel) //pencarian node sebelum pDel
					pCur = NB(pCur);
				NB(pCur) = FS(*pDel);
				if(NB(*pDel) == NULL)
					NB(FS(*pDel)) = NULL;
				else
					NB(FS(*pDel)) = NB(*pDel);
				nbDNode(&(*pDel));
			}
			return;
		}
		else //kondisi ketika yang dihapus merupakan root
		{
			Root(*pTree) = FS(pCur)	;
			Parent(Root(*pTree)) = NULL;
			nbDNode(&(*pDel));
			return;
		}
	}	
}

void nbPrint(nbAddr node, char tab[]){
	char tempTab[255];
	strcpy(tempTab, tab);
	strcat(tempTab, "-");
	if (node!=NULL){
		printf("%s%d\n",tab,Info(node));
		nbPrint(FS(node),tempTab);
		nbPrint(NB(node),tab);
	}
}

