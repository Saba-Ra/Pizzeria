#pragma once
#include"KDtree.h"
#include"hashTable.h"
#include"windows.h"
#include"stdexcept"
#include"list"
#include"conio.h"


void gotoxy(int, int);

void logo_loading();

void help_loading();

void print_logo();

void print_help();

void update_list(list<pair<string, int>>&, const string&, int);

void give_max(list<pair<string, int>>&);

void printAll(hashTable&,string);

void print_menu() {

	KDtree tree;
	hashTable table;
	list<pair<string, int>> mostBranch;
	string input, name, mainName;
	coordinate A, B, C, D;
	bool flag = false;
	int R;
	while (1) {
		if (flag == true) {
			print_logo();
			print_help();
		}
		flag = true;
		cout << "\t\t\t\t\t";
		cout << "\x1b[38;5;220m";
		cin >> input;
		if (input == "Add-N") {
			cin >> name;
			cout << "\t\t\t\t\t\x1b[38;5;208mNow enter 4 coordinates :\x1b[38;5;220m\n";
			cin >> A >> B >> C >> D;
			//region insert
			cout << "\t\t\t\t\t\x1b[38;5;208mRegion added successfully \x1b[38;5;220m\n";
			Sleep(1000);
			system("cls");
		}
		else if (input == "Add-P") {
			cin >> name >> A;
			tree.insert("", name, A, table);
		}
		else if (input == "Add-Br") {
			cin >> mainName >> name >> A;
			tree.insert(mainName, name, A, table);
			update_list(mostBranch, name, 1);
		}
		else if (input == "Del-Br") {
			cin >> name >> A;
			tree.Delete(A);
		}
		else if (input == "List-P") {
			cin >> name;
			tree.pizzeria_in_region();
		}
		else if (input == "List-Brs") {
			cin >> name;
			printAll(table,name);

		}
		else if (input == "Near-P") {
			cin >> A;
			tree.nearest_pizzeria(A);
			Sleep(4000);
		}
		else if (input == "Near-Br") {
			cin >> name >> A;
			tree.nearest_branch(name, table);
		}
		else if (input == "Avail-P") {
			cin >> R >> A;
			tree.pizzeria_in_circle();
		}
		else if (input == "Most-Brs") {
			give_max(mostBranch);
		}
		else {
			cout << "\t\t\t\t\tWrong input!\n";
			Sleep(1000);
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
	SetConsoleOutputCP(65001);
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
	//Hide cursor
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);

	//Help menu
	std::string helpMenu =
		"\x1b[38;5;208m"
		"\t\t\t\t\t\t--------help---------\n"
		"\t\t\t\t\tAdd-N name\n"
		"\t\t\t\t\tAdd-P name \n"
		"\t\t\t\t\tAdd-Br mainBranch name \n"
		"\t\t\t\t\tDel-Br \n"
		"\t\t\t\t\tList-P regionName\n"
		"\t\t\t\t\tList-Brs namePizzeria\n"
		"\t\t\t\t\tNear-P \n"
		"\t\t\t\t\tNear-Br name \n"
		"\t\t\t\t\tAvail-P radius \n"
		"\t\t\t\t\tMost-Brs\n\n";

	//Load menu line by line
	for (int i = 0; i < helpMenu.size(); ++i) {
		//one character at a time
		cout << helpMenu[i];
		Sleep(10);
	}

	// Show cursor
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
		"\t\t\t\t\tNear-Br name \n"
		"\t\t\t\t\tAvail-P radius \n"
		"\t\t\t\t\tMost-Brs\n\n";
	//Undo
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

void give_max(list<pair<string, int>>& mostBranch) {

	int max = INT_MIN;
	string mainBranch = "";
	for (const auto& pair : mostBranch) {
		if (pair.second > max) {
			max = pair.second;
			mainBranch = pair.first;
		}
	}
	if (mainBranch != "")
		cout << "\n\x1b[38;5;223m\t\t\t\t\t" << mainBranch << "\x1b[38;5;220m\n";
	else
		cout << "\n\x1b[38;5;223m\t\t\t\t\tNo Pizzeria added yet!\x1b[38;5;220m\n";
	Sleep(4000);
}

void printAll(hashTable&table, string name) {
	try {
		vector<coordinate>vec = table.search(name);
		int j = 1;
		for (auto i : vec) {
			cout << "\t\t\t\t\tX" << j << " : " << i.set_get_xy()[0] << endl;
			cout << "\t\t\t\t\tY" << j << " : " << i.set_get_xy()[1] << endl;
			j++;
		}
		cout << "\t\t\t\t\tPress any key to go back\n";
		while (!_kbhit()) {}
		_getch();
	}
	catch (exception error) {
		cerr << error.what();
		Sleep(3000);
	}
}