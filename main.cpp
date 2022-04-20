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
	nbInsert(&pTree, nbSearch(Root(pTree), 9), 10);
	nbInsert(&pTree, nbSearch(Root(pTree), 10), 67);
	printf("Tree : \n");
	nbPrint(Root(pTree), str);
	printf("\nLevel pada data berisi 3: %d\n", getLevel(nbSearch(Root(pTree), 3)));
	printf("Degree dari data berisi 3 : %d\n", degree(nbSearch(Root(pTree), 3)));
	printf("Height pada data berisi 3: %d\n", getHeight(nbSearch(Root(pTree), 3), pTree));
	printf("Jumlah Level/depth pada tree : %d\n\n", nbNumLev(pTree));
	srcNode = nbSearch(Root(pTree), 9);
	nbDelete( &srcNode, &pTree);
	
	printf("Deletion pada node bernilai 9\n");
	nbPrint(Root(pTree), str);
	
	srcNode = nbSearch(Root(pTree), 67);
	nbDelete( &srcNode, &pTree);
	
	printf("Deletion pada node bernilai 67\n");
	nbPrint(Root(pTree), str);
	
	srcNode = nbSearch(Root(pTree), 3);
	nbDelete( &srcNode, &pTree);
	
	printf("Deletion pada root\n");
	nbPrint(Root(pTree), str);
	
	return 0;
}
