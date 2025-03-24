### Naval battle project

Abbiamo ideato il progetto basandoci sulla connessione tra diverse classi e sottoclassi;
le classi "strutturali" hanno come obbiettivo creare gli oggetti fondamentali per il gioco, come i campi di battaglia, le navi e le loro rispettive coordinate.
    Ogni oggetto-nave si specializza in base al tipo nelle relative sottoclassi; i tipi di nave si differenziano in base alla loro struttura nel campo da gioco,
alla loro "forma" e alle loro azioni.
    Per gestire i turni di gioco abbiamo creato una classe astratta (Player), da cui derivano due sottoclassi: human e computer, che prevedono l'istanziamento
e i turni dei rispettivi giocatore umano e giocatore gestito dal computer (basato su istanziamenti e azioni pseudo-casuali).
    In seguito abbiamo così deciso di dare il compito al main per la gestione della partita effettiva, tramite l'ausilio delle classi Human e Computer che
gestiscono i vari oggetti (campi di battaglia e navi) per l'intero svolgimento della partita.
    Inoltre, sempre in human e computer c'è la gestione in lettura dei file di log, che è invece affidata al replay, che si occupa nello specifico di trascrivere
passo dopo passo istanziamento, mosse e di darlo in output per ricostruire le partite terminate.

Poniamo qui un elenco sul funzionamento delle rispettive classi:

    1) Battlefield:  ogni oggetto battlefield prevede la creazione di due campi di battaglia per ogni giocatore, uno d'attacco e uno di difesa; la classe si occupa della modifica delle posizioni delle navi, delle loro azioni e dei comandi speciali nei vari campi d'attacco e di difesa (quindi in ogni partita verrano creati due oggetti battlefield).

    2) NavalUnit: è una classe astratta che estende tre sottoclassi che specificano le tipologie di navi (Battleship, Support vessel, submarine ); ogni sottoclasse
                  erediterà action e in generale diverse caratteristiche per le data-member. Abbiamo pensato di ragionare ponendo come data member di battlefield una
                  lista di puntatori di tipo NavalUnit che si specificano in base al tipo di nave e di conseguenza per il tipo di azione che potranno svolgere. 
                  Per questo motivo NalvaUnit e Battlefield sono fortemente legate.
        2.1) Battleship
        2.2) SupportVessel
        2.3) Submarine

    3) Coordinate: questa classe gestisce gli oggetti coordinata, importanti poichè sono data-member di ciascuna nave (memorizzate in std::vector di coordinate).
                   Controlla anche le operazioni tra le varie coordinate utili nella gestione delle navi istanziate nel Battlefield. La classe fornisce una funzione che,
                   dato un intervallo di coordinate (stessa riga o stessa colonna), restituisce un std::vector che contiene tutte le coordinate comprese nell'intervallo
                   (estremi inclusi). Questa funzione è stata pensata per calcolare in maniera efficace le coordinate che si trovano tra prua e poppa.

    4) Player: è una classe classe astratta che estende due sottoclassi, human e computer. 
        4.1) Human: prevede l'istanziamento fatto da standard input, con gestione dei turni basata sulla volontà dell'utente;
        4.2) Computer: prevede l'istanziamento e gestione delle mosse basato su un algoritmo pseudo-randomico; 
        (inoltre in ciascuna di queste due classi, ogni istanziamento e ogni mossa verrà riportata nel file di log)

    5) Replay: viene gestita la lettura del file di log e la conseguente stampa in output. Non effettua controlli sulla validità delle mosse presenti nel file "log.txt".

    6) Main: nel main c'è l'effettiva gestione della partita: vengono istanziati i campi di battaglia e le navi dei due Player; viene richiesto ai Player di inizializzare le
             proprie unità; vengono gestiti i turni.
             Abbiamo messo un limite di mosse pari a 2000, basandoci su una media delle durate delle partite tra computer e computer. (Queste spesso finiscono in stallo)

NOTE AGGIUNTIVE: 
    - le navi sono memorizzate nel battlefield tramite una struttura std::list di puntatori di NavalUnit in cui l'ispezione delle coordinate e delle navi in generale avviene 
      tramite lo scorrimento di quest'ultima.

    - abbiamo pensato di rimuovere le navi affondate dalla lista, refreshando di volta in volta il campo di battaglia, dopo un'operazione di "erase", affinché la modifica
      sia possibile anche in output.

    - abbiamo deciso che la classe che rappresenta le coordinate accettasse anche gli indici di riga 'J' e 'K' per mantenerla più generica possibile. In conseguenza a ciò, tutte
      le funzioni che istanziano oggetti di tipo coordinata, fanno un conttrollo (se necessario) sull'indice di riga.

    - non abbiamo usato una data-member per verificare se una specifica nave sia orizzontale o verticale, ma all'interno della funzione "move" di Battlefield abbiamo
      gestito la cosa tramite semplici operazioni matematiche, calcolando la distanza tra prua e poppa di ogni nave.
 
