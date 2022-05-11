# hydrogen_bondings
Calculation of forces between magnets and test dipoles of zero volume for cylindrical neodymium magnets used in presentational model of hydrogen bondings in macro scale.

[Literatura](http://dsp.vscht.cz/konference_matlab/matlab07/prispevky/kosek_mikolanda/kosek_mikolanda.pdf) w sprawie modelowania oddziaływań magnetostatycznych zachęca do dwóch modeli: dipolowego i prądowego. W tym programie zastosowałem model dipolowy dla przykładowych magnetyzacji których skalowanie na szczęście nic nie znaczy bez określenia pozostałych cech topologii pola sił. Stąd istotne, niezależne parametry dla modelowania magnesów to:
- ich ilość,
- stosunek wielkości środkowego do zewnętrznych,
- odległości jednych i drugich.
- wysokość

## DZIAŁANIE
integral.cc można skompilować komendą _makefile_ bądź _g++ integral.cc -o integral_ (jednak nie jest to konieczne, program jest już skompilowany), przyspieszyć działanie programu można przez zmniejszenie dokładności całkowania (wartości __INT_RES__).

Plik __main.ipynb__  powinien być uruchomiony w programie __jupyter__.

Inicjalizując z odpowiednimi parametrami bądź wpisując własne funkcje inicjalizacyjne (jak na przykładnie wewnątrz proramu) można budować inne układy magnesów, wielkość macierzy i położenie magnesów wewnątrz można kontrolować parametrami inicjalizacji oraz nx i ny (rozmiarami macierzy).

