#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;

struct Sotr{
    string name;
    string date;
    string role;
    float cash;
};

struct ListItem{
    Sotr sotr;
    ListItem *pNext, *pPred;
};

struct List{
    ListItem *pFirst;
};

void add_in_list(List & list, ListItem *p){
    if (list.pFirst == 0){
        list.pFirst = p;
        list.pFirst->pNext = p;
        list.pFirst->pPred = p;
    }
    else
    {
        p->pNext = list.pFirst;
        p->pPred = list.pFirst->pPred;
        list.pFirst->pPred->pNext = p;
        list.pFirst->pPred = p;
    }
}

void print(List list){
    ListItem *p = list.pFirst;
    do{
        cout << endl << p->sotr.name;
        p = p->pNext;
    } while (p != list.pFirst);
}

void vvod(const string &file){
    int n; //число объектов
    cout << "Vvedite kolichestvo: ";
    cin >> n;
    cin.ignore();
    vector<Sotr> sotr;
    for (int i = 0; i < n; i++){
        sotr.resize(i + 1);
        getline(cin, sotr[i].name);
        getline(cin, sotr[i].date);
        getline(cin, sotr[i].role);
        cin >> sotr[i].cash;
        cin.ignore();
    }
    ofstream myfile;
    myfile.open(file);
    for (int i = 0; i < n; i++){
        myfile << sotr[i].name << endl;
        myfile << sotr[i].date << endl;
        myfile << sotr[i].role << endl;
        myfile << sotr[i].cash << endl;
    }
    myfile.close();
}

void vivod(string file){
    ifstream myFile;
    myFile.open(file);
    vector<Sotr> sotr;
    int i = 0;
    while (!myFile.eof()){
        sotr.resize(i + 1);
        getline(myFile, sotr[i].name);
        getline(myFile, sotr[i].date);
        getline(myFile, sotr[i].role);
        myFile >> sotr[i].cash;
        myFile.ignore();
        i++;
    }
    myFile.close();

    for (int i = 0; i < sotr.size(); i++){
        for (int j = i + 1; j < sotr.size(); j++){
            if (sotr[i].name > sotr[j].name){
                auto t = sotr[i];
                sotr[i] = sotr[j];
                sotr[j] = t;
            }
        }
    }

    for (auto i : sotr){
        cout << i.name << endl << i.date << endl << i.role << endl << i.cash << endl;
    }

    List l1 = { nullptr };
    ListItem *p;

    for (auto k : sotr){
        p->sotr = k;
        add_in_list(l1, p);
    }

    print(l1);
}


int main() {
    string file;
    int comm;
    cout << "File name: ";
//    cin >> file;
    file = "test1.txt";
    cout << "Press 1: ";
//    cin >> comm;
    comm = 2;
    if (comm == 1){
        vvod(file);
    }
    if (comm == 2){
        vivod(file);
    }


    return 0;
}
