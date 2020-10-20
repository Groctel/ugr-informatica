def mcd(a,b):
    i=0
    while b != 0:
        (a,b) = (b,a%b)
        i+=1
        print(f"{}, {}", a, b)
    return (a,i)
