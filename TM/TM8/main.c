#include "header.h"

int main()
{
    tree T;
    // input
    char arr[14];
    for (int i = 0; i < 14; i++)
    {
        scanf(" %c", &arr[i]);
    }
    
    // instruksi
    makeTree(arr[0], &T);
    addLeft(arr[1], T.root);
	addRight(arr[2],T.root);
	addLeft(arr[3],T.root->right);
	addRight(arr[4],T.root->left);
	addRight(arr[5],T.root->right);
	addLeft(arr[6],T.root->left->right);
	addRight(arr[7],T.root->right->left);
	addRight(arr[8],T.root->left->right);
	addRight(arr[9],T.root->right->right);
	addLeft(arr[10],T.root->right->right);
	addLeft(arr[11],T.root->left->right->left);
	addLeft(arr[12],T.root->right->left->right);
	addRight(arr[13],T.root->right->left->right);
    // output secara pre order
	printf("Pre Order:\n");
    printTreePreOrder(T.root); 

	delLeft(T.root->left->right->left);//L Hilang
	// output secara in order
    printf("\nIn Order:\n");
    printTreeInOrder(T.root); 

	delRight(T.root->right->right);//J Terhapus 
	// output secara post order
    printf("\nPost Order:\n");
    printTreePostOrder(T.root); 
    printf("\n");

    return 0;
}
