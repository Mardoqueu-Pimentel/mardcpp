//
// Created by mard on 4/28/19.
//

#ifndef MARDCPP_LINKEDLIST_H
#define MARDCPP_LINKEDLIST_H

#include <utility>
#include <cassert>

#include "../mardcpp.h"

namespace mardcpp {

	template<typename T>
	class LinkedList {
		struct Node {
			T val;
			Node *next;

			Node(T val)
			: val(val) {}
		};

		struct Iter {
			Node *node;

			Iter(Node *node)
			: node(node) {}

			Iter& operator++() {
				assert(node != nullptr && "Iter out of bounds");
				node = node->next;
				return *this;
			}

			bool operator!=(const Iter& iter) {
				return node != iter.node;
			}

			T& operator*() {
				assert(node != nullptr && "Iter out of bounds");
				return node->val;
			}
		};

		Node *first, *last;
		Size size;

	public:
		LinkedList()
		: first(nullptr), last(nullptr), size(0) {}

		~LinkedList() {
			Node *curr = first, *prev;
			while(curr) {
				prev = curr;
				curr = curr->next;
				delete prev;
			}
		}

		void add(T val) {
			Node *node = new Node(val);
			if (first) {
				node->next = first;
				first = node;
			} else {
				first = last = node;
			}
			++size;
		}

		void addBack(T val) {
			Node *node = new Node(val);
			if (first) {
				last->next = node;
				last = node;
			} else {
				first = last = node;
			}
			++size;
		}

		void remove() {
			Node *node = first;
			first = first->next;
			delete first;
		}

		bool isEmpty() {
			return size == 0;
		}

		Iter begin() {
			return Iter(first);
		}

		Iter end() {
			return Iter(last->next);
		}
	};
}

#endif //MARDCPP_LINKEDLIST_H
