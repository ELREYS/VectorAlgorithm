#include <iostream>
#include <iomanip>
#include <sys/stat.h>
#include <ctime>
#include <vector>
#include <typeinfo>

using namespace std;

template <typename T>
void ausgeben(vector<T> v)
{

    for (T s : v)
    {
        cout << s << endl;
    }
    cout << "======================================\n";
};

class Famiglia{
    public:
    string ruolo;
    string sex;
    int chiamata;
    Famiglia();
    Famiglia(string r,string pos){
        ruolo = r;
        sex = pos;
        //
        cout << "Costruttore e stato chiamato " << r << endl;
    }
    ~Famiglia(){
        //cout << "Destructor called di " << ruolo << endl;
    };
};

template <typename T>
void print(string t, T v){
    cout << t << " " << v << endl;
};

int main(int argc, char const *argv[])
{

    // vector<string> listaA{"Ronaldo", "Neymar", "Pirlo", "GIUSEPPE", "Tevez", "Maldini", "Del Piero", "Messi"};

    // ausgeben(listaA);
    // auto listaB = listaA;
    // cout << "Begin: " << *listaB.begin() << endl;
    // cout << "End: " << *(listaB.end() - 1) << endl;
    // cout << "Reversed Begin: " << *(listaB.rbegin()) << endl;
    // cout << "Reversed End: " << *(listaB.rend()) << endl;

    // //Attraversiamo la lista

    // //Attraversa da inizio a fine
    // for (auto position = listaB.begin(); position != listaB.end(); position++)
    // {
    //     cout << "begin()" << *position << endl;
    // }

    // cout << "======================================\n";

    // //Attraversa da fine a inizio
    // for (auto pos = listaA.rbegin(); pos != listaA.rend(); pos++)
    // {
    //     cout << "rbegin()" << *pos << endl;
    // }

    // cout << "======================================\n";

    // listaA.assign({"Baggio"}); // Aggiungi Baggio all vettore e cancella il resto!!
    // ausgeben(listaA);
    // listaA.swap(listaB);
    // cout << "Swap A-> B" << endl;
    // ausgeben(listaA);
    // ausgeben(listaB);

    // cout << "front() " << listaA.front() << endl;
    // cout << "back() " << listaA.back() << endl;

    // //Typeinfo
    // cout << typeid(listaA.front()).name() << endl;
    // cout << typeid(listaA.begin()).name() << endl;
    // cout << typeid(listaA.rbegin()).name() << endl;
    // //Capacity -- Capacity of the currently allocated storage.
    // print("Capacity",listaA.capacity());
    // print("Size:",listaA.size());

    
    // ///Rsize Vector change reallocate the space immediately
    // vector<int> numeriInteri ;
    // print("Capacity Int resize()",numeriInteri.capacity());
    // numeriInteri.resize(1000);
    // print("Capacity Int",numeriInteri.capacity());
    // for (auto pos = numeriInteri.begin(); pos != numeriInteri.end(); pos++)
    // {
    //     *pos += 100;
         
    // }

    // numeriInteri.clear();
    // cout << numeriInteri.empty();

    // ///Reserve Vector change reallocate the space immediately
    // print("Capacity Int reserve()",numeriInteri.capacity());
    // numeriInteri.reserve(1000);
    // print("Capacity Int",numeriInteri.capacity());
    // for (auto pos = numeriInteri.begin(); pos != numeriInteri.end(); pos++)
    // {
    //     *pos += 100;
         
    // }


    // for (size_t i = 0; i < 10; i++)
    // {
    //     numeriInteri.push_back(i*1);
    //     cout << "Capacity Items : "<< (i*1) << " " << numeriInteri.capacity() << endl;
    // }

    // print("Capacity Int",numeriInteri.capacity());

    // numeriInteri.shrink_to_fit();

    // //Dynamic Size Allocatiion

    // print("Capacity: ",numeriInteri.capacity());

    // numeriInteri.clear();
    // numeriInteri.shrink_to_fit();

    // print("Capacity: ",numeriInteri.capacity());


    // //Costruiamo un vettore per Famiglia

    

    // for(auto f:Fam){
    //     cout << f.sex << ":" << f.ruolo << endl;
    // }
    // print("Cap:",Fam.capacity());

    // Fam.emplace(Fam.end(),"SorellaMinore","D");


    // for(auto f:Fam){
    //     cout << f.sex << ":" << f.ruolo << endl;
    // }
    // print("Cap:",Fam.capacity());

    // Fam.emplace(Fam.begin()+2,Fam.at(5));
    // Fam.pop_back();

    // for(auto f:Fam){
    //     cout << f.sex << ":" << f.ruolo << endl;
    // }
    // print("Cap:",Fam.capacity());


    vector<Famiglia> Fam;

    cout << "Vettore creato con push_back()" << endl;

    Fam.push_back({"Padre","U"});
    Fam.push_back({"Madre","D"});
    Fam.push_back({"FiglioMaggiore","U"});
    Fam.push_back({"FiglioMinore","U"});
    Fam.push_back({"Cane","D"});

    Fam.clear();
    Fam.shrink_to_fit();

    cout << "=====================================================================\n";


    cout << "Vettore creato con emplace()" << endl;

    for(auto f:Fam){
        cout << f.ruolo << " " << f.sex << endl;
    }

    Fam.emplace(Fam.begin(),"Padre","U");
    Fam.emplace(Fam.begin(),"Madre","D");
    Fam.emplace(Fam.begin(),"FiglioMaggiore","U");
    Fam.emplace(Fam.begin(),"FiglioMinore","U");
    Fam.emplace(Fam.begin(),"Cane","D");

    for(auto f:Fam){
        cout << f.ruolo << " " << f.sex << endl;
    }

     Fam.clear();
    Fam.shrink_to_fit();

    cout << "=====================================================================\n";

    cout << "Vettore creato con emplace_back" << endl;

    for(auto f:Fam){
        cout << f.ruolo << " " << f.sex << endl;
    }

    Fam.emplace_back("Padre","U");
    Fam.emplace_back("Madre","D");
    Fam.emplace_back("FiglioMaggiore","U");
    Fam.emplace_back("FiglioMinore","U");
    Fam.emplace_back("Cane","D");
    Fam.insert(Fam.begin(),{"Nonno","D"});

    for(auto f:Fam){
        cout << f.ruolo << " " << f.sex << endl;
    }

    print("MaxSize:",Fam.max_size());

    Fam.insert(Fam.begin()+2,{"Zia","D"});
    auto famB = Fam;
    Fam.erase(Fam.begin()+2);

    Fam.insert(Fam.begin()+2,famB.begin(),famB.end());

    
    
    
    


    


    return 0;
}