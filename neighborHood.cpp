#include "neighborHood.h"

void neighborHood::insert(string Name, vector<coordinate> Vertices) {

	regions.push_back(make_pair(Name, Vertices));

}
//void neighborHood::search(KDtree tree) {
//
//}

vector<coordinate> neighborHood::make_vec(coordinate A, coordinate B, coordinate C, coordinate D) {
	vector<coordinate> vertices(4);
	vertices.push_back(A);
	vertices.push_back(B);
	vertices.push_back(C);
	vertices.push_back(D);
	return vertices;
}
//void neighborHood::search(string name,KDtree tree) {
//    auto regionIterator = find_if(regions.begin(), regions.end(), [&](const auto& region) { return region.first == name;});
//
//    if (regionIterator != regions.end()) {
//       auto& region = *regionIterator;
//        traverseTree(tree.getRoot(), region.second);
//    }
//    else {
//        std::cout << "\n\t\t\t\t\t\x1b[38;5;223mRegion with name " << name << " not found." << endl;
//    }
//
//}
//
//void neighborHood::traverseTree(treeNode* node, const vector<coordinate>& regionVertices) {
//
//    if (node == nullptr) {
//        cout << "\n\t\t\t\t\t\x1b[38;5;223mNo branches yet!\n";
//        Sleep(3000);
//        return;
//    }
//   
//    if (isInsideRectangle(node->get_point(), regionVertices)) {
//       cout << "\n\t\t\t\t\t\x1b[38;5;223m"<< node->get_point() << endl;
//    }
//
//    traverseTree(node->set_get_left(), regionVertices);
//    traverseTree(node->set_get_right(), regionVertices);
//}
//
//bool neighborHood::isInsideRectangle(const coordinate& point, const std::vector<coordinate>& vertices) {
//    // Assuming the vertices are in clockwise order
//    // Check if the point is to the left of the line formed by two vertices
//    // If the point is to the left of all lines, it's inside the rectangle
//    for (size_t i = 0; i < vertices.size(); ++i) {
//        int j = (i + 1) % vertices.size();
//        if (crossProduct(vertices[i], vertices[j], point) < 0) {
//            return false;
//        }
//    }
//    return true;
//}
//
//// Helper function to calculate the cross product of two vectors formed by three points
//double neighborHood::crossProduct(const coordinate& A, const coordinate& B, const coordinate& C) {
//    double BAx = A.get_x() - B.get_x();
//    double BAy = A.get_y() - B.get_y();
//    double BCx = C.get_x() - B.get_x();
//    double BCy = C.get_y() - B.get_y();
//    return (BAx * BCy - BAy * BCx);
//}
void neighborHood::search(string name, KDtree& tree) {
	auto regionIterator = find_if(regions.begin(), regions.end(), [&](const auto& region) {
		return region.first == name;
		});

	if (regionIterator != regions.end()) {
		auto& region = *regionIterator;
		traverseTree(tree.getRoot(), region.second);
	}
	else {
		cout << "\n\t\t\t\t\t\x1b[38;5;223mRegion with name " << name << " not found." << endl;
	}
}

void neighborHood::traverseTree(treeNode* node, vector<coordinate>& regionVertices) {
	if (node == nullptr) {
		cout << "\n\t\t\t\t\t\x1b[38;5;223mNo branches yet!" << endl;
		return;
	}

	bool foundInside = false;

	if (isInsideRectangle(node->get_point(), regionVertices)) {
		cout << "\n\t\t\t\t\t\x1b[38;5;223m" << node->get_point() << endl;
		foundInside = true;
	}

	traverseTree(node->set_get_left(), regionVertices);
	traverseTree(node->set_get_right(), regionVertices);

	if (!foundInside) {
		cout << "\n\t\t\t\t\t\x1b[38;5;223mNo nodes found inside the region." << endl;
	}
}

bool neighborHood::isInsideRectangle(coordinate& point, vector<coordinate>& vertices) {
	//some fucking algorithm
	return false;
}