#include <iostream>

using namespace std;

class Node{

public:
	int data;
	Node *next = NULL;

	public:
		Node(){
		}
		Node(int d) {
		data = d;
	}

	void addToList(Node curr){
		//cout<<"Data : "<<d<<endl;
		curr.next = this;
		//curr = this;
		//return curr;
	}
};

int main(){

	int n=0 , i ,d;

	cout << "Enter the number of nodes in the linked list";
	cin>>n;

	if(n<=0){
		cout<<"Enter a valid positive number";
		return 0;
	}

	cin>>d;
	Node head(d);

	Node curr(d);
	curr = head;
	//head.addToList(curr);

	//head.addToList(d);

	for (i=0; i<n-1 ; i++){
		cin>>d;
		Node obj(d);
		//obj.addToList(curr);
		curr.next = obj;
		curr = obj;
		if(i==0)
			head.next = obj.next;
	}
	Node ptr;
	ptr = head;

	while(ptr.next != NULL){
		cout<<ptr.data<<" --> ";
	}



	return 0;
}
