# target:prerequiresites
# tab CMD

target = list
target_list = main.o head_list.o

$(target): $(target_list)
	gcc $^ -o $@

%.o: %.c
	gcc -c $^ -o $@

clean:
	rm *.o $(target).exe -f