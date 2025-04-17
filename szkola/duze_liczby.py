wejscie=input()
a,b,c= wejscie.split()
a=int(a)
c=int(c)
if b=="==":
    if a==c:  print("TAK")
    else: print("NIE")
if b=="!=":
    if a!=c: print("TAK")
    else: print("NIE")
if b=="<":
    if a<c: print("TAK")
    else: print("NIE")
if b==">":
    if a>c: print("TAK")
    else: print("NIE")
if b=="<=":
    if a<=c: print("TAK")
    else: print("NIE")
if b==">=":
    if a>=c: print("TAK")
    else: print("NIE")