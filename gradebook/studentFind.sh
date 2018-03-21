# The find a student option should search through the students file,
# and output results to the console.

echo "find a student"
echo "Input the student's name: \c"
read NAME
echo "\n"
awk -v name="$NAME" '$1 == name { print "name: " $1, "\n" "year: " $2, "\n" "books out: " $3 }' students
echo "\n"
