#include <bits/stdc++.h>
using namespace std;

void decifra(int n, int d, int l, int *messaggio, char *plaintext) {
  // Esempio di implementazione con un solo carattere da decifrare.
  // Mettiamo il risultato della decifrazione in plaintext[0] e il
  // carattere di fine stringa in plaintext[1].

  // to decrypt from c:
  //  ans = c^d % n
  // l is length
  // messaggio[i] represents the i-th encrypted letter in int value
  // need to fill plaintext from 0 to l-1 and put a \0 at l

  // A · B) mod M = (A mod M · B mod M ) mod M

  // initial brute force approach
  for (int i = 0; i < l; i++) {
      int c = messaggio[i];
      long long ans;

      int exp = 0;
      ans = 1;

      while (exp < d) {
          int value = 1;
          int actual = 0;
          while (value*2 <= d-exp) {
              value *= 2;
              actual++;
          }
          long long temp = c % n;
          for (int j = 0; j < actual; j++) {
              temp = (temp * temp) % n;
          }
          ans = (ans * temp) % n ;
          exp += value;
      }

      plaintext[i] = ans;
  }
  plaintext[l] = '\0';
}
