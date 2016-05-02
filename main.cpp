#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct ghiozdan
{
    unsigned int id;
    int valoare;
    int cantitate;
}rucsac[10000];


bool sort_ghiozdan (const ghiozdan a, const ghiozdan b)
{
    return 1.*a.valoare/a.cantitate > 1.*b.valoare/b.cantitate;
}
void rucsacel ()
{
    ifstream f("date.in");
    ofstream h("date.out");

    int n, m,i, spatiu_liber;
    double p, val_total=0;

    f>>n;
    f>>m;

    spatiu_liber=m;

    for (i=0; i<n; i++)
    {
        f>>rucsac[i].id;
        f>>rucsac[i].cantitate;
        f>>rucsac[i].valoare;
    }

    sort (rucsac, rucsac+n, sort_ghiozdan);
    i=0;

    while ((spatiu_liber>0)&&(i<n))
    {
            if (rucsac[i].cantitate<=spatiu_liber)
        {
            spatiu_liber = spatiu_liber - rucsac[i].cantitate;
            h<<rucsac[i].id<<endl;
            val_total+=rucsac[i].valoare;
            i++;
        }
            else
        {
            p=(double)spatiu_liber/rucsac[i].cantitate;
            h<<rucsac[i].id<<" partial";
            spatiu_liber=0;
            val_total+=p*rucsac[i].valoare;
        }

    }

    h<<endl<<"Valoare:"<<val_total;

    h.close();
    f.close();

}

int main()
{
    rucsacel();
    return 0;
}
