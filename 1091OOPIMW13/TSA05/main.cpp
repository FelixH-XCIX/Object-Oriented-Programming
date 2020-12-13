#include <iostream>
#include <string>
#include <vector>
#include <string.h> 
#include <sstream>

struct person {
    std::string name;
    std::string sympthom;
    std::string access;
    std::string travelHistory;
};

int main() {
    std::string command;//Access or List
    std::vector<person>record;

    while (std::cin >> command) {
        std::vector<std::string>tokens;

        if (command == "Access") {
            //For storing data
            std::string data;
            std::string spaces;
            std::getline(std::cin, data);


            std::stringstream input(data);
            std::string medium;

            //Tokenize input
            while (std::getline(input, medium, ' ')) {
                tokens.push_back(medium);
            }
            tokens.erase(tokens.begin());//erase spaces

            //process data
            //name
            record.push_back(person());
            record[record.size() - 1].name = tokens[0];
            tokens.erase(tokens.begin());

            //Travel History
            record[record.size() - 1].travelHistory = tokens[tokens.size() - 1];
            tokens.pop_back();

            //Sympthoms
            for (int i = 0; i < tokens.size(); i++) {
                record[record.size() - 1].sympthom.append(tokens[i]);
                //Add space
                if (i != tokens.size() - 1) {
                    record[record.size() - 1].sympthom.append(" ");
                }
            }

            //Deny List
            std::string sympthomList[5] = { "Fever","Fatigue","Dry cough","Shortness of breath","Chills" };
            std::string countryList[9] = { "China","USA","Italy","Spain","Germany","Iran","France","UK","Switzerland" };

            //check access
            int check1 = 1;
            int check2 = 1;
            for (int i = 0; i < 5; i++) {
                if (record[record.size() - 1].sympthom == sympthomList[i]) {
                    check1 = 0;
                    break;
                }
            }

            for (int i = 0; i < 9; i++) {
                if (record[record.size() - 1].travelHistory == countryList[i]) {
                    check2 = 0;
                    break;
                }
            }

            if (check1 == 1 && check2 == 1) {
                record[record.size() - 1].access = "Allowed";
                std::cout << record[record.size() - 1].name << " Access allowed." << std::endl;
            }
            else {
                record[record.size() - 1].access = "Denied";
                std::cout << record[record.size() - 1].name << " Access denied." << std::endl;
            }

        }
        else if (command == "List") {
            for (int i = 0; i < record.size(); i++) {
                std::cout << record[i].name << "\t" << record[i].sympthom << "\t" << record[i].travelHistory << "\t" << record[i].access << std::endl;
            }

        }
        //std::cout << std::endl;
    }
    std::cout << std::endl;
}