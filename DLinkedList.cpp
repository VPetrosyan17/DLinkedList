#include <iostream>

template<typename T>

struct Node{
	T data;
	Node<T>* prev;
	Node<T>* next;
	Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

template<typename T>
class DLinkedList{
	public:
	DLinkedList() : head(nullptr), tail(nullptr) {}

	//insert element to the list
	void insert(T value){
	Node<T>* newNode = new Node(value);
	if(head == nullptr){
		head = newNode;
	}

	}
	
	//adding node to the end of the list
	void append(T value){
		Node<T>* newNode = new Node(value);
		if(head == nullptr){
			head = newNode;
			tail = newNode;
		}else{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}
	
	//adding node to the front of the list
	void prepend(T value){
		Node<T>* newNode = new Node(value);
		if(head == nullptr){
			head = newNode;
			tail = newNode;
		}else{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}

	//insert node at given position
	void insert(T value, int pos){
		Node<T>* newNode = new Node(value);
		if(pos == 0){
			prepend(value);
		}else{
			Node<T>* curr = head;
			int currPos = 0;
			while(curr && currPos < pos){
				curr = curr->next;
				currPos++;
			}
			if(currPos == pos){
				newNode->next = curr->next;
				newNode->next = curr;
				if(curr->prev){
					curr->prev->next = newNode;
				}else{
					head = newNode;
				}

				curr->prev = newNode;
			}else{
				append(value);
			}
		}
	}
	
	//remove node
	void remove(T value){
		Node<T>* curr = head;
		while(curr != nullptr){
			if(curr->data == value){
				if(curr->prev != nullptr){
					curr->prev->next = curr->next;
				}else{
					head = curr->next;
				}
				if(curr->next != nullptr){
					curr->next->prev = curr->prev;
				}else{
					tail = curr->prev;
				}
				delete curr;
			}
			curr = curr->next;
		}
	}

	//displaying node
	void display(){
		Node<T>* curr = head;
		while(curr != nullptr){
			std::cout << curr->data << " ";
			curr = curr->next;
		}
	}
	private:
	Node<T>* head;
	Node<T>* tail;
};

int main(){
	DLinkedList<int> list;

	std::cout << "The elements of list: ";
	
	list.append(1);
	list.append(2);
	list.append(3);
	list.prepend(4);

	list.display();

  	std::cout << std::endl;

	std::cout << "The elements of list: ";

	list.remove(2);
	list.insert(10, 2);

	list.display();
	std::cout << std::endl;
}
