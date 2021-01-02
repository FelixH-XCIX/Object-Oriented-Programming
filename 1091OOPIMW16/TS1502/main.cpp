#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <utility>


using namespace std;

typedef pair<string, string>book_info;
typedef map<book_info, set<int>> Books;
Books database;

void insert(book_info b_info, int version) {
    if (database.count(b_info) && database[b_info].count(version)) {
        cout << "Datum already exist." << endl;
    }
    else {
        cout << "Insert " << b_info.second << "'s " << b_info.first << ", Edition: " << version << "." << endl;
        database[b_info].insert(version);
    }
}

void deleteEdition(book_info b_info, int version) {
    if (database.count(b_info)) {
        set<int>::iterator it;
        it = database[b_info].find(version);
        if (it != database[b_info].end()) {
            cout << "Delete " << b_info.second << "'s " << b_info.first << ", Edition: " << version << "." << endl;
            database[b_info].erase(it);
        }
        else {
            cout << "Datum doesn't exist." << endl;
        }
    }
    else {
        cout << "Datum doesn't exist." << endl;
    }
}

void deleteBook(book_info b_info) {
    Books::iterator it;
    it = database.find(b_info);
    if (it != database.end()) {
        cout << "Delete " << b_info.second << "'s " << b_info.first << "." << endl;
        database.erase(it);
    }
    else {
        cout << "Book doesn't exist." << endl;
    }
}

void findBook(book_info b_info) {
    if (database.count(b_info)) {
        set<int>::iterator it = database[b_info].begin();
        cout << "Title: " << b_info.first << "\tAuthor: " << b_info.second << "\tEdition:";
        for (; it != database[b_info].end(); it++) {
            if (it == database[b_info].begin())
                cout << " " << *it;
            else
                cout << ", " << *it;
        }
        cout << endl;
    }
    else
        cout << "Book doesn't exist." << endl;
}

void findAuthor(string author) {
    Books::iterator it;
    int count = 0;
    it = database.begin();
    for (; it != database.end(); it++) {
        if (it->first.second == author) {
            if (count == 0) {
                cout << author << "'s Books: " << it->first.first;
            }
            else {
                cout << ", " << it->first.first;
            }
            ++count;
        }
    }
    if (!count)
        cout << "No book found.";
    cout << endl;
}

struct titleComp {
    bool operator()(const book_info& k1, const book_info& k2) const {
        if (k1.first != k2.first)
            return k1.first < k2.first;
        else
            return k1.second < k2.second;
    }
};


void listByTitle() {
    map<book_info, set<int>, titleComp> temp;
    Books::iterator it;
    it = database.begin();
    for (; it != database.end(); it++) {
        temp[it->first] = it->second;
    }
    it = temp.begin();
    for (; it != temp.end(); it++) {
        set<int>::iterator set_it;
        set_it = it->second.begin();
        cout << "Title: " << it->first.first << "\tAuthor: " << it->first.second << "\tEdition:";
        for (; set_it != it->second.end(); set_it++) {
            if (set_it == it->second.begin()) {
                cout << " " << *set_it;
            }
            else {
                cout << ", " << *set_it;
            }
        }
        cout << endl;
    }
}

struct authorComp {
    bool operator()(const book_info& a, const book_info& b)const {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        else {
            return a.first < b.first;
        }
    }
};


void listByAuthor() {
    map<book_info, set<int>, authorComp> temp;
    Books::iterator it;
    it = database.begin();
    for (; it != database.end(); it++) {
        temp[it->first] = it->second;
    }
    it = temp.begin();
    for (; it != temp.end(); it++) {
        set<int>::iterator set_it;
        set_it = it->second.begin();
        cout << "Title: " << it->first.first << "\tAuthor: " << it->first.second << "\tEdition:";
        for (; set_it != it->second.end(); set_it++) {
            if (set_it == it->second.begin()) {
                cout << " " << *set_it;
            }
            else {
                cout << ", " << *set_it;
            }
        }
        cout << endl;
    }

}




int main() {
    string command;
    while (getline(cin, command)) {
        stringstream ss(command);
        getline(ss, command, '\"');

        if (command.substr(0, 6) == "Insert") {
            string author, title;
            int edition = -1;

            while (getline(ss, title, '\"')) {
                if (title != " ") {
                    break;
                }
            }
            while (getline(ss, author, '\"')) {
                if (author != " ") {
                    break;
                }
            }
            ss >> edition;

            book_info temp;
            temp.first = title;
            temp.second = author;

            if (title == "" || author == "" || edition == -1) {
                cout << "Incomplete Command." << endl;
            }
            else {
                insert(temp, edition);
            }
        }
        else if (command.substr(0, 14) == "Delete Edition") {
            string title, author;
            int edition = -1;

            while (getline(ss, title, '\"')) {
                if (title != " ") {
                    break;
                }
            }
            while (getline(ss, author, '\"')) {
                if (author != " ") {
                    break;
                }
            }

            ss >> edition;

            book_info temp;
            temp.first = title;
            temp.second = author;

            if (title == "" || author == "" || edition == -1) {
                cout << "Incomplete Command." << endl;
            }
            else {
                deleteEdition(temp, edition);
            }
        }

        else if (command.substr(0, 11) == "Delete Book") {
            string title, author;

            while (getline(ss, title, '\"')) {
                if (title != " ") {
                    break;
                }
            }
            while (getline(ss, author, '\"')) {
                if (author != " ") {
                    break;
                }
            }
            book_info temp;
            temp.first = title;
            temp.second = author;

            if (title == "" || author == "") {
                cout << "Incomplete Command." << endl;
            }
            else {
                deleteBook(temp);
            }
        }
        else if (command.substr(0, 9) == "Find Book") {
            string title, author;

            while (getline(ss, title, '\"')) {
                if (title != " ") {
                    break;
                }
            }

            while (getline(ss, author, '\"')) {
                if (author != " ") {
                    break;
                }
            }

            book_info temp;
            temp.first = title;
            temp.second = author;

            if (title == "" || author == "") {
                cout << "Incomplete Command." << endl;
            }
            else {
                findBook(temp);
            }
        }

        else if (command.substr(0, 11) == "Find Author") {
            string author;
            while (getline(ss, author, '\"')) {
                if (author != " ") {
                    break;
                }
            }
            if (author == "") {
                cout << "Incomplete Command." << endl;
            }
            else {
                findAuthor(author);
            }
        }
        else if (command.substr(0, 13) == "Sort by Title") {
            listByTitle();
        }
        else if (command.substr(0, 14) == "Sort by Author") {
            listByAuthor();
        }
        else {
            cout << "Unknown Command.\n";
        }
    }
}