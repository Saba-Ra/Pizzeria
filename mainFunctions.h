#pragma once
#include"KDtree.h"
#include"hashTable.h"
#include"stdexcept"
#include"list"
#include"conio.h"
#include"neighborHood.h"
#include <sstream>
#include "hashTablePlus.h"

void gotoxy(int, int);

void logo_loading();

void help_loading();

void print_logo();

void print_help();

void update_list(list<pair<string, int>>&, const string&, int);

void give_max(list<pair<string, int>>&);

void printAll(hashTable&, string);

bool is_valid_command(string);

void print_menu() {
	int currentLevel = 0;
	KDtree tree;
	hashTable table;
	hashTablePlus commandsTable;
	list<pair<string, int>> mostBranch;
	string user_input, name, Br_name;
	coordinate A, B, C, D;
	neighborHood regions;
	float R;
	bool flag = false;
	while (1) {
		if (flag == true) {
			print_logo();
			print_help();
		}
		flag = true;
		cout << "\t\t\t\t\t";
		cout << "\x1b[38;5;220mEnter your commands separated by &&: ";
		getline(cin, user_input);
		stringstream ss(user_input);
		string command;
		vector<string> commands;

		// Split input by "&&"
		while (getline(ss, command, '&')) {
			if (command != "")
				commands.push_back(command);
		}

		// Validate each command
		bool all_commands_valid = true;
		for (auto& cmd : commands) {
			if (!is_valid_command(cmd)) {
				cout << "\n\t\t\t\t\t\x1b[38;5;223mInvalid command format! " << endl;
				Sleep(3000);
				all_commands_valid = false;
				break;
			}
		}
		if (all_commands_valid) {
			for (const auto& cmd : commands) {
				stringstream cmd_ss(cmd);
				string action, name;
				cmd_ss >> action >> name;
				cout << "\x1b[38;5;220m";
				if (action == "Add-N") {
					cout << "\n\t\t\t\t\t\x1b[38;5;223mNow enter 4 coordinates :\x1b[38;5;220m\n";
					cin >> A >> B >> C >> D;
					regions.insert(name, regions.make_vec(A, B, C, D));
					cout << "\n\t\t\t\t\t\x1b[38;5;223mRegion added successfully \x1b[38;5;220m\n";
					Sleep(3000);
				}
				else if (action == "Add-P") {
					cin >> A;
					tree.insert(name, name, A, table, commandsTable, currentLevel, true);
					currentLevel++;
					Sleep(2000);
				}
				else if (action == "Add-Br") {
					cout << "\n\t\t\t\t\t\x1b[38;5;223mEnter this branch's name : ";
					cin >> Br_name >> A;
					tree.insert(name, Br_name, A, table, commandsTable, currentLevel, true);
					update_list(mostBranch, name, 1);
					currentLevel++;
					Sleep(2000);
				}
				else if (action == "Del-Br") {
					cin >> A;
					try { tree.Delete(A, table, mostBranch, commandsTable, currentLevel, false, true); }
					catch (const char* error) { cout << "\n\t\t\t\t\t" << error; }
					currentLevel++;
					Sleep(3000);
				}
				else if (action == "List-P") {
					regions.search(name, tree);
					currentLevel++;
				}
				else if (action == "List-Brs") {
					printAll(table, name);
					currentLevel++;
				}
				else if (action == "Near-P") {
					cin >> A;
					tree.nearest_pizzeria(A, true);
					currentLevel++;
					Sleep(4000);
				}
				else if (action == "Near-Br") {
					cin >> A;
					try { tree.nearest_branch(name, A, table); }
					catch (exception error) { cerr << error.what(); }
					currentLevel++;
					Sleep(2000);
				}
				else if (action == "Avail-P") {
					cin >> A;
					stringstream(name) >> R;
					tree.pizzeria_in_circle(A, R);
					currentLevel++;
					Sleep(5000);
				}
				else if (action == "Most-Brs") {
					give_max(mostBranch);
					currentLevel++;
				}
				else if (action == "Undo") {
					int num;
					cout << "\n\t\t\t\t\t\x1b[38;5;223mEnter how many levels you want to go back: ";
					cin >> num;
					commandsTable.Undo(num, currentLevel,regions,table,tree,commandsTable, mostBranch);
					Sleep(2000);
				}
				cout << "\n";
			}
		}
		system("cls");
	}
}

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void logo_loading() {

	//Hide cursor
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);

	cout << "\x1b[38;5;124m";
	int total = 90; // Total number of steps
	string loadingWord =
		"\t\t\t\t██████╗ ██╗██████╗██████╗███████╗██████╗ ██╗██████╗\n"
		"\t\t\t\t██╔══██╗██║   ██╔╝   ██╔╝██╔════╝██╔══██╗██║██ ║██║\n"
		"\t\t\t\t██████╔╝██║  ██╔╝   ██╔╝ █████╗  ██████╔╝██║██████║\n"
		"\t\t\t\t██╔═══╝ ██║ ██╔╝   ██╔╝  ██╔══╝  ██╔══██╗██║██  ██║\n"
		"\t\t\t\t██║     ██║██████║██████║███████╗██║  ██║██║██  ██║\n"
		"\t\t\t\t╚═╝     ╚═╝╚═════╝╚═════╝╚══════╝╚═╝  ╚═╝╚═╝╚═╝ ╚═╝\033[0m\n\n";

	cout << "\n\n\n\n";

	for (int i = 0; i < total; ++i) {
		gotoxy(0, 4);
		cout << loadingWord.substr(0, i * loadingWord.size() / total);
		Sleep(30);
	}

	gotoxy(0, 4);
	cout << loadingWord << std::endl;
	help_loading();
	print_menu();
}

