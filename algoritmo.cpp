#include <iostream>
#include <iomanip>
#include <sys/stat.h>
#include <ctime>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

class Arma
{
private:
    string nome = "";
    string tipo = "";
    int danno = 0;

public:
    Arma() {}
    Arma(string _nome, string _tipo, int _danno = 10)
    {
        nome = _nome;
        tipo = _tipo;
        danno = _danno;
    };

    int getDanno() const { return danno; }
    string Descrizione()
    {
        return "ARMA:" + nome + "|TIPO: " + tipo + "|DANNO: " + to_string(danno);
    }
    bool operator==(const Arma &altra)
    {
        return (nome == altra.nome && tipo == altra.tipo && danno == altra.danno);
    }
    bool operator==(string nome_cercato)
    {
        return (nome == nome_cercato);
    }

    bool operator()(Arma a){
        return a.getDanno()>50;
    }

    void operator<<(ostream tm){
        tm << "Arma: " << nome << endl;
    }

    
};

template <typename T>
void ausgeben(vector<T> v)
{

    for (T s : v)
    {
        cout << s << endl;
    }
    cout << "======================================\n";
};

class Alunni
{

public:
    string nome;
    Alunni();
    Alunni(string n)
    {
        nome = n;

        //
        cout << "Costruttore e stato chiamato " << n << endl;
    }
    ~Alunni(){
        //cout << "Destructor called di " << ruolo << endl;
    };
};

template <typename T>
void print(string t, T v)
{
    cout << t << " " << v << endl;
};

bool nomeTroppoLungho(string n)
{
    if (n.length() == 5)
    {
        return true;
    }
    else
    {
        return false;
    }
};

bool filtro(Arma &a){
    return a.getDanno() > 50;
}

int main(int argc, char const *argv[])
{

    vector<string> AlunniA{"Baggio", "Berti", "Del Piero", "Buffon", "GIUSEPPE", "Pagliuccha", "Belotti", "Messi", "Iccardi", "Ronaldo", "Totti"};

    //Find() not sort
    auto trovato = find(AlunniA.begin(), AlunniA.end(), "GIUSEPPE");
    if (trovato != AlunniA.end())
    {
        //cout << *trovato << endl;
        AlunniA.erase(trovato);
    }
    else
    {
        cout << "NON trovato" << endl;
    }

    ausgeben(AlunniA);

    vector<int> nomeLength;
    for (auto n : AlunniA)
    {
        nomeLength.emplace(nomeLength.begin(), n.length());
    }

    //FIND con un BOOL

    auto nome = count(nomeLength.begin(), nomeLength.end(), 6);
    cout << "primo Nome lungho 4 char : " << nome << endl;

    //Vector Arma

    int maxDanno = 50;

    vector<Arma> armi {
        Arma{"Magnum", "Gun", 15},
        Arma{"ak47", "Fucile", 20},
        Arma{"Colt", "Gun", 100},
        Arma{"Anilator", "Rocket", 250},
        Arma{"Devastor", "machine Gun", 70}
        };
    //Opzione 1: Function declaration
    auto it_trovata = find_if(armi.begin(),armi.end(),filtro);
    if(it_trovata != armi.end()){
        cout << "Trovata:" << it_trovata->Descrizione() << endl;
    }
    //Opzione 2: Lmbda
    auto it_trovataLam = find_if(armi.begin(),armi.end(),[=](Arma x){return x.getDanno()> maxDanno;});
    if(it_trovataLam != armi.end()){
        cout << "Trovata:" << it_trovataLam->Descrizione() << endl;
    }

    //Opzione 1: Class () operator declaration
    auto it_trovataLamClass = find_if(armi.begin(),armi.end(),Arma());
    if(it_trovataLamClass != armi.end()){
        cout << "Trovata:" << it_trovataLamClass->Descrizione() << endl;
    }

    //Usiamo il search

    auto pistola  = any_of(armi.begin(),armi.end(),[=](Arma x){return x.getDanno() < maxDanno;});
    cout << "Result: " << pistola << endl; 
    
    sort(armi.begin(),armi.end(),[](Arma y, Arma x){return y.Descrizione()<x.Descrizione();});
    for(auto f:armi){cout << f.Descrizione() << endl;}



    
    //Race search use fin and binary_search
    vector<int> tantiNumeri;
    const int quanti  = 100000000;
    tantiNumeri .reserve(quanti);

    for(int i =0;i<quanti;i++){
        tantiNumeri.push_back(i);
    }

    const int QUANTE_RICERCHE = 10000;

    //RICERCA SEQUENZIALE CON FIND
    auto inizia = chrono::high_resolution_clock::now();
    for (size_t i = 0; i < QUANTE_RICERCHE; i++)
    {
        auto it_trovata = find(tantiNumeri.begin(),tantiNumeri.end(),rand()%(QUANTE_RICERCHE)*2);

    }
    auto fine = chrono::high_resolution_clock::now();

    auto microsecondi = chrono::duration_cast<chrono::microseconds>(fine-inizia);
    auto secondi = chrono::duration_cast<chrono::seconds>(fine-inizia);
    cout << microsecondi.count() << " microsec - ";
    cout << secondi.count() << " secondi - " << endl;

    //Ricerca BINARIA con Binary_search

     inizia = chrono::high_resolution_clock::now();
    for (size_t i = 0; i < QUANTE_RICERCHE; i++)
    {
        auto it_trovata = binary_search(tantiNumeri.begin(),tantiNumeri.end(),rand()%(QUANTE_RICERCHE)*2);

    }
     fine = chrono::high_resolution_clock::now();

     microsecondi = chrono::duration_cast<chrono::microseconds>(fine-inizia);
     secondi = chrono::duration_cast<chrono::seconds>(fine-inizia);
    cout << microsecondi.count() << " microsec - ";
    cout << secondi.count() << " secondi - " << endl;

    
    

}
 