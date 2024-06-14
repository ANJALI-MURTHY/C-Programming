obj = menu.o CreateLL.o addAddress.o lookUpAddress.o lookUp.o aliasForLoc.o updateAddress.o deleteAddress.o checkRange.o saveToFile.o newNode.o displayList.o 
output: $(obj)
	gcc -o output $(obj)

menu.o: menu.c header.h
	gcc -c menu.c
CreateLL.o: CreateLL.c header.h
	gcc -c CreateLL.c
addAddress.o: addAddress.c header.h
	gcc -c addAddress.c
lookUp.o: lookUp.c header.h
	gcc -c lookUp.c
lookUpAddress.o: lookUpAddress.c header.h
	gcc -c lookUpAddress.c
aliasForLoc.o: aliasForLoc.c header.h
	gcc -c aliasForLoc.c
updateAddress.o: updateAddress.c header.h
	gcc -c updateAddress.c
deleteAddress.o: deleteAddress.c header.h
	gcc -c deleteAddress.c
checkRange.o: checkRange.c header.h
	gcc -c checkRange.c
saveToFile.o: saveToFile.c header.h
	gcc -c saveToFile.c
newNode.o: newNode.c header.h
	gcc -c newNode.c
displayList.o: displayList.c header.h
	gcc -c displayList.c


clean:
	rm -rf a.out
	m -rf $(obj)