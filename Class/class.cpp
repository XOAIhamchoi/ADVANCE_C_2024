#include <iostream>
using namespace std;




class information {
    public: 
        char* name;
        int old;  
};


class HinhChuNhat {
    public:
        double chieu_dai; // property 
        double chieu_rong; // property cách gọi trong C++
        double DienTich(){
            return chieu_dai*chieu_rong; // Method  
        }
        void Display(); // Method 

        // class nó cung cấp 1 contructor và nó trung tên với class 
        // và nó có thể nằm ở bất kỳ phạm vi nào

        HinhChuNhat()
        {
            chieu_dai = 10;
            chieu_rong = 30;
        }
        // contructor co tác dụng khi chung ta khởi tao object bất kỳ
        // thì hàm contructor sẽ tự động chạy
        // nghia là nó sẽ tự động gán giá trị chiều dài, chiều rộng 
        // khi khởi tạo object

        // cách khởi tạo contructor khác
        

        // destructor khi khởi tạo object nó cũng sẽ chạy destructor này
        // destructor này có giống lệnh free trong C
        // nghĩa là nó giải phóng đối tượng 
        ~HinhChuNhat(){

        }
        
};


void HinhChuNhat::Display (){
    cout << "dientich:" <<DienTich()<<endl;
}

int main(int argc, char const *argv[])
{
    HinhChuNhat Hinh_1;  // Hinh_1 được gọi object 
    Hinh_1.chieu_dai = 10.5;
    Hinh_1.chieu_rong = 5;

    cout << "chieudai:" <<Hinh_1.chieu_dai<<endl;
    cout << "chieurong:" <<Hinh_1.chieu_rong<<endl;
    Hinh_1.Display();
    
    information oai;
    oai.name="nguyen xuan oai";
    oai.old =22;
    cout<<"ten:"<<oai.name<<endl;
    cout<<"ole:"<<oai.old<<endl;
    return 0;
}



