//链式队列为 CircleQueue

template<class T>
bool CircleQueue<T>::EnQueue(T x){
	if(p==NULL) p= new QueueNode(x);
	else{
		QueueNode<T>* temp = new QueueNode<T>(x);
		p->link = temp;
		p = temp;
	}
	return true;
}

template<class T>
bool CircleQueue<T>::DeQueue(T x){
	if(p==NULL) return false;
	else{
		QueueNode<T>* del = front;
		front = del->link;
		delete del;
		return true;
	}
}