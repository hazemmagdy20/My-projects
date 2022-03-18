list = [9,7,2,5,6,1,3,8,4]
first_player = str(input("plz enter player 1's name: "))
second_player = str(input("plz enter player 2's name: "))
list1 = []
list2 = []
while len(list) != 3 :
    print(list)
    print(first_player)
    a = int(input("plz choose number from list: "))
    while a not in list :
        a = int(input("plz choose number from list: "))
    list1.append(a)
    list.remove(a)
    if len(list1) == 3 :
        if list1[0] + list1[1] + list1[2] == 15 :
            print(first_player , "is winner")
            break
    print(list)
    print(second_player)
    b = int(input("plz choose number from list: "))
    while b not in list :
        b = int(input("plz choose number from list: "))
    list2.append(b)
    list.remove(b)
    if len(list2) == 3 :
        if list2[0] + list2[1] + list2[2] == 15 :
            print(second_player , "is winner")
            break 
while len(list) != 1 and list1[0] + list1[1] + list1[2] != 15 and list2[0] + list2[1] + list2[2] != 15 :
    print(list)
    print(first_player)
    a = int(input("plz choose number from list: "))
    while a not in list :
       a = int(input("plz choose number from list: ")) 
    list1.append(a)
    list.remove(a)
    if list1[1] + list1[2] + list1[3] == 15 or list1[0] + list1[1] + list1[3] ==15 or list1[0] + list1[2] + list1[3] == 15 :
        print(first_player , "is winner")
        break 
    if list1[1] + list1[2] + list1[3] != 15 and list1[0] + list1[1] + list1[3] != 15 and list1[0] + list1[2] + list1[3] != 15: 
        print(list)
        print(second_player)
        b = int(input("plz choose number from list: "))
        while b not in list :
            b = int(input("plz choose number from list: "))
        list2.append(b)
        list.remove(b)
        if list2[1] + list2[2] + list2[3] == 15 or list2[0] + list2[1] + list2[3] ==15 or list2[0] + list2[2] + list2[3] == 15 :
            print(second_player , "is winner")
            break
while len(list) == 1 and  list1[1] + list1[2] + list1[3] != 15 and list1[0] + list1[1] + list1[3] != 15 and list1[0] + list1[2] + list1[3] != 15 and list2[1] + list2[2] + list2[3] != 15 and list2[0] + list2[1] + list2[3] != 15 and list2[0] + list2[2] + list2[3] !=15: 
    print(list)
    print(first_player)
    a = int(input("plz choose number from list: "))
    while a not in list :
        a = int(input("plz choose number from list: "))
    list1.append(a)
    list.remove(a)
    if list1[0] + list1[3] + list1[4] == 15 or list1[1] + list1[3] + list1[4] == 15 :
        print(first_player , "is winner")
        break
    elif list1[0] + list1[2] + list1[4] == 15 or list1[2] + list1[3] + list1[4] == 15 :
        print(first_player , "is winner")
        break
    elif list1[1] + list1[2] + list1[4] == 15 or list1[0] + list1[1] + list1[4 ]== 15 :
         print(first_player , "is winner")
         break
    else :
        print("the game is draw")