#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

void tinhThoiGianNghiHuu(const std::string& hoTen, const std::string& gioiTinh, const std::tm& ngaySinh) {
	std::time_t now = std::time(nullptr);
	std::tm *ltm = std::localtime(&now);
	int namHienTai = 1900 + ltm->tm_year;

	int tuoi = namHienTai - (1900 + ngaySinh.tm_year);

	try {
		if (gioiTinh != "Nam" && gioiTinh != "Nu") {
			throw std::string("errcode");
		}

		int tuoiNghiHuu = (gioiTinh == "Nam") ? 62 : 60;

		if (tuoi < 18 || tuoi > tuoiNghiHuu) {
			throw 101;
		}

		int namNghiHuu = 1900 + ngaySinh.tm_year + tuoiNghiHuu;

		std::cout << hoTen << ", Gioi tinh " << gioiTinh << ", Ngay sinh "
			<< std::setw(2) << std::setfill('0') << ngaySinh.tm_mday << "/"
			<< std::setw(2) << std::setfill('0') << ngaySinh.tm_mon + 1 << "/"
			<< 1900 + ngaySinh.tm_year << ". Hien tai (nam " << namHienTai << ") da "
			<< tuoi << " tuoi. Thoi gian duoc nghi huu la thang "
			<< std::setw(2) << std::setfill('0') << ngaySinh.tm_mon + 1 << "/"
			<< namNghiHuu << ".\n";

	}
	catch (int errCode) {
		if (errCode == 101) {
			std::cout << "Loi: Tuoi khong nam trong khoang 18 den " << ((gioiTinh == "nam") ? "62" : "60") << "!\n";
		}
	}
	catch (const std::string& errCode) {
		if (errCode == "errcode") {
			std::cout << "Loi: Gioi tinh khong hop le!\n";
		}
	}
}

int main() {
	std::string hoTen, gioiTinh;
	std::tm ngaySinh = {};

	std::cout << "Nhap ho va ten: ";
	std::getline(std::cin, hoTen);

	std::cout << "Nhap gioi tinh (Nam/Nu): ";
	std::getline(std::cin, gioiTinh);

	std::cout << "Nhap ngay sinh (Ngay/Thang/Nam): ";
	std::cin >> std::get_time(&ngaySinh, "%d/%m/%Y");

	tinhThoiGianNghiHuu(hoTen, gioiTinh, ngaySinh);
	system("pause");
	return 0;
}
