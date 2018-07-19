"""This script connects to the BTC Markets API
Downloads ticker data, and writes the data to a local MongoDB instance

Author: Jason Neurohr
Version: 0.1
"""

import json
import requests
import pymongo

def mongo_insert(rec):
    """Insert record into MongoDB
    """

    client = pymongo.MongoClient('localhost', 27017)
    # client = pymongo.MongoClient("mongodb://james:HqXkxESZWWq9@18.191.185.76/btc2", 27017)
    db = client.btc2
    collection = db['ticks']

    try:
        result = collection.insert_one(rec)
        rec_id = result.inserted_id
    except pymongo.errors.ConnectionFailure as err:
        # print('Connection Error: ', err, sep='')
        print('Connection Error: ', err)

def get_tick(url):
    """Get tick data from BTCMarkets API

    Returns:
        dict: Tick data as a dictionary
    """

    req = requests.session()
    res = req.get(url)
    res_text = json.loads(res.text)

    return res_text

def main():
    """Main function
    """

    # Initialise ticker URLs list
    tick_urls = [
        'https://api.btcmarkets.net/market/ETH/AUD/tick',
        'https://api.btcmarkets.net/market/BTC/AUD/tick'
    ]

    # For each ticker URL in the tick_urls list
    # get the data and then commit to MongoDB
    for ticker in tick_urls:
        rec = get_tick(ticker)
        mongo_insert(rec)

if __name__ == "__main__":
    main()
