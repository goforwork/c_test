# target:prerequiresites
# tab CMD

arr.exe: main.o sqlist.o
	gcc $^ -o $@

%.o: %.c
	gcc -c $^ -o $@

clean:
	rm *.o arr.exe -f