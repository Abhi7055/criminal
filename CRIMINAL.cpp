#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstdlib>
#include<cstring>
using namespace std;
void add();
void file_in();
void file_out();
void file_search();
void file_modify();
void deleter();
class addrecord
{
    private:
            char name[30],gender[30],crime[30],
            address[50],victim[30],vadd[30],adate[30],rdate[30];
            int n,y,weight,contact,punishment;
            float height;
    public:
        void login();
        void mainmenu();
        void input();
        void output();
        void searchrecord();
        void editrecord();
        void viewrecord();
        void deleterecord();
        int return_code()
        {
            return n;
        }
};
int main()
{
    system("color ff");
   cout<<"\t   WELCOME TO THE CRIMINAL RECORD MANAGEMENT SYSTEM"<<endl;
    addrecord p;
    system("pause");
    system("cls");
    cout<<"\tWELCOME TO THE LOGIN MENU "<<endl;
    p.login();
    p.mainmenu();
    return 0;
}
void addrecord::login()
{
    int i=0,j=0,c;
    char uname[10],p[10]="criminal",q[10]="1234";
    char pword[10];
    do
    {
        cout<<"\n                     PLEASE LOGIN FIRST                  "<<endl;
        cout<<"\n\t\tENTER USERNAME:"<<"\t";
        cin>>uname;
        cout<<"\n\t\tENTER PASSWORD:"<<"\t";
        while(i<5)
        {
            pword[i]=_getch();
            c=pword[i];
            if(c==13) break;
            else cout<<"*";
            i++;
        }
        pword[i]='\0';
        i=0;
        system("cls");
        if(strcmp(uname,p)==0 && strcmp(pword,q)==0)
        {
            break;
        }
        else
        {
            cout<<".OOPS...Login Unsuccessful"<<endl;
            j++;
            _getch();
            system("cls");
        }
    }
    while(j<=2);
    if(j>2)
    {
        cout<<"\n\t   ! SORRY YOU HAVE ENTERED THE WRONG\n\t   USER NAME OR PASSWORD FOR MANY TIMES "<<endl;
        _getch();
        exit(0);
    }
    system("cls");
}
void addrecord::mainmenu()
{
        cout<<" \n \t\t MAIN MENU OF CRIMINAL RECORD MANAGEMENT SYSTEM   "<<endl;
        cout<<"\n\n \t\t: : MAIN MENU: :-\n"<<endl;
        cout<<"\t1. ADD RECORD"<<endl;
        cout<<"\n\t2. SEARCH RECORD"<<endl;
        cout<<"\n\t3. EDIT RECORD"<<endl;
        cout<<"\n\t4. VIEW RECORD"<<endl;
        cout<<"\n\t5. DELETE RECORD"<<endl;
        cout<<"\n\t6. EXIT"<<endl;
        cout<<"\n\n\tEnter your choice:-\t\t";
        int n;
        cin>>n;
                switch(n)
        {
        case 1:
                add();
                break;
        case 2:
                searchrecord();
                break;
        case 3:
                editrecord();
                break;
        case 4:
                viewrecord();
                break;
        case 5:
                deleterecord();
                break;
        case 6:
                system("cls");
                _getch();
                exit(0);
            default:
                system("cls");
                cout<<"\n\n OOPS ! YOU ENTER WRONG CHOICE.PRESS AGAIN.....\n"<<endl;
                system("pause");
                system("cls");
                mainmenu();
                _getch();
                break;
            }
}
void addrecord::input()
{
        cout<<"CRIMINAL Code:\t";
        cin>>n;
        cout<<endl;
        cout<<"Criminal's full  name:\t";
        cin.ignore();
        cin.getline(name,30);
        cout<<endl;
        cout<<"Age:\t";
        cin>>y;
        cout<<endl;
        cout<<"Gender:\t";
        cin.ignore();
        cin.getline(gender,30);
        cout<<endl;
        cout<<"Crime :\t";
        cin.getline(crime,30);
        cout<<endl;
        cout<<"Victim's name:\t";
        cin.getline(victim,30);
        cout<<endl;
        cout<<"Victim's Address:\t";
        cin.getline(vadd,30);
        cout<<endl;
        cout<<"Punishment(year):\t";
        cin>>punishment;
        cout<<endl;
        cout<<"Convict Address:\t";
        cin.ignore();
        cin.getline(address,50);
        cout<<endl;
        cout<<"Arrest Date:\t";
        cin.ignore();
        cin.getline(adate,30);
        cout<<endl;
        cout<<"Release Date:\t";
        cin.getline(rdate,30);
        cout<<endl;
}
void addrecord::output()
{      cout<<"Details:"<<endl;
       cout<<endl;
        cout<<"\nCRIMINAL Code:"<<n<<endl<<endl;
        cout<<"Criminal's full  name:"<<name<<endl<<endl;
        cout<<"Age:"<<y<<endl<<endl;
        cout<<"Gender:"<<gender<<endl<<endl<<"Crime :"<<crime<<endl<<endl;
        cout<<"Victim's name:"<<victim<<endl<<endl<<"Victim's Address:\t"<<vadd<<endl<<endl;
        cout<<"Punishment(year):\t"<<punishment<<endl;
        cout<<"Convict Address:\t"<<address<<endl<<endl<<"Arrest Date:\t"<<adate<<endl<<endl<<"Release Date:\t"<<rdate<<endl<<endl;
        cout<<endl;
}
void addrecord::searchrecord()
{
    system("cls");
    cout<<"\t\t        SEARCH RECORD       \t"<<endl;
    file_search();
    cout<<"\t\tDo you want to search Again ? Press Y/y";
    cout<<"\n\t\t Or ! press any key to go back to the main menu\t:";
    char h;
    h=_getch();
    if(h=='Y' || h=='y')
    {
        searchrecord();
    }
    else
    {
        system("cls");
        mainmenu();
    }
}
void addrecord::editrecord()
{
    system("cls");
    cout<<"\t\t        EDIT RECORD          "<<endl;
    file_modify();
    cout<<"\t\tDo you want to Edit Again ? Press Y/y";
    cout<<"\n\t\t Or ! press any key to go back to the main menu\t:";
    char m;
    m=_getch();
    if(m=='Y' || m=='y')
    {
        editrecord();
        cout<<"\n\t\tRecord Updated...";
    }
    else
    {
        cout<<"You Enter wrong choice\n\n";
        system("cls");
        mainmenu();
    }
}
void addrecord::viewrecord()
{
    system("cls");
    file_out();
    system("cls");
    mainmenu();
}
void addrecord::deleterecord()
{
    system("cls");
    cout<<"     DELETE ANY CONVICT'S RECORD   "<<endl;
    deleter();
    cout<<"\t\tDo you want to delete another record ? Press Y/y";
    cout<<"\n\t\t Or ! press any key to go back to the main menu\t:";
    char m;
    m=_getch();
    if(m=='Y' || m=='y')
    {
        deleter();
        cout<<"\n\t\tRecord Updated...";
    }
    else
    {
        cout<<"Record not Found\n\n";
        system("cls");
        mainmenu();
    }
}
void file_in()
{
        addrecord p;
        ofstream file;
        file.open("information.data",ios::binary |ios::app);
        if(!file.is_open())
        {
            cout<<"file doesn't exist"<<endl;
        }
        else
        {
            p.input();
            file.write((char*)(&p),sizeof(addrecord));
        }
}
 void file_out()
{
        addrecord p;
        ifstream file;
        file.open("information.data",ios::binary);
        if(!file.is_open())
        {
            cout<<"file doesn't exist"<<endl;
        }
        else
        {
            while(file.read( (char*)(&p) ,sizeof(addrecord)))
            {
    cout<<"\t\t       VIEWED ALL RECORD      \n";
                p.output();
                cout<<"\t\tPress Enter to watch more record:.....";
                system("pause");
                system("cls");
            }
        }
        file.close();
}
void add()
{
        char k;
        addrecord p;
        system("cls");
        cout<<"\t\t                    ADD CONVICT RECORD          "<<endl;
        file_in();
        cout<<"\n\t\trecord added.........."<<endl;
        cout<<"\t\tDo you wants to add another record?  press:y/Y"<<"\n";
        cout<<"\t\tOr,Press any key to go back main menu:\t";
        k=_getch();
        if(k=='Y' || k=='y')
        {
            add();
        }
        else
        {
            system("cls");
            p.mainmenu();
        }
}
void file_search()
{
    addrecord p;
    cout<<"\n\nEnter criminal's code for searching..:\t";
    int L;
    cin>>L;
    fstream file;
    file.open("information.data",ios::in | ios::out |ios::binary);
    if(!file.is_open())
    {
        cout<<"File doesn't exist";
    }
    else
    {
        while(!file.eof())
        {
            file.read((char*)(&p),sizeof(addrecord));
            if(p.return_code()==L)
            {
                p.output();
            file.read((char*)(&p),sizeof(addrecord));
                file.close();
            }
        }
    }
}
void file_modify()
{
    int k;
    cout<<"Enter criminal's code for editing\t:";
    cin>>k;
    cout<<endl;
    addrecord p;
    bool found=false;
    fstream file;
    file.open("information.data",ios::in | ios::out | ios::binary);
    file.seekg(0);
	if(!file)
	{
		cout<<"\n\nFIle doesn't exist !!\t";
		system("pause");
		system("cls");
		p.mainmenu();
	}
	while(!file.eof() && found==false)
	{
		file.read((char*)(&p),sizeof(addrecord));
		if(p.return_code()==k)
		{
			cout<<"\n\nEnter The New Details of account"<<endl;
			p.input();
			int pos=(-1)*static_cast<int>(sizeof(addrecord));
			file.seekp(pos,ios::cur);
			file.write((char*)(&p),sizeof(addrecord));
			cout<<"\n\n\tRecord Updated......\n";
			found=true;
		  }
	}
	file.close();
	if(found==false)
    cout<<"\n\nRecord Not Found ";
}
void deleter()
{
    cout<<"\nWhich information you want to delete? Enter code:\t";
    int f;
    cin>>f;
    addrecord p;
    ifstream file;
    ofstream ofile;
    file.open("information.data",ios::binary);
    if(!file.is_open())
    {
        cout<<"\nFile doesn't exist";
    }
    ofile.open("temp.data",ios::binary);
    file.seekg(0,ios::beg);
    while(file.read((char*)(&p),sizeof(addrecord)))
    {
        if(p.return_code()!=f)
        {
            ofile.write((char*)(&p),sizeof(addrecord));
        }
    }
    ofile.close();
    file.close();
    remove("information.data");
    rename("temp.data","information.data");
    cout<<"\n\tRecord deleted...\n";
}
