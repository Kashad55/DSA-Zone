parent=input()
child=input()
if child=='Y':
    litofchild=list(map(str,input().split(',')))
    parentcomm=len(litofchild)*0.1*5000
    childcomm=0.05*5000
    print(f"{parent}:{parentcomm} and child comm:{childcomm}")
else :
    print(f"{parent}:",5000*0.05)