import webbrowser
import spacy
nlp = spacy.load('en_core_web_sm')
from py2neo import Node, Relationship, Graph


## Importing the data
with open ("umls/entities.txt", "r") as myfile:
    entities = myfile.readlines()
for i in range(len(entities)):
    entities[i] = entities[i].split()

with open ("umls/entity_category.txt", "r") as myfile:
    entity_category = myfile.readlines()
for i in range(len(entity_category)):
    entity_category[i] = entity_category[i].split()
    
with open ("umls/relations.txt", "r") as myfile:
    relations = myfile.readlines()
for i in range(len(relations)):
    relations[i] = relations[i].split()


with open ("umls/triples.txt", "r") as myfile:
    triples = myfile.readlines()
for i in range(len(triples)):
    triples[i] = triples[i].split()
    
## getting entity_to_id and id_to_entity
entity_to_id = {}
id_to_entity = {}
for i in entities:
    entity_to_id[i[1]] = i[0]
    id_to_entity[i[0]] = i[1]

## getting category_to_id and id_to_category
category_to_id = {}
id_to_category = {}
for i in entity_category:
    category_to_id[i[1]] = i[0]
    id_to_category[i[0]] = i[1]
    
## getting relation_to_id and id_to_relation
relation_to_id = {}
id_to_relation = {}
for i in relations:
    relation_to_id[i[1]] = i[0]
    id_to_relation[i[0]] = i[1]

## Creating Nodes
nodes_e = []
nodes_c = []
for i in range(len(entities)):
    nodes_e.append(Node('Entity',name = entities[i][1],id_e = entity_to_id[entities[i][1]]))
for i in range(len(entity_category)):
    nodes_c.append(Node('Category',name = entity_category[i][1],id_c = category_to_id[entity_category[i][1]]))

relationships = []
for i in triples:
    relationship = Relationship(nodes_e[int(i[1])],id_to_relation[i[0]].replace('-','_'),nodes_e[int(i[2])])
    relationships.append(relationship)

# CReating the graph
graph =Graph(host='localhost',user='neo4j', password=None) # initial graph from the data
#graph = Graph('bolt://neo4j:test@127.0.0.1:7687/db/data')
tx = graph.begin()

for node in nodes_e:
    tx.create(node)
for relationship in relationships:
    tx.create(relationship)
    
tx.commit()

#url = 'http://localhost:7474'
#webbrowser.open(url, new=2) # new=2 opens a new tab
