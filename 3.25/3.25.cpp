//链式队列为 CircleQueue

template<class T>
bool CircleQueue<T>::EnQueue(T x){
	if(p==NULL) p= new QueueNode(x);
	else{
		QueueNode<T>* temp = new QueueNode<T>(x);
		temp->link=p->link;
		p->link = temp;
		p = temp;
	}
	return true;
}

template<class T>
bool CircleQueue<T>::DeQueue(T x){
	if(p==NULL) return false;
	else{
		QueueNode<T>* del = p->link;
		p = del->link;
		x=del->data;
		delete del;
		return true;
	}
}