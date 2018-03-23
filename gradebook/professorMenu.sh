<<PROGRAM_DESCRIPTION
If the user chose option 2, the next menu(s) will look like this:
********************************************************************************
Choose a course:

1. Algebra
2. Anthropology
3. Learning
4. Anti-learning

Choose an option:

1. View grades
2. Modify grades

Algebra grades:
1. Jack          A
2. Jill          C
3. Doinkleton    B

Which student's grade is to be modified?

1. Jack
2. Jill
3. Doinkleton

Doinkleton's new grade is: [Enter Grade]


add average grade output function
add "find all grades above 69" function
********************************************************************************
PROGRAM_DESCRIPTION

echo "These are the professors:\n"
awk 'BEGIN { FS = "|" } ;
           { print $1 }' professors
echo "Which professor are you? \c"
read NAME
echo ""

echo "$NAME, here are your courses:\n"

awk -v name="$NAME" '
    {
        FS = "|";
        if ($1~name)
        {
            for (i=2; i<=NF; i++)
            {
                print $i
            }
        }
    }' professors
echo "\nWhich course would you like to view?"
read COURSE
echo "You chose $COURSE\n"
echo "Choose an option:\n"
echo "1. View grades"
echo "2. Modify grades\n"
read OPTION
if [ $OPTION == 1 ]
then
    echo "$COURSE"
    # view grades of the chosen course
    awk -v course="$COURSE" 'BEGIN { FS = "|" };
                       $3~course { print $2 $4}' grades
elif [ $OPTION == 2 ]
then
    echo "You chose 2."
    # modify the grades of the chosen course
else
    echo "You mis-chose $OPTION."
    echo "Please choose 1 or 2\n"
fi


# display everyone in the course, and their grade
# ask

# awk -v name="$NAME" 'BEGIN { FS = "|" } ;
#                    $1~name { print $0}' professors
# awk -v name="$NAME" -f findGrade.awk grades



# echo "you can modify an account\n"
#
# echo "Input the student's name: \c"
# read NAME
# echo "Input the student's new name: \c"
# read NEW_NAME
# echo "Input the student's new year: \c"
# read NEW_YEAR
# echo "\n"
#
# rm tmp
# touch tmp

# awk 'BEGIN {
#    for (i = 0; i < ARGC - 1; ++i) {
#       printf "ARGV[%d] = %s\n", i, ARGV[i]
#    }
# }' one two three four

# awk '{ print "name: " $1, "year: " $2 }' students

# awk -v name="$NAME" -v new_name="$NEW_NAME" -v new_year="$NEW_YEAR" '{
#     if ($1 == name)
#         print new_name," ",new_year >> "tmp";
#     else
#         print $1," ",$2 >> "tmp" ;
#  }' students
#
# awk '{print $0}' tmp > students
# # mv tmp students
# awk '{ print "name: " $1, "year: " $2 }' students
