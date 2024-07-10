#include <iostream>

int main() {
	int a, b, c;

	std::cout << "Nhap vao so nguyen a: ";
	std::cin >> a;

	std::cout << "Nhap vao so nguyen b: ";
	std::cin >> b;

	std::cout << "Nhap vao so nguyen c: ";
	std::cin >> c;

	if (a - b == 0) {
		std::cout << "Loi: Khong the chia cho (a - b) = 0\n";
	}
	else {
		float ketQua = static_cast<float>(c) / (a - b);
		std::cout << "Ket qua c / (a - b) la: " << ketQua << std::endl;
	}
	system("pause");
	return 0;

}
