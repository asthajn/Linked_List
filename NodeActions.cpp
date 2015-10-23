#include <iostream>

using namespace std;

class Node{

	int data;
	Node* next;

	public:
		Node(){}

		void setData(int d){
			data = d;
		}

		void setNext(Node* anext){
			next = anext;
		}

		Node* Next(){
			return next;
		}
		int Data(){
			return data;
		}
};

class List{
	Node* head;
	Node* curr;

public:
	List(){head = NULL; curr = head ;};

	void addTolist(int data);
	void print();
	void deleteFromListBegin(int n);
	void deleteFromListEnd(int n);

};

void List::addTolist(int data){
	Node* newnode = new Node();

	newnode->setData(data);
	newnode->setNext(NULL);

	if(head == NULL){
		head = newnode;
		curr = head;
	}
	else{
		curr->setNext(newnode);
		curr = newnode;
	}

}

void List::print(){

	Node* tmp = head;

	do	{
		cout<<tmp->Data()<<"->";
		tmp = tmp->Next();
	}while (tmp!=NULL);

	cout<<"NULL\n";
}

void List::deleteFromListBegin(int n){

	Node* tmp = head;
	
	for (int i=0;i<n;i++){
		Node* tmp2 = tmp;
		tmp= tmp->Next();
		delete tmp2;
	}

	head = tmp;
}

void List::deleteFromListEnd(int n){
	Node* tmp = head;
	Node* tmp2= head;

	for(int i=0;tmp->Next()!=NULL;tmp = tmp->Next(),i++){

		if(i>=n)
			tmp2=tmp2->Next();
	}
	tmp = tmp2->Next();
	tmp2->setNext(NULL);

	while(tmp->Next()!=NULL){
		Node* tmp1 = tmp;
		tmp= tmp->Next();
		delete tmp1;
	}
}
int main(){

	int n=0 , i ,d;
	List list;

	cout << "Enter the number of nodes in the linked list";
	cin>>n;

	if(n<=0){
		cout<<"Enter a valid positive number";
		return 0;
	}

	for(i=0;i<n;i++){
		cin>>d;
		cout<<"Adding to the list "<<d<<"\n";
		list.addTolist(d);
	}

	list.print();
	list.deleteFromListBegin(2);
	list.print();
	list.addTolist(20);
	list.addTolist(3);
	list.addTolist(7);
	list.deleteFromListEnd(2);
	list.print();

	return 0;
}
