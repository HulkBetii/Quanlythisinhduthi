#include <iostream>
#include <fstream>

using namespace std;

class con_nguoi
{
private:
    string hoten;
    string gioi_tinh;
    string ngaysinh;
    string quequan;
    int cmnd;
public:
    con_nguoi()
    {
        hoten = "NO INFO";
        gioi_tinh = "NO INFO";
        ngaysinh = "NO INFO";
        quequan = "NO INFO";
        cmnd = 0;
    }
    con_nguoi(string ht, string gt, string ns, string qq, int cm)
    {
        hoten = ht;
        gioi_tinh = gt;
        ngaysinh = ns;
        quequan = qq;
        cmnd = cm;
    }
    void virtual nhap()
    {
        fflush(stdin);
        cout<<"Nhap Ho va Ten: ";
        getline(cin, hoten);
        cout<<"Nhap Gioi Tinh: ";
        getline(cin, gioi_tinh);
        cout<<"Nhap Ngay Sinh: ";
        getline(cin, ngaysinh);
        cout<<"Nhap Que Quan: ";
        getline(cin, quequan);
        cout<<"Nhap CMND: ";
        cin>>cmnd;
    }
    void virtual hienthi()
    {
        cout<<"Ho va Ten: "<<hoten<<endl;
        cout<<"Gioi Tinh"<<"  Ngay Sinh"<<"  Que Quan"<<"  CMND"<<endl;
        cout<<"   "<<gioi_tinh<<"     "<<ngaysinh<<"   "<<quequan<<"   "<<cmnd<<endl;
    }

    void virtual ghifile(ofstream &dataout)
    {
        dataout<<hoten<<";"<<gioi_tinh<<";"<<ngaysinh<<";"<<quequan<<";"<<cmnd<<";";
    }

    void virtual docfile(ifstream &datain)
    {
        getline(datain, hoten, ';');
        getline(datain, gioi_tinh, ';');
        getline(datain, ngaysinh, ';');
        getline(datain, quequan, ';');
        datain>>cmnd;
        datain.ignore();
    }

    int virtual getsbd()=0;
    double virtual getdm1()=0;
    double virtual getdm2()=0;
    double virtual getdm3()=0;
    double virtual gettd()=0;
    friend void suafile(con_nguoi *x[], int n);
    friend int xoafile(con_nguoi *x[], int n);
    friend void thisinhdau(con_nguoi *x[], int n);
    friend void sapxep(con_nguoi *x[], int n);
    friend void timkiem(con_nguoi *x[],int n);
    friend void thisinhcaonhat(con_nguoi *x[], int n);
    friend void phieubaodiem(con_nguoi *x[], int n);
    friend int checknhap(con_nguoi *x[], int n);
    friend int checksua(con_nguoi *x[], int vitri, int n);


};

class dt_thi : public con_nguoi
{
private:
    int sbd;
    double dm1;
    double dm2;
    double dm3;
    double tongd1;
public:
    dt_thi() : con_nguoi()
    {
        sbd = 0;
        dm1 = 0;
        dm2 = 0;
        dm3 = 0;
        tongd1 = 0;
    }
    dt_thi(string ht, string gt, string ns, string qq, int cm, int bd, double d1, double d2, double d3, double td1) : con_nguoi(ht, gt, ns, qq, cm)
    {
        sbd = bd;
        dm1 = d1;
        dm2 = d2;
        dm3 = d3;
        tongd1 = td1;
    }
    void nhap()
    {
        con_nguoi::nhap();
        cout<<"Nhap SBD: ";
        cin>>sbd;
        do
        {
            cout<<"Nhap Diem Mon 1: ";
            cin>>dm1;
            cout<<"Nhap Diem Mon 2: ";
            cin>>dm2;
            if(dm1<0 || dm1>10 || dm2 <0 || dm2 >10)
                cout<<"\n/!\\/!\\ NHAP SAI, MOI NHAP LAI!!!"<<endl;
        }
        while(dm1<0 || dm1>10 || dm2 <0 || dm2 >10);
        tongd1 = dm1 + dm2;
    }
    void hienthi()
    {
        con_nguoi::hienthi();
        cout<<"SBD "<<"  Diem Mon 1"<<"  Diem Mon 2"<<"  Diem Mon 3"<<"  Tong diem"<<endl;
        cout<<sbd<<"       "<<dm1<<"            "<<dm2<<"           "<<dm3<<"         "<<tongd1<<endl;
    }

