# The create account option should write to the student file.
# get student info from the user
# write that stuff to the file.
# echo "Input loco moco: "
# read LOCO_MOCO
# echo $LOCO_MOCO

echo "you can create an account"
echo "Input the student's name: \c"
read NAME
echo "Input the student's year"
echo "(freshman, sophomore, junior, senior, other): \c"
read YEAR
echo "$NAME $YEAR" >> students
echo "\nAccounts:\n"
awk '{ print "name: " $1, "year: " $2 }' students
