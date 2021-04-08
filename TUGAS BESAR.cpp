#include<iostream>
#include<string.h>
#include<cstdlib>
#include<cstdio>
#include<conio.h>

using namespace std;


  struct song   
            {
                string nama_lagu;
                string artist;
                string genre;
                string label;
                double durasi;
                struct song *next;
                struct song *prev;
            }*start,*last;

    int counter =0;

class Songplayer    
{
    public:
            Songplayer()    
            {
                start = NULL;            

                last = NULL;         

            }

            song *create_song(string,string,string,string,double );
            void insert_begin();    //tambahkan lagu di awal.
            void insert_last();     //tambahkan lagu pada akhir.
            void insert_pos();      //tambahkan lagu pada posisi yang diinginkan.
            void delete_pos();      //hapus lagu pada posisi yang diinginkan.
            void search();          //mencari lagu.
            void del_search();      //cari lagu dan hapus.
            void sort1();           //sorting
            void display();         //tampilkan play list.
            void reverse();         //membalikkan play list.
            
};

int main()

{

    int choice;

    Songplayer s;	//objek


    while (1)

    {

        cout<<"======================================="<<endl;

        cout<<"	Aplikasi Playlist Lagu "<<endl;

        cout<<"======================================="<<endl;

        cout<<"1.Masukan lagu di awal"<<endl;

        cout<<"2.Masukan lagu di akhir"<<endl;

        cout<<"3.Masukkan lagu pada posisi yang diinginkan"<<endl;

        cout<<"4.Hapus lagu pada posisi yang diinginkan"<<endl;

        cout<<"5.Cari lagu"<<endl;

        cout<<"6.Hapus lagu yang dicari"<<endl;

        cout<<"7.Urutkan Playlist"<<endl;

        cout<<"8.Tampilkan Playlist"<<endl;

        cout<<"9.Reverse the PlayList"<<endl;

        cout<<"10.Exit"<<endl;



        cout<<"Masukan Pilihan Mu	: ";

        cin>>choice;

        switch(choice)

        {

        case 1:

            s.insert_begin();
            break;


        case 2:

            s.insert_last();
            break;

        case 3:

            s.insert_pos();
            break;

        case 4:

            s.delete_pos();
            break;

        case 5:

            s.search();
            break;

        case 6:

            s.del_search();
            break;

        case 7:

            s.sort1();
            break;

        case 8:

            s.display();
            break;

        case 9:

            s.reverse();
            break;
            
        case 10:

            exit(1);

        default:

            cout<<"Pilihan tidak ada, Anda salah"<<endl;

        }

    }

    return 0;

}

song* Songplayer::create_song(string sname,string sartist,string sgenre,string slabel,double slength)     
{
    counter++;

    struct song *temp;

    temp = new(struct song);

    temp->nama_lagu = sname;
    temp->artist = sartist;
    temp->genre = sgenre;
    temp->label = slabel;
    temp->durasi = slength;

    temp->next = NULL;
    temp->prev = NULL;

    return temp;

}

void Songplayer::insert_begin()                                                 

{

    string nama_lagu,artist,genre,label;
    double durasi;

    cout<<"Masukan Nama Lagu\t:";
		cin.ignore();
        getline(cin, nama_lagu);
    cout<<endl<<"Masukan Nama Artist\t:";
        getline(cin, artist);
    cout<<endl<<"Masukan Genre Lagu\t:";
        cin>>genre;
    cout<<endl<<"Masukan Label Lagu\t:";
        cin>>label;
    cout<<endl<<"Masukan Durasi Lagu\t:";
        cin>>durasi;
    

    struct song *temp;
    temp = create_song(nama_lagu,artist,genre,label,durasi);

    if (start == last && start == NULL)
    {

        start = last = temp;

        start->next = last->next = NULL;
        start->prev = last->prev = NULL;
        cout<<"Lagu berhasil dimasukkan dalam empty list"<<endl;
        cout<<endl;
    }

    else

    {

        temp->next = start;
        start->prev = temp;

        start = temp;

        start->prev = last;
        last->next = start;

        cout<<"lagu berhasil dimasukkan"<<endl;
        cout<<endl;
    }

}