    void ghifile(ofstream &dataout)
    {
        con_nguoi::ghifile(dataout);
        dataout<<sbd<<";"<<dm1<<";"<<dm2<<";"<<dm3<<";"<<tongd1<<"\n";
    }

    void docfile(ifstream &datain)
    {
        con_nguoi::docfile(datain);
        datain>>sbd;
        datain.ignore();
        datain>>dm1;
        datain.ignore();
        datain>>dm2;
        datain.ignore();
        datain>>dm3;
        datain.ignore();
        datain>>tongd1;
        datain.ignore();
    }
    int getsbd()
    {
        return sbd;
    }
    double getdm1()
    {
        return dm1;
    }
    double getdm2()
    {
        return dm2;
    }
    double getdm3()
    {
        return dm3;
    }
    double gettd()
    {
        return tongd1;
    }
    friend void suafile(con_nguoi *x[], int n);
    friend int xoafile(con_nguoi *x[], int n);
    friend void thisinhdau(con_nguoi *x[], int n);
    friend void sapxep(con_nguoi *x[], int n);
    friend void timkiem(con_nguoi *x[],int n);
    friend void thisinhcaonhat(con_nguoi *x[], int n);
    friend void phieubaodiem(con_nguoi *x[], int n);
    friend int checknhap(con_nguoi *x[], int n);
    friend int checksua(con_nguoi *x[], int vitri, int n);

};

class dt_thi_nk : public con_nguoi
{
private:
    int sbd;
    double dm1;
    double dm2;
    double dm3;
    double tongd2;
public:
    dt_thi_nk() : con_nguoi()
    {
        sbd = 0;
        dm1 = 0;
        dm2 = 0;
        dm3 = 0;
        tongd2 = 0;
    }
    dt_thi_nk(string ht, string gt, string ns, string qq, int cm, int bd, double d1, double d2, double d3, double td2) : con_nguoi()
    {
        sbd = bd;
        dm1 = d1;
        dm2 = d2;
        dm3 = d3;
        tongd2 = td2;
    }
    void nhap()
    {
        con_nguoi::nhap();
        cout<<"Nhap SBD: ";
        cin>>sbd;
        do
        {
            cout<<"Nhap Diem Mon 1: ";
            cin>>dm1;
            cout<<"Nhap Diem Mon 2: ";
            cin>>dm2;
            cout<<"Nhap Diem Mon 3: ";
            cin>>dm3;
            if(dm1<0 || dm1>10 || dm2 <0 || dm2 >10 || dm3<0 || dm3>10)
                cout<<"\n/!\\/!\\ NHAP SAI, MOI NHAP LAI!!!"<<endl;
        }
        while(dm1<0 || dm1>10 || dm2 <0 || dm2 >10 || dm3<0 || dm3>10);
        tongd2 = dm1 + dm2 +dm3*2;
    }

    void hienthi()
    {
        con_nguoi::hienthi();
        cout<<"SBD "<<"  Diem Mon 1"<<"  Diem Mon 2"<<"  Diem Mon 3"<<"  Tong diem"<<endl;
        cout<<sbd<<"       "<<dm1<<"            "<<dm2<<"           "<<dm3<<"         "<<tongd2<<endl;
    }

    void ghifile(ofstream &dataout)
    {
        con_nguoi::ghifile(dataout);
        dataout<<sbd<<";"<<dm1<<";"<<dm2<<";"<<dm3<<";"<<tongd2<<"\n";
    }

