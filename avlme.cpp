#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
	int ht;
}node;

int height(node * T)
{
	int lh,rh;
	if(T==NULL)
		return(0);
	
	if(T->left == NULL)
		lh = 0;
	else
		lh = 1 + T->left->ht;
		
	if(T->right == NULL)
		rh = 0;
	else
		rh = 1 + T->right->ht;
		
	if(lh>rh)
		return (lh);
	return(rh);	 
}

int BF(node * T)
{
	int lh,rh;
	if(T==NULL)
		return(0);
	
	if(T->left == NULL)
		lh = 0;
	else
		lh = 1 + T->left->ht;
		
	if(T->right == NULL)
		rh = 0;
	else
		rh = 1 + T->right->ht;
	
	return(lh-rh);	 
}
node *rotateright(node *T)
{
	node *temp;
	temp = T->left;
	T->left = temp->right;
	temp->right = T;
	T->ht = height(T);
	temp->ht = height(temp);
	return(temp);
}
node *rotateleft(node *T)
{
	node *temp;
	temp = T->right;
	T->right = temp->left;
	temp->left = T;
	T->ht = height(T);
	temp->ht = height(temp);
	return(temp);
}

node *LL(node *T)
{
	T = rotateright(T);
	return(T);
}
node *LR(node *T)
{
	T->left = rotateleft(T->left);
	T = rotateright(T);
	return(T);
}
node *RR(node *T)
{
	T = rotateleft(T);
	return(T);
}
node *RL(node *T)
{
	T->right = rotateright(T->right);
	T = rotateleft(T);
	return(T);
}


node * insert(node * T,int key)
{
	if(T == NULL)
	{
		T = (node*)malloc(sizeof(node));
		T->data = key;
		T->right = NULL;
		T->left = NULL;
	}
		else
			if(key < T->data)
			{
			T->left = insert(T->left,key);
			if(BF(T)==2)
				if(key < T->left->data)
					T = LL(T);
				else
				T = LR(T);
			}
    	else
			if(key > T->data)
			{
			T->right = insert(T->right,key);
			if(BF(T)==-2)
				if(key > T->right->data)
					T = RR(T);
				else
				T = RL(T);
			}
		
	T->ht = height(T);
	return(T);
}


node * delet(node *T,int key)
{
	node *temp;
	if(T==NULL)
		return NULL;
	if(key > T->data)
	{
		 T->right=delet(T->right,key);
            if(BF(T)==2)
                if(BF(T->left)>=0)
                    T=LL(T);
                else
                    T=LR(T);
	}
	
	if(key < T->data)
	{
		T->right = delet(T->right,key);
			if(BF(T) == -2)
				if(BF(T->right) <= 0)
					T = RR(T);
			else
				T = LR(T);
	}
	
	else
	{
		if(T->right!=NULL)
		{
			temp = T->right;
			while(temp->left != NULL)
				temp = temp->left;
			
			T->data = temp->data;
			T->right = delet(T->right,temp->data);
			
			if(BF(T) == 2)
				if(BF(T->left) >= 0)
					T = LL(T);
				else
					T = LR(T);
		}
		else
			return(T->left);
	}
	T->ht = height(T);
	return(T);
}

void inorder(node *T)
{
    if(T!=NULL)
    {
       inorder(T->left);
        printf("%d(Bf=%d)",T->data,BF(T));
        inorder(T->right);
    }
    else 
    	return;
}

int main()
{
	node *root = NULL;
	int i,n;
	root = NULL;
	for(i=0;i<5;i++)
	{
		scanf("%d",&n);
		root = insert(root,n);
	}
	inorder(root);
	
	printf("Delete :");
	scanf("%d",&n);
	root = delet(root,n);
	inorder(root);
}

