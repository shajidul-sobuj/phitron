#include <bits/stdc++.h>
using namespace std;

#define endl '\n'


// vertebrado
//   ave
//     carnivoro → aguia
//     onivoro → pomba
//   mamifero
//     onivoro → homem
//     herbivoro → vaca

// invertebrado
//   inseto
//     hematofago → pulga
//     herbivoro → lagarta
//   anelideo
//     hematofago → sanguessuga
//     onivoro → minhoca


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a,b,c;
    cin >> a >> b >> c;
    if (a == "vertebrado" && b == "ave" && c == "carnivoro") cout << "aguia\n";
    else if (a == "vertebrado" && b == "ave" && c == "onivoro") cout << "pomba\n";
    else if (a == "vertebrado" && b == "mamifero" && c == "onivoro") cout << "homem\n";
    else if (a == "vertebrado" && b == "mamifero" && c == "herbivoro") cout << "vaca\n";
    else if (a == "invertebrado" && b == "inseto" && c == "hematofago") cout << "pulga\n";
    else if (a == "invertebrado" && b == "inseto" && c == "herbivoro") cout << "lagarta\n";
    else if (a == "invertebrado" && b == "anelideo" && c == "hematofago") cout << "sanguessuga\n";
    else if (a == "invertebrado" && b == "anelideo" && c == "onivoro") cout << "minhoca\n";

    return 0;
}