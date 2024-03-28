#include<iostream> 
#include<vector> 
#include<fstream>
using namespace std ; 

void LoadFile ( string file_name , vector<string> &Name, vector<int>  &Phone_number , vector<string> &email  ) 
{ 
    ifstream infile ; 
    infile.open(file_name ) ; 
    string n ; 
    while (infile >> n ) 
    { 
        Name.push_back(n) ;
        int p ; 
        infile >> p ; 
        Phone_number.push_back(p) ; 
        string e ; 
        infile >> e ; 
        email.push_back(e) ; 
    }
    infile.close() ; 
}


void NhapDuLieu (vector<string> &name, vector<int> &phone_number, vector<string> &email )
{ 
    string  n , e ; 
    int p  ; 
    bool flag = false ; 
    int index ; 
    cout << "MOI BAN NHAP VAO TEN : " ;
    cin >> n ; 
    for ( int i = 0 ; i < name.size() ; i ++ ) 
    { 
        if ( n == name[i]) 
        { 
            int c ; 
            flag = true ; 
            index = i ; 
            cout << endl;
            cout << "####               TEN NGUOI DUNG DA TON TAI               #### " << endl; 
            cout << "   ???? BAN CO MUON THAY DOI THONG TIN LIEN LAC KHONG ????      " << endl; 
            cout << "                 1. THAY DOI THONG TIN LIEN LAC                 " << endl; 
            cout << "                 2. KHONG THAY DOI THONG TIN LIEN LAC           " << endl; 
            cout << endl; 
            cout << "MOi BAN NHAP VAO CHUC NANG :  " ; 
            cin >> c ; 
            if ( c == 1 ) 
            { 
                 
                cout << "####  THONG BAO: BAN DA CHON CHUC NANG THAY DOI THONG TIN  #### " << endl; 
                cout << endl; 


                cout << "MOI BAN NHAP VAO SO DIEN THOAI THAY DOI : " ; 
                cin >> p; 
                phone_number[index] = p ; 

                cout << "MOI BAN NHAP VAO EMAIL THAY DOI : " ; 
                cin >> e ; 
                email[index] = e ; 
                
                cout << "####  THONG BAO: BAN DA THAY DOI THONG TIN LIEN LAC   #### " << endl; 
                cout << "####     CHUONG TRINH SE QUAY TRO VE MENU CHINH       #### " << endl; 

                return ; 
            }
        }
    }
    if ( flag == false ) 
    { 
        name.push_back(n) ; 

        cout << "MOI BAN NHAP VAO SO DIEN THOAI : " ; 
        cin >> p ; 
        phone_number.push_back(p) ; 

        cout << "MOI BAN NHAP VAO EMAIL : " ; 
        cin >> e ; 
        email.push_back(e) ;

        cout << "####  THONG BAO: BAN DA LUU THANH CONG THONG TIN LIEN LAC   #### " << endl; 
        cout << "####     CHUONG TRINH SE QUAY TRO VE MENU CHINH             #### " << endl; 
 
        return ; 
    }


}
void InRaDuLieu ( vector<string> &name, vector<int> &phone_number , vector<string> email ) 
{ 
    string  n , e ; 
    int p  ; 
    bool flag = false ; 
    int index = 0 ; 
    cout << endl; 
    cout << "####    BAN DA LUA CHON CHUC NANG 2 TU MENU    ####" << endl ; 
    cout << " MOI BAN NHAP VAO TEN NGUOI BAN MUON TIM: " ; 
    cin >> n ; 

    vector <int> month_no_data ; 
    for ( int i = 0 ; i < name.size() ; i++) 
    { 
        if (n == name[i])
        { 
            index = i ; 
            flag = true ; 
        }
    }
    if ( flag == true ) 
    { 
        cout << "THONG TIN LIEN LAC " << endl; 
        cout << "TEN : " << name[index] << endl ; 
        cout << "SO DIEN THOAI : " << phone_number[index] << endl; 
        cout << "EMAIL : " << email[index] << endl; 
        cout << endl; 
    }
    if ( flag == false ) 
    { 
        int c ; 
        cout << "####    THONG BAO: KHONG TON TAI TEN NAY TRONG DANH BA       #### " << endl; 
        cout << "####  ???? BAN CO MUON THEM TEN NAY VAO DANH BA KHONG ????   #### " << endl; 
        cout << "               1.THEM TEN NGUOI NAY VAO DANH BA                   " << endl; 
        cout << "               2.KHONG THEM TEN NGUOI NAY VAO DANH BA             " << endl; 
        cout << "MOI BAN NHAP VAO CHUC NANG :" ; 
        cin >> c ; 
        if ( c == 1 ) 
        { 
            name.push_back(n);
            cout << "####    THONG BAO: BAN DA CHOC CHUC NANG THEM THONG TIN LIEN LAC NAY       #### " << endl; 
            cout << "MOI BAN NHAP VAO SO DIEN THOAI : " ; 
            cin >> p;  
            phone_number.push_back(p) ; 
            cout << "MOI BAN NHAP VAO EMAIL :" ; 
            cin >> e ; 
            email.push_back(e) ; 
            cout << "####    THONG BAO: BAN DA THANH CONG THEM MOI THONG TIN LEIN LAC NAY    ####" << endl; 
            cout << "####            CHUONG TRINH SE QUAY TRO LAI GAI DIEN CHINH                 " << endl; 

            return ; 
        }
    }
}    

void SaveData ( string file_name  ,vector<string> &Name, vector<int> &phone_number, vector<string> &email  ) 
{ 
    ofstream outfile; 
    outfile.open("list.dat") ; 
    
    for ( int i = 0 ; i < Name.size() ; i ++ ) 
    { 
        outfile << Name[i] ; 
        outfile << " " ; 
        outfile << phone_number[i] ; 
        outfile << " " ; 
        outfile << email[i] ; 
        outfile << endl; 
    }
    outfile.close() ; 
}
void ShowData (string file_name , int lenght) 
{ 

    ifstream infile ; 
    infile.open(file_name) ; 
    if (!infile.eof()) { return ; } 
    float data ; 
    for ( int i = 0 ; i < lenght  ; i ++ ) 
    { 
        for ( int j = 0 ; j < 13 ; j ++ ) 
        { 
            infile >> data ; 
            cout << data ; 
        } 
        cout << endl; 
    }
}