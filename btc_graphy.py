"""This script connects to a local MongoDB instance and
generates a line Graph using Plotly for data inserted by the
btc_dump.py script

Author: Jason Neurohr
Version: 0.1
"""

import time
import datetime
import plotly
import pymongo
from plotly.graph_objs import Layout, Scatter


def main():
    """Main Function
    """

    eth_last_price = []
    eth_best_bid = []
    eth_best_ask = []
    eth_timestamp = []

    btc_last_price = []
    btc_best_bid = []
    btc_best_ask = []
    btc_timestamp = []

    client = pymongo.MongoClient('localhost', 27017)
    db = client.btc2
    collection = db['ticks']

    # get beginning and end of date range of interest
    sometime_east_coast = datetime.datetime.\
    strptime("2018-06-27 18:34:25", "%Y-%m-%d %H:%M:%S")

    sometime_hawaii = datetime.datetime.\
    strptime("2018-06-27 12:34:25", "%Y-%m-%d %H:%M:%S")

    # account for timezone difference
    est_minus_hst_minus_dst = sometime_east_coast - sometime_hawaii

    # this is 10 hours slow
    begin = datetime.datetime.\
    strptime("2018-06-28 08:32:00", "%Y-%m-%d %H:%M:%S")

    # this is 10 hours slow
    end = datetime.datetime.now() + est_minus_hst_minus_dst

    try:
        for rec in collection.find({"instrument":"ETH"}):
            eth_ts = datetime.datetime.fromtimestamp(rec['timestamp'])
            if (eth_ts >= begin) and (eth_ts <= end):
                eth_last_price.append(rec['lastPrice'])
                eth_best_bid.append(rec['bestBid'])
                eth_best_ask.append(rec['bestAsk'])
                eth_timestamp.append(eth_ts)
    except Exception as err:
        print(err)

    # Because of the price difference between Etherum and Bitcoin
    # Divide Bitcon prices by 10 to make the graph nicer
    try:
        for rec in collection.find({"instrument":"BTC"}):
            btc_ts = datetime.datetime.fromtimestamp(rec['timestamp'])
            if (btc_ts >= begin) and (btc_ts <= end):
                btc_last_price.append(rec['lastPrice'] / 10)
                btc_best_bid.append(rec['bestBid'] / 10)
                btc_best_ask.append(rec['bestAsk'] / 10)
                btc_timestamp.append(btc_ts)
    except Exception as err:
        print(err)

    eth_lp = Scatter(
        y=eth_last_price,
        x=eth_timestamp,
        name='ETH Last Price',
        mode='lines+markers')

    eth_bb = Scatter(
        y=eth_best_bid,
        x=eth_timestamp,
        name='ETH Best Bid',
        mode='lines+markers')

    eth_ba = Scatter(
        y=eth_best_ask,
        x=eth_timestamp,
        name='ETH Best Ask',
        mode='lines+markers')

    btc_lp = Scatter(
        y=btc_last_price,
        x=btc_timestamp,
        name='BTC Last Price minus 10^1',
        mode='lines+markers')

    btc_bb = Scatter(
        y=btc_best_bid,
        x=btc_timestamp,
        name='BTC Best Bid minus 10^1',
        mode='lines+markers')

    btc_ba = Scatter(
        y=btc_best_ask,
        x=btc_timestamp,
        name='BTC Best Ask minus 10^1',
        mode='lines+markers')

    plotly.offline.plot(
        {
            # 'data': [eth_lp, eth_bb, eth_ba, btc_lp, btc_bb, btc_ba],
            'data': [btc_lp, btc_bb, btc_ba],
            'layout': Layout(title="BTC Markets Graph")},
        filename=r"btc.html", auto_open=True)

if __name__ == "__main__":
    main()
