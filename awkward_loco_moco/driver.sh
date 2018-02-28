# This program simulates an automated library system.

# The user menu looks like this:

# Choose an option:
#
# 1. Create account
# 2. Modify account
# 3. Find a book
# 4. Find a student

# In the same directory as this script, there needs to be a file
# called students and a file called books. Both files have 7-10
# fields.

# The driver program displays the menu and calls the other programs.
while [ true ]
do
    # echo -e "loco moco \c"
    # read response
    echo -e "Choose an option:\n"
    echo -e "1. Create account"
    echo -e "2. Modify account"
    echo -e "3. Find a book"
    echo -e "4. Find a student\n"
    read OPTION
    echo ""
    # choose the appropriate helper program, based on OPTION

    if [ $OPTION == 1 ]
    then
        echo "You chose 1."
        sh ./createAccount.sh
    elif [ $OPTION == 2 ]
    then
        echo "You chose 2."
        sh ./modifyAccount.sh
    elif [ $OPTION == 3 ]
    then
        echo "You chose 3."
        sh ./bookFind.sh
    elif [ $OPTION == 4 ]
    then
        echo "You chose 4."
        sh ./studentFind.sh
    else
        echo "You mis-chose $OPTION."
        echo "Please choose 1, 2, 3, or 4."
    fi
done
