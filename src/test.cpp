//
// Created by mard on 5/12/19.
//

/*

using mardcpp::u32;

using Row = std::vector<int>;
using Mat = std::vector<Row>;

Mat matMul(const Mat &m1, const Mat &m2) {
	Mat result(m1.size(), Row(m2[0].size(), 0));

	#pragma omp parallel for
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[0].size(); ++j) {
			int sum = 0;
			#pragma omp simd
			for (int k = 0; k < m2.size(); ++k) {
				sum += m1[i][k] * m2[k][j];
			}
			result[i][j] = sum;
		}
	}

	return result;
}*/

int main(int argc, char const *argv[]) {

/*	mardcpp::Arguments arguments(argc, argv);
	cout << arguments << '\n';
	auto N = arguments.getOrDefault("N", 2);
	int mal = N, mac = N, mbc = N;

	Mat ma(mal, Row(mac, 0)), mb(mac, Row(mbc, 0));
	for (int i = 0; i < ma.size(); ++i) {
		for (int j = 0; j < ma[0].size(); ++j) {
			ma[i][j] = Rand::get(0, 9);
		}
	}
	for (int i = 0; i < mb.size(); ++i) {
		for (int j = 0; j < mb[0].size(); ++j) {
			mb[i][j] = Rand::get(0, 9);
		}
	}

	cout << ma << "\n\n";
	cout << mb << "\n\n";

	Mat result;
	mardcpp::time::Time time;
	{
		mardcpp::time::Timer timer(time);
		result = matMul(ma, mb);
	}

	cout << "Time: " << time << "\n\n";*/

	return 0;
}