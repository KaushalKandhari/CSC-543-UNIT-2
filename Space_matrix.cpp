#include <iostream>
#include <map>

class SparseMatrix {
private:
    int n_R;  // Number of rows
    int n_C;  // Number of columns
    std::map<std::pair<int, int>, int> e;  // Non-zero elements

public:
    // Constructor to initialize the matrix dimensions
    SparseMatrix(int rows, int cols) : n_R(rows), n_C(cols) {
    }

    // Function to insert a non-zero element into the sparse matrix
    void insert(int r, int c, int v) {
        if (r >= 0 && r < n_R && c >= 0 && c < n_C) {
            if (v != 0) {
                e[std::make_pair(r, c)] = v; // Store the element in the map
            }
        }
    }

    // Function to print the sparse matrix
    void print() {
        for (int i = 0; i < n_R; i++) {
            for (int j = 0; j < n_C; j++) {
                auto element = e.find(std::make_pair(i, j));
                if (element != e.end()) {
                    std::cout << element->second << " "; // Print the non-zero element's value
                } else {
                    std::cout << "0 "; // Print 0 for zero elements
                }
            }
            std::cout << std::endl; // Move to the next row
        }
    }
};

int main() {
    int n_R;  // Number of rows
    int n_C;  // Number of columns
    std::cout << "number of rows: ";
    std::cin >> n_R;
    std::cout << "number of columns: ";
    std::cin >> n_C;

    SparseMatrix sparseMatrix(n_R, n_C);

    std::cout << "non-zero elements (row, column, value) (To stop enter -1):" << std::endl;
    int r;  // Row
    int c;  // Column
    int v;  // Value
    while (true) {
        std::cin >> r;
        if (r == -1) break;
        std::cin >> c >> v;
        sparseMatrix.insert(r, c, v);
    }

    std::cout << "Sparse Matrix:" << std::endl;
    sparseMatrix.print();

    return 0;
}
