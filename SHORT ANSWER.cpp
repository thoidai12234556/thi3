#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class PhanSo{
	public:
		int tuSo;
		int mauSo;
	public:
		//Hàm tao defaul_16
		PhanSo(){
			tuSo=0;
			mauSo=1;
		}
		
		//Hàm tao duoc tham so hóa_17
    	PhanSo(int tu, int mau){
        	tuSo = tu;
        	mauSo = mau;
   		}
   		
   		// Hàm tao ban sao_18
    	PhanSo(const PhanSo& other){
        	tuSo = other.tuSo;
        	mauSo = other.mauSo;
    	}
    	
    	//Ðinh nghia toán tu dau vào (>>)_19
		friend istream& operator>>(istream& is, PhanSo& ps){
    		cout << "Nhap tu so: ";
    		is >> ps.tuSo;
    		cout << "Nhap mau so: ";
    		is >> ps.mauSo;

    		return is;
		}
    	
    	//Ðinh nghia toán tu dau ra (<<)_20	
		friend ostream& operator<<(ostream& os, const PhanSo& ps){
    		os << ps.tuSo << "/" << ps.mauSo;
    		
    		return os;
		}
    	
    	// Ðinh nghia toán tu cong (+)_21
		friend PhanSo operator+(const PhanSo& ps1, const PhanSo& ps2) {
    		PhanSo ketQua;
    		ketQua.tuSo = ps1.tuSo * ps2.mauSo + ps2.tuSo * ps1.mauSo;
    		ketQua.mauSo = ps1.mauSo * ps2.mauSo;

    	return ketQua;
		}
		
		// Ðinh nghia toán tu cong (/)_22
		friend PhanSo operator/(const PhanSo& ps1, const PhanSo& ps2) {
    		PhanSo ketQua;
    		ketQua.tuSo = ps1.tuSo * ps2.mauSo;
    		ketQua.mauSo = ps1.mauSo * ps2.tuSo;

    	return ketQua;
		}
		
		// Quá tai toán tu so sánh bang (==)_23
    	friend int operator==(const PhanSo& ps1, const PhanSo& ps2){
    		// Tính giá tri nhân chung de so sánh
   			int nhanChung = ps1.tuSo * ps2.mauSo - ps2.tuSo * ps1.mauSo;

    		if (nhanChung == 0){
    		    return 0; // Hai phân so bang nhau
    		}
    		else if (nhanChung < 0){
    		    return -1; // phanSo1 < phanSo2
    		}
    		else{
    		    return 1; // phanSo1 > phanSo2
    		}
		}
		
		// Hàm rút gon phân so
    	friend void rutGonPhanSo(PhanSo& phanSo){
    		// Tìm (UCLN) cua tu so và mau so
    		int a = phanSo.tuSo;
    		int b = phanSo.mauSo;
    		int ucln = 1;

    		for (int i=1; i<=a && i<=b; i++){
    		    if (a%i==0 && b%i==0){
    		        ucln=i;
    		    }
    		}

    		// Rút gon ps
    		phanSo.tuSo /= ucln;
    		phanSo.mauSo /= ucln;
			}
};


int main(){
//16
//	PhanSo f;
//	cout<<"tu: "<<f.tuSo<<endl;
//	cout<<"mau: "<<f.mauSo<<endl;

//17
//	PhanSo phanSo(3, 4);
//    cout << "Tu so: " << phanSo.tuSo <<endl;
//    cout << "Mau so: " << phanSo.mauSo <<endl;

//18
//	PhanSo phanSo1;
//	// Tao mot doi tuong ban sao cua phanSo1
//    PhanSo phanSo2(phanSo1);
	
//22
//	PhanSo phanSo1;
//    PhanSo phanSo2;
//    
//    cout << "Nhap phan so 1: "<<endl; cin >> phanSo1;
//    cout << "Nhap phan so 2: "<<endl; cin >> phanSo2;
//    
//    PhanSo phanSoThuong = phanSo1 / phanSo2;
//    cout << "Thuong hai phan so: " << phanSoThuong <<endl;
	
//23
//	PhanSo phanSo1(3, 4);
//    PhanSo phanSo2(6, 8);
//    PhanSo phanSo3(2, 3);
//
//    int ketQuaSoSanh1 = phanSo1 == phanSo2;
//    if (ketQuaSoSanh1 == -1) {
//        cout << "Phan so 1 nho hon phan so 2" <<endl;
//    } else if (ketQuaSoSanh1 == 1) {
//        cout << "Phan so 1 lon hon phan so 2" <<endl;
//    } else {
//        cout << "Phan so 1 bang phan so 2" <<endl;
//    }
//    
//    int ketQuaSoSanh2 = phanSo1 == phanSo3;
//    if (ketQuaSoSanh2 == -1) {
//        cout << "Phan so 1 nho hon phan so 3" <<endl;
//    } else if (ketQuaSoSanh2 == 1) {
//        cout << "Phan so 1 lon hon phan so 3" <<endl;
//    } else {
//        cout << "Phan so 1 bang phan so 3" <<endl;
//    }

//24
//    PhanSo phanSo;
//    cout << "Nhap phan so: "<<endl; cin >> phanSo;
//    rutGonPhanSo(phanSo);
//    cout << "Phan so sau khi rut gon: " << phanSo <<endl;
	
	return 0;
}

