# This file contains the function definition of parent(dogo, side).

import MySQLdb

def parent(dogo, side):
    """
    This function returns the name of a dog's parent.

    Parameters:
        dogo (str) : the name of the dog whose parent we seek.
        side (str) : 'dam' or 'sire', i.e., maternal side or paternal side.

    Returns:
        parent (str) : the name of a parent, if it's known.
            If a progenitor's name is unknown, then <unknown> is returned.
    """
    # Get DB credentials.
    creds = []
    with open('/etc/cs172/configs/common_db_credentials', 'r') as file:
        creds = file.read().split()

    # Connect to the DB.
    db = MySQLdb.connect(
        host = 'localhost',
        user = creds[0],
        passwd = creds[1],
        db = 'cs172'
    )

    if dogo == '<unknown>':
        return('<unknown>')

    cursor = db.cursor(MySQLdb.cursors.DictCursor)
    cursor.execute("SELECT * FROM dogs WHERE name=%s", [dogo])
    res = cursor.fetchall()
    return(res[0][side])

