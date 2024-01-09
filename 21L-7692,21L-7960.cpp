#include<iostream>
#include<fstream>
#include<Windows.h>
using namespace std;
int m[900][900];
int i = 0;
int j = 0;
int option = 0;
int f_file_row = 0;
int f_file_colm = 0;
int selection_menu = 0;
int f_file_rindx = 0;
int f_file_cindx = 0;
int f_file_active = 0;
string n_filer;
int counter = 0;
string name[900];
int load_menu_selection = 0;
int n_a = 0;
int n_b = 0;
int load_menu_option = 0;
int m2[900][900];
int PERSON_A_ROW = 0;
int PERSON_B_ROW = 0;
string PERSON_A;
string PERSON_B;
VOID FRND_SUG() {
    cout << "\t\t ENTER THE NUMBER OF PERSON A=";
    cin >> PERSON_A_ROW;
    cout << "\t\t ENTER THE NUMBER OF PERSON B=";
    cin >> PERSON_B_ROW;
    if ((PERSON_A_ROW != PERSON_B_ROW) && (PERSON_A_ROW<= f_file_row && PERSON_B_ROW <= f_file_row)) {
        cout << "FRIEND SUGGETION FOR " << name[PERSON_A_ROW] << " IS = ";
        for (int i = 1; i <= f_file_row; i++) {
            if (m[PERSON_A_ROW][i] == 0 && PERSON_A_ROW != i) {
                cout << name[i] << " ";
            }
        }
        cout << endl;
        cout << "FRIEND SUGGETION FOR " << name[PERSON_B_ROW] << " IS = ";
        for (int i = 1; i <= f_file_row; i++) {
            if (m[PERSON_B_ROW][i] == 0 && PERSON_A_ROW != i) {
                cout << name[i] << " ";
            }
        }
        cout << endl;
        cout << "IF YOU WANT TO MAKE FRIENDS PRESS 6 AND ENTER THIER NUMBERS AGAIN" << endl;
    }
    else
        cout << "INVALID INPUT" << endl;
    cout << "**************************************************************************" << endl;

}
void mutual_frnd() {
    ofstream out_file("MUTUAL_FRIEND.txt");
    cout << "\t\t ENTER THE NUMBER OF PERSON A=";
    cin >> PERSON_A_ROW;
    cout << "\t\t ENTER THE  NUMBER OF PERSON B=";
    cin >> PERSON_B_ROW;
    if (PERSON_A_ROW != PERSON_B_ROW) {
        for (i = 1; i <= f_file_row; i++) {
            if (m[PERSON_A_ROW][i] == 1 && m[PERSON_B_ROW][i] == 1) {
                if (out_file.is_open()) {
                    out_file << "MUTUAL FRIEND  = " << name[i] << endl << "COLUMN LOCATION = " << i << endl;
                    cout << "MUTUAL FRIEND  = " << name[i] << endl << "COLUMN LOCATION = " << i << endl;
                }
            }
        }
    }
    else
        cout << "\t\tINVALID INPUT." << endl;
    out_file.close();
    cout << "**************************************************************************" << endl;


}
void NEW_FRND() {
    cout << "\t\t FRIENDSHIP WILL BE FROM A TO B." << endl;
    cout << "\t\t ENTER THE NUMBER  OF PERSON A=";
    cin >> n_a;
    cout << "\t\t ENTER THE  NAME OF PERSON B=";
    cin >> n_b;
    if (n_a != n_b) {
         counter++;
        m[n_a][n_b] = 1;
        m2[n_a][n_b] = 1;
        m[n_b][n_a] = 1;
        for (int i = 1; i <= f_file_row; i++) {
            for (int j = 1; j <= f_file_row; j++) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
        cout << "INVALID INPUT" << endl;
    cout << "**************************************************************************" << endl;
}
int load_menu() {
    cout << "5->MUTUAL FRIEND." << endl << "6->MAKE NEW FRIEND." << endl << "7->FRIEND SUGGESSTIONS." << endl <<"8->FOR MAIN MENU." << endl << "YOUR SELECTION=";
    cin >> load_menu_option;
    cout << "**************************************************************************" << endl;
    return load_menu_option;
}
void load_f() {
    ifstream f_file("friends.txt");
    if (f_file.is_open()) {
        f_file >> f_file_row;
        cout << "ROWS AND COLUMN (TOTAL PEOPLE)=" << f_file_row << " " << f_file_row << endl;
        m[f_file_row][f_file_row];
        f_file >> f_file_active;
        cout << "ACTIVE STATUS=" << f_file_active << endl;
        for (i = 1; i <= f_file_active; i++) {
            for (j = 1; j <= f_file_active; j++) {
                f_file >> f_file_rindx >> f_file_cindx;
                if (f_file_cindx == f_file_rindx) {
                    m[f_file_rindx][f_file_cindx] = 0;
                }
                if (f_file_cindx != f_file_rindx) {
                    m[f_file_rindx][f_file_cindx] = 1;
                    m2[f_file_rindx][f_file_cindx] = 1;
                    m[f_file_cindx][f_file_rindx] = 1;
                    
                }
            }
        }
        cout << "LOADED SUCCESSFULLY." << endl;
    }
    cout << "YOUR DATA FROM ARRAY" << endl;
    cout << "\t\t\t\t";
    for (int r = 1; r <= f_file_row; r++) {
        for (int c = 1; c <= f_file_row; c++) {

            cout << m[r][c] << " ";
        }
        cout << endl << "\t\t\t\t";
    }
    cout << endl;
    if (!f_file.is_open()) {
        cout << " NOT LOADED SUCCESSFULLY" << endl;
    }
    cout << endl;
}
void load_n() {
    ifstream n_file("names.txt");
    if (n_file.is_open()) {
        for (int i = 1; i <= f_file_row; i++) {
            n_file >> n_filer;
            name[i] = n_filer;
            cout << i << ")" << name[i] << endl;
        }
    }

    cout << "**************************************************************************" << endl;
    do {
        load_menu_selection = load_menu();
        if (load_menu_selection == 5) {
            Sleep(550);
            mutual_frnd();
            cout << endl;
        }
        if (load_menu_selection == 6) {
            Sleep(550);
            NEW_FRND();
            cout << endl;
        }
        if (load_menu_selection == 7) {
            Sleep(550);
            FRND_SUG();
            cout << endl;
        }

    } while (load_menu_selection == 5 || load_menu_selection == 6 || load_menu_selection == 7);

}
void SAVE() {
    ofstream ffile("friends.txt");
    ofstream nfile("names.txt");
    if (nfile.is_open()) {
        for (int i = 1; i <= f_file_row; i++) {
            nfile << name[i] << endl;
        }
    }
    nfile.close();
    if (ffile.is_open()) {
        ffile << f_file_row << endl;
        cout << "TOTAL PEOPLE=" << f_file_row << endl;
        f_file_active = (f_file_active + counter);
        ffile << f_file_active << endl;
        cout << "ACTIVE STATUS=" << f_file_active << endl;
        cout << "DATA HISTORY=" << endl;
        for (int i = 1; i <= f_file_row; i++) {
            for (int j = 1; j <= f_file_row; j++) {
                if (m2[i][j] == 1) {
                    ffile << i << " " << j << endl;
                    cout << i << " " << j << endl;
                }
            }
        }
    }
    ffile.close();
    cout << "SAVED" << endl;
    counter = 0;
}
int present_menu() {
    cout << "**************************************************************************" << endl;
    cout << "*1->LOAD friends.txt" << "\t\t\t\t\t\t\t\t\b\b\b\b\b\b\b*" << endl << "*2->LOAD names.txt" << "\t\t\t\t\t\t\t\t\b\b\b\b\b\b\b*" << endl << "*3->SAVE" << "\t\t\t\t\t\t\t\t\t\b\b\b\b\b\b\b*" << endl << "*4->QUIT" << "\t\t\t\t\t\t\t\t\t\b\b\b\b\b\b\b*" << endl << "*YOUR SELECTION=";
    cin >> option;
    cout << "**************************************************************************" << endl;
    return option;
}
int main() {
    do {
        selection_menu = present_menu();
        if (selection_menu == 1) {
            Sleep(550);
            load_f();
        }
        if (selection_menu == 2) {
            Sleep(550);
            load_n();
        }
        if (selection_menu == 3) {
            Sleep(550);
            SAVE();
        }
    } while (selection_menu == 1 || selection_menu == 2 || selection_menu == 3);
    return 0;
}

