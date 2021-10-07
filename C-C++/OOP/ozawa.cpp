// Khái niệm:
// - Class: Định nghĩa 1 class
// - Object: Khai báo (khởi tạo) 1 object

// Một số phương thức đặc biệt:
// 1. Contructor (hàm khởi tạo): tự động gọi ra khi khởi tạo đối tượng
// đây là hàm ngầm định (implicit >< explicit) được gọi ra chứ không có định nghĩa
// 2. Distructor (hàm hủy):

// 3. Đặc trưng của OOP
// 3.1. Tính đóng gói (Encapsulation): private hết các thuộc tính của object
// 3.2. Tính trừu tượng (Abstraction): thay đổi các thuộc tính thông qua cơ chế (sử dụng các phương thức)

#include <iostream>
#include <string>

class Phu_nu
{
public:
    Phu_nu()
    {
    }

    Phu_nu(const std::string &ht, bool z = true) // ht = "Maria Ozawa"
        : ho_ten(ht), con_zin(z)
    {
        // ho_ten = ht;
        // con_zin = z;
    }

    ~Phu_nu()
    {
        std::cout << "Chia tay " << ho_ten << std::endl;
    }
    void trang_diem()
    {
    }

    std::string choi_nhac_cu(std::string nhac_cu)
    {
        return "";
    }

private:
    std::string ho_ten;
    bool con_zin;
};

class Dan_ong
{

} *vu = new Dan_ong;

int main()
{
    Phu_nu thao;
    // Phu_nu *maria_ozawa = new Phu_nu;
    // maria_ozawa->ho_ten = "Maria Ozawa";
    // Phu_nu *maria_ozawa = new Phu_nu("Maria Ozawa", false);
    Phu_nu *maria_ozawa = new Phu_nu("Maria Ozawa");
    std::cout << maria_ozawa->ho_ten << std::endl;
    maria_ozawa->choi_nhac_cu("ken");
    return 0;
}