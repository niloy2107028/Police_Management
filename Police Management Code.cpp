#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int no_of_fir = 0;
int no_of_criminals = 0;
int no_of_police = 0;

class police;
class criminal;
class court;
class police_management;

class police
{
private:
    int police_badge_no;
    string police_name;
    string police_status;

public:
    void set()
    {
        cout <<endl<<"Enter police badge no: ";
        cin >> police_badge_no;
        cout <<endl<< "Enter police name: ";
        cin >> police_name;
        cout <<endl<< "Enter police current status: ";
        cin >> police_status;
    }
    void get()
    {
        cout <<endl<< "Police badge no: " << police_badge_no << endl;
        cout <<endl<< "Police name: " << police_name << endl;
        cout <<endl<< "Police current status: " << police_status << endl;
        cout <<endl<< "------------------------" << endl;
    }

    friend police_management;
};

class criminal
{
private:
    int criminal_badge_no;
    string criminal_name;
    int criminal_age;
    string criminal_offense;
    int fir_num;

public:
    void set(string cr_name, string ofn, int firno)
    {
        cout <<endl<<"Enter criminal badge no: ";
        cin >> criminal_badge_no;
        cout << endl<<"Enter criminal age: ";
        cin >> criminal_age;
        criminal_name = cr_name;
        criminal_offense = ofn;
        fir_num = firno;
    }
    void set()
    {
        cout << endl<<"Enter criminal badge no: ";
        cin >> criminal_badge_no;
        cout << endl<<"Enter criminal fir no: ";
        cin >> fir_num;
        cout <<endl<< "Enter criminal name: ";
        cin >> criminal_name;
        cout <<endl<<"Enter criminal age: ";
        cin >> criminal_age;
        cout << endl<<"Enter criminal offense: ";
        cin >> criminal_offense;
    }
    void get()
    {
        cout << endl<<"Criminal badge no: " << criminal_badge_no << endl;
        cout << endl<<"Criminal fir no: " << fir_num << endl;
        cout << endl<<"Criminal name: " << criminal_name << endl;
        cout << endl<<"Criminal age: " << criminal_age << endl;
        cout << endl<<"Criminal offense: " << criminal_offense << endl;
        cout << endl<<"------------------------" << endl;
    }
    friend police_management;
};

class fir
{
private:
    int fir_id;
    string fir_type;
    string fir_time_date;
    string fir_location;
    string fir_victim;
    string fir_status;

    int no_of_witness_under_victim;
    string suspect;

    int no_of_witnesses_under_suspect;
    police investigating_officer;
    string fir_result;

public:
    void set()
    {
        cout << endl<<"Enter a fir number: ";
        cin >> fir_id;
        cout << endl<<"Enter fir type: ";
        cin >> fir_type;
        cout <<endl<<"Enter fir date_time: ";
        cin >> fir_time_date;
        cout << endl<<"Enter fir location: ";
        cin >> fir_location;
        cout << endl<<"Enter fir victim's name: ";
        cin >> fir_victim;
        cout << endl<<"Enter fir status: ";
        cin >> fir_status;

        investigating_officer.set();
        cout << endl<<"Enter number of witnesses under victim: ";
        cin >> no_of_witness_under_victim;

        cout << endl<<"Enter suspect's name: ";
        cin >> suspect;
    }

    void get()
    {
        cout << endl<<"Fir number: " << fir_id << endl;
        cout << endl<<"Fir type: " << fir_type << endl;
        cout << endl<<"Fir occurring date and time: " << fir_time_date << endl;
        cout << endl<<"Fir location: " << fir_location << endl;
        cout << endl<<"Fir victim: " << fir_victim << endl;
        cout << endl<<"Fir current status: " << fir_status << endl;

        investigating_officer.get();

        cout << endl<<"Number of witnesses under victim: " << no_of_witness_under_victim << endl;

        cout << endl<<"Suspect's name: " << suspect << endl;
        cout << endl<<"Fir result: " << fir_result << endl;

        cout << endl<<"--------------------------------" << endl;
    }

