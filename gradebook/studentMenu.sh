<<STUDENT_MENU_DESCRIPTION
If the user chose option 1, the next menu(s) will look like this:
********************************************************************************
Which student are you?

Jack
Jill
Doinkleton
...

Doinkleton, here are your courses and grades:

Algebra:           C
Anthropology:      B
Learning:          A
Anti-learning:     F

********************************************************************************
STUDENT_MENU_DESCRIPTION

echo "These are the students:\n"
awk 'BEGIN { FS = "|" } ;
           { print $2 }' students
echo "Which student are you? \c"
read NAME
echo ""
echo "$NAME, here is your record:\n"
# awk -v name="$NAME" '$1~name{ print "Student ID: " $1}' students
awk -v name="$NAME" 'BEGIN { FS = "|" } ;
                   $2~name { print "Student ID: " $1}' students
# PICKUP HERE: merge the students and marks files. Only students and courses
# are required. Aint no SQL in this project.

# awk 'BEGIN { FS = "|" } ;
#            { print $2 }' students
