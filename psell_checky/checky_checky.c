// get name of file to be spell checked as single arg
// go through each word, one at at time
// see if its in your dictionary -- linear search
    // if it is, move on to next word
    // if it isn't, add it to the collection of words that are mispelled
        // maybe add it's location to output, as well
            // location is line number and character count
                // get this from something else

// #include <stdio.h>
//
// int main(void)
// {
//     char words[200][20];
//
//     printf("Hello World\n");
//     return 0;
// }

#include <stdio.h>
#include <string.h>

// words were retrieved (then all caps'd by James in a c++ program) from
// http://hawaiian-words.com/hawaiian-dictionary/
const char * words[] = {
    "A HUI HOU",
    "A HUI HOU KāKOU",
    "A‘ā",
    "‘A‘OLE PILIKIA",
    "‘AE",
    "AHUPUA‘A",
    "‘ĀINA",
    "AKAMAI",
    "AKUA",
    "ALA",
    "ALELO",
    "ALI‘I",
    "ALOHA",
    "ALOHA ‘AUINALā",
    "ALOHA ‘OE",
    "ALOHA AHIAHI",
    "ALOHA ‘āINA",
    "ALOHA AU IA ‘OE",
    "ALOHA KAKAHIAKA",
    "ALOHA NUI LOA",
    "‘A‘OLE PILIKIA",
    "‘AUANA",
    "‘AUMAKUA",
    "E KOMO MAI",
    "HāLAU",
    "HALE",
    "HANA",
    "HANA HOU",
    "HāNAI",
    "HAOLE",
    "HAPA HAOLE",
    "HāPAI",
    "HAU‘OLI Lā HāNAU",
    "HAU‘OLI Lā HO‘OMAHA LOA",
    "HAU‘OLI Lā HO‘OMANA‘O",
    "HAU‘OLI",
    "HAU‘OLI HANUKAHA",
    "HAU‘OLI HANUKAHA ME KA MAKAHIKI HOU",
    "HAU‘OLI MAKAHIKI HOU",
    "HEHENA",
    "HEIAU",
    "HELE",
    "HIAPO",
    "HINA",
    "HOALOHA	FRIEND",
    "Hō‘IKE	SHOW, DISPLAY",
    "HōKū",
    "HOLOHOLO",
    "HONU",
    "HUHū",
    "HULA",
    "HULI-HULI",
    "HUMUHUMUNUKUNUKUAPUA'A",
    "I'A",
    "IMU",
    "KAHIKO",
    "KAHU",
    "KAHUNA",
    "KAI",
    "KāLā",
    "KALA MAI IA‘U",
    "KALO",
    "KAMA‘āINA",
    "KāNE",
    "KANIKAPILA",
    "KAPA",
    "KAPU",
    "KEIKI",
    "KOA",
    "KōKUA",
    "KOLOHE",
    "KULEANA",
    "KULIKULI",
    "KUMU",
    "KUPUNA",
    "KU‘UIPO",
    "LAKI",
    "LANAI",
    "LANI",
    "LAU",
    "LAULE‘A",
    "LAULIMA",
    "LEHUA",
    "LEI",
    "LEILANI",
    "LO‘I",
    "LOLO",
    "Lū‘AU",
    "LUNA",
    "MAHALO",
    "MAHALO NUI LOA",
    "MAHA‘OI",
    "MAHINA",
    "MAIKA‘I",
    "MAIKA‘I NO AU",
    "MAKA",
    "MAKAI",
    "MAKANA",
    "MAKUA",
    "MāLAMA",
    "MALIHINI",
    "MANA‘O",
    "MANAPUA",
    "MANINI",
    "MANō",
    "MANU",
    "MANUAHI",
    "MAOLI",
    "MAU LOA",
    "MAUKA",
    "MELE",
    "MELE KALIKIMAKA",
    "MELE KALIKIMAKA ME KA HAU‘OLI MAKAHIKI HOU",
    "MENEHUNE",
    "MOANA",
    "MOKU",
    "MO‘O",
    "MO‘OPUNA",
    "NALU",
    "NANI",
    "NīELE",
    "NIU",
    "NUI",
    "‘O IA MAU Nō",
    "‘OHANA",
    "‘ŌKOLE",
    "‘ŌLELO",
    "‘OLI",
    "‘ONO",
    "‘ŌPALA",
    "‘ŌPū",
    "PāHOEHOE",
    "PALAHē",
    "PALI",
    "PANIOLO",
    "PAU",
    "PEHEA ‘OE",
    "PILAU",
    "PILIKIA",
    "PōHAKU",
    "POI",
    "PAKALOLO",
    "PōMAIKA`I",
    "Pū",
    "PUA‘A",
    "PULE",
    "PūPū",
    "PUPULE",
    "PU‘UWAI",
    "TūTū",
    "U‘I",
    "‘UKU",
    "WA‘A",
    "WAHINE",
    "WAI",
    "WAIPAHē",
    "WIKIWIKI"
};

// n_words is an array of strings that knows it's size // 157, here, mwahaha
#define n_words (sizeof (words) / sizeof (const char *))

int main (int argc, char *argv[])
{
    for (int i = 0; i < n_words; i++) {
        // printf ("%d: %s\n", i, words[i]);
        printf ("%s\n", words[i]);
    }
    return 0;
}

/* Example using strcmp by TechOnTheNet.com */

// #include <stdio.h>
// #include <string.h>
//
// int main(int argc, const char * argv[])
// {
//     /* Create a place to store our results */
//     int result;
//
//     /* Create two arrays to hold our data */
//     char example1[50];
//     char example2[50];
//
//     /* Copy two strings into our data arrays */
//     strcpy(example1, "C programming at TechOnTheNet.com");
//     strcpy(example2, "C programming is fun");
//
//     /* Compare the two strings provided */
//     result = strcmp(example1, example2);
//
//     /* If the two strings are the same say so */
//     if (result == 0) printf("Strings are the same\n");
//
//     /* If the first string is less than the second say so
//      (This is because the 'a' in the word 'at' is less than
//      the 'i' in the word 'is' */
//     if (result < 0) printf("Second string is less than the first\n");
//
//     return 0;
// }
