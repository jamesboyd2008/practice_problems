#!/bin/sh
# This program checks a document for spelling errors.
# It does so by comparing each word in the document against a list of words
# composed from another provided dictionary file.
# This program takes 2 arguments:
#   1. The dictionary file, a text file.
#   2. The document to be spell-checked, a text file.
# The output will consist of every detected spelling error and the line on
# which it occured.

declare -a words=() # this variable will hold the words in the dictionary

# iterate over every word in the dictionary file (argument $1)
for word in $(cat $1);
do
    a_word="$(tr [A-Z] [a-z] <<< "$word")" # convert letters to lower case
    a_word="$(tr -d '[:punct:]' <<< "$a_word")" # remove punctuation
    words+=($a_word) # append word to dictionary array
done

# slowly sort words alphabetically and remove duplicates
# TODO: question the necessity of alphabetization for speed's sake.
words=($(echo "${words[@]}" | tr ' ' '\n' | sort -u | tr '\n' ' '))

# print the sorted, normalized, no-duplicates dictionary
# for i in "${words[@]}"
# do
#     echo "$i"
# done

line_count=1
while read line; do # iterate over every line in document (argument $2)
    for word in $line; # iterate over every word in the line
    do
        a_word="$(tr [A-Z] [a-z] <<< "$word")" # convert letters to lower case
        a_word="$(tr -d '[:punct:]' <<< "$a_word")" # remove punctuation
        # if the word is not in the dictionary, it's a spelling error.
        if [[ ! " ${words[@]} " =~ " ${a_word} " ]];
        then
            # print it and its location
            a_word="$(tr -d '[:punct:]' <<< "$word")" # keep original case
            echo "$a_word was misspelled on line $line_count"
        fi
    done
    let line_count+=1
done < $2 # the document to be checked for spelling errors

# Opportunities for improvement:
# suggest alternative spellings for mispelled words based on the most similar
#     word in the dictionary.
# give the user the opportunity to use a built in dictionary ... ispell?
# optimize for speed? This program is SLOW.
