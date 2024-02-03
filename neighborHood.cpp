#include "neighborHood.h"
#include"conio.h"
void neighborHood::insert(string Name, vector<coordinate> Vertices) {

	regions.push_back(make_pair(Name, Vertices));

}


vector<coordinate> neighborHood::make_vec(coordinate A, coordinate B, coordinate C, coordinate D) {
	vector<coordinate> vertices;
	vertices.push_back(A);
	vertices.push_back(B);
	vertices.push_back(C);
	vertices.push_back(D);
	return vertices;
}

void neighborHood::search(string name, KDtree& tree) {
	if (tree.getRoot() == NULL) {
		cout << "\n\t\t\t\t\t\x1b[38;5;223mNo branches yet!" << endl;
		Sleep(3000);
		return;
	}
	auto regionIterator = find_if(regions.begin(), regions.end(), [&](const auto& region) {
		return region.first == name;
		});
	bool foundInside = false;
	if (regionIterator != regions.end()) {
		auto& region = *regionIterator;
		traverseTree(tree.getRoot(), region.second, foundInside);
		if (!foundInside) {
			cout << "\n\t\t\t\t\t\x1b[38;5;223mNo nodes found inside the region." << endl;
			Sleep(3000);
		}
		else {
			cout << "\n\t\t\t\t\tPress any key to go back\n\x1b[38;5;220m";
			while (!_kbhit()) {}
			_getch();
		}
	}
	else {
		cout << "\n\t\t\t\t\t\x1b[38;5;223mRegion with name " << name << " not found." << endl;
		Sleep(3000);
	}

}

void neighborHood::traverseTree(treeNode* node, vector<coordinate>& regionVertices, bool& foundInside) {
	if (node == NULL)
		return;


	if (isInsideRectangle(node->get_point(), regionVertices)) {
		cout << "\n\t\t\t\t\t\x1b[38;5;223m" << node->get_point() << endl;
		foundInside = true;
	}

	traverseTree(node->set_get_left(), regionVertices, foundInside);
	traverseTree(node->set_get_right(), regionVertices, foundInside);
}


bool neighborHood::isInsideRectangle(coordinate& point, vector<coordinate>& vertices) {

	int intersections = 0;
	coordinate point1, point2;
	for (int i = 0; i < 4; ++i) {
		point1 = vertices[i];
		point2 = vertices[(i + 1) % 4];

		// check the ray from point along the positive x-axis 
		// to see if it intersects with (point1, point2)
		if ((point1.set_get_xy()[1] > point.set_get_xy()[1]) != (point2.set_get_xy()[1] > point.set_get_xy()[1]) &&
			point.set_get_xy()[0] < (point2.set_get_xy()[1] - point1.set_get_xy()[0]) * (point.set_get_xy()[1] - point1.set_get_xy()[1]) / (point2.set_get_xy()[1] - point1.set_get_xy()[1]) + point1.set_get_xy()[0]) {
			intersections++;
		}
	}

	// odd intersections=> point is inside
	if (intersections % 2 == 1)
		return true;
	else
		return false;
}

void neighborHood::Delete_region(string regionName) {
	// Iterate through the regions vector and remove the region with the matching name and rectangle coordinates
	for (auto it = regions.begin(); it != regions.end(); ++it) {
		if (it->first == regionName) {
			regions.erase(it);
			cout << "\n\t\t\t\t\t\x1b[38;5;223mRegion " << regionName << " deleted successfully." << endl;
			Sleep(3000);
			return;
		}

	}
}