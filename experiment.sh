read END
for i in $(seq 1 $END)
do
	echo $i
	./a.out $i >> bsd.txt
	./b.out $i >> rbt.txt
done
