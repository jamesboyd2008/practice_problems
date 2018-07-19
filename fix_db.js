// This program renames a field within an array in every item in the DB
// from hybrid_sel* to hybrid_selVal*.

// Prerequisites:
// conda install -c conda-forge nodejs
// npm install (assuming the package.json is still here)

const MongoClient = require('mongodb').MongoClient;
const assert = require('assert');

// Connection URL
const url = 'mongodb://localhost:27017';

MongoClient.connect(url, { useNewUrlParser: true }, function(err, db) {
    if (err) throw err;
    var dbo = db.db("ytla");
    dbo.collection("datum").find({}).toArray(function(err, result) {
        if (err) throw err;
        result.forEach(function(item){
            for(i = 0; i != item.antennas.length; ++i)
            {
                item.antennas[i].hybrid_selValX = item.antennas[i].hybrid_selX;
                item.antennas[i].hybrid_selValY = item.antennas[i].hybrid_selY;
                delete item.antennas[i].hybrid_selX;
                delete item.antennas[i].hybrid_selY;
            }
            dbo.collection("datum").update({_id: item._id}, item);
        })
        db.close();
    });
});