void Songplayer::insert_last()                                                     

{

    string nama_lagu,artist,genre,label;
    double durasi;

    cout<<"Masukan Nama Lagu\t:";
		cin.ignore();
        getline(cin, nama_lagu);
    cout<<endl<<"Masukan Nama Artist\t:";
        getline(cin, artist);
    cout<<endl<<"Masukan Genre Lagu\t:";
        cin>>genre;
    cout<<endl<<"Masukan Label Lagu\t:";
        cin>>label;
    cout<<endl<<"Masukan Durasi Lagu\t:";
        cin>>durasi;
	
    struct song *temp;

    temp = create_song(nama_lagu,artist,genre,label,durasi);

    if (start == last && start == NULL)

    {

        start = last = temp;

        start->next = last->next = NULL;
        start->prev = last->prev = NULL;

        cout<<"Lagu berhasil dimasukkan dalam empty list"<<endl;

    }

    else

    {
        last->next = temp;
        temp->prev = last;

        last = temp;

        start->prev = last;
        last->next = start;

        cout<<"lagu berhasil dimasukkan"<<endl;
    }

}

void Songplayer::insert_pos()                            

{
    string nama_lagu,artist,genre,label;
    double durasi;
    int  pos, i;

    cout<<"Masukan Nama Lagu\t:";
		cin.ignore();
        getline(cin, nama_lagu);
    cout<<endl<<"Masukan Nama Artist\t:";
        getline(cin, artist);
    cout<<endl<<"Masukan Genre Lagu\t:";
        cin>>genre;
    cout<<endl<<"Masukan Label Lagu\t:";
        cin>>label;
    cout<<endl<<"Masukan Durasi Lagu\t:";
        cin>>durasi;
    


    cout<<endl<<"Masukkan posisi lagu yang ingin Anda masukkan: ";
        cin>>pos;

    struct song *temp,*q,*ptr;

    temp = create_song(nama_lagu,artist,genre,label,durasi);

    if (start == last && start == NULL)
    {
        if (pos == 1)
        {

            start = last = temp;

            start->next = last->next = NULL;
            start->prev = last->prev = NULL;

            cout<<"Lagu berhasil dimasukkan dalam empty list"<<endl;
        }
        else
        {
            cout<<"Position out of range"<<endl;
            counter--;
            return;
        }
    }
    else
    {
        if (counter < pos)
        {
             cout<<"Position out of range"<<endl;
             counter--;
             return;
        }
        q = start;
        for (i = 1;i <= counter;i++)
        {
            ptr = q;
            q = q->next;
            if (i == pos - 1)
            {
                ptr->next = temp;
                temp->prev = ptr;
                temp->next = q;
                q->prev = temp;

                cout<<"Lagu berhasil dimasukkan di posisi "<<pos<<endl;
                break;
            }
        }
    }
}

void Songplayer::delete_pos()                                                        
{
    int pos, i;
    song *ptr, *s;

    if (start == last && start == NULL)
    {
        cout<<"Play list tidak ada "<<endl;
        return;
    }

    cout<<endl<<"Masukkan posisi elemen yang akan dihapus: ";
        cin>>pos;

    s = start;

    if(pos == 1)
    {
        counter--;
        last->next = s->next;
        s->next->prev = last;

        start = s->next;
        free(s);
        cout<<"Lagu berhasil dihapus "<<endl;

        return;

    }

    for (i = 0;i < pos - 1;i++ )
    {
        s = s->next;
        ptr = s->prev;

    }
    ptr->next = s->next;
    s->next->prev = ptr;

    if (pos == counter)
    {
        last = ptr;
    }
    counter--;
    free(s);
    cout<<"Lagu berhasil dihapus"<<endl;

}


