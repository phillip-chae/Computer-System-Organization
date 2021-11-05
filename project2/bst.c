#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

//Author: Phillip Chae
//Purpose: Implement a few functions to be used for the BST structure such as: Insert, inorder traversal print, remove the largest string, and remove the smallest string

void add ( bst_node ** root, char * word ) {
	//When new node is reached, make one and assign values to its variables
	if (*root == NULL){
      //Allocate memory for the new structure
		*root = malloc(sizeof(bst_node));
		(*root)->data = word;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	//See if the string should go left or right from this node by comparing with the node it is at
	if(strcmp(word,(*root)->data) < 0)
		add(&((*root)->left), word);
	if(strcmp(word,(*root)->data) > 0)
		add(&((*root)->right), word);
}

//Simple inorder left -> root -> right recursion 
void inorder ( bst_node * root ) {
	if(root != NULL){
      //Traverse left
		inorder(root->left);
      //Print the root data
		printf("%s ", root->data);
      //Traverse right
		inorder(root->right);
	}    
}

//Removes the smallest string the tree contains  
char * removeSmallest (bst_node ** root ){
	if(*root == NULL) return NULL;
	//Keep recursing to the left node if there are any because that is where the smallest string is located in a tree
	if((*root)->left!=NULL)
      return removeSmallest(&((*root)->left));
   else{
      //Store the node data so that it is not deleted while tree arrangement
      char * temp = (*root)->data;
      //If there is a right node, it is now at the location of its parent
      if((*root)->right!=NULL)
         *root = (*root)->right;
      //If not, delete node
      else
         *root = NULL;
         return temp;
      }
	   return NULL;
}

//Removes the largest string the tree contains 
char * removeLargest (bst_node ** root ){
	if(*root == NULL) return NULL;
	//Keeps going to the rightmost node as its the node with the biggest value
	if((*root)->right!=NULL)
      return removeLargest(&((*root)->right));
   else{
      //Store the node data so that it is not deleted while tree arrangement
      char * temp = (*root)->data;
      //If there is a left node, it is now at the location of its parent
      if((*root)->left!=NULL)
         *root = (*root)->left;
      //If not, delete node
      else   
         *root = NULL;
      return temp;
   }
	return NULL;  
}