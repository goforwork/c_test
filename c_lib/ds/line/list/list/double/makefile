# target:prerequiresites
# tab CMD

target = llist
target_list = main.o llist.o

$(target): $(target_list)
	gcc $^ -o $@

%.o: %.c
	gcc -c $^ -o $@

clean:
	rm *.o $(target).exe -f