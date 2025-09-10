#include <iostream>
#include <vector>   // Per usare il contenitore std::vector
#include <cmath>    // Per usare std::sqrt in modo chiaro

int main() {
    // ===========================
    // 1) LETTURA DELL'INPUT
    // ===========================
    // L'utente inserisce un numero intero N >= 2.
    // Troveremo tutti i numeri primi da 2 a N compreso.
    std::cout << "Inserisci N (>= 2): ";
    long long N;
    std::cin >> N;

    // Controllo rapido di validita'
    if (N < 2) {
        std::cout << "Non ci sono numeri primi <= " << N << "\n";
        return 0;
    }

    // ========================================
    // 2) STRUTTURA DATI PER MARCARE I COMPOSTI
    // ========================================
    // Usiamo un vettore di booleani "is_prime" di dimensione N+1.
    // is_prime[x] = true  -> x e' (per ora) considerato primo
    // is_prime[x] = false -> x e' composto (non primo)
    //
    // Nota didattica: potremmo usare anche vector<char> per evitare
    // le ottimizzazioni particolari di vector<bool>, ma per la lezione
    // va benissimo anche cosi'.
    std::vector<bool> is_prime(N + 1, true);

    // 0 e 1 non sono numeri primi per definizione
    is_prime[0] = false;
    is_prime[1] = false;

    // ==========================================================
    // 3) IDEA DEL CRIVELLO
    // ==========================================================
    // Per ogni p da 2 a sqrt(N):
    //   - Se p e' ancora marcato come "primo",
    //     allora "cancelliamo" (marcando false) tutti i suoi multipli
    //     a partire da p*p (perche' i multipli < p*p sono gia' stati
    //     marcati in precedenza da primi piu' piccoli).
    //
    // Perche' fino a sqrt(N)?
    //   - Se N ha un divisore composito > sqrt(N), l'altro divisore
    //     corrispondente e' < sqrt(N). Quindi tutto e' gia' coperto.
    //
    // Perche' partire da p*p?
    //   - Perche' k*p con k < p e' gia' stato eliminato quando
    //     abbiamo considerato il primo k.
    //
    // Attenzione: p*p potrebbe superare il range se N fosse enorme,
    // ma con N entro l'intervallo tipico di esercizi scolastici non e'
    // un problema. Per sicurezza convertiamo a long long nell'indice.

    long long limite = static_cast<long long>(std::sqrt(static_cast<long double>(N)));
    for (long long p = 2; p <= limite; ++p) {
        if (is_prime[p]) {
            // p e' primo: eliminiamo i suoi multipli da p*p fino a N
            long long start = p * p; // primo multiplo da marcare

            // Se per qualche motivo p*p supera N (per numeri molto grandi),
            // il ciclo interno non partira' e non succede nulla di male.
            for (long long m = start; m <= N; m += p) {
                is_prime[m] = false; // m e' multiplo di p -> non e' primo
            }
        }
    }

    // =======================================
    // 4) STAMPA DI TUTTI I NUMERI PRIMI <= N
    // =======================================
    std::cout << "Numeri primi fino a " << N << ":\n";
    for (long long x = 2; x <= N; ++x) {
        if (is_prime[x]) {
            std::cout << x << " ";
        }
    }
    std::cout << "\n";

    // =========================
    // 5) NOTE DI COMPLESSITA'
    // =========================
    // Complessita' temporale (classica): O(N log log N)
    // Spazio usato: O(N) per il vettore is_prime.

    return 0;
}
