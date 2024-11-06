Gheorghe Marius Razvan 324CA

Tema 2 Proiectarea Algoritmilor

Problema 1 ----Numarare-----

Citesc datele de intrare,adica cele 2 grafuri.
Aplic algoritmul de sortare topologica asupra primului graf
pentru a mi asigura ca atunci cand accesez un nod u sa am calculate
caile prin care se ajunge la u adica de la toti predecesorii sai,ceea ce
va face sortarea topologica.Aplic sortarea topologica algoritmul lui Kahn
unde mai intai se verifica gradul intern al nodurilor iar in coada se pun 
prima oara cel cu gradul 0 care nu mai sunt precedate de alte noduri.
In functia compute_paths() vectorul dp[i] reprezinta caile de la sursa la i.
Pentru fiecare nod din sortarea topologica parcurg vecinii sai pentru graful 1
si verific daca aceleasi arce se regasesc si in graful 2,daca se gasesc
adaug la neighbor numarul de cai care ajung la node pentru ca automat vor
ajunge si la neighbor.In final dp[n] contine numarul total de cai de la sursa
la destinatie.
Complexitatea la algoritmul lui Kahn este O(n+m) iar la compute_paths pentru
fiecare nod din sortarea topologica actualizam valorile pentru vecinii sai,
deci complexitatea este O(n+m).

Problema 2 ----Trenuri----
La problema 2 stochez nodurile asa cum sunt citite sub forma de string,
procedez ca la problema anterioara si sortez topologic graful.
In functia get_result vectorul dist reprezinta distanta maxima de la nodul 
start la orice nod.Iterez prin fiecare nod din sortarea topologica,apoi iterez
prin vecinii fiecarui nod si actualizez distanta maxima la fiecare vecin
daca cea anterioara era mai mica si altfel imi va da distanta maxima de la
start la end.
Complexitatea programului este O(n+m) atat pentru sortarea topologica cat si
pentru calculul maxim al oraselor.

Problema3 ----Drumuri----

Aplic algoritmul lui Dijkstra pentru a afla distantele minime.
Calculez distantele minime de la x la toate nodurile grafului si de 
la y la fel folosind dijkstra si de la z la graful inversat(transpus).
Trec prin toate nodurile sa verific daca sunt parte din drumurile minime
de la x la z si de la y la z de aceea pentrun fiecare nod i
existanda un drumu de la x la z care trece prin i si de la y la z
care trece prin i costul fiind dist_x[i]+dist_y[i]+dist_z[i].
Plecand in acelasi timp din z catre x si y se vor intalni
intr un punct comun,intermediar adica in punctul i iar din i
pleaca inspre x si y si de aici => dist_x[i]+dist_y[i]+dist_z[i].
Complexitatea este O((n+m)*logn) deoarece acel logn vine din utilizarea
cozii de prioritate din operatiile de inserare iar n+m
pentru ca parcurgem toate nodurile si toate muchiile.
