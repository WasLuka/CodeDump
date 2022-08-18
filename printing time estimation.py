#calculates estimated time based on percentage and time

#will add data checking and saving to a txt
"""
for i in range(1, (1+len(times))):
            x = i 
"""
from secrets import choice


times = []
i = 0
esttime = 0
order = ''
completed = ''
time = ''

print("""
    This is a rough 3d printing time estimator
    commands:
    "add (percentage) (hours) (minutes)"-add a time for estimation
    "time"- displays the estimated time
    "exit"- exit out of the program
    """)

def averagetime(x):
    average = 0
    for i in x:
        average += i
    return average/len(x)

def estimator(x, y):
    multi = 100/x
    time = y*multi
    return time/60

while True:
    order = ''
    userinput = list(map(str, input('>').split()))

    if len(userinput) == 4:  #rough command estimation
        order = userinput[0]
        completed = userinput[1]
        time = int(userinput[2])*60 + int(userinput[3])
        
    elif len(userinput) == 1:
        order = userinput[0]

    
    if order.lower() == 'add':      #command sorting and activation
        try:
            completed = int(completed)
            times.append(estimator(completed, time))
            print(f'{"%.2f" % times[-1]}h')
        except ValueError:
            print('add command only works with numbers please check your command for errors')
        except:
            print('I do not understand')
    
    elif order.lower() == "time":
        print(f'average time: {"%.2f" % averagetime(times)}h, last added time: {"%.2f" % times[-1]}h')
    
    elif order.lower() == "exit":
        print('Are you sure?[y/n]')
        choise = input('>')
        
        if choise == 'y' or choise == 'yes':
            print('Goodbye!')
            break
        elif choise == 'n' or choise == 'no':

            print('exit procedure terminated.')
        else:
            print('something went wrong, please try again.')
    else:
        print('I do not understand')