#include "contacts_header.h"


//Linked list template
namespace linke_list {
	template<class T>
	class node {

	public:

		node();
		//~node();

		node(node &copy);

		void setPNext(node* next);
		void setData(T dat);


		T getData();
		node* getPNext();


	private:
		node *pNext;
		T data;


	};

	template<class T>
	class  linked_list {

	public:
		linked_list();

		void set_pTop(node<T> *n);

		node < T >* get_pTop();

		void add_at_end(node<T> *n);

		//void add_at_end_V2(node<T> *n);

		node<T>* makeNode(T n);


		node<T> *pTop;

		

	private:


	};





	//------------Node-----------------------------

	template <class T>
	void node<T>::setPNext(node<T>* next) {
		this->pNext = next;

	}

	template <class T>
	node<T>::node(node<T> &copy) {
		this->setData(copy->getData());

	}


	template<class T>
	void node<T>::setData(T dat) {
		this->data = dat;
		//this->pNext = nullptr;
	}

	template <class T>
	T node<T>::getData() {
		return data;
	}

	template <class T>
	node<T>* node<T>::getPNext() {
		return pNext;
	}
	template <class T>
	node<T>::node() {

		pNext = nullptr;
	}
	//-----------------------------------------------------------------


	//-------linked_list----------------------
	template <class T>
	linked_list<T>::linked_list() {

		this->pTop = nullptr;

	}

	template <class T>
	void linked_list<T>::set_pTop(node<T> *n) {
		pTop = n;

	}

	template <class T>
	node < T >* linked_list<T>::get_pTop() {
		return pTop;
	}

	template <class T>
	void linked_list<T>::add_at_end(node<T> *n) {
		node<T> *pCur = nullptr;

		pCur = pTop;
		if (pCur != nullptr) {
			while (pCur->getPNext() != nullptr) {
				pCur = pCur->getPNext();
			}
			pCur->setPNext(n);
		}
		else {
			pTop = n;
		}
	}

	template <class T>
	node<T>* linked_list<T>::makeNode(T n) {
		node<T> *pNew = nullptr;

		pNew = new (node<T>);

		pNew->setData(n);

		return pNew;

	}

}
