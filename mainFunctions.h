#pragma once
#include"KDtree.h"
#include"hashTable.h"
#include"windows.h"
#include"stdexcept"
void print_menu();
void print_help();
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
		Sleep(35);
	}

	gotoxy(0, 4);
	cout << loadingWord << std::endl;
	print_help();
	print_menu();
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


void printAll(vector<coordinate> vec) {
	int j = 1;
	for (auto i : vec) {
		cout << "X" << j << " : " << i.set_get_xy()[0];
		cout << "Y" << j << " : " << i.set_get_xy()[1];
		j++;
	}
}

void print_menu() {	
	//names can have space
	//don't forget to fix cin
	KDtree tree;
	hashTable table;
	string input, name,mainName;
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
		else if (input=="Add-P") {
			cin >> name >> A;
			tree.insert("", name, A, table);
		}
		else if (input == "Add-Br") {
			cin >> mainName>>name >> A;
			tree.insert(mainName,name,A, table);
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
			try {
				printAll(table.search(name));
			}
			catch (exception error) {
				cerr << error.what();
			}
		}
		else if (input == "Near-P") {
			cin >> A;
			tree.nearest_pizzeria(A);
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

		}
		else {
			cout << "\t\t\t\t\tWrong input!\n";
			Sleep(1000);
		}
		system("cls");
	}
}