import _pickle

def create_note():
	choice=input("Add text to file (a), or rewrite file (w)")
	if (choice=='a'):
		outFile=open("test.txt","ab")
	elif (choice=='w'):
		outFile=open("test.txt", "wb")
	flag=True
	while flag:
		phone=input("Enter phone number: ")
		time=input("Enter start time (GG:XX): ").split(":")
		starth=int(time[0])
		startm=int(time[1])
		time=input("Enter end time (GG:XX): ").split(":")
		endh=int(time[0])
		endm=int(time[1])
		log={'phone':phone,'starth':starth,'startm':startm,'endh':endh,'endm':endm}
		_pickle.dump(log, outFile)
		c=input("Continue? (Y/N)")
		if ((c == 'n') or (c == 'N')):
			flag=False
	outFile.close()
def printing():
	with open("test.txt", "rb") as inFile:
		try:
			log=_pickle.load(inFile)
		except EOFError:
			print("no data-----------")		
		print("\nInformation about phone calls:")
		while True:
			print(log['phone']," ",log['starth'],":",log['startm']," ",log['endh'],":",log['endm'])
			try:
				log=_pickle.load(inFile)
			except EOFError:
				break
def price():
	mainFile=open("test.txt","rb")
	helpFile=open("second.txt","wb")
	j=1
	try:
		log=_pickle.load(mainFile)
	except EOFError:
		print("no data-----------")	
	while True:
		times=log['starth']*60+log['startm']
		timef=log['endh']*60+log['endm']
		if(times>timef):
			timef=timef+1440
		i=0
		finished=False
		price=0.00
		while (finished==False):
			if (times==timef):
				length=i
				if (length>=3):
					_pickle.dump(log,helpFile)
				print("Price for phone",j,"is",price)
				print("Length for phone",j,"is",length)
				finished=True
				j=j+1
			else:
				if (times>=540 and times<=1200):
					price=price+1.5
				elif (times>1200 and times<1980):
					price=price+0.9
				elif (times<=540 and times>=0):
					price=price+0.9
				elif (times >=1980 and times<=2640):
					price=price+1.5
				times=times+1
				i=i+1
		
		try:
			log=_pickle.load(mainFile)
		except EOFError:
			break
	mainFile.close()
	helpFile.close()
def copy():
	mainFile=open("test.txt","wb")
	helpFile=open("second.txt","rb")
	try:
		log=_pickle.load(helpFile)
	except EOFError:
		print("no data-----------")
	while True:
		_pickle.dump(log,mainFile)
		try:
			log=_pickle.load(helpFile)
		except EOFError:
			break
	mainFile.close()
	helpFile.close()


create_note()
printing()
price()
copy()
printing()	