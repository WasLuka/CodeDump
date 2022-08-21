#sorting algoirthm named bubble sort google it to know more about it

sortlist = list(map(int, input().split()))
count = 0
for x in range(1, (len(sortlist) + 1)):

    for i in range(0, (len(sortlist) - x)):
        if sortlist[i] > sortlist[(i + 1)]:
            value = sortlist.pop(i)
            sortlist.insert((i + 1), value)

            count += 1
print(sortlist)   
