#!/bin/sh
# This program checks a document for spelling errors.
# It does so by comparing each word in the document against a list of words
# composed from another provided dictionary file.
# This program takes 2 arguments:
#   1. The dictionary file, a text file.
#   2. The document to be spell-checked, a text file.
# The output will consist of every detected spelling error and its location
# in the document.

# declare -a words=("hey" "ho" "we" "dont" "know" "how" "to" "grow")

declare -a words=() # this is where we'll keep our words

# iterate over every word in the dictionary file (argument $1)
for word in $(cat $1);
do
    a_word="$(tr [A-Z] [a-z] <<< "$word")" # convert letters to lower case
    a_word="$(tr -d '[:punct:]' <<< "$a_word")" # remove punctuation
    words+=($a_word) # append word to array
done

# slowly sort words alphabetically and remove duplicates
words=($(echo "${words[@]}" | tr ' ' '\n' | sort -u | tr '\n' ' '))

# for i in "${words[@]}"
# do
#     echo "$i"
# done

declare -a questionable_words=()

# document: the document to be checked for spelling errors
# iterate over every word in document (argument $2)
# for word in $(cat $2);
# do
#     a_word="$(tr [A-Z] [a-z] <<< "$word")" # convert letters to lower case
#     a_word="$(tr -d '[:punct:]' <<< "$a_word")" # remove punctuation
#     # if its in the dictionary, move on
#     if [!["${words[@]}" =~ "${word}" ]];
#     then
#         echo $word
#     fi
#     # if not, it's a spelling error. print it and its location
#
# done










# Opportunities for improvement:
# optimize for speed? This program is SLOW.
