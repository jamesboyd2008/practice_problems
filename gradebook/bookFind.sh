# The find a book option should search through the books file,
# and output results to the console.

echo "Find a book by...\n"
echo "1. title"
echo "2. author\n"
read OPTION
echo ""

if [ $OPTION == 1 ]
then
    echo "You chose 1."
    echo "Input the book's title: \c"
    read TITLE
    echo "\n"
    awk -v title="$TITLE" '$1~title{ print "title: " $1, "\n" "author: " $2 }' books
    echo "\n"
    echo "Woud you like to check this book out? (y/n) \c"
    read CHECK_OUT
    if [ $CHECK_OUT == "y" ]
    then
        rm tmp
        touch tmp

        echo "To whom shall this book be checked out? \c"
        read NAME

        # account for student having book
        awk -v name="$NAME" -v title="$TITLE" '{
            if ($1 == name)
                print $1," ",$2," ",title >> "tmp";
            else
                print $1," ",$2 >> "tmp" ;
         }' students

        awk '{print $0}' tmp > students
        # mv tmp students
        awk '{ print "name: " $1, "year: " $2, "titles out: " $3 }' students

        # account for book being out
        awk -v title="$TITLE" '{
            if ($1 == title)
                print $1," ",$2," ","out" >> "tmp";
            else
                print $1," ",$2 >> "tmp";
        }' books
        awk '{print $0}' tmp > books
    fi
elif [ $OPTION == 2 ]
then
    echo "You chose 2."
    echo "Input the book's author: \c"
    read AUTHOR
    echo "Do you care about the date of publishing? (y/n): \c"
    read CARE
    if [ $CARE != "y" ]
    then
        echo "\n"
        awk -v author="$AUTHOR" '$2~author{ print "title: " $1, "\n" "author: " $2 }' books
        echo "\n"
    else
        echo "Enter earliest possible date of publishing: \c"
        read DATE
        echo "\n"
        # awk -v author="$AUTHOR" '$2~author{ print "title: " $1, "\n" "author: " $2 }' books
        awk -v author="$AUTHOR" -v date="$DATE" '$2~author && $3 >= date { print "title: " $1, "\n" "author: " $2 "\n" "date published: " $3}' books
        echo "\n"
    fi
else
    echo "You mis-chose $OPTION."
    echo "Next time, please choose 1 or 2."
fi