    void docfile(ifstream &datain)
    {
        con_nguoi::docfile(datain);
        datain>>sbd;
        datain.ignore();
        datain>>dm1;
        datain.ignore();
        datain>>dm2;
        datain.ignore();
        datain>>dm3;
        datain.ignore();
        datain>>tongd2;
        datain.ignore();
    }
    int getsbd()
    {
        return sbd;
    }
    double getdm1()
    {
        return dm1;
    }
    double getdm2()
    {
        return dm2;
    }
    double getdm3()
    {
        return dm3;
    }
    double gettd()
    {
        return tongd2;
    }
    friend void suafile(con_nguoi *x[], int n);
    friend int xoafile(con_nguoi *x[], int n);
    friend void thisinhdau(con_nguoi *x[], int n);
    friend void sapxep(con_nguoi *x[], int n);
    friend void timkiem(con_nguoi *x[],int n);
    friend void thisinhcaonhat(con_nguoi *x[], int n);
    friend void phieubaodiem(con_nguoi *x[], int n);
    friend int checknhap(con_nguoi *x[], int n);
    friend int checksua(con_nguoi *x[], int vitri, int n);
};

void docfilett(ifstream &datain, con_nguoi *x[],int &n)
{
    while(datain.eof()==false)
    {
        x[n] = new dt_thi();
        x[n]->docfile(datain);
        n++;
    }
    n--;
}

void docfilenk(ifstream &datain, con_nguoi *x[],int &m)
{
    while(datain.eof()==false)
    {
        x[m] = new dt_thi_nk();
        x[m]->docfile(datain);
        m++;
    }
    m--;
}

void ghidulieu(ofstream &dataout, con_nguoi *x[],int &n)
{
    for(int i=0; i<n; i++)
    {
        x[i]->ghifile(dataout);
    }
}

void xuatthongtin(con_nguoi *x[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"\nTHI SINH THU "<<i+1<<endl;
        x[i]->hienthi();
    }
}

void suafile(con_nguoi *x[], int n)
{
    int cm;
    int biendem=0;
    cout<<"Nhap CMND thi sinh muon SUA:";
    cin>>cm;
    ofstream data2;
    data2.open("database2.txt", ios::app|ios::out);
    for(int i=0; i<n; i++)
    {
        if(x[i]->cmnd==cm)
        {
            cout<<"\n\n**THONG TIN THI SINH TRUOC KHI SUA**"<<endl;
            x[i]->hienthi();
            cout<<"\n\nNHAP THONG TIN MONG MUON:"<<endl;
nl:
            fflush(stdin);
            x[i]->nhap();
            if(checksua(x, i, n)!=1)
            {
                cout<<"\n/!\\/!\\ So CMND hoac SBD da Ton Tai!!"<<endl;
                cout<<"Moi nhap lai!!"<<endl;
                goto nl;
            }
            x[i]->ghifile(data2);
            biendem++;
            cout<<"\n\n******************************************"<<endl;
            cout<<">>>DA SUA THONG TIN THI SINH THANH CONG<<<"<<endl;
            cout<<"******************************************"<<endl;
            cout<<"\n\n**THONG TIN THI SINH SAU KHI SUA**"<<endl;
            x[i]->hienthi();
        }
        else
        {
            x[i]->ghifile(data2);
        }
    }
    data2.close();
    if(biendem == 0)
    {
        cout<<"\n/!\\ KHONG TIM THAY THI SINH!!!"<<endl;
    }
}

int xoafile(con_nguoi *x[], int n)
{
    int biendem=0;
    int cm;
    cout<<"Nhap CMND thi sinh muon XOA:";
    cin>>cm;
    ofstream data2;
    data2.open("database2.txt", ios::app|ios::out);
    for(int i=0; i<n; i++)
    {
        if(x[i]->cmnd==cm)
        {
            biendem++;
            int vitri = i;
            for(int i=vitri; i<n-1; i++)
            {
                x[i] = x[i+1];
            }
            i--;
            n--;
        }
        else
        {
            x[i]->ghifile(data2);
        }
    }
    data2.close();
    return biendem;
}

