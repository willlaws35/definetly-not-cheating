import random
print("file created, please rename once test is complete.")
result=open(r"results.txt","a")
recom=""
run = 1
while run>0:
    n1=(random.randint(1,11))
    n2=(random.randint(1,11))
    n=n1+n2
    needed = 21 - n
    print("your card total is ",n)
    if n<=10:
        print ("success rate = 100%")
        recom==("recommend pick up")

    else:
        print("total required for 21 = ",needed)
        if needed ==0:
            print("probability of success = 100%")
            recom==("recommend pick up")
        if needed>=10:
            ratio=3
            y=13-(needed-1)
            ratio=ratio+y
            test1=7.692307692*ratio
            print("probability of success = ",test1,"%")
            fail1=100-test1
            print("probability of failure = ",fail1,"%")
            if test1>=50:
                recom==("recommend pick up")
            else:
                recom==("recommend stick")
        elif 0<needed<10:
            testVal=7.6923076092*needed
            print("probability of success = ",testVal,"%")
            failVal=100-testVal
            print("probability of failure = ",failVal,"%")
            if testVal>=50:
                recom==("recommend pick up")
            else:
                recom==("recommend stick")
    L = [str(n), str(needed), recom, "/n"]
    result.writelines(L)
    print("writing to txt file")
    recom==""
    choice = input("do you wish to go again ? (y/n)")
    if choice == "n":
        print("You have chosen to exit, happy playing.")
        run = run-1





