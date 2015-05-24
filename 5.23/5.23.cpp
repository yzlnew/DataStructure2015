template<class T>
int leavescount(BinTreeNode<T> *t) const{
	if(t==NULL) return 0;		//t为空，返回0
	if(t->leftChild==NULL&&t->rightChild==NULL) return 1;		//t的左子树和右子树都为空，返回1
	else
		return leavescount(t->leftChild)+leavescount(t->rightChild);	//递归
}

template<class T>
void exchange(BinTreeNode<T> *t){
	BinTreeNode<T> *temp;	//交换时用来存储的临时变量
	if(t->leftChild!=NULL||t->rightChild!=NULL){
		temp=t->rightChild;
		t->rightChild=t->leftChild;
		t->leftChild=temp;
		exchange(t->leftChild);			//对左右子树递归
		exchange(t->rightChild);
	}
}