void thisinhdau(con_nguoi *x[], int n)
{
    int bd=0;
    int j=0;
    int k=0;
    for(int i=0; i<n; i++)
    {
        if(x[i]->getdm3()==0)
        {

            if(x[i]->gettd() >= 18)
            {
                cout<<"\nTHI SINH THU "<<j+1<<endl;
                x[i]->hienthi();
                j++;
            }
            else
                bd++;
        }
        else
        {
            if(x[i]->gettd() >= 21)
            {
                cout<<"\nTHI SINH THU "<<k+1<<endl;
                x[i]->hienthi();
                k++;
            }
            else
                bd++;
        }
    }

    if(bd>=n)
        cout<<"\n/!\\ KHONG CO THI SINH DAU!!!"<<endl;
}

void sapxep(con_nguoi *x[], int n)
{
    con_nguoi *z;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(x[i]->gettd() >= x[j]->gettd())
            {
                z = x[i];
                x[i] = x[j];
                x[j] = z;
            }
        }
    }
}

void timkiem(con_nguoi *x[],int n)
{
    int cm;
    cout<<"Nhap CMND thi sinh muon TIM KIEM:";
    cin>>cm;
    int bd=0;
    for(int i=0; i<n; i++)
    {
        if(x[i]->cmnd==cm)
        {
            cout<<"\n\n***THONG TIN THI SINH MUON TIM***"<<endl;
            x[i]->hienthi();
        }
        else
            bd++;
    }
    if(bd>=n)
        cout<<"\n/!\\ KHONG CO THI SINH CAN TIM!!!"<<endl;
}

void thisinhcaonhat(con_nguoi *x[], int n)
{
    con_nguoi *maxx;
    maxx = x[0];
    for(int i=1; i<n; i++)
    {
            if(maxx->gettd() <= x[i]->gettd())
            {
                maxx = x[i];
            }
    }
    int k=0;
    for(int i=0; i<n; i++)
    {
        if(maxx->gettd() == x[i]->gettd())
        {
            cout<<"\nTHI SINH THU "<<k+1<<endl;
            x[i]->hienthi();
            k++;
        }
    }
}

void phieubaodiem(con_nguoi *x[], int n)
{
    int bd;
    cout<<"Nhap SBD thi sinh nhan Phieu Bao Diem:";
    cin>>bd;
    int biendem=0;
    for(int i=0; i<n; i++)
    {
        if(x[i]->getsbd()==bd)
        {
            cout<<"\n\n============PHIEU BAO DIEM============"<<endl;
            cout<<"Ho Ten:"<<x[i]->hoten<<"\t"<<"SBD:"<<x[i]->getsbd()<<endl;
            cout<<"Diem Mon 1:"<<x[i]->getdm1()<<"\t"<<"Diem Mon 2:"<<x[i]->getdm2()<<endl;
            cout<<"Diem Mon 3:"<<x[i]->getdm3()<<"\t""Tong Diem:"<<x[i]->gettd()<<endl;
            cout<<"======================================"<<endl;
        }
        else
            biendem++;
    }
    if(biendem>=n)
        cout<<"\n/!\\ KHONG CO THI SINH CAN TIM!!!"<<endl;
}

int checknhap(con_nguoi *x[], int n)
{
    int bd=0;
    for(int j=0; j<n-1; j++)
    {
        if(x[n]->cmnd==x[j]->cmnd || x[n]->getsbd()==x[j]->getsbd())
            bd++;
    }
    return bd;
}

int checksua(con_nguoi *x[], int vitri, int n)
{
    int bd=0;
    for(int i=0; i<n; i++)
    {
        if(x[vitri]->cmnd==x[i]->cmnd || x[vitri]->getsbd()==x[i]->getsbd())
            bd++;
    }
    return bd;
}


