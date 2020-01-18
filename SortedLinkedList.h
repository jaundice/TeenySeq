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
namespace ByteFarm {
	namespace DataStructures {
		using namespace ByteFarm::DataStructures;
		template <class T>
		class SortComparer {

		public:

			virtual int Compare(T* a, T* b) = 0;


		};

		template <class T>
		class SortedLinkedList : public Collection<T> {
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

				virtual ~Enumerator() override {
					_curr = nullptr;
				}
			};


		public:
			virtual uint32_t GetCount() override {
				return count;
			}

			SortedLinkedList(SortComparer<T>* comparer) {
				Comparer = comparer;
			}


			virtual ByteFarm::DataStructures::Enumerator<T>* GetEnumerator() override {
				return new Enumerator(Head);
			}

			virtual void Remove(T* obj) override {

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

			virtual T* GetItemAtIndex(uint32_t index) override {
				if (index > GetCount()) {
					return NULL;
				}

				ByteFarm::DataStructures::Enumerator<T>* enu = GetEnumerator();

				for (uint32_t i = 0; i < index; i++) {
					enu->Next();
				}

				T* ret = enu->GetCurrent();

				delete enu;

				return ret;

			}

			virtual void Clear() override {
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

			virtual void Insert(T* obj) override {
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

			virtual ~SortedLinkedList() override {
				Clear();
			}
		};



	}
}
#endif

