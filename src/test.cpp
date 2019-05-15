//
// Created by mard on 5/12/19.
//

#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <queue>

#include <mardcpp/utils/ios.h>



int main() {
	mardcpp::OutputStream cout(std::cout);

	std::default_random_engine gen(42);

	int V = 10;
	float conectivity = 0.5;

	std::vector<std::vector<int>> vertexes(V, std::vector<int>(V, -1));

	std::uniform_int_distribution<int> costDist(1, 20);
	std::uniform_int_distribution<int> conDist(1, 100);
	auto costr = [&](){ return costDist(gen); };
	auto con = [&](){ return conDist(gen); };

	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < V; ++j) {
			if (i == j or con() <= (conectivity * 100)) {
				vertexes[i][j] = costr();
			}
		}
	}


	using Node = std::pair<int,int>;

	std::vector<Node> G[V];
	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < V; ++j) {
			if (vertexes[i][j] >= 1) {
				G[i].emplace_back(vertexes[i][j], j);
			}
		}
	}

	using Container = std::vector<Node>;
	using PriorityQueue = std::priority_queue<Node, Container, std::greater<>>;

	Container container; container.reserve(V*V);
	PriorityQueue queue(std::greater<>(), std::move(container));

	std::vector<char> open(V, true);
	open[0] = false;
	for (const auto&[cost, out]: G[0]) {
		if (open[out]) {
			queue.emplace(cost, out);
		}
	}




	for (int i = 0, j = 0; i < V; ++i) {
		for (j = 0; j < V - 1; ++j) {
			cout << std::setw(4) << vertexes[i][j] << ' ';
		}
		cout << std::setw(4) << vertexes[i][j] << '\n';
	}

	std::ofstream g("graph.gv");
	mardcpp::OutputStream osg(g);

	osg << "digraph {\n";

	if (g.is_open()) {

		while (not queue.empty()) {
			const auto&[_, curr] = queue.top(); queue.pop();

			for (const auto&[cost, out] : G[curr]) {
				if (open[out]) {

					osg << '\t' << (char)('a' + curr) << " -> " << (char)('a' + out) << ";\n";

					open[out] = false;
					queue.emplace(cost, out);
				}
			}
		}


	}

	osg << "}\n";


	return 0;
}