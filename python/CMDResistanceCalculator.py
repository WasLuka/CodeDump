import sys
#dictionary of all Band color codes
numColors = {"black": "0", "brown": "1", "red": "2", "orange": "3", "yellow": "4", "green": "5", "blue": "6", "purple": "7", "grey": "8", "white": "9"}
mulColors = {"black": 1, "brown": 10, "red": 10 ** 2, "orange": 10 ** 3, "yellow": 10 ** 4, "green": 10 ** 5, "blue": 10 ** 6, "purple": 10 ** 7,}
tolColors = {"brown": 0.01, "red": 0.02, "green": 0.005, "blue": 0.0025, "purple": 0.001, "grey": 0.0005, "gold": 0.05, "silver": 0.1, " ": 0.2}

resistance = ""
resist = ""
resmul = ""
tolmul = ""


colors = sys.argv
colors.pop(0)
count = len(colors)

if count == 5:                          #check how many colors were given for accuarte calculation
    res = colors[0:3]
    index = 3
elif count == 4:
    res = colors[0:2]
    index = 2
elif count == 3:
    colors.append(" ")
    res = colors[0:2]
    index = 2
else:
    print("Something went wrong please try again")

for i in res:                               #putting first three or two numbers together so they can be multiplied and we get resistance and calculate the tolerance   
    resist = resist + numColors[i]
resist = int(resist)

resistance = resist * mulColors[colors[index]]

tolerance = resistance * tolColors[colors[-1]]

if resistance >= 1000:                      #checks if resistance is more than 1k or 1M so it can shorten it for easier reading same with tolerance
    if resistance >= 1000000:
        resistance = resistance / 1000000
        resmul = "M"
    else:
        resistance = resistance / 1000
        resmul = "k"           
if tolerance >= 1000:
    if tolerance >= 1000000:
        tolerance = tolerance / 1000000
        tolmul = "M"
    tolerance = tolerance / 1000
    tolmul = "k"

print(f"resistance value is:{resistance}{resmul}Ω and tolerance is {tolerance}{tolmul}Ω")