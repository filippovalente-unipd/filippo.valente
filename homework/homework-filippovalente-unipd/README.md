HOMEWORK INVERNO 2019 - VALENTE FILIPPO

(Ignorare cartella 'test')

Per eseguire :
1. innanzitutto creare la cartella 'build' :
    "mkdir build"
2. eseguire il cmake dentro ad essa :
    "cd build"
    "cmake .."
3. eseguire il programma :
    "cd src"
    "./main"

Test effettuati con una capacità del parcheggio di 10 posti.

Sono arrivato al punto 1.

Riscontro un problema nell'output a video: quando si passa da un parcheggio all'altro, capita che si visualizza un'uscita prima di un'entrata (anche se essendo il parcheggio vuoto, la thread che si occupa delle uscite dovrebbe essere in 'wait'); penso che questo problema sia legato ad un fatto di interleaving tra le thread ( magari è successo :
-ingresso auto
-uscita auto
-stampa uscita
-stampa ingresso
).
Ho utilizzato un mutex nel main per sincronizzare i cout, che magari porta all'errore suddetto.