void help_loading() {

	//Help menu
	string helpMenu =
		"\x1b[38;5;208m"
		"\t\t\t\t\t\t--------help---------\n"
		"\t\t\t\t\tAdd-N name\n"
		"\t\t\t\t\tAdd-P name \n"
		"\t\t\t\t\tAdd-Br mainBranch name \n"
		"\t\t\t\t\tDel-Br \n"
		"\t\t\t\t\tList-P regionName\n"
		"\t\t\t\t\tList-Brs namePizzeria\n"
		"\t\t\t\t\tNear-P \n"
		"\t\t\t\t\tNear-Br mainBranch \n"
		"\t\t\t\t\tAvail-P radius \n"
		"\t\t\t\t\tMost-Brs\n"
		"\t\t\t\t\tUndo\n\n";

	//Load menu line by line
	for (int i = 0; i < helpMenu.size(); ++i) {
		//one character at a time
		cout << helpMenu[i];
		Sleep(10);
	}

	// Show cursor
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);
	cursorInfo.bVisible = true;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);

}

void print_logo() {

	cout << "\n\n\n\n";
	cout << "\x1b[38;5;124m"
		"\t\t\t\t██████╗ ██╗██████╗██████╗███████╗██████╗ ██╗██████╗\n"
		"\t\t\t\t██╔══██╗██║   ██╔╝   ██╔╝██╔════╝██╔══██╗██║██ ║██║\n"
		"\t\t\t\t██████╔╝██║  ██╔╝   ██╔╝ █████╗  ██████╔╝██║██████║\n"
		"\t\t\t\t██╔═══╝ ██║ ██╔╝   ██╔╝  ██╔══╝  ██╔══██╗██║██  ██║\n"
		"\t\t\t\t██║     ██║██████║██████║███████╗██║  ██║██║██  ██║\n"
		"\t\t\t\t╚═╝     ╚═╝╚═════╝╚═════╝╚══════╝╚═╝  ╚═╝╚═╝╚═╝ ╚═╝\033[0m\n\n\n";

}

void print_help() {
	//help menu
	cout << "\x1b[38;5;208m";
	cout << "\t\t\t\t\t\t--------help---------\n"
		"\t\t\t\t\tAdd-N name\n"
		"\t\t\t\t\tAdd-P name \n"
		"\t\t\t\t\tAdd-Br mainBranch name \n"
		"\t\t\t\t\tDel-Br \n"
		"\t\t\t\t\tList-P regionName\n"
		"\t\t\t\t\tList-Brs namePizzeria\n"
		"\t\t\t\t\tNear-P \n"
		"\t\t\t\t\tNear-Br mainBranch \n"
		"\t\t\t\t\tAvail-P radius \n"
		"\t\t\t\t\tMost-Brs\n"
		"\t\t\t\t\tUndo\n\n";
}

void update_list(list<pair<string, int>>& mostBranch, const string& name, int value) {

	for (auto& pair : mostBranch) {
		if (pair.first == name) {
			pair.second++;
			return;
		}
	}
	mostBranch.push_back(make_pair(name, value));
}

//there was no need to sort the list to extract the max
//sort has been implemented in insert

void give_max(list<pair<string, int>>& mostBranch) {
	int max = INT_MIN;
	list<string> mainBranches;
	for (const auto& pair : mostBranch) {
		if (pair.second > max) {
			max = pair.second;
			mainBranches.clear(); // clear previous list
			mainBranches.push_back(pair.first); // add the new max branch
		}
		else if (pair.second == max) {
			mainBranches.push_back(pair.first); // list of mainBranches with same max value
		}
	}

	if (!mainBranches.empty()) {
		cout << "\n\x1b[38;5;223m\t\t\t\t\tMax branch(s):\n";
		for (const auto& branch : mainBranches) {
			cout << "\t\t\t\t\t" << branch << "\n";
		}
	}
	else {
		cout << "\n\x1b[38;5;223m\t\t\t\t\tNo Pizzeria added yet!\n";
	}
	cout << "\x1b[38;5;220m";
	Sleep(4000);
}

void printAll(hashTable& table, string name) {
	try {
		vector<pair<coordinate, string>>* vec = table.search(name);
		int j = 1;
		for (auto& i : *vec) {
			cout << "\n\t\t\t\t\t\x1b[38;5;223mX" << j << " : " << i.first.set_get_xy()[0] << endl;
			cout << "\t\t\t\t\tY" << j << " : " << i.first.set_get_xy()[1] << endl;
			j++;
		}
		cout << "\n\t\t\t\t\tPress any key to go back\n\x1b[38;5;220m";
		while (!_kbhit()) {}
		_getch();
	}
	catch (exception error) {
		cerr << error.what();
		Sleep(3000);
	}
}

bool is_valid_command(string cmd) {

	stringstream ss(cmd);
	string action;
	ss >> action;

	if (action == "Add-N" || action == "Add-P" || action == "Add-Br" ||
		action == "Del-Br" || action == "List-P" || action == "List-Brs" ||
		action == "Near-P" || action == "Near-Br" || action == "Avail-P" || action == "Most-Brs" || action == "Undo") {

		// Check if additional arguments are provided
		if (action == "Add-N" || action == "Add-P" || action == "Avail-P" || action == "List-P" || action == "Near-Br" || action == "Add-Br") {
			string arg;
			if (!(ss >> arg)) {
				return false;
			}
		}

		return true;
	}

	return false;
}