void Songplayer::search()                                       
{    int pos = 0, i;
    bool flag = false;
    struct song *s;
    string sname;

    if (start == last && start == NULL)
    {
        cout<<" Play list tidak dibuat, tidak ada yang bisa dicari "<<endl;
        return;

    }
    cout<<endl<<"Masukkan nama lagu yang akan dicari: ";
        cin>>sname;

    s = start;
    for (i = 0;i < counter;i++)
    {
        pos++;
        if (s->nama_lagu == sname)
        {
            cout<<"lagu "<<sname<<" berada di posisi: "<<pos<<endl;
            flag = true;
        }
        s = s->next;
    }
    if (!flag)
        cout<<"lagu tidak ditemukan dalam play list"<<endl;

}



void Songplayer::del_search()                                       
{
    int  i;
    bool flag = false;
    struct song *s;
    string sname;

    if (start == last && start == NULL)
    {
        cout<<" Play list tidak dibuat, tidak ada yang bisa dicari "<<endl;
        return;

    }
    cout<<endl<<"Masukkan nama lagu yang akan dicari: ";
        cin>>sname;

    s = start;
    for (i = 0;i < counter;i++)
    {
        
        if (s->nama_lagu == sname)
        {
            cout<<"Lagu "<<sname<<" ditemukan di posisi: "<<endl;
            flag = true;
            delete s;
            cout<<"  Berhasil dihapus "<<endl;
        }
        s = s->next;
    }
    if (!flag)
        cout<<"lagu tidak ditemukan dalam play list"<<endl;

}

void Songplayer::sort1()                                                
{
    struct song *temp, *s;
    int i;
    string str;

    if (start == last && start == NULL)
    {
        cout<<"Play list kosong, tidak ada yang menyortir"<<endl;
        return;
    }

    s = start;
    for (i = 0;i < counter;i++)
    {
        temp = s->next;

        while (temp != start)
        {
            if (s->nama_lagu  > temp->nama_lagu)
            {
                str = s->nama_lagu;
                s->nama_lagu = temp->nama_lagu;
                temp->nama_lagu = str;
            }
            temp = temp->next;
        }
        s = s->next;
    }

}


void  Songplayer::display()
{
    int i;
    struct song *s;

	cout<<"\tLIST PLAYLIST LAGU\t"<<endl;
	cout<<"<-------------------------------->"<<endl<<endl;
    if (start == last && start == NULL)
    {
        cout<<"Play list kosong, tidak ada yang bisa ditampilkan"<<endl;
        return;
    }

    s = start;

    for (i = 0;i < counter-1;i++)
    {
		cout<<"Lagu \t\t:";
			cout<<s->nama_lagu<<endl;
		cout<<"Artist \t\t:";
			cout<<s->artist<<endl;
		cout<<"Genre \t\t:";
			cout<<s->genre<<endl;
		cout<<"Label \t\t:";
			cout<<s->label<<endl;
		cout<<"Durasi(menit) \t:";
			cout<<s->durasi<<endl;
		cout<<"<=========================>"<<endl;
        s = s->next;
    }
    cout<<"Lagu \t\t:";
			cout<<s->nama_lagu<<endl;
		cout<<"Artist \t\t:";
			cout<<s->artist<<endl;
		cout<<"Genre \t\t:";
			cout<<s->genre<<endl;
		cout<<"Label \t\t:";
			cout<<s->label<<endl;
		cout<<"Durasi(menit) \t:";
			cout<<s->durasi<<endl;
		cout<<"<=========================>"<<endl;
        s = s->next;




}

void Songplayer::reverse()
{
    if (start == last && start == NULL)
    {
        cout<<"Play list kosong, tidak ada yang bisa dibalik"<<endl;
        return;
    }
    struct song *p1, *p2;

    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;

    while (p2 != start)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }

    last = start;
    start = p1;

    cout<<"play list berhasil dibalik"<<endl;

}



