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
words=($(echo "${words[@]}" | tr ' ' '\n' | sort -u | tr '\n' ' '))

words_length=${#words[@]}

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
            echo "$a_word was misspelled on line $line_count"

            # suggest alternative spellings for mispelled words based on the
            # two most similar word(s) in the dictionary.
            # Loop through dictionary.
            for (( word_count=0; word_count<${words_length}; word_count++ ));
            do
                # Stop once you pass where the typo would be.
                if [[ " ${words[word_count]} " > " ${a_word} " ]];
                then
                    if [[ $word_count > 0 ]]; # avoid program crash
                    then
                        # suggest the word before it
                        echo -e "Perhaps \"${words[word_count - 1]}\" or \c"
                        # suggest the word after it
                        echo -e "\"${words[word_count]}\" might work.\n"
                    else # in case "a" ain't in the dictionary
                        echo -e "Perhaps \"${words[word_count]}\" might work.\n"
                    fi
                    break;
                fi
            done
        fi
    done
    let line_count+=1
done < $2 # the document to be checked for spelling errors

# Opportunities for improvement:
# give the user the opportunity to use a built in dictionary ... ispell?
# optimize for speed? This program is SLOW.