int main()
{
    ifstream datain;
    ofstream dataout;
    int n=0;
    con_nguoi *tt[100];
    int m=0;

    con_nguoi *nk[100];
    datain.open("database.txt", ios::in);
    docfilett(datain, tt, n);
    datain.close();

    datain.open("databasenk.txt", ios::in);
    docfilett(datain, nk, m);
    datain.close();
menu:
    int chon;
    string tk;
    string mk;

    cout<<"\n\n\t\t\t*******************************"<<endl;
    cout<<"\t\t\t    Quan Ly Thi Sinh Du Thi    "<<endl;
    cout<<"\t\t\t*******************************"<<endl;
    cout<<"\t\t\t|  1) Admin                   |"<<endl;
    cout<<"\t\t\t|                             |"<<endl;
    cout<<"\t\t\t|  2) Chuc Nang               |"<<endl;
    cout<<"\t\t\t|                             |"<<endl;
    cout<<"\t\t\t|  3) Thoat                   |"<<endl;
    cout<<"\t\t\t|                             |"<<endl;
klc1:
    cout<<"\t\t Vui Long Nhap Lua Chon:";
    cin>>chon;

    switch(chon)
    {
    case 1:   //OK
    {
admin:
        fflush(stdin);
        cout<<"\n\t Vui Long Dang Nhap "<<endl;
        cout<<"\t Nhap Tai Khoan "<<endl;
        getline(cin, tk);
        cout<<"\t Nhap Mat Khau "<<endl;
        getline(cin, mk);

        if(tk == "admin" && mk == "123456")
        {
m1:
            int chon;
            cout<<"\n\n\t\t\t ------------Admin------------"<<endl;
            cout<<"\t\t\t|  1) Them thi sinh          |"<<endl;
            cout<<"\t\t\t|                            |"<<endl;
            cout<<"\t\t\t|  2) Sua thong tin thi sinh |"<<endl;
            cout<<"\t\t\t|                            |"<<endl;
            cout<<"\t\t\t|  3) Xoa thong tin thi sinh |"<<endl;
            cout<<"\t\t\t|                            |"<<endl;
            cout<<"\t\t\t|  4) Xuat danh sach thi sinh|"<<endl;
            cout<<"\t\t\t|                            |"<<endl;
            cout<<"\t\t\t|  5) Quay lai menu chinh    |"<<endl;
            cout<<"\t\t\t|                            |"<<endl;
klc:
            cout<<"\t\t Vui Long Nhap Lua Chon!:";
            cin>>chon;

            switch(chon)
            {
            case 1:
            {
add:
                int chon1;
                cout<<"\n\n\t\t\t------------Them Thi Sinh-----------"<<endl;
                cout<<"\t\t\t|  1) Them thi sinh thuong         |"<<endl;
                cout<<"\t\t\t|                                  |"<<endl;
                cout<<"\t\t\t|  2) Them thi sinh thi nang khieu |"<<endl;
                cout<<"\t\t\t|                                  |"<<endl;
                cout<<"\t\t\t|  3) Quay lai admin               |"<<endl;
                cout<<"\t\t\t|                                  |"<<endl;
mot1:
                cout<<"\t\t Vui Long Nhap Lua Chon!:";
                cin>>chon1;
                switch(chon1)
                {
                case 1:
                {
                    cout<<"\nTHI SINH THU "<<n<<endl;
                    for(int i=0; i<1; i++)
                    {
nhaplai:
                        tt[n] = new dt_thi();
                        tt[n]->nhap();
                        if(checknhap(tt, n)!=0)
                        {
                            cout<<"\n/!\\/!\\ So CMND hoac SBD da ton tai!!"<<endl;
                            cout<<"Moi nhap lai!!"<<endl;
                            goto nhaplai;
                        }
                        n++;
                    }
                    dataout.open("database.txt",ios::out|ios::trunc);
                    ghidulieu(dataout, tt, n);
                    dataout.close();

                    cout<<"\n\n*************************************"<<endl;
                    cout<<">>>>>DA THEM THI SINH THANH CONG<<<<<"<<endl;
                    cout<<"*************************************"<<endl;
                    cout<<"\n***THONG TIN THI SINH VUA NHAP***"<<endl;
                    tt[n-1]->hienthi();
                    break;
                }
                case 2:
                {
                    cout<<"\nTHI SINH THU "<<m<<endl;
                    for(int i=0; i<1; i++)
                    {
nhaplai1:
                        nk[m] = new dt_thi_nk();
                        nk[m]->nhap();
                        if(checknhap(nk, m)!=0)
                        {
                            cout<<"\n/!\\/!\\ So CMND hoac SBD da ton tai!!"<<endl;
                            cout<<"Moi nhap lai!!"<<endl;
                            goto nhaplai1;
                        }
                        m++;
                    }
                    dataout.open("databasenk.txt",ios::out|ios::trunc);
                    ghidulieu(dataout, nk, m);
                    dataout.close();

                    cout<<"\n\n*************************************"<<endl;
                    cout<<">>>>>DA THEM THI SINH THANH CONG<<<<<"<<endl;
                    cout<<"*************************************"<<endl;
                    cout<<"\n***THONG TIN THI SINH VUA NHAP***"<<endl;
                    nk[m-1]->hienthi();
                    break;
                }
                case 3:
                {
                    goto m1;
                }
                default:
                {
                    cout<<"/!\\ Khong co lua chon, moi nhap lai!"<<endl;
                    goto mot1;
                }
                }
                goto add;
            }

            case 2:
            {
edit:
                int chon2;
                cout<<"\n\n\t\t\t-------SUA THONG TIN THI SINH-------"<<endl;
                cout<<"\t\t\t|  1) SUA thong tin thi sinh           |"<<endl;
                cout<<"\t\t\t|                                      |"<<endl;
                cout<<"\t\t\t|  2) SUA thong tin thi sinh nang khieu|"<<endl;
                cout<<"\t\t\t|                                      |"<<endl;
                cout<<"\t\t\t|  3) Quay lai admin                   |"<<endl;
                cout<<"\t\t\t|                                      |"<<endl;
mot2:
                cout<<"\t\t Vui Long Nhap Lua Chon!:";
                cin>>chon2;
                switch(chon2)
                {
                case 1:
                {
                    suafile(tt, n);
                    remove("database.txt");
                    rename("database2.txt","database.txt");
                    break;
                }
                case 2:
                {
                    suafile(nk, m);
                    remove("databasenk.txt");
                    rename("database2.txt","databasenk.txt");
                    break;
                }
                case 3:
                {
                    goto m1;
                }
                default:
                {
                    cout<<"/!\\ Khong co lua chon, moi nhap lai!"<<endl;
                    goto mot2;
                }
                }
                goto edit;
            }

            case 3:
            {
                int chon3;
deletee:
                cout<<"\n\n\t\t\t-------XOA THONG TIN THI SINH-------"<<endl;
                cout<<"\t\t\t|  1) XOA thong tin thi sinh           |"<<endl;
                cout<<"\t\t\t|                                      |"<<endl;
                cout<<"\t\t\t|  2) XOA thong tin thi sinh nang khieu|"<<endl;
                cout<<"\t\t\t|                                      |"<<endl;
                cout<<"\t\t\t|  3) Quay lai admin                   |"<<endl;
                cout<<"\t\t\t|                                      |"<<endl;
mot3:
                cout<<"\t\t Vui Long Nhap Lua Chon!:";
                cin>>chon3;
                switch(chon3)
                {
                case 1:
                {
                    if(xoafile(tt, n)==0)
                    {
                        cout<<"n\n>>>KHONG TIM THAY THI SINH<<<"<<endl;
                    }
                    else
                    {
                        cout<<"n\n****************************************"<<endl;
                        cout<<">>>XOA THONG TIN THI SINH THANH CONG<<<"<<endl;
                        cout<<"***************************************"<<endl;
                        n=n-1;
                    }
                    remove("database.txt");
                    rename("database2.txt","database.txt");
                    break;
                }
                case 2:
                {
                    if(xoafile(nk, m)==0)
                    {
                        cout<<"n\n>>>KHONG TIM THAY THI SINH<<<"<<endl;
                    }
                    else
                    {
                        cout<<"n\n****************************************"<<endl;
                        cout<<">>>XOA THONG TIN THI SINH THANH CONG<<<"<<endl;
                        cout<<"***************************************"<<endl;
                        m=m-1;
                    }
                    remove("databasenk.txt");
                    rename("database2.txt","databasenk.txt");
                    break;
                }
                case 3:
                {
                    goto m1;
                }
                default:
                {
                    cout<<"/!\\ Khong co lua chon, moi nhap lai!"<<endl;
                    goto mot3;
                }
                }
                goto deletee;
            }

            case 4:
            {
                cout<<"\n\n>>>>DANH SACH THI SINH<<<<<"<<endl;
                xuatthongtin(tt, n);
                cout<<"\n\n>>>>DANH SACH THI SINH NANG KHIEU<<<<<"<<endl;
                xuatthongtin(nk, m);
                break;
            }
            case 5:
            {
                goto menu;
            }

            default:
            {
                cout<<"/!\\ Khong co lua chon, moi nhap lai!"<<endl;
                goto klc;
            }
            }
            goto m1;
        }
        else
        {
            cout<<"\n/!\\ Sai Mat Khau hoac Tai Khoan, moi Nhap Lai!"<<endl;
            goto admin;
        }
        break;
    }

    case 2: //OK
    {
chucnang:
        int chon;
        cout<<"\n\n\t\t\t-----------Chuc Nang-----------"<<endl;
        cout<<"\t\t\t|  1) Liet ke thi sinh Dau    |"<<endl;
        cout<<"\t\t\t|                             |"<<endl;
        cout<<"\t\t\t|  2) Sap xep                 |"<<endl;
        cout<<"\t\t\t|                             |"<<endl;
        cout<<"\t\t\t|  3) Tim kiem                |"<<endl;
        cout<<"\t\t\t|                             |"<<endl;
        cout<<"\t\t\t|  4) Thi sinh diem cao nhat  |"<<endl;
        cout<<"\t\t\t|                             |"<<endl;
        cout<<"\t\t\t|  5) Phieu bao diem          |"<<endl;
        cout<<"\t\t\t|                             |"<<endl;
        cout<<"\t\t\t|  6) Quay lai menu chinh     |"<<endl;
        cout<<"\t\t\t|                             |"<<endl;
klc2:
        cout<<"\t\t Vui Long Nhap Lua Chon!:";
        cin>>chon;

        switch(chon)
        {
        case 1:
        {
            cout<<"\n\n==========DANH SACH THI SINH DAU=========="<<endl;
            cout<<"\n\n***DANH SACH THI SINH***"<<endl;
            thisinhdau(tt, n);
            cout<<"\n\n***DANH SACH THI SINH THONG NANG KHIEU***"<<endl;
            thisinhdau(nk, m);
            break;
        }

        case 2:
        {
sx:
            int chon2;
            cout<<"\n\n\t\t\t------------SAP XEP Thi Sinh-----------"<<endl;
            cout<<"\t\t\t|  1) SAP XEP thi sinh thuong         |"<<endl;
            cout<<"\t\t\t|                                     |"<<endl;
            cout<<"\t\t\t|  2) SAP XEP thi sinh thi nang khieu |"<<endl;
            cout<<"\t\t\t|                                     |"<<endl;
            cout<<"\t\t\t|  3) Quay lai Chuc Nang              |"<<endl;
            cout<<"\t\t\t|                                     |"<<endl;
hai2:
            cout<<"\t\t Vui Long Nhap Lua Chon!:";
            cin>>chon2;
            switch(chon2)
            {
            case 1:
            {
                sapxep(tt, n);
                cout<<"\n\n=====DANH SACH THI SINH SAU KHI SAP XEP====="<<endl;
                xuatthongtin(tt, n);
                //Ghi danh sach sap xep vaof file
                dataout.open("sapxep_database.txt", ios::out|ios::trunc);
                ghidulieu(dataout, tt, n);
                cout<<"\n\n>>>>Danh Sach thi sinh Sau khi Sap Xep duoc Ghi vao FILE 'sapxep_database.txt'"<<endl;
                dataout.close();
                break;
            }
            case 2:
            {
                sapxep(nk, m);
                cout<<"\n\n=====DANH SACH THI SINH NANG KHIEU SAU KHI SAP XEP====="<<endl;
                xuatthongtin(nk, m);
                //Ghi danh sach sap xep vaof file
                dataout.open("sapxep_database.txt", ios::out|ios::trunc);
                ghidulieu(dataout, nk, m);
                cout<<"\n\n>>>>Danh Sach thi sinh Sau khi Sap Xep duoc Ghi vao FILE 'sapxep_database.txt'"<<endl;
                dataout.close();
                break;
            }
            case 3:
            {
                goto chucnang;
            }
            default:
            {
                cout<<"/!\\ Khong co lua chon, moi nhap lai!"<<endl;
                goto hai2;
            }
            }
            goto sx;
        }

        case 3:
        {
tk:
            int chon3;
            cout<<"\n\n\t\t\t------------TIM KIEM Thi Sinh-----------"<<endl;
            cout<<"\t\t\t|  1) TIM KIEM thi sinh thuong         |"<<endl;
            cout<<"\t\t\t|                                      |"<<endl;
            cout<<"\t\t\t|  2) TIM KIEM thi sinh thi nang khieu |"<<endl;
            cout<<"\t\t\t|                                      |"<<endl;
            cout<<"\t\t\t|  3) Quay lai Chuc Nang               |"<<endl;
            cout<<"\t\t\t|                                      |"<<endl;
hai3:
            cout<<"\t\t Vui Long Nhap Lua Chon!:";
            cin>>chon3;
            switch(chon3)
            {
            case 1:
            {
                timkiem(tt, n);
                break;
            }
            case 2:
            {
                timkiem(nk, m);
                break;
            }
            case 3:
            {
                goto chucnang;
            }
            default:
            {
                cout<<"/!\\ Khong co lua chon, moi nhap lai!"<<endl;
                goto hai3;
            }
            }
            goto tk;
        }

        case 4:
        {
            cout<<"\n\n>>>>>THI SINH DIEM CAO NHAT<<<<<"<<endl;
            thisinhcaonhat(tt, n);
            cout<<"\n\n>>>>THI SINH NANG KHIEU DIEM CAO NHAT<<<<"<<endl;
            thisinhcaonhat(nk, m);
            break;
        }

        case 5:
        {
pbd:
            int chon5;
            cout<<"\n\n\t\t\t----------PHIEU BAO DIEM Thi Sinh----------"<<endl;
            cout<<"\t\t\t|  1) PHIEU BAO DIEM thi sinh thuong      |"<<endl;
            cout<<"\t\t\t|                                         |"<<endl;
            cout<<"\t\t\t|  2) PHIEU BAO DIEM thi sinh nang khieu  |"<<endl;
            cout<<"\t\t\t|                                         |"<<endl;
            cout<<"\t\t\t|  3) Quay lai Chuc Nang                  |"<<endl;
            cout<<"\t\t\t|                                         |"<<endl;
hai5:
            cout<<"\t\t Vui Long Nhap Lua Chon!:";
            cin>>chon5;
            switch(chon5)
            {
            case 1:
            {
                phieubaodiem(tt, n);
                break;
            }
            case 2:
            {
                phieubaodiem(nk, m);
                break;
            }
            case 3:
            {
                goto chucnang;
            }
            default:
            {
                cout<<"/!\\ Khong co lua chon, moi nhap lai!"<<endl;
                goto hai5;
            }
            }
            goto pbd;
            break;
        }

        case 6:
        {
            goto menu;
        }

        default:
        {
            cout<<"/!\\ Khong co lua chon, moi nhap lai!"<<endl;
            goto klc2;
        }
        }
        goto chucnang;
    }

    case 3:  //OK
    {
        exit(0);
        break;
    }

    default: //OK
    {
        cout<<"Khong co lua chon, moi nhap lai!"<<endl;
        goto klc1;
    }
    }
    goto menu;
    return 0;
}








