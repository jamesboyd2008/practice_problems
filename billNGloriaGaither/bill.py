# This script manipulates data from a file, music.csv, which contains real
# data about songs and their artists.

import csv

def longLoud(quality):
    """
    This function determines which musician made a the most extreme song, by a
    given metric, such as loudness or duration.

    Params:
        quality (str): The quality for which we seek the producer of the song
                       with the most quantity.

    Returns:
        artist (str): The artist who produced the most music, by a metric.
    """
    with open('music.csv', 'r') as musicFile:
        reader = csv.DictReader(musicFile)
        artist = ''
        mostMusic = None
        for row in reader:
            quantity = float(row[quality])
            if mostMusic is None or quantity > mostMusic:
                artist = row['artist']
                mostMusic = quantity
    return artist

def mostMusic(quality, matchQuantity = ''):
    """
    This function determines which musician made the most songs that satisfy a
    given criteria, such as quantity of hit songs.

    Params:
        quality (str): The quality for which we seek the producer of the song
                       with the most quantity.
        matchQuantity (str): The value a song must meet or exceed to count
                             towards an artist's total.

    Returns:
        champs (list): The artist(s) who produced the most music, by a metric.
    """
    songs = {} # artists are keys, the number of songs they made are values.
    with open('music.csv', 'r') as musicFile:
        reader = csv.DictReader(musicFile)
        for row in reader:
            artist = row['artist']
            # matchQuantity defaults to an empty str for the purpose of
            # counting songs produced, assuming every song a has a name.
            if row[quality] >= matchQuantity:
                songs[artist] = songs[artist] + 1 if artist in songs else 1
    # return(max(songs, key = songs.get)) # doesn't account for ties

    # The block below determines which artist songs made the most songs.
    max = None
    champs = []
    for artist in songs:
        if max is None or songs[artist] == max:
            max = songs[artist]
            champs.append(artist)
        elif songs[artist] > max:
            max = songs[artist]
            champs = [artist]

    return(champs)

def mostGenres():
    """
    This function determines which artist's work, from music.csv, spans the most
    distinct genres.

    Params:
        None

    Returns:
        champs (list) : The artist(s), whose works spans the most genres.
    """
    songs = {}
    with open('music.csv', 'r') as musicFile:
        reader = csv.DictReader(musicFile)
        # Concerning the artists dict, below:
            # Artists are keys.
            # The values are lists of genres of songs the artists made.
        artists = {}
        # Populate the artists dict.
        for row in reader:
            artist = row['artist']
            term = row['terms']
            if artist in artists:
                if term not in artists[artist]: # Doing the job of a set, here.
                    artists[artist].append(term)
            else:
                artists[artist] = [term]

    # The block below determines which artist(s) list of generes is the longest.
    max = None
    champs = []
    for artist in artists:
        genres = len(artists[artist])
        if max is None or genres == max:
            max = genres # It's not necessary to do this so much.
            champs.append(artist)
        elif genres > max:
            max = genres
            champs = [artist]

    return(champs)


def main():
    for champ in mostMusic('song'):
        print('The artist(s) with the most songs is', champ)

    print('The artist with the longest song is', longLoud('duration (seconds)'))
    print('The artist who is the loudest is', longLoud('loudness'))

    for champ in mostMusic('buzz', '0.8'):
        print('The artist(s) with the most hits is', champ)

    for champ in mostGenres():
        print('The artist(s) whose work spans the most genres is', champ)

if __name__ == '__main__':
    main()

