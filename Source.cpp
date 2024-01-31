#include"KDtree.h"
#include"hashNode.h"
#include"windows.h"
int main() {
	SetConsoleOutputCP(65001);

	cout <<"\n\n\x1b[38;5;124m"
		"\t\t\t\t\t██████╗ ██╗██████╗██████╗███████╗██████╗ ██╗██████╗\n"
		"\t\t\t\t\t██╔══██╗██║   ██╔╝   ██╔╝██╔════╝██╔══██╗██║██ ║██║\n"
		"\t\t\t\t\t██████╔╝██║  ██╔╝   ██╔╝ █████╗  ██████╔╝██║██████║\n"
		"\t\t\t\t\t██╔═══╝ ██║ ██╔╝   ██╔╝  ██╔══╝  ██╔══██╗██║██  ██║\n"
		"\t\t\t\t\t██║     ██║██████║██████║███████╗██║  ██║██║██  ██║\n"
		"\t\t\t\t\t╚═╝     ╚═╝╚═════╝╚═════╝╚══════╝╚═╝  ╚═╝╚═╝╚═╝ ╚═╝\033[0m\n\n\n";



	cout << "\x1b[38;5;208m";
	KDtree tree;
	string input, name;
	coordinate A, B, C, D;
	int R;
	//help menu
	cout << "\t\t\t\t\t\t\t--------help---------\n"
		"\t\t\t\t\t\tAdd-N name x1 y1 x2 y2 x3 y3 x4 y4\n"
		"\t\t\t\t\t\tAdd-P name x y\n"
		"\t\t\t\t\t\tAdd-Br mainBranch name x y\n"
		"\t\t\t\t\t\tDel-Br x y\n"
		"\t\t\t\t\t\tList-P regionName\n"
		"\t\t\t\t\t\tList-Brs namePizzeria\n"
		"\t\t\t\t\t\tNear-P x y\n"
		"\t\t\t\t\t\tNear-Br name x y\n"
		"\t\t\t\t\t\tAvail-P radius x y\n"
		"\t\t\t\t\t\tMost-Brs\n\n";
	//Undo
	while (1) {
		cout << "\t\t\t\t\t\t";
		cout << "\x1b[38;5;220m";
		cin >> input;
		if (input == "Add-N") {
			cin >> name >> A >> B >> C >> D;

		}
		else if (input == "Add-Br") {
			cin >> name >> A;
		}
		else if (input == "Del-Br") {
			cin >> name >> A;
		}
		else if (input == "List-P") {
			cin >> name;
		}
		else if (input == "List-Brs") {
			cin >> name;
		}
		else if (input == "Near-P") {
			cin >> A;
		}
		else if (input == "Near-Br") {
			cin >> name >> A;
		}
		else if (input == "Avail-P") {
			cin >> R >> A;
		}
		else if (input == "Most-Brs") {

		}
		else {
			cout << "\t\t\t\t\t\tWrong input!\n";
		}
	}
}