#!/usr/bin/env python
# -*- coding: utf-8 -*-
from cassandra.cluster import Cluster
from cassandra.auth import PlainTextAuthProvider
import yaml
file = open('config.yaml')
config = yaml.load(file, Loader=yaml.FullLoader)
 
config = config['cassandra']
auth_provider = PlainTextAuthProvider(
    username=config['username'],
    password=config['password'])
cluster = Cluster(config['hosts'], 
 auth_provider = auth_provider)
session = cluster.connect('nazwa_przestrzeni')

rows = session.execute("Zapytanie w CQL")
for row in rows:
 print("Ciekawy napis: {0}".format(row[0]))

from cassandra.query import SimpleStatement
from cassandra import ConsistencyLevel

query = SimpleStatement("Zapytanie w CQL", consistency_level=ConsistencyLevel.QUORUM)
rows = session.execute(query)
