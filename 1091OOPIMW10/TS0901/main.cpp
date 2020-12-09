#include <iostream>
#include <string>
#include <vector>

int main() {
	//m is number of pairs
	//n is number of translation
	int m, n;

	while (std::cin >> m >> n) {
		//Conditions to break
		if (m == 0 && n == 0) {
			break;
		}
		else if (m > 500 && m < 1 || n > 50 && n < 1) {
			break;
		}

		std::vector<char>lhs;
		std::vector<char>rhs;

		//store translation
		char left, right;
		for (int i = 0; i < m; i++) {
			std::cin >> left >> right;
			lhs.push_back(left);
			rhs.push_back(right);
		}
		for (int i = 0; i < rhs.size(); i++) {
			for (int k = 0; k < lhs.size(); k++) {
				if (rhs[i] == lhs[k]) {
					bool check = 1;
					for (int h = 0; h < lhs.size(); h++) {
						if (rhs[h] == rhs[k] && lhs[h] == lhs[i]) {
							check = 0;
							break;
						}
					}
					if (check == 1) {
						lhs.push_back(lhs[i]);
						rhs.push_back(rhs[k]);
					}
				}
			}
		}


		//start translation
		std::string lhsInput, rhsInput;
		for (int i = 0; i < n; i++) {
			std::cin >> lhsInput >> rhsInput;
			//check
			if (lhsInput.size() != rhsInput.size()) {
				std::cout << "no" << std::endl;
			}
			else {
				for (int i = 0; i < lhs.size(); i++) {
					for (int k = 0; k < lhsInput.size(); k++) {
						if (lhs[i] == lhsInput[k] && rhsInput[k] == rhs[i]) {
							lhsInput[k] = rhs[i];
						}
					}
				}
				int flag = 1;
				for (int j = 0; j < lhsInput.size(); j++) {
					if (lhsInput[j] != rhsInput[j]) {
						flag = 0;
					}
				}
				if (flag == 1) {
					std::cout << "yes" << std::endl;
				}
				else {
					std::cout << "no" << std::endl;
				}
			}
		}
	}
}