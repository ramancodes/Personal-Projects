from pymongo import MongoClient


class MongoDB:
    def __init__(self, email, password, name=None, client=None, db=None, collection=None):
        self.password, self.name, self.email = password, name, email
        self.client, self.db, self.collection = client, db, collection

    def login(self):
        query = {"$and": [{"email": {"$eq": self.email}}, {"password": {"$eq": self.password}}]}
        self.connect_to_db()
        self.create_db(dbname=self.db)
        self.create_collection(coll_name=self.collection)
        result = self.read_data(query=query)
        if result is None:
            return "User Not Found! Please Register"
        else:
            return result["name"]

    def signup(self):
        self.connect_to_db()
        self.create_db(dbname=self.db)
        self.create_collection(coll_name=self.collection)
        result = self.insert()
        return result

    def connect_to_db(self):
        client = MongoClient('mongodb://localhost:27017')
        self.client = client

    def create_db(self, dbname):
        db = self.client[dbname]
        self.db = db

    def create_collection(self, coll_name):
        collection = self.db[coll_name]
        self.collection = collection

    def insert(self):
        query = {
            "email": self.email
        }
        ret_data = self.collection.count_documents(query)

        if ret_data == 1:
            return "Email Already Registered"
        else:
            data = {
                "name": self.name,
                "email": self.email,
                "password": self.password
            }
            self.collection.insert_one(data)
            return "Registration Successful"

    def read_data(self, query):
        result = self.collection.count_documents(query)
        if result >= 1:
            userdata = self.collection.find_one(query)
            return userdata
        else:
            return None
