#pragma once
#include"KDtree.h"
#include"hashNode.h"
#include"windows.h"
void print_logo() {

	cout << "\n\n\x1b[38;5;124m"
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
		"\t\t\t\t\tAdd-P name x y\n"
		"\t\t\t\t\tAdd-Br mainBranch name x y\n"
		"\t\t\t\t\tDel-Br x y\n"
		"\t\t\t\t\tList-P regionName\n"
		"\t\t\t\t\tList-Brs namePizzeria\n"
		"\t\t\t\t\tNear-P x y\n"
		"\t\t\t\t\tNear-Br name x y\n"
		"\t\t\t\t\tAvail-P radius x y\n"
		"\t\t\t\t\tMost-Brs\n\n";
	//Undo
}
void print_menu() {	
	KDtree tree;
	string input, name;
	coordinate A, B, C, D;
	int R;
	while (1) {
		print_logo();
		print_help();
		cout << "\t\t\t\t\t";
		cout << "\x1b[38;5;220m";
		cin >> input;
		if (input == "Add-N") {
			cin >> name;
			cout << "\t\t\t\t\t\x1b[38;5;208mNow enter 4 coordinates :\x1b[38;5;220m\n";
			cin >> A >> B >> C >> D;
			tree.insert();
			tree.insert();
			tree.insert();
			tree.insert();
			cout << "\t\t\t\t\t\x1b[38;5;208mRegion added successfully :\x1b[38;5;220m\n";
			Sleep(1000);
			system("cls");
		}
		else if (input == "Add-Br") {
			cin >> name >> A;
			tree.insert();
		}
		else if (input == "Del-Br") {
			cin >> name >> A;
			tree.Delete();
		}
		else if (input == "List-P") {
			cin >> name;
			tree.pizzeria_in_region();
		}
		else if (input == "List-Brs") {
			cin >> name;
		}
		else if (input == "Near-P") {
			cin >> A;
			tree.nearest_pizzeria(A);
		}
		else if (input == "Near-Br") {
			cin >> name >> A;
			tree.nearest_branch();
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