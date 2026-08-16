# Crivello di Eratostene

Piccolo esempio didattico in C++ che calcola tutti i numeri primi minori o uguali a un limite inserito dall'utente.

## Compilazione

È sufficiente un compilatore compatibile con C++17:

```bash
g++ -std=c++17 -O2 -Wall -Wextra -pedantic eratostene.cpp -o eratostene
```

## Esecuzione

```bash
./eratostene
```

Inserisci un intero `N >= 2`. Il programma applica il crivello di Eratostene e stampa i numeri primi fino a `N` compreso.

## Complessità

- tempo: `O(N log log N)`;
- memoria: `O(N)`.

## Licenza

Il codice è distribuito con licenza [CC0 1.0 Universal](LICENSE).
