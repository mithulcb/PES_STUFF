def find(ssn,d):
    veg1=[]
    veg2=[]
    sumer=["jan","feb","mar","apr","may","jun"]
    winter=["jul","aug","sep","oct","nov","dec"]
    for i in d:
        for j in d[i]:
            print(j)
            if(ssn=='summer' and j in sumer):
                veg1.append(i)
            elif(ssn=='winter' and j in winter):
                veg2.append(i)
            elif(j in winter and j in sumer):
                veg1.append(i+"BOTH")
                veg2.append(i+"BOTH")
    print("summer months",veg1)
    print("winter months",veg2)



d={}
n=int(input("enter number of vegetables"))
for i in range(0,n):
    x=input("enter name of vegetable")
    l=[]
    n1=int(input("enter no of months of harvest"))
    for j in range(0,n1):
       m=input("enter month")
       l.append(m)
    d[x]=l
print(d)
s=input("enter season")
find(s,d)