    friend court;

    int firid()
    {
        return fir_id;
    }
    string fir_suspect_name()
    {
        return suspect;
    }
    string fir_offence_name()
    {
        return fir_type;
    }

    friend police_management;
    friend bool tribunal(fir &object, int firid);
};

class court
{
private:
    int no_of_witnesses_under_suspect;

public:
    void set()
    {
        cout << endl<<"Enter no of witnesses under suspect: ";
        cin >> no_of_witnesses_under_suspect;
    }

    void get()
    {
        cout << endl<<"Number of witnesses under suspect: " << no_of_witnesses_under_suspect << endl;
    }


    friend police_management;
};

class police_management
{
private:
    police po[101];
    criminal cr[101];
    court co[101];
    fir fr[101];

public:
    void fir_reg()
    {
        fr[no_of_fir].set();
        no_of_fir++;
    }

    void display_all_pending_fires()
    {
        int x = 0;
        cout <<endl<< "Pending fires list:" << endl;
        cout << endl<<"------------------------" << endl;
        for (int i = 0; i < no_of_fir; i++)
        {
            if (fr[i].fir_status == "unsolved")
            {
                fr[i].get();
                x++;
            }
        }
        if (x == 0)
        {
            cout <<endl<< "No pending fires" << endl;
        }
    }

    void display_all_solved_fires()
    {
        int x = 0;
        cout << endl<<"Solved fires list:" << endl;
        cout << endl<<"------------------------" << endl;
        for (int i = 0; i < no_of_fir; i++)
        {
            if (fr[i].fir_status == "solved")
            {
                fr[i].get();
                x++;
            }
        }
        if (x == 0)
        {
            cout << endl<<"No solved fires" << endl;
        }
    }

    void tribunal(int firid)
    {
        for (int i = 0; i < no_of_fir; i++)
        {
            if (fr[i].fir_id == firid)
            {
                cout << endl<<"Enter no of witnesses under suspect: ";
                cin >> fr[i].no_of_witnesses_under_suspect;
                if (fr[i].no_of_witnesses_under_suspect < fr[i].no_of_witness_under_victim)
                {
                    cout << endl<<fr[i].suspect << " is a criminal" << endl;
                    fr[i].fir_status = "solved";
                    fr[i].fir_result = "suspect is a criminal";
                    cr[no_of_criminals].set(fr[i].fir_suspect_name(), fr[i].fir_offence_name(), fr[i].firid());
                    cr[no_of_criminals].get();
                    no_of_criminals++;
                }
            }
        }
    }

    void police_reg()
    {
        po[no_of_police].set();
        no_of_police++;
    }

    void display_all_police_officers()
    {
        int x = 0;
        cout <<endl<<"Displaying all police officers:" << endl;
        cout << "------------------------" << endl;
        for (int i = 0; i < no_of_police; i++)
        {
            cout << endl<<"Police " << i + 1 << " details:" << endl;
            po[i].get();
            x++;
        }

        if (x == 0)
        {
            cout << endl<<"No police officer here" << endl;
        }
    }

    void criminal_reg()
    {
        cr[no_of_criminals].set();
        no_of_criminals++;
    }

    void display_all_criminals()
    {
        int x = 0;
        cout <<endl<<"Displaying all criminals:" << endl;
        cout << endl<<"------------------------" << endl;
        for (int i = 0; i < no_of_criminals; i++)
        {
            cout <<endl<< "Criminal " << i + 1 << " :" << endl;
            cr[i].get();
            x++;
        }

        if (x == 0)
        {
            cout << endl<<"No criminals here" << endl;
        }
    }

    void search_police(int p_id)
    {
        for (int i = 0; i < no_of_police; i++)
        {
            if (po[i].police_badge_no == p_id)
            {
                po[i].get();
            }
            else
            {
                cout <<endl<< "Invalid police badge no." << endl;
            }
        }
    }

