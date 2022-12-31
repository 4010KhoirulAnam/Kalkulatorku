#include <iostream>

using namespace std;

struct TNode{
    int data;
    TNode *next;
};
TNode *head, *head2;//global variabel

int isEmpty(){
    if(head==NULL)return 1;
    else return 0;
}
void insertDepan(int databaru){
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;
    if(isEmpty()==1){//kosong
        head=baru;
    }else{//isi
        baru->next = head;
        head=baru;
    }
    cout<<"Data masuk\n";
}
void insertBelakang(int databaru){
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;
    if(isEmpty()==1){
        head=baru;
    }else{
        TNode *bantu;
        bantu=head;
        while(bantu->next!=NULL){
            bantu=bantu->next;
        }
        bantu->next = baru;
    }
    cout<<"Data masuk\n";
}
void insertBelakang2(int databaru){
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;
    if(head2==NULL){
        head2=baru;
    }else{
        TNode *bantu;
        bantu=head2;
        while(bantu->next!=NULL){
            bantu=bantu->next;
        }
        bantu->next = baru;
    }
    cout<<"Data masuk\n";
}
void insertDepan2(int databaru){
    if(databaru%2==0){
        databaru--;
    }
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;
    if(head2==NULL){//kosong
        head2=baru;
    }else{//isi
        baru->next = head2;
        head2=baru;
    }
    cout<<"Data masuk\n";
}
int nbEl(){
    TNode *bantu;
    bantu=head;
    int nb=0;
    if(isEmpty()==0){
        do{
            bantu=bantu->next;
            nb++;
        }while(bantu!=NULL);
        cout << endl;
    }else cout <<"Masih kosong\n";
    return nb;
}

void tambahPosisi(int databaru, int posisi){
    if(isEmpty()==1 || posisi<=1){//tambah depan
        insertDepan(databaru);
    }else if(nbEl()<posisi){//tambah belakang
        insertBelakang(databaru);
    }else{//tambah tengah
        TNode *baru;
        baru = new TNode;
        baru->data = databaru;
        baru->next = NULL;
        TNode *bantu1, *bantu2;
        bantu1=head;
        int counter=1;
        while(counter<posisi){
            if(bantu1->next!=NULL){
                counter++;
                bantu2=bantu1;
                bantu1=bantu1->next;
            }
        }
        bantu2->next=baru;
        baru->next=bantu1;
    }
}
void tampil(){
    TNode *bantu;
    bantu=head;
    if(isEmpty()==0){
        while(bantu!=NULL){
            cout<<bantu->data<<" ";
            bantu=bantu->next;
        }
        cout << endl;
    }else cout <<"Masih kosong\n";
}
void tampil2(){
    TNode *bantu;
    bantu=head2;
    if(head2!=NULL){
        while(bantu!=NULL){
            cout<<bantu->data<<" ";
            bantu=bantu->next;
        }
        cout << endl;
    }else cout <<"Masih kosong\n";
}

void hapusDepan(){
    if(!isEmpty()){
        TNode *bantu;
        bantu=head;
        head=head->next;
        bantu->next=NULL;
        cout<<bantu->data<<" berhasil dihapus\n";
        delete bantu;
    }
    else cout <<"Sudah kosong\n";
}
void hapusBelakang(){
    if(!isEmpty()){
        TNode *bantu1, *bantu2;
        bantu1=head;
        if(bantu1->next==NULL){//sisa1
            head=NULL;
            cout<<bantu1->data<<" berhasil dihapus\n";
            delete bantu1;
        }
        else{
            while(bantu1->next!=NULL){
                bantu2=bantu1;
                bantu1=bantu1->next;
            }
            bantu2->next=NULL;
            cout<<bantu1->data<<" berhasil dihapus\n";
            delete bantu1;
        }
    }
    else cout <<"Sudah kosong\n";
}
void hapusPosisi(int posisi){
    if(posisi<=1){//hapus depan
        hapusDepan();
    }
    else if(posisi>=nbEl()){//hapus belakang ketika posisi terakhir atau lebih
        hapusBelakang();
    }
    else{
        if(nbEl()>=3){//minim 3 elemen
            TNode *bantu1, *bantu2, *del;
            bantu1=head;
            del=bantu1->next;
            bantu2=del->next;
            int hapus=2;
            while(hapus<posisi){
                hapus++;
                bantu1=bantu1->next;
                del=del->next;
                bantu2=bantu2->next;
            }
            cout << del->data<<" berhasil dihapus"<<endl;
            delete(del);
            bantu1->next=bantu2;
        }
    }
}

void hapusAfter(int nilai){
    if(isEmpty()==0){//tidak boleh kosong
        TNode *bantu1, *bantu2, *del;
        bantu1=head;
        bool hps=false;
        while(bantu1->next!=NULL){
            if (bantu1->data==nilai){//ketemu
                del=bantu1->next;
                if(del->next!=NULL){//masih ada elemen di belakngnya lagi
                    bantu2=del->next;
                    bantu1->next=bantu2;
                    nilai=del->data;
                    delete(del);
                    hps=true;
                }else{//tidak elemen lagi dibelakang
                    bantu1->next=NULL;
                    nilai=del->data;
                    delete(del);
                    hps=true;
                }
                break;
            }else{
                bantu1=bantu1->next;//digeser
            }
        }
        if(hps==true){
            cout << nilai << "telah dihapus\n";
        }else{
            cout << "tidak ada after\n";
        }
    }else cout <<"Masih kosong\n";
}

int main(){
    int databaru,posisi;
    /*cout<<"Masukan Data Depan= ";cin>>databaru;
    insertDepan(databaru);
    cout<<"Masukan Data Depan= ";cin>>databaru;
    insertDepan(databaru);
    cout<<"Masukan Data Depan= ";cin>>databaru;
    insertDepan(databaru);*/
    cout<<"Masukan Data Belakang = ";cin>>databaru;
    insertBelakang(databaru);
    cout<<"Masukan Data Belakang = ";cin>>databaru;
    insertBelakang(databaru);
    cout<<"Masukan Data Belakang = ";cin>>databaru;
    insertBelakang(databaru);
    cout<<"Masukan Data tengah = ";cin>>databaru;
    cout<<"Posisi/index Data tengah = ";cin>>posisi;
    tambahPosisi(databaru,posisi);
    tampil();
    cout << nbEl()<<endl;
    cout<<"Hapus after = ";cin>>posisi;
    hapusAfter(posisi);
    tampil();
    cout<<"Hapus after = ";cin>>posisi;
    hapusAfter(posisi);
    tampil();
    cout<<"Hapus after = ";cin>>posisi;
    hapusAfter(posisi);
    tampil();
    cout<<"Hapus after = ";cin>>posisi;
    hapusAfter(posisi);
    tampil();
    cout << nbEl()<<endl;
    /*hapusDepan();
    tampil();
    hapusDepan();
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    hapusBelakang();
    tampil();
    hapusBelakang();
    tampil();
    hapusBelakang();
    hapusDepan();*/
}



/*
void xxxxx(){
    if(!isEmpty()){
        TNode *bantu;
        bantu=head;
        while(bantu!=NULL){
            insertDepan2(bantu->data);
            bantu=bantu->next;
        }
    }
    tampil2();
}*/
