#include <conio.h>
#include <windows.h>

#include "nbtree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	nbTree pTree;
	nbAddr srcNode;
	nbCreate(&pTree);
	char str[]="";
	
	nbInsert(&pTree, NULL, 3);
	nbInsert(&pTree, nbSearch(Root(pTree), 3), 7);
	nbInsert(&pTree, nbSearch(Root(pTree), 3), 2);
	nbInsert(&pTree, nbSearch(Root(pTree), 3), 1);
	
	nbInsert(&pTree, nbSearch(Root(pTree), 7), 8);
	nbInsert(&pTree, nbSearch(Root(pTree), 7), 9);
	nbInsert(&pTree, nbSearch(Root(pTree), 7), 6);
	
	nbInsert(&pTree, nbSearch(Root(pTree), 9), 0);
	nbPrint(Root(pTree), str);
	printf("\n\n\n");
	
	srcNode = nbSearch(Root(pTree), 9);
	nbDelete( &srcNode, &pTree);
	
	nbPrint(Root(pTree), str);
	
	return 0;
}
