#include<iostream>
#include<vector> 
#include<fstream> 
#include"source_danh_ba.h"


using namespace std ; 
vector<string> name , email ; 
vector<int> phone_number; 

int main ( )
{ 

    string FILE_NAME = "danhba.dat" ; 
    LoadFile (FILE_NAME, name , phone_number , email ) ; 

    int choose; 
    do
    { 
        cout << endl; 
        cout << "####         CHAO MUNG BAN DEN VOI DANH BA                ####"<< endl; 
        cout << "      ##################################################      "<< endl; 
        cout << "                 ****    MUC LUC    ****                      "<< endl;
        cout << "             1. NHAP VAO THONG TIN DANH BA                    "<< endl; 
        cout << "             2. TIM KIEM THONG TIN DANH BA                    "<< endl; 
        cout << "             3. THOAT CHUONG TRINH                            "<< endl; 
        cout << "      ##################################################      "<< endl; 
        cout << "$ Luu y : Ngoai cac chuc nang tren thi khong con chuc nang khac $" << endl; 
        cout << "$ mong nguoi dung khong nhap sai chuc nang.Voi bat ki hanh dong $" << endl; 
        cout << "$ vo tinh hay co y. Chuong trinh se tu dong tro ve menu chinh.   $" << endl; 
        cout << "!!!!!!      Hay can nhac truoc khi dua ra quyet dinh       !!!!!!" << endl; 
        cout << endl ; 
        cout << "MOI BAN NHAP CHUC NANG : " ; 
        cin >> choose; 
        cout << endl; 
        if ( choose == 1 ) 
        { 
           cout << "####        THONG BAO: BAN DA LUA CHON CHUC NANG 1        ####" << endl; 
           NhapDuLieu(name, phone_number, email) ; 
        }
        if ( choose == 2 ) 
        { 
           cout << "####        THONG BAO: BAN DA LUA CHON CHUC NANG 2        ####" << endl; 
           InRaDuLieu (name, phone_number, email) ; 
      
        }
        if ( choose !=1 && choose != 2 && choose != 3 || choose <= 0 || typeid(choose) != typeid(int)) 
        { 
            int c = 0 ; 
            cout << endl; 
            cout << "!!!!!!!!     ERROR: CHUC NANG NAY KHONG TON TAI        !!!!!!!" << endl; 
            cout << "      ??? BAN CO MUON TIEP TUC SU DUNG CHUONG TRINH ???       " << endl; 
            cout << "                1. TIEP TUC CHUONG TRINH                      " << endl; 
            cout << "                2. THOAT CHUONG TRINH                         " << endl; 
            cout << "  $ WARNING : Neu ban tiep tuc nhap sai chuong trinh, chuong trinh se tu dong tat $ " << endl; 
            cout << " MOI BAN NHAP CHUC NANG : " ; 
            
            cin >> c ; 
            if ( c == 1 ) { 

                cout << "####      BAN DA CHO PHEP CHUONG TRINH TIEP TUC CHAY      ####" << endl; 
            }
            if ( c == 2 ) { 
                cout << endl; 
                cout << "####           BAN DA CHO CHUONG TRINH KET THUC           ####" << endl; 
                cout << "          =)) CAM ON BAN DA SU DUNG CHUONG TRINH =))          " << endl; 
                cout << endl; 
                break ; 
            } 
            if ( c != 1 && c != 2 || c < 0 ) 
            {  
                cout << "!!!!!       ERROR : BAN DA NHAP SAI CHUC NANG 2 LAN      !!!!!" << endl; 
                cout << "!!!!!             CHUONG TRINH SE TU DONG TAT            !!!!!" << endl; 
                cout << "           =(( CAM ON BAN DA SU DUNG CHUONG TRINH =((         " << endl; 
                cout << endl; 
                break; 
            }
        }
        if ( choose == 3 )
        { 
            cout << "####               CHUONG TRINH KET THUC                  ####" << endl; 
            cout << "        =)) CAM ON BAN DA SU DUNG CHUONG TRINH =))            " << endl; 
            cout << endl; 
        }
    }while ( choose != 3 ) ;
    SaveData(FILE_NAME,name, phone_number, email  ) ; 
    // ShowData(FILE_NAME, year.size() );
    return 0 ; 
}
