#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Person{
	protected:
		string name;
		int yob; //year of birth
	
	public:
		// Phuong thuc nhap thông tin nguoi
		virtual void nhapThongTin(){
			cout << "Nhap ten: ";
			getline(cin, name);
			cout << "Nhap nam sinh: ";
			cin >> yob;
			cin.ignore(); //Loai bo ký tu '\n' còn sót lai trong buffer sau khi doc yob
		}

		// Phuong thuc in thông tin nguoi
		virtual void inThongTin(){
			cout << "Ten: " << name << endl;
			cout << "Nam sinh: " << yob << endl;
		}
};

class Employee : public Person{
	float sc; //salary coefficient
	
	public:
	void nhapThongTin(){
		Person::nhapThongTin();
		cout << "Nhap he so luong: ";
		cin >> sc;
		cin.ignore();
	}

	void inThongTin(){
		Person::inThongTin();
		cout << "He so luong: " << sc << endl;
	}

	// Phuong th?c tính luong
	float tinhLuong(){
		return sc * 1500000;
	}

	// Phuong th?c tang h? s? luong cho nhân viên có nam sinh tru?c 1970
	void tangHeSoLuong(){
		if (Person::yob < 1970){
			sc += 0.33;
		}
	}
};

class FootballPlayer : public Person{
	int nogs; //number of goals scored
	
	public:
		void nhapThongTin(){
			Person::nhapThongTin();
			cout << "Nhap so ban thang: ";
			cin >> nogs;
			cin.ignore();
		}

		void inThongTin(){
			Person::inThongTin();
			cout << "So ban thang: " << nogs << endl;
		}

		// Phuong th?c tính luong
		float tinhLuong(){
			return 10000000 + nogs * 350000;
		}
};

class Group{
	int n; //numbee of people in the group
	Person **a;
	
	public:
	void nhapDanhSach(){
		cout << "Nhap so thanh vien trong nhom: ";
		cin >> n;
		cin.ignore();
		a = new Person*[n];

		for (int i = 0; i < n; i++){
			int choice;
			cout << "Nhap loai thanh vien (1: Nhan vien, 2: Cau thu): ";
			cin >> choice;
			cin.ignore();

			if (choice == 1){
				a[i] = new Employee();
				a[i]->nhapThongTin();
			} else if (choice == 2){
				a[i] = new FootballPlayer();
				a[i]->nhapThongTin();
			}
		}
	}

	// Phuong th?c in danh sách thành viên nhóm
	void inDanhSach(){
		for (int i = 0; i < n; i++){
			a[i]->inThongTin();
		}
	}

	// Phuong th?c s?p x?p thành viên nhóm theo luong gi?m d?n
	void sapXepTheoLuong(){
		sort(a, a + n, [](Person* p1, Person* p2){
			if (Employee* e1 = dynamic_cast<Employee*>(p1)){
				if (Employee* e2 = dynamic_cast<Employee*>(p2)){
					return e1->tinhLuong() > e2->tinhLuong();
				}
			}
			return false;
		});
	}

	// Phuong th?c tang h? s? luong cho nhân viên có nam sinh tru?c 1970
	void tangHeSoLuongNhanVien(){
		for (int i = 0; i < n; i++){
			if (Employee* e = dynamic_cast<Employee*>(a[i])){
				e->tangHeSoLuong();
			}
		}
	}
};

int main(){
    Group team;

    // Nh?p danh sách thành viên nhóm
    team.nhapDanhSach();
    
	cout<<"";
    // In danh sách thành viên nhóm
    cout << "Danh sach thanh vien trong nhom:" << endl;
    team.inDanhSach();
    
	cout<<"";
    // S?p x?p thành viên nhóm theo luong gi?m d?n
    team.sapXepTheoLuong();
    
	cout<<"";
    // In danh sách thành viên nhóm sau khi s?p x?p
    cout << "Danh sach thanh vien trong nhom sau khi sap xep:" << endl;
    team.inDanhSach();	
    
	cout<<"";
    // Tang h? s? luong cho nhân viên có nam sinh tru?c 1970
    team.tangHeSoLuongNhanVien();
    
	cout<<"";
    // In danh sách thành viên nhóm sau khi tang h? s? luong
    cout << "Danh sach thanh vien trong nhom sau khi tang he so luong:" << endl;
    team.inDanhSach();

    return 0;
}


