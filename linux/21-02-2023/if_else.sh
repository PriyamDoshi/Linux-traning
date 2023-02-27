
#1/bin/bash
NAME="priyam"
if [ "$NAME" = "riyam" ];
then
	echo " wellcome doshi"
else 
	echo "f o"
	fi
count=10
read input
if (( $count > $input ))
then
echo "true"
else 
echo "f"
fi
echo "inter your age\n"
read age
if [[ "$age" > 18 && "$age" < 30 ]];
then 
echo "enjoy"
else
 echo "sad life"
fi

