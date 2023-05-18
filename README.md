# calculatorul-studentului
Un program în C, are rolul unui calculator de mână, ce poate prelucra numere mari, atât pentru operațiile de bază, cât și pentru diferite funcții (serii de puteri, logaritm, funcții exponențiale etc.)

## Modul de implementare al functiilor utilizate:

Calculatorul studentului utilizeaza mai multe functii care depind de recursivitate, 
serii Taylor si alte concepte matematice.

### Logaritm Natural
Se bazeaza pe seria:

![LN1](https://github.com/edwardnita/calculatorul-studentului/assets/118977068/ef3540cd-5fad-4270-b9f1-669726ff322d)

Aceasta formula functioneaza doar pentru abs(x) < 1. Asa ca folosim si relatia:
 ln(x) = k*ln(X) + ln(x/2^k)
Impartim x la 2 de k ori, pana ce x este in intervalul cerut

### Logaritm
Folosim relatia urmatoare, pentru a calcula doar ln(a) si ln(b).

![log](https://github.com/edwardnita/calculatorul-studentului/assets/118977068/b5488d77-576c-49a3-a801-4df62253be58)

### Exponentiala
Se bazeaza pe seria(care merge pentru orice x):

![exp](https://github.com/edwardnita/calculatorul-studentului/assets/118977068/7ccbf3fe-b4e7-46e7-bb49-1c497044793f)

### Functia putere
Functia imparte exponentul in parte intreaga si fractionara.
Partea fractionara este calculata cu formula:

![power1](https://github.com/edwardnita/calculatorul-studentului/assets/118977068/2f2f0b60-75a9-4339-bb52-3ccf9e96f5d2)

Iar partea naturala este calculata recursiv:

![power2](https://github.com/edwardnita/calculatorul-studentului/assets/118977068/d7bf72b7-2b6c-4196-b268-81e87f3ef390)

### Factorial
Factorialul este calculat recursiv, insa folosind un acumulator ca optimizare

### Functile trigonometrice si invers triggonometrice
Sinusul si cosinusul au fost calculate folosind serii:

![sinsicos](https://github.com/edwardnita/calculatorul-studentului/assets/118977068/a8abf474-e8a1-45d5-a73f-fd5794d74b30)

Tangenta si cotangenta au fost calculate folosind formulele clasice:
tg = sin/cos
ctg = cos/sin

Arcsinusul a fost fost calculat de asemena folosind serii:

![arcsin](https://github.com/edwardnita/calculatorul-studentului/assets/118977068/e1319931-9ebf-4687-a88b-d55d509728b7)

Arccosinusul a fost calculat in functie de arcsin, astfel:

![arccos](https://github.com/edwardnita/calculatorul-studentului/assets/118977068/8c438200-fbfc-4286-b72a-0ea12b4d369f)


