# The modify account option should write to the student file.

echo "you can modify an account\n"

echo "Input the student's name: \c"
read NAME
echo "Input the student's new name: \c"
read NEW_NAME
echo "Input the student's new year: \c"
read NEW_YEAR
echo "\n"

rm tmp
touch tmp

# awk 'BEGIN {
#    for (i = 0; i < ARGC - 1; ++i) {
#       printf "ARGV[%d] = %s\n", i, ARGV[i]
#    }
# }' one two three four

# awk '{ print "name: " $1, "year: " $2 }' students

awk -v name="$NAME" -v new_name="$NEW_NAME" -v new_year="$NEW_YEAR" '{
    if ($1 == name)
        print new_name," ",new_year >> "tmp";
    else
        print $1," ",$2 >> "tmp" ;
 }' students

awk '{print $0}' tmp > students
# mv tmp students
awk '{ print "name: " $1, "year: " $2 }' students
