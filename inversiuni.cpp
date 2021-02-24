/// se da o permutare. Sa se determine numarul de inversiuni ale sale (n <= 200000)

#include <iostream>

#define inStream cin
#define outStream cout

using namespace std;

const int NMAX = 200001;
int n, permutation[NMAX], bit[NMAX];

inline int lbs(int nr) {
    return nr & -nr;
}

/// accumulate(i) => cate numere sunt mai mici sau egale decat i in BIT
int accumulate(int index) {

    int ret{};

    for(;index;index -= lbs(index))
        ret += bit[index];

    return ret;
}

void update(int index, int value) {
    for(;index <= n;index += lbs(index))
        bit[index] += value;
}

int main() {

    inStream >> n;

    for(int i = 1;i <= n;++i)
        inStream >> permutation[i];

    /// profitam de modul in care un "Binary Indexed Tree"(BIT) e structurat/construit
    /// elementul maxim intr o permutare este N
    /// deci iteram peste permutare
    /// si vedem cate elemente sunt mai mici sau egale cu permutation[index] - 1
    /// dupa updatam BIT, mai specific update(permutation[index], 1)

    int inversions{};
    for(int i = n;i >= 1;--i) {
        inversions += accumulate(permutation[i] - 1);
        update(permutation[i], 1);
    }

    outStream << inversions;

    return 0;
}
