// SortedLinkedList.h

#ifndef _SORTEDLINKEDLIST_h
#define _SORTEDLINKEDLIST_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include "Enumerator.h"
#include "Collection.h"

namespace ByteFarm
{
	namespace DataStructures
	{
		using namespace DataStructures;

		template <class T>
		class SortComparer
		{
		public:
			virtual int Compare(T* a, T* b) = 0;
		};

		template <class T>
		class Node
		{
		public:
			T* Value = nullptr;
			Node* Next = nullptr;

			~Node();;
		};

		template <class T>
		Node<T>::~Node()
		{
			delete this->Value;
		}

		template <class T>
		class LinkedList : public Collection<T>
		{
		protected:


			Node<T>* Head = nullptr;
			uint32_t count = 0;


			class Enumerator : public DataStructures::Enumerator<T>
			{
				Node<T>* _curr = nullptr;
			public:
				T* GetCurrent() override;

				bool Next() override;

				Enumerator(Node<T>* root);

				~Enumerator() override;
			};


		public:

			LinkedList();

			uint32_t GetCount() override
			{
				return count;
			}

			DataStructures::Enumerator<T>* GetEnumerator() override;

			void Remove(T* obj) override;;


			T* GetItemAtIndex(uint32_t index) override
			{
				if (index > GetCount())
				{
					return nullptr;
				}

				DataStructures::Enumerator<T>* enu = GetEnumerator();

				for (uint32_t i = 0; i < index; i++)
				{
					enu->Next();
				}

				T* ret = enu->GetCurrent();

				delete enu;

				return ret;
			};

			void Insert(T* obj) override;

			void Clear() override;

			~LinkedList() override;
		};


		template <class T>
		T* LinkedList<T>::Enumerator::GetCurrent()
		{
			return (_curr) ? _curr->Value : NULL;
		}

		template <class T>
		bool LinkedList<T>::Enumerator::Next()
		{
			if ((_curr->Next))
			{
				_curr = _curr->Next;
				return true;
			}
			_curr = nullptr;
			return false;
		}

		template <class T>
		LinkedList<T>::Enumerator::Enumerator(Node<T>* root)
		{
			_curr = root;
		}

		template <class T>
		LinkedList<T>::Enumerator::~Enumerator()
		{
			_curr = nullptr;
		}

		template <class T>
		LinkedList<T>::LinkedList()
		{
		}

		template <class T>
		Enumerator<T>* LinkedList<T>::GetEnumerator()
		{
			return new Enumerator(Head);
		}

		template <class T>
		void LinkedList<T>::Remove(T* obj)
		{
			if (Head->Value == obj)
			{
				Node<T>* n = Head;
				Head = n->Next;
				n->Next = nullptr;
				delete n;
				count--;
			}
			else
			{
				Node<T>* prev = nullptr;
				Node<T>* curr = nullptr;

				for (curr = Head; curr != nullptr && curr->Value != obj; curr = curr->Next)
				{
					prev = curr;
				}

				if (curr != nullptr && curr->Value == obj)
				{
					prev->Next = curr->Next;
					curr->Next = nullptr;
					delete curr;
					count--;
				}
			}
		}

		template <class T>
		void LinkedList<T>::Insert(T* obj)
		{
			Node<T>* node = new Node<T>();
			node->Value = obj;
			if (!(Head))
			{
				Head = node;
			}
			else
			{
				Node<T>* prev = nullptr;
				int16_t i = 0;
				for (Node<T>* curr = Head; (curr); i++, curr = curr->Next)
				{
					prev = curr;
				}


				if ((prev) && !(prev->Next))
				{
					prev->Next = node;
				}
			}
			count++;
		}

		template <class T>
		void LinkedList<T>::Clear()
		{
			Node<T>* c = Head;
			Head = nullptr;

			while (c != nullptr)
			{
				Node<T>* n = c->Next;
				c->Next = nullptr;
				delete c;
				c = n;
			}

			count = 0;
		}

		template <class T>
		LinkedList<T>::~LinkedList()
		{
			Clear();
		}

		template <class T>
		class SortedLinkedList : public LinkedList<T>
		{
			SortComparer<T>* Comparer;


		public:
			SortedLinkedList(SortComparer<T>* comparer);

			void Insert(T* obj) override;

			~SortedLinkedList() override;
		};

		template <class T>
		SortedLinkedList<T>::SortedLinkedList(SortComparer<T>* comparer)
		{
			Comparer = comparer;
		}

		template <class T>
		void SortedLinkedList<T>::Insert(T* obj)
		{
			Node<T>* node = new Node<T>();
			node->Value = obj;
			if (!(this->Head))
			{
				this->Head = node;
			}
			else
			{
				Node<T>* prev = nullptr;

				int16_t i = 0;
				for (Node<T>* curr = this->Head; (curr); i++, curr = curr->Next)
				{
					if (Comparer->Compare(node->Value, curr->Value) < 1)
					{
						if (this->Head == curr)
						{
							//Serial.println(F("replacing head"));
							this->Head = node;
							node->Next = curr;
							break;
						}
						prev->Next = node;
						node->Next = curr;
						break;
					}

					prev = curr;
				}
				if ((prev) && !(prev->Next))
				{
					prev->Next = node;
				}
			}
			++this->count;
		}

		template <class T>
		SortedLinkedList<T>::~SortedLinkedList()
		{
			this->Clear();
		}
	}
}

#endif
