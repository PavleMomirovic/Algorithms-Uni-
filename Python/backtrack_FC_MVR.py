import queue


graph = {
    #primer sa vezbi
    'A' : ['B', 'C'],
    'B' : ['A', 'C', 'E'],
    'E' : ['B', 'C','D'],
    'D' : ['C', 'E'],
    'C' : ['A', 'B', 'E','D']
}

colors = set({ 'red', 'green', 'blue'})

def backtrack_fc_mvr(graf, boje):
    FirstState={
        'uncolored':list(graf.keys()),
        'domain':{ x: list(boje) for x in graf.keys() },
        'colored':{}      #dictionary vec obojenih. A: red B:blue..
    }
    stackOfStates= queue.LifoQueue(1000) #ogranicenje je za sad 1000, moze i matematicki da se izracuna koliko da bude tacno
    stackOfStates.put(FirstState)
    solution=None
    while not stackOfStates.empty() and not solution:
        currState=stackOfStates.get()
        #print(currState)
        if not currState['uncolored']:
            solution = currState['colored']
        else:
            currNode = currState['uncolored'][0] #biramo cvor za bojenje
            potential = list(currState['domain'][currNode]) #lista potencijalnih boja
            
            for n in graf[currNode]: #za sve susede proveravamo
                if n in currState['colored'].keys() and currState['colored'][n] in potential:
                    #print("Prolazim proveru, izbacujem mu",currState['colored'][n])
                    potential.remove(currState['colored'][n]) #izbaci iz potenciajlnih boja ako je ima neki sused
            for p in potential: #ako ima opcija za boju onda
                newDomain = {}
                for k in currState['domain'].keys():
                    newDomain[k]=list(currState['domain'][k])
                newDomain[currNode] = [p]
                forwardCheckingBool=True #postace false, ako neko iz newDomain, nakon provere nece imati opcije
                for n in graf[currNode]:
                    if p in newDomain[n]: #potencial[0] je nasa odabrana boja
                        #print("iz domena",n,"sklanjam boju",p)
                        newDomain[n].remove(p)  #ovde treba da se doda FC
                    if len(newDomain[n])==0:
                        forwardCheckingBool=False

                if forwardCheckingBool:
                    stackOfStates.put({
                    #sledeci red je u stvari MVR, jer sortira da sledeci cvor koji obilazimo bude onaj sa najmanje opcija
                    #ne dolazi do izrazaja FC kada u lakim primerima koristimo MVR, zato je tu test primer ispod
                    #'uncolored': [x for x in currState['uncolored'] if x is not currNode],
                        'uncolored': sorted([x for x in currState['uncolored'] if x is not currNode], key=lambda x: len(newDomain[x])),
                        'domain': newDomain,
                        'colored': currState['colored'] | { currNode: p }, #dodajemo jos jedan 
                    })
        

    return solution

sol = backtrack_fc_mvr(graph, colors)
print(sol)