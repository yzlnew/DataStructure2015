template <class T>
LinkNode<T> *List<T>::Locate(int i){
	LinkNode<T> *current = first;
	if(i==0) return first;
	else if(i>0){
		int k=0;
		while(current!=NULL&&k<i){current=current->link;k++;}
		return current;
	}
	else return NULL;
};

template<class T>
LinkNode<T> *List<T>::Max(){
	if(first->link=NULL) return NULL;
	else{
		LinkNode<T> *current = first->link;
		LinkNode<T> *max = current;
		while(current!=NULL){
			if(current->data>max->data) max=current;
			current=current->link;
		}
		return max;
	}
};

template<class T>
int List<T>::Number(T x){
	int number=0;
	LinkNode *current=first->link;
	while(current!=NULL){
		if(current->data==x) number++;
		current=current->link;
	}
	return number;
};

template<class T>
bool List<T>::Create(T a[],int n){
	LinkNode *newNode;
	makeEmpty();
	for(int i=0;i<n;i++){
		newNode=new LinkNode<T>(a[n-i]);
		newNode->link=first->link;
		first->link=newNode;
	}
	return 1;
};

template<class T>
bool List<T>::Tidyup(){
	LinkNode *current=first->link,*del;
	while(current!=NULL&&current->link!=NULL){
		if(current->data==current->link->data){
			del=current->link;
			current->link=del->link;
			delete del;
		}
		else current=current->link;
	}
	return 1;
};
