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
    return 1.*a.valoare < 1.*b.valoare;
}
void rucsacel ()
{
    ifstream f("date.in");
    ofstream h("date.out");
    int n, m,i, spatiu_liber;
    double p, val_total=0;

    f>>n;
    f>>m; // m=dim_sac

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
            h<<rucsac[i].id<<" ";
            h<<rucsac[i].cantitate<<endl;
            val_total+=rucsac[i].valoare*rucsac[i].cantitate;
            i++;
        }
            else
        {
            //p=(double)spatiu_liber/rucsac[i].cantitate;
            h<<rucsac[i].id<<" "<<spatiu_liber;
            val_total+=spatiu_liber*rucsac[i].valoare;
            spatiu_liber=0;

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
