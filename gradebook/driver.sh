<<PROGRAM_DESCRIPTION
This program simulates the functionality of a gradebook.
Students and professors, observing the honor system, use the same program.
    --> Authentication can be implemented at a later date.

Students can view their grades in their courses.
Professors can change students' grades in courses.

The user menu(s) look like this:
********************************************************************************
You are a ...

1. Student
2. Professor
********************************************************************************

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

The driver program displays the menu and calls the other programs.
PROGRAM_DESCRIPTION

while [ true ]
do
    echo -e "You are a ...\n"
    echo -e "1. Student"
    echo -e "2. Professor"
    read OPTION
    echo ""

    if [ $OPTION == 1 ]
    then
        echo "You chose 1."
        sh ./studentMenu.sh
    elif [ $OPTION == 2 ]
    then
        echo "You chose 2."
        sh ./professorMenu.sh
    else
        echo "You mis-chose $OPTION."
        echo "Please choose 1 or 2"
    fi
done
