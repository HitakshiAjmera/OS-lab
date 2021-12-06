   
#sjf non preemptive 0 arrival time
def turnaround_time(p,n):
   ct=0
   tat=[0]
   for i in range(1,n+1):
       ct=ct+p[i][0] 
       tat.append(ct)
   return tat

def waiting_time(p,tat,n):
    wat=[0]
    for i in range(1,n+1):
        wt=tat[i]-p[i][0]
        wat.append(wt)
    return wat

def find_avg(p,n):
    tat=turnaround_time(p,n)
    print(tat)
    tat_average=sum(tat)/n
    wat=waiting_time(p,tat,n)
    print(wat)
    wat_average=sum(wat)/n
    print('AVERAGE TURN AROUND TIME IS GIVEN BY: {}'.format(tat_average))
    print('AVERAGE WAITING TIME IS GIVEN BY: {} '.format(wat_average))


n=int(input('ENTER THE NUMBER OF PROCESSES: '))
p=[[0,0]]
#[[burst time, processid]]
for i in range(1,n+1):
    b=int(input('ENTER THE BURST TIME OF : %d  '%i))
    p.append([b,i])
p.sort()
find_avg(p,n)