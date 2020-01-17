// SortedLinkedList.h

#ifndef _SORTEDLINKEDLIST_h
#define _SORTEDLINKEDLIST_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include "Enumerator.h"
namespace ByteFarm {
	namespace DataStructures {

		template <class T>
		class SortComparer {

		public:

			virtual int Compare(T* a, T* b) = 0;


		};

		template <class T>
		class SortedLinkedList {
			class Node {

			public:
				T* Value = nullptr;
				Node* Next = nullptr;

				~Node() {
					delete this->Value;
				};
			};

			Node* Head = nullptr;
			uint32_t count = 0;


			SortComparer<T>* Comparer;


		public:
			uint32_t GetCount() {
				return count;
			}

			SortedLinkedList(SortComparer<T>* comparer) {
				Comparer = comparer;
			}

			class Enumerator : public ByteFarm::DataStructures::Enumerator<T> {
				Node* _curr = nullptr;


			public:
				virtual T* GetCurrent() override {
					return (_curr) ? _curr->Value : NULL;
				};

				virtual bool Next() override {
					if ((_curr->Next)) {
						_curr = _curr->Next;
						return true;
					}
					else {
						_curr = nullptr;
					}
					return false;
				}
				Enumerator(Node* root) {
					_curr = root;
				};

				virtual ~Enumerator() {
					_curr = nullptr;
				}
			};

			Enumerator* GetEnumerator() {
				return new Enumerator(Head);
			}

			void Remove(T* obj) {

				if (Head->Value == obj) {
					Node* n = Head;
					Head = n->Next;
					n->Next = nullptr;
					delete n;
					count--;
				}
				else {

					Node* prev = nullptr;
					Node* curr = nullptr;

					for (curr = Head; curr != nullptr && curr->Value != obj; curr = curr->Next) {
						prev = curr;
					}

					if (curr != nullptr && curr->Value == obj) {
						prev->Next = curr->Next;
						curr->Next = nullptr;
						delete curr;
						count--;
					}
				}
			}

			T* GetItemAtIndex(int index) {
				if (index > GetCount()) {
					return NULL;
				}

				Enumerator* enu = GetEnumerator();

				for (int i = 0; i < index; i++) {
					enu->Next();
				}

				T* ret = enu->Current();

				delete enu;

				return ret;

			}

			void Clear() {
				Node* c = Head;
				Head = nullptr;

				while (c != nullptr) {
					Node* n = c->Next;
					c->Next = nullptr;
					delete c;
					c = n;
				}

				count = 0;
			}

			void Insert(T* obj) {
				Node* node = new Node();
				node->Value = obj;
				if (!(Head)) {
					Head = node;
				}
				else {
					Node* prev = nullptr;

					int16_t i = 0;
					for (Node* curr = Head; (curr); i++, curr = curr->Next) {

						if (Comparer->Compare(node->Value, curr->Value) < 1) {
							if (Head == curr) {
								//Serial.println(F("replacing head"));
								Head = node;
								node->Next = curr;
								break;
							}
							else {
								prev->Next = node;
								node->Next = curr;
								break;
							}
						}

						prev = curr;
					}
					if ((prev) && !(prev->Next)) {
						prev->Next = node;
					}

				}
				count++;
			}
		};



	}
}
#endif

