#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

int schitatPotomkov(const std::string& uzel,
                    const std::map<std::string, std::vector<std::string>>& derevo,
                    std::map<std::string, int>& kolPotomkov) {
    if (derevo.find(uzel) == derevo.end()) {
        kolPotomkov[uzel] = 0;
        return 1;
    }
    
    int obshiy = 0;
    for (const auto& rebenok : derevo.at(uzel)) {
        obshiy += schitatPotomkov(rebenok, derevo, kolPotomkov);
    }
    kolPotomkov[uzel] = obshiy;
    return obshiy + 1;
}

void postroitPuty(const std::string& uzel,
                  const std::map<std::string, std::vector<std::string>>& derevo,
                  std::map<std::string, std::vector<std::string>>& puti,
                  std::vector<std::string>& tekushiyPut) {
    tekushiyPut.push_back(uzel);
    puti[uzel] = tekushiyPut;
    
    if (derevo.find(uzel) != derevo.end()) {
        for (const auto& rebenok : derevo.at(uzel)) {
            postroitPuty(rebenok, derevo, puti, tekushiyPut);
        }
    }
    
    tekushiyPut.pop_back();
}

int main() {
    int N;
    std::cin >> N;
    
    std::map<std::string, std::vector<std::string>> derevo;
    std::map<std::string, std::string> kartaRoditeley;
    std::set<std::string> vseUzel;
    std::set<std::string> deti;
    
    for (int i = 0; i < N - 1; ++i) {
        std::string rebenok, roditel;
        std::cin >> rebenok >> roditel;
        derevo[roditel].push_back(rebenok);
        kartaRoditeley[rebenok] = roditel;
        vseUzel.insert(rebenok);
        vseUzel.insert(roditel);
        deti.insert(rebenok);
    }
    
    std::string koren;
    for (const auto& uzel : vseUzel) {
        if (deti.find(uzel) == deti.end()) {
            koren = uzel;
            break;
        }
    }
    
    std::map<std::string, std::vector<std::string>> puti;
    std::vector<std::string> tekushiyPut;
    postroitPuty(koren, derevo, puti, tekushiyPut);
    
    std::string A, B;
    while (std::cin >> A >> B) {
        const std::vector<std::string>& putA = puti[A];
        const std::vector<std::string>& putB = puti[B];
        
        std::string nopa = koren;
        size_t dlin = std::min(putA.size(), putB.size());
        for (size_t i = 0; i < dlin; ++i) {
            if (putA[i] == putB[i]) {
                nopa = putA[i];
            } else {
                break;
            }
        }
        
        std::cout << nopa << "\n";
    }
    
    return 0;
}