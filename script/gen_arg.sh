#!/bin/bash

# echo  "#!/bin/bash"
# echo
echo -n "ls "

i=1
while [ $(($i+1)) -le $1 ]
do
	echo -n "a "
	i=$((i + 1))
done

echo -n b