    void search_criminal(int cr_id)
    {
		int x=0;
        for (int i = 0; i < no_of_criminals; i++)
        {
            if (cr[i].criminal_badge_no == cr_id)
            {
                cr[i].get();
				x++;
				break;
            }
           
        }
		if(x==0){
			cout<<endl<<endl<<"Invalid criminal badge no."<<endl;
		}
    }

    void search_fir(int fr_id)
    {
        for (int i = 0; i < no_of_fir; i++)
        {
            if (fr[i].fir_id == fr_id)
            {
                fr[i].get();
            }
            else
            {
                cout <<endl<< "Invalid fir no." << endl;
            }
        }
    }
};

int main()
{
    string password_admin="2107028_niloy";

    cout<<endl<<"------WELCOME TO THE POLICE SYSTEM------"<<endl<<endl;

    string temp_password;

    cout<<"ENTER THE PASSWORD FOR LOGIN (PASSWORD:2107028_niloy): ";
    cin>>temp_password;



    if(password_admin==temp_password){
        cout<<endl<<"------------LOGIN SUCCESSFUL-------------"<<endl;
            police_management pm;
    char choice;
    int operation;
    do{
    
        cout<<endl<<"YOU CAN PERFORM THE FOLLOWING OPERATION"<<endl;
        cout << endl<<"Choose one of the following:" << endl;
        cout << endl<<"1. Register a FIR." << endl;
        cout << endl<<"2. Display all pending FIRs." << endl;
        cout << endl<<"3. Display all solved FIRs." << endl;
        cout << endl<<"4. Solve a FIR via Court." << endl;
        cout << endl<<"5. Register police officers." << endl;
        cout << endl<<"6. Display all police officers." << endl;
        cout << endl<<"7. Register criminals." << endl;
        cout << endl<<"8. Display all criminals." << endl;
        cout << endl<<"9. Search a police." << endl;
        cout << endl<<"10. Search a criminal." << endl;
        cout << endl<<"11. Search a FIR." << endl;
        cout << endl<<"12. Exit." << endl;

        cout << endl<<"Your choice: ";
        cin >> operation;

        switch (operation)
        {
        case 1:
            pm.fir_reg();
            cout << endl<<"Entry successful.\n";
            break;
        case 2:
            pm.display_all_pending_fires();
            break;
        case 3:
            pm.display_all_solved_fires();
            break;
        case 4:
            int id;
            cout << endl<<"Enter the fir id of the unsolved fir: ";
            cin >> id;
            pm.tribunal(id);
            break;
        case 5:
            int np;
            cout << endl<<"How many police officers you want to register: ";
            cin >> np;
            for (int i = 0; i < np; i++)
            {
                cout << endl<<"Enter police " << i + 1 << " details: " << endl;
                pm.police_reg();
            }
            cout << endl<<"Entry successful.\n";
            break;
        case 6:
            pm.display_all_police_officers();
            break;
        case 7:
            int nc;
            cout << endl<<"How many criminals you want to register: ";
            cin >> nc;
            for (int i = 0; i < nc; i++)
            {
                cout <<endl<<"Enter criminal " << i + 1 << " details: " << endl;
                pm.criminal_reg();
            }
            cout << endl<<"Entry successful.\n";
            break;
        case 8:
            pm.display_all_criminals();
            break;
        case 9:
            int pid;
            cout << endl<<"Enter a valid police badge no: ";
            cin >> pid;
            pm.search_police(pid);
            break;
        case 10:
            int crid;
            cout << endl<<"Enter a valid criminal badge no: ";
            cin >> crid;
            pm.search_criminal(crid);
            break;
        case 11:
            int firid;
            cout <<endl<< "Enter a valid fir no: ";
            cin >> firid;
            pm.search_fir(firid);
            break;
        case 12:
            return 0;
        default:
            cout << endl<<"Invalid operation selected." << endl;
        }

        cout << endl<<"Wanna continue? (y/n): ";
        cin >> choice;
        system("cls");
    } while (choice == 'y' || choice == 'Y');

    return 0;
    }
    else{
        cout<<endl<<"WRONG PASSWORD"<<endl;
    }



}
