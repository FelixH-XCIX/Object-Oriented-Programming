#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <sstream>
#include <algorithm>

struct Course {
	std::string name;
	std::vector<std::string> times;
};


bool compFunc(std::string lhs, std::string rhs) {
	char day[5] = { 'M','T','W','R','F' };
	char period[9] = { '1','2','3','4','5','6','7','8','9' };//10th period

	int leftdayindex, rightdayindex;
	for (int i = 0; i < 5; i++) {
		if (lhs[0] == day[i]) {
			leftdayindex = i;
		}
		if (rhs[0] == day[i]) {
			rightdayindex = i;
		}
	}

	if (leftdayindex > rightdayindex) {
		return false;
	}
	else if (leftdayindex < rightdayindex) {
		return true;
	}

	if (lhs.size() == 3) {
		return false;
	}
	if (rhs.size() == 3) {
		return true;
	}
	//second index
	if (lhs[1] > rhs[1]) {
		return false;
	}
	else {
		return true;
	}
}

int main() {
	//Data structure
	std::map<std::string, std::vector<Course>> record;

	//vector to store order of the student
	std::vector<std::string>order;

	std::string command;
	while (std::cin >> command) {
		if (command == "AddStudent") {
			std::map<std::string, std::vector<Course>>::iterator it;

			//Get input
			std::string inputName;
			std::cin >> inputName;

			//find student name
			it = record.find(inputName);
			if (it != record.end()) {
				std::cout << "The student's name is duplicate." << std::endl;
			}
			else {
				record[inputName];
				order.push_back(inputName);
			}
		}
		else if (command == "AddCourse") {
			//Get input
			std::string inputName;
			std::string inputCourse;
			std::string classTime;

			std::cin >> inputName >> inputCourse;
			std::getline(std::cin, classTime);

			//erase space infront of classTime
			classTime.erase(classTime.begin());

			//check if student exist
			std::map<std::string, std::vector<Course>>::iterator it;
			it = record.find(inputName);
			if (it != record.end()) {
				//Read time
				std::string tempTime;
				std::stringstream ss(classTime);
				std::vector<std::string>timeVec;
				while (ss >> tempTime) {
					timeVec.push_back(tempTime);
				}

				int flag = 0;
				//check if class conflict or not
				for (int i = 0; i < record.find(inputName)->second.size(); i++) {
					for (int k = 0; k < record.find(inputName)->second[i].times.size(); k++) {
						for (int h = 0; h < timeVec.size(); h++) {
							if (timeVec[h] == record.find(inputName)->second[i].times[k]) {
								flag = 1;
								break;
							}
						}
					}
				}

				if (flag == 0) {
					struct Course course;
					course.name = inputCourse;
					for (int i = 0; i < timeVec.size(); i++) {
						course.times.push_back(timeVec[i]);
					}
					record[inputName].push_back(course);
				}
				else {
					std::cout << "Course conflict." << std::endl;
				}
			}
			else {
				std::cout << "The student's name does not exist." << std::endl;
			}
		}
		else if (command == "DelStudent") {
			std::string inputName;
			std::cin >> inputName;

			std::map<std::string, std::vector<Course>>::iterator it;

			it = record.find(inputName);
			//if not found
			if (it == record.end()) {
				std::cout << "The student's name does not exist." << std::endl;
			}
			else {
				record.erase(inputName);
				//order
				int pos = 0;
				for (int i = 0; i < order.size(); i++) {
					if (order[i] == inputName) {
						pos = i;
					}
				}
				order.erase(order.begin() + pos);
			}
		}
		else if (command == "DelCourse") {
			std::string inputName;
			std::string inputCourse;

			std::cin >> inputName >> inputCourse;

			int flag = 0;

			if (record.find(inputName) == record.end()) {
				std::cout << "The student's name does not exist." << std::endl;
			}
			else if (record.find(inputName)->second.size() == 0) {
				std::cout << "The course does not exist." << std::endl;
			}
			else {
				for (int i = 0; i < record.find(inputName)->second.size(); i++) {
					if (record.find(inputName)->second[i].name == inputCourse) {
						flag = 1;
						record.find(inputName)->second.erase(record.find(inputName)->second.begin() + i);
						break;
					}
				}
				if (flag == 0) {
					std::cout << "The course does not exist." << std::endl;
				}
			}


		}
		else if (command == "Print") {
			std::string inputName;
			std::string inputCourse;

			std::cin >> inputName;
			if (inputName == "StudentList") {

				if (!record.empty()) {
					if (record.size() == order.size()) {
						for (int i = 0; i < order.size(); i++) {
							std::cout << order[i] << std::endl;
						}
					}

				}
				else {
					std::cout << "The Students list is empty." << std::endl;
				}
			}
			else {
				std::getline(std::cin, inputCourse);
				if (inputCourse != "") {
					inputCourse.erase(inputCourse.begin());
				}

				std::map<std::string, std::vector<Course>>::iterator it;

				it = record.find(inputName);
				if (it == record.end()) {
					std::cout << "The student's name does not exist." << std::endl;
				}
				else {
					//empty
					if (inputCourse.empty()) {
						std::string starter[5] = { "M","T","W","R","F" };
						std::string ending[10] = { "1","2","3","4","5","6","7","8","9","10" };

						for (int i = 0; i < 5; i++) {
							std::cout << starter[i] << ":";
							for (int k = 0; k < 10; k++) {
								std::string fulltime = starter[i] + ending[k];
								for (int j = 0; j < record.find(inputName)->second.size(); j++) {
									for (int h = 0; h < record.find(inputName)->second[j].times.size(); h++) {
										if (record.find(inputName)->second[j].times[h] == fulltime) {
											std::cout << " " << ending[k] << ":" << record[inputName][j].name;
										}
									}
								}
							}
							std::cout << std::endl;
						}
					}
					//not empty
					else {
						//add sort here   record[inputName].size()
						int index = 0;
						for (int i = 0; i < record[inputName].size(); i++) {
							if (record[inputName][i].name == inputCourse) {
								index = i;
							}
						}
						std::sort(record[inputName][index].times.begin(), record[inputName][index].times.end(), compFunc);
						int flag = 0;
						//check if course exist
						for (int i = 0; i < record.find(inputName)->second.size(); i++) {
							if (inputCourse == record.find(inputName)->second[i].name) {
								flag = 1;
								std::cout << record.find(inputName)->second[i].name << " ";
								for (int j = 0; j < record.find(inputName)->second[i].times.size(); j++) {
									std::cout << record.find(inputName)->second[i].times[j];
									if (!(j == (record.find(inputName)->second[i].times.size() - 1))) {
										std::cout << " ";
									}
									else {
										std::cout << std::endl;
									}
								}
							}
						}
						if (flag == 0) {
							std::cout << "The course does not exist." << std::endl;
						}
					}
				}
			}
		}
	}
}