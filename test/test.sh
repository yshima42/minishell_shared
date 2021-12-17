#!/bin/bash
##Usage
##680.sh | bash
echo  "#!/bin/bash"
echo
echo -n "echo aaa | "

i=1
while [ $(($i+2)) -le $1 ]
do
	echo -n "cat | "
	i=$((i + 1))
done

echo -n cat