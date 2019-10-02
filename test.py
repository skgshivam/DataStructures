input1= 5
input2=[5,5,5,5,5]
list = []
input2.sort()
total = 0
for i in range(len(input2)):
    temp = input2[i]
    if temp not in list:
        list.append(temp)
        total += temp
    else:
        while temp in list:
            temp += 1
        list.append(temp)
        total +=  
        