//
// Created by mard on 4/28/19.
//

#pragma once

#include <mardcpp/collections/def.hpp>

namespace mardCpp {

	template<typename tType>
	class LinkedList {
		struct Node {
			tType val;
			Node *next;

			Node(tType val)
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

			tType& operator*() {
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

		void add(tType val) {
			Node *node = new Node(val);
			if (first) {
				node->next = first;
				first = node;
			} else {
				first = last = node;
			}
			++size;
		}

		void addBack(tType val) {
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

