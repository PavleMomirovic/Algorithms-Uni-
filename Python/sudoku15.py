#Na tabli veličine 3x3 treba rasporediti brojeve 1 do 9, tako da važi da je zbir elemenata u svakoj
#vrsti i koloni jednak (iznosi 15). Na samom početku u levom gornjem uglu se nalazi broj 1 a u
#donjem desnom uglu table broj 3, dok su ostala polja prazna. Igrač u svakom koraku unosi jednu
#cifru u jedno polje. Odrediti i zapamtiti redosled popunjavanja table koji vodi rešenju.
# 1 9 5
# 6 2 7
# 8 4 3

import queue


def provera(pozicija):
    #ovde proverim dal je stanje ciljno i dajem mu heuristiku
    brojNula=0
    brojGresaka=0

    for i in range(0,3):
        for j in range(0,3):
            if pozicija[i][j]==0: brojNula+=1
        if pozicija[0][i]+pozicija[1][i]+pozicija[2][i]>15: brojGresaka+=10
        if pozicija[i][0]+pozicija[i][1]+pozicija[i][2]>15: brojGresaka+=10


    return brojNula+brojGresaka

def sledecaStanja(pozicija):
    lista=[]
    next=0
    has2=False
    for  red in pozicija: 
        for p in red:
            if p>=next: next=p+1
            if p==2: has2=True #specijalni slucaj sa brojem 2, jer na pocetku vec imamo 1 i 3
    if not has2: next=2

    for i in range(0,3):
        for j in range(0,3):
            if pozicija[i][j]==0:
                poz=list(map(lambda x: list (map(lambda y: y,x)),pozicija))
                poz[i][j]=next
                lista.append(poz)
    # vraca sve moguce pozicije nakon upisa sledeceg broja
    return lista


def glavnaFja(start):
    k=0
    potezi=queue.LifoQueue(81)
    potezi.put(start)
    while not potezi.empty():
        current=potezi.get()
        k+=1
        #print(current)
        lista=sledecaStanja(current)
        lista.sort(key=provera)
        #print(lista)
        if provera(lista[0])==0:
            #print("provera vraca true")
            print(k)
            return lista[0]
        #print(len(lista))
        for e in lista:
            if provera(e)<10:
                #print("Dodajem potez",e)
                potezi.put(e)


    return []

pozicija=[[1,0,0],[0,0,0],[0,0,3]]
print(glavnaFja(pozicija